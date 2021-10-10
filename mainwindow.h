#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "peripherals.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;

    Peripherals peripherals;

    void loadSettings();
    void saveSettings();

    void doubleClicked(const QModelIndex& index);
    void parse();
};
#endif // MAINWINDOW_H
