#include "mainwindow.h"
#include "cpphighlighter.h"
#include "svdmodel.h"
#include "ui_mainwindow.h"

#include <QClipboard>
#include <QSettings>
#include <QShortcut>

#include "Types.h"
#include "tree.h"
#include "xrxmlser.hpp"
// #include "acropdf.h"
// #include "communicator.h"
// #include <QWebChannel>

QString fileName{
    uR"(C:\ST\STM32CubeIDE_1.7.0\STM32CubeIDE\plugins\com.st.stm32cube.ide.mcu.productdb.debug_2.0.0.202107021202\resources\cmsis\STMicroelectronics_CMSIS_SVD\STM32L476.svd)"_s};

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    cppHighlighter = new CppHighlighter(ui->textEdit->document());
    ui->textEdit->setFont({u"JetBrains Mono Light"_s, 10});
    const int tabStop = 4; // 4 characters

    QFontMetricsF metrics(ui->textEdit->font());
    ui->textEdit->setTabStopDistance(tabStop * metrics.averageCharWidth());

    connect(ui->pbOpen, &QPushButton::clicked, this, &MainWindow::parse);
    connect(ui->treeView, &QTreeView::doubleClicked, this, &MainWindow::doubleClicked);

    loadSettings();

    ui->pbOpen->click();
    menuBar()->addAction(u"&Expand All"_s, ui->treeView, &QTreeView::expandAll);

    connect(new QShortcut(QKeySequence::Copy, this), &QShortcut::activated, [this] {
        auto selectedRows{ui->treeView->selectionModel()->selectedRows()};
        if(selectedRows.size()) {
            QClipboard* clipboard = QGuiApplication::clipboard();
            QString originalText = clipboard->text();
            QString newText;
            for(auto&& index: selectedRows) {
                newText += u"QString %1;\n"_s.arg(index.data().toString());
            }
            clipboard->setText(newText);
        }
    });
}

MainWindow::~MainWindow() {
    saveSettings();
    delete ui;
}

void MainWindow::loadSettings() {
    QSettings settings;
    settings.beginGroup("MainWindow");
    restoreGeometry(settings.value("Geometry").toByteArray());
    restoreState(settings.value("State").toByteArray());
    ui->lePath->setText(settings.value("lePath", fileName).toString());
    ui->splitter->restoreState(settings.value("splitter").toByteArray());
    ui->treeView->header()->restoreState(settings.value("treeView").toByteArray());
    ui->treeView_2->header()->restoreState(settings.value("treeView_2").toByteArray());
    //    ui->lePdfPath->setText(settings.value("lePdfPath", fileName).toString());
}

void MainWindow::saveSettings() {
    QSettings settings;
    settings.beginGroup("MainWindow");
    settings.setValue("Geometry", saveGeometry());
    settings.setValue("State", saveState());
    settings.setValue("lePath", ui->lePath->text());
    settings.setValue("splitter", ui->splitter->saveState());
    settings.setValue("treeView", ui->treeView->header()->saveState());
    settings.setValue("treeView_2", ui->treeView_2->header()->saveState());
    //    settings.setValue("lePdfPath", ui->lePdfPath->text());
}

void MainWindow::doubleClicked(const QModelIndex& index) {
    class TreeView : public QTreeView {
    public:
        TreeView(const QModelIndex& index) {
            setModel(new SvdModel{static_cast<SvdNode*>(index.internalPointer()), this});
            header()->setSectionResizeMode(QHeaderView::Stretch);
            header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
            setAlternatingRowColors(true);
            setTextElideMode(Qt::ElideMiddle);
            setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
            setAnimated(true);
            expandAll();
            resize(640, 1080);
            show();
        }
        void closeEvent(QCloseEvent* event) { deleteLater(); }
    };
    if(index.data().toString() == u"peripheral")
        new TreeView(index);
}

void MainWindow::parse() {
    delete ui->treeView->model();
    peripherals.clear();
    if(QFile::exists(ui->lePath->text())) {
        ui->treeView->setModel(new SvdModel{SvdParser(ui->lePath->text(), peripherals), ui->treeView});
        ui->treeView->header()->setSectionResizeMode(QHeaderView::Stretch);
        ui->treeView->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
        peripherals.generate(ui->textEdit);
        ui->textEdit->moveCursor(QTextCursor::Start);
    }

    static Generated::Device device{};
    XML::Serializer(ui->lePath->text().toUtf8()) >> device;

    ui->treeView_2->setModel(new TreeModel{(new Item{device, new TreeItem})->parent(), ui->treeView});

    ui->treeView->expandAll();
    ui->treeView->header()->sectionResizeMode(QHeaderView::ResizeToContents);
    ui->treeView_2->expandAll();
    ui->treeView_2->header()->sectionResizeMode(QHeaderView::ResizeToContents);
}
