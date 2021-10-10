#include "svdnode.h"



SvdNode::SvdNode(const QList<QVariant>& data, SvdNode* parent)
{
    m_parentItem = parent;
    data_ = data;
}

SvdNode::~SvdNode()
{
    qDeleteAll(m_childItems);
}

void SvdNode::appendChild(SvdNode* item)
{
    m_childItems.append(item);
}

SvdNode* SvdNode::child(int row)
{
    return m_childItems.value(row);
}

int SvdNode::childCount() const
{
    return m_childItems.count();
}

int SvdNode::columnCount() const
{
    return data_.count();
}

QVariant SvdNode::data(int column) const
{
    return data_.value(column);
}

SvdNode* SvdNode::parent()
{
    return m_parentItem;
}

int SvdNode::row() const
{
    if (m_parentItem)
        return m_parentItem->m_childItems.indexOf(const_cast<SvdNode*>(this));

    return 0;
}
