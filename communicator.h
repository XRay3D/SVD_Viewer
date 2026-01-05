#pragma once

#include <QObject>

class Communicator final : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)
    QString url_;

public:
    using QObject::QObject;

    QString url() const { return url_; }
    void setUrl(const QString &url);

signals:
    void urlChanged(const QString &);
};
