#pragma once

#include <QtCore>
#include <memory>

class SvdNode {
    friend class SvdParser;

public:
    explicit SvdNode(const QList<QVariant>& data, SvdNode* parentItem = 0);
    ~SvdNode();

    void appendChild(SvdNode* child);

    SvdNode* child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    SvdNode* parent();

private:
    QList<SvdNode*> m_childItems;
    QList<QVariant> data_;
    SvdNode* m_parentItem;
};
