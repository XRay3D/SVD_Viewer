#pragma once

#include "svdparser.h"
#include <QAbstractItemModel>

class SvdModel : public QAbstractItemModel {
    Q_OBJECT
    SvdNode* rootItem;

public:
    explicit SvdModel(SvdNode* rootItem, QObject* parent = 0);
    ~SvdModel();

    QVariant data(const QModelIndex& index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column, const QModelIndex& parent = {}) const override;
    QModelIndex parent(const QModelIndex& index) const override;
    int rowCount(const QModelIndex& parent = {}) const override;
    int columnCount(const QModelIndex& parent = {}) const override;
};
