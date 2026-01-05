#include "communicator.h"
#include <QApplication>

void Communicator::setUrl(const QString &data)
{
    if (data == url_)
        return;
    url_ = data;
    emit urlChanged(url_);
}
