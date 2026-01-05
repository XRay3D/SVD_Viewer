#pragma once

#include "peripherals.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE

class CppHighlighter;
class Communicator;

namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow final : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    CppHighlighter* cppHighlighter;
    Communicator* communicator_;

    Peripherals peripherals;

    void loadSettings();
    void saveSettings();

    void doubleClicked(const QModelIndex& index);
    void parse();
};
