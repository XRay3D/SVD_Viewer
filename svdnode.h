#pragma once

#include <QtCore>
#include <memory>

class SvdNode {
    friend class SvdParser;

public:
    explicit SvdNode(const QList<QVariant>& data, SvdNode* parentItem = nullptr);

    ~SvdNode();

    QVariant data(int column) const { return data_.value(column); }

    SvdNode* child(int row) { return childs_.value(row); }

    SvdNode* parent() { return parent_; }

    int childCount() const { return childs_.count(); }

    int columnCount() const { return data_.count(); }

    int row() const { return parent_ ? parent_->childs_.indexOf(const_cast<SvdNode*>(this)) : 0; }

    void appendChild(SvdNode* item) { childs_.append(item); }

private:
    QList<QVariant> data_;
    QList<SvdNode*> childs_;
    SvdNode* const parent_;
};
