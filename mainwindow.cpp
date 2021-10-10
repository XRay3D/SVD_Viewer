#include "mainwindow.h"
#include "svdmodel.h"
#include "ui_mainwindow.h"
#include <QSettings>

QString fileName { R"(C:\ST\STM32CubeIDE_1.7.0\STM32CubeIDE\plugins\com.st.stm32cube.ide.mcu.productdb.debug_2.0.0.202107021202\resources\cmsis\STMicroelectronics_CMSIS_SVD\STM32L476.svd)" };

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pbOpen, &QPushButton::clicked, [this] {
        delete ui->treeView->model();
        if (QFile::exists(ui->lePath->text())) {
            ui->treeView->setModel(new SvdModel { SvdParser(ui->lePath->text()), ui->treeView });
            ui->treeView->header()->setSectionResizeMode(QHeaderView::Stretch);
            ui->treeView->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
        }
    });

    connect(ui->treeView, &QTreeView::doubleClicked, [](const QModelIndex& index) {
        class TreeView : public QTreeView {
        public:
            TreeView(const QModelIndex& index)
            {
                setModel(new SvdModel { static_cast<SvdNode*>(index.internalPointer()), this });
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
        if (index.data().toString() == "peripheral")
            new TreeView(index);
    });

    loadSettings();

    ui->pbOpen->click();
    menuBar()->addAction("&Expand All", ui->treeView, &QTreeView::expandAll);

    /*


    */
}

MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}

void MainWindow::loadSettings()
{
    QSettings settings;
    settings.beginGroup("MainWindow");
    restoreGeometry(settings.value("Geometry").toByteArray());
    restoreState(settings.value("State").toByteArray());
    ui->lePath->setText(settings.value("lePath", fileName).toString());
}

void MainWindow::saveSettings()
{
    QSettings settings;
    settings.beginGroup("MainWindow");
    settings.setValue("Geometry", saveGeometry());
    settings.setValue("State", saveState());
    settings.setValue("lePath", ui->lePath->text());
}
