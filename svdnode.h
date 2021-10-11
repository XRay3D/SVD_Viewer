#pragma once

#include <QtCore>
#include <memory>

class SvdNode {
    friend class SvdParser;

public:
    explicit SvdNode(const QStringList& data, SvdNode* parent = nullptr)
        : data_(data)
        , parent_ { parent }
    {
    }
    //explicit SvdNode(const QList<QVariant>& data, SvdNode* parentItem = nullptr);

    ~SvdNode() { qDeleteAll(childs_); }

    auto data(int column) const { return data_.value(column); }

    SvdNode* child(int row) { return childs_.value(row); }

    SvdNode* parent() { return parent_; }

    int childCount() const { return childs_.count(); }

    int columnCount() const { return data_.count(); }

    int row() const { return parent_ ? parent_->childs_.indexOf(const_cast<SvdNode*>(this)) : 0; }

    void appendChild(SvdNode* item) { childs_.append(item); }

private:
    QStringList data_;
    //QList<QVariant> data_;
    QList<SvdNode*> childs_;
    SvdNode* const parent_;
};
