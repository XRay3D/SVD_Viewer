#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "peripherals.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE

class CppHighlighter;
class Communicator;

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
    CppHighlighter* cppHighlighter;
    Communicator* m_communicator;

    Peripherals peripherals;

    void loadSettings();
    void saveSettings();

    void doubleClicked(const QModelIndex& index);
    void parse();
};
#endif // MAINWINDOW_H
