#pragma once

#include "xrxmlser.hpp"
#include <QAbstractItemModel>
#include <qbitarray.h>

namespace meta = std ::meta;
using namespace std::string_view_literals;
using namespace Qt::Literals;

template <class T> concept IsOptional = std::is_same_v<T, std::optional<typename T::value_type>>;
template <class T> concept IsVector = std::is_same_v<T, std::vector<typename T::value_type>>;
template <template <class...> class Var, class... Ts> concept IsVariant
    = std::is_same_v<Var<Ts...>, std::variant<Ts...>>;
// template <template <class> class Vec, class Ts> concept IsVector
//     = std::is_same_v<Vec<Ts>, std::vector<Ts>>;
// template <template <class> class Opt, class Ts> concept IsOptional
//     = std::is_same_v<Opt<Ts>, std::optional<Ts>>;

template <class T> constexpr std::string_view TYPE_NAME = display_string_of(^^T);
template <> constexpr std::string_view TYPE_NAME<int8_t> = "int8"sv;
template <> constexpr std::string_view TYPE_NAME<int16_t> = "int16"sv;
template <> constexpr std::string_view TYPE_NAME<int32_t> = "int32"sv;
template <> constexpr std::string_view TYPE_NAME<int64_t> = "int64"sv;
template <> constexpr std::string_view TYPE_NAME<std::string> = "std::string"sv;
template <> constexpr std::string_view TYPE_NAME<uint8_t> = "uint8"sv;
template <> constexpr std::string_view TYPE_NAME<uint16_t> = "uint16"sv;
template <> constexpr std::string_view TYPE_NAME<uint32_t> = "uint32"sv;
template <> constexpr std::string_view TYPE_NAME<uint64_t> = "uint64"sv;

template <typename T>
struct Item;

struct TreeItem {
    TreeItem(TreeItem* parent = nullptr)
        : parent_{parent} {
        if(parent_) parent_->children.emplace_back(this);
        else data_ = {
                 "Field Name"sv,
                 "Value"sv,
                 "Description"sv,
                 "Type Name"sv,
             };
    }

    virtual ~TreeItem() = default;

    virtual QVariant data(int column, int role) const {
        if(role == Qt::DisplayRole
            || role == Qt::EditRole
            || role == Qt::ToolTipRole)
            return QByteArray{
                QByteArrayData{nullptr, const_cast<char*>(data_[column].data()), qsizetype(data_[column].size())}
            };
        return {};
    }

    TreeItem* child(size_t number) {
        return (number >= children.size())
            ? nullptr
            : children.at(number).get();
    }

    TreeItem* parent() { return parent_; }

    virtual bool setData(int column, const QVariant& value) { return false; }

    ptrdiff_t childNumber() const {
        if(parent_)
            if(auto it = std::ranges::find(parent_->children, this, &std::unique_ptr<TreeItem>::get); it != parent_->children.end())
                return std::distance(parent_->children.begin(), it);
        return 0;
    }
    size_t columnCount() const { return data_.size(); }
    size_t size() const { return children.size(); }

    std::string_view& data(size_t i) { return data_[i]; }

    enum {
        FieldName,
        Value,
        Description,
        TypeName,
    };

protected:
    std::vector<std::unique_ptr<TreeItem>> children;
    std::array<std::string_view, 4> data_;

    TreeItem* parent_{};

    static consteval auto members(meta::info info) {
        static constexpr auto CTX = meta::access_context::unprivileged();
        return std::define_static_array([info] consteval {
            auto members = nonstatic_data_members_of(info, CTX);
            [&members](this auto self, auto&& bases) -> void {
                for(meta::info base: bases | std::views::transform(meta::type_of)) {
                    self(bases_of(base, CTX));
                    members.append_range(meta::nonstatic_data_members_of(base, CTX));
                }
            }(bases_of(info, CTX));
            return members;
        }());
    }

    template <XML::IsClass Ty> void createChild(Ty& arg) {
        // data_[FieldName] = TYPE_NAME<T>;
        template for(constexpr auto FIELD: members(^^Ty)) {
            if constexpr(
                (display_string_of(FIELD) == "name"sv && requires { data_[Value] = arg.[:FIELD:]; })
                || display_string_of(FIELD) == "description"sv)
                continue; // Пропуск, отображаются в родительском элементе.
            if constexpr(IsOptional<decltype(arg.[:FIELD:])>) {
                if(arg.[:FIELD:]) {
                    TreeItem* item = new ::Item{*arg.[:FIELD:], this};
                    item->data(FieldName) = display_string_of(FIELD);
                }
            } else if constexpr(IsVector<decltype(arg.[:FIELD:])>) {
                if(arg.[:FIELD:].size()) {
                    TreeItem* item = new ::Item{arg.[:FIELD:], this};
                    item->data(FieldName) = display_string_of(FIELD);
                }
            } else {
                TreeItem* item = new ::Item{arg.[:FIELD:], this};
                item->data(FieldName) = display_string_of(FIELD);
            }
        }
    }

    template <typename Ty> void createChild(std::vector<Ty>& arg) {
        for(auto&& var: arg) new ::Item{var, this};
    }

    template <typename... Ts> void createChild(std::variant<Ts...>& arg) {
        arg.visit([this](auto& arg) { new ::Item{arg, this}; });
    }

    template <typename Ty> void createChild(Ty&) {
        // qWarning() << TYPE_NAME<Ty>;
    }
};

template <typename T>
struct Item : TreeItem {
    T& val;
    Item(T& val, TreeItem* parent = nullptr)
        : TreeItem{parent}, val{val} {
        data_[TypeName] = TYPE_NAME<T>;
        if constexpr(requires { data_[Value] = val.name; }) data_[Value] = val.name;
        // if constexpr(requires { data_[Value] = *val.name; }) data_[Value] = *val.name;
        if constexpr(requires { data_[Description] = val.description; })
            data_[Description] = val.description;
        else {
            if constexpr(requires { data_[Description] = *val.description; })
                if(val.description) data_[Description] = *val.description;
            if constexpr(requires { data_[Description] = *val.derivedFrom; })
                if(val.derivedFrom) data_[Description] = *val.derivedFrom;
        }
        data_[FieldName] = TYPE_NAME<T>;
        createChild(val);
    }

    // TreeItem interface
    QVariant data(int column, int role) const override {
        if(column == Value) {
            if(role == Qt::DisplayRole || role == Qt::EditRole) {
                /**/ if constexpr(std::is_same_v<T, std::string>) {
                    return QByteArray{
                        QByteArrayData{nullptr, const_cast<char*>(val.data()), qsizetype(val.size())}
                    };
                } else if constexpr(std::is_same_v<T, std::string_view>) {
                    return val.data();
                } else if constexpr(std::is_arithmetic_v<T> && sizeof(T) == 1) {
                    return val;
                } else if constexpr(IsVector<T>) {
                    return static_cast<int>(val.size());
                } else if constexpr(XML::IsFloating<T> || std::is_same_v<T, bool>) {
                    return val;
                } else if constexpr(XML::IsIntegral<T>) {
                    return "0x"_ba += QByteArray::number(val, 16) + " (" + QByteArray::number(val) + ')';
                } else if constexpr(std::is_enum_v<T>) {
                    auto sv = XML::toString(val);
                    return QByteArray{
                        QByteArrayData{nullptr, const_cast<char*>(sv.data()), qsizetype(sv.size())}
                    };
                }
            }
            if constexpr(std::is_same_v<T, std::string>) {
                if(role == Qt::BackgroundRole && val.front() == '#')
                    return QColor{val.c_str()};
            }
        }
        return TreeItem::data(column, role);
    }
    bool setData(int column, const QVariant& value) override {
        return TreeItem::setData(column, value);
    }
};

template <typename T> Item(T&, TreeItem*) -> Item<T>;

struct TreeModel : public QAbstractItemModel {
    // Q_OBJECT

public:
    TreeModel(TreeItem* rootItem, QObject* parent = nullptr)
        : QAbstractItemModel{parent}
        , rootItem{rootItem} {
    }

    template <typename T>
    TreeModel(T& data, QObject* parent = nullptr)
        : TreeModel{(new Item{data, new TreeItem})->parent(), parent} {
    }

    ~TreeModel() { delete rootItem; }

    QVariant data(const QModelIndex& index, int role) const override {
        if(index.isValid())
            return getItem(index)->data(index.column(), role);
        return {};
    }
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
        if(orientation == Qt::Horizontal && role == Qt::DisplayRole)
            return rootItem->data(section, role);
        return QAbstractItemModel::headerData(section, orientation, role);
    }

    QModelIndex index(int row, int column, const QModelIndex& parent = {}) const override {
        if(parent.isValid() && parent.column()) return {};
        TreeItem* item = getItem(parent);
        if(!item) return {};
        item = item->child(row);
        if(item) return createIndex(row, column, item);
        return {};
    }
    QModelIndex parent(const QModelIndex& index) const override {
        if(!index.isValid()) return {};
        TreeItem* item = getItem(index);
        TreeItem* parent = item ? item->parent() : nullptr;
        if(parent == rootItem || !parent) return {};
        return createIndex(parent->childNumber(), 0, parent);
    }

    int rowCount(const QModelIndex& parent = {}) const override {
        if(parent.isValid() && parent.column()) return 0;
        TreeItem* item = getItem(parent);
        return item ? item->size() : 0;
    }

    int columnCount(const QModelIndex& /*parent*/ = {}) const override {
        return rootItem->columnCount();
    }

    // Qt::ItemFlags flags(const QModelIndex& index) const override {
    //     if(!index.isValid()) return Qt::NoItemFlags;
    //     return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
    // }
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override {
        if(role != Qt::EditRole) return false;
        TreeItem* item = getItem(index);
        const bool result = item->setData(index.column(), value);
        if(result) emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});
        return result;
    }
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant& value, int role = Qt::EditRole) override {
        if(role != Qt::EditRole || orientation != Qt::Horizontal) return false;
        const bool result = rootItem->setData(section, value);
        if(result) emit headerDataChanged(orientation, section, section);
        return result;
    }

private:
    TreeItem* getItem(const QModelIndex& index) const {
        if(index.isValid())
            if(TreeItem* item = static_cast<TreeItem*>(index.internalPointer()))
                return item;
        return rootItem;
    }

    TreeItem* rootItem;
};
