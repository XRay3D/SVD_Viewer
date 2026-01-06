#pragma once

#include "peripherals.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow final : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    class CppHighlighter* cppHighlighter;
    class Communicator* communicator_;
    class ProxyModel* proxyModel;
    Peripherals peripherals;

    void loadSettings();
    void saveSettings();

    void doubleClicked(const QModelIndex& index);
    void parse();
};
