#include "svdmodel.h"

SvdModel::SvdModel(SvdNode* rootItem, QObject* parent)
    : QAbstractItemModel(parent)
    , rootItem { rootItem }
{
}

SvdModel::~SvdModel()
{
    if (!rootItem->parent())
        delete rootItem;
}

int SvdModel::columnCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return static_cast<SvdNode*>(parent.internalPointer())->columnCount();
    else
        return rootItem->columnCount();
}

QVariant SvdModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return {};

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        SvdNode* item = static_cast<SvdNode*>(index.internalPointer());
        return item->data(index.column());
    }
    return {};
}

Qt::ItemFlags SvdModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return {};

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

QVariant SvdModel::headerData(int section, Qt::Orientation orientation,
    int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return {};
}

QModelIndex SvdModel::index(int row, int column, const QModelIndex& parent)
    const
{
    if (!hasIndex(row, column, parent))
        return {};

    SvdNode* parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<SvdNode*>(parent.internalPointer());

    SvdNode* childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return {};
}

QModelIndex SvdModel::parent(const QModelIndex& index) const
{
    if (!index.isValid())
        return {};

    SvdNode* childItem = static_cast<SvdNode*>(index.internalPointer());
    SvdNode* parentItem = childItem->parent();

    if (parentItem == rootItem)
        return {};

    return createIndex(parentItem->row(), 0, parentItem);
}

int SvdModel::rowCount(const QModelIndex& parent) const
{
    SvdNode* parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<SvdNode*>(parent.internalPointer());

    return parentItem->childCount();
}
