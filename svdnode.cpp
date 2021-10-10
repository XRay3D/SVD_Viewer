#include "svdnode.h"

SvdNode::SvdNode(const QList<QVariant>& data, SvdNode* parent)
    : data_(data)
    , parent_ { parent }
{
}

SvdNode::~SvdNode() { qDeleteAll(childs_); }
