#include "mainwindow.h"

#include <QApplication>
#include <QSettings>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationName("SVD_Viewer");
    QApplication::setOrganizationName("XR Soft");

    QSettings::setDefaultFormat(QSettings::IniFormat);
    QSettings::setPath(QSettings::IniFormat, QSettings::UserScope, QApplication::applicationDirPath());

    MainWindow w;
    w.show();
    return a.exec();
}
