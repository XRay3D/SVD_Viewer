#pragma once

#include <QtCore>
#include <memory>

class SvdNode
{
    friend class SvdParser;

public:
    explicit SvdNode(const QStringList &data, SvdNode *parent = nullptr)
        : data_{data}
        , parent_{parent}
    {}

    ~SvdNode() = default;

    auto data(int column) const { return data_.value(column); }

    SvdNode *child(int row) { return childs_.at(row).get(); }

    SvdNode *parent() { return parent_; }

    int childCount() const { return childs_.size(); }

    int columnCount() const { return data_.count(); }

    int row() const
    {
        if (parent_) {
            auto it = std::ranges::find(parent_->childs_, this, &std::unique_ptr<SvdNode>::get);
            return it - childs_.begin();
        }
        return 0;
    }

    void appendChild(SvdNode *item) { childs_.emplace_back(item); }

private:
    QStringList data_;
    std::vector<std::unique_ptr<SvdNode>> childs_;
    SvdNode *const parent_;
};
