#include "mainwindow.h"
#include "cpphighlighter.h"
#include "svdmodel.h"
#include "ui_mainwindow.h"
#include <QClipboard>
#include <QSettings>
#include <QShortcut>
//#include "acropdf.h"
//#include "communicator.h"
//#include <QWebChannel>

QString fileName { R"(C:\ST\STM32CubeIDE_1.7.0\STM32CubeIDE\plugins\com.st.stm32cube.ide.mcu.productdb.debug_2.0.0.202107021202\resources\cmsis\STMicroelectronics_CMSIS_SVD\STM32L476.svd)" };

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cppHighlighter = new CppHighlighter(ui->textEdit->document());
    ui->textEdit->setFont({ "JetBrains Mono Light", 10 });
    const int tabStop = 4; // 4 characters

    QFontMetricsF metrics(ui->textEdit->font());
    ui->textEdit->setTabStopDistance(tabStop * metrics.averageCharWidth());

    connect(ui->pbOpen, &QPushButton::clicked, this, &MainWindow::parse);
    connect(ui->treeView, &QTreeView::doubleClicked, this, &MainWindow::doubleClicked);

    loadSettings();

    ui->pbOpen->click();
    menuBar()->addAction("&Expand All", ui->treeView, &QTreeView::expandAll);

    connect(new QShortcut(QKeySequence::Copy, this), &QShortcut::activated, [this] {
        auto selectedRows { ui->treeView->selectionModel()->selectedRows() };
        if (selectedRows.size()) {
            QClipboard* clipboard = QGuiApplication::clipboard();
            QString originalText = clipboard->text();
            QString newText;
            for (auto&& index : selectedRows) {
                newText += QString("QString %1;\n").arg(index.data().toString());
            }
            clipboard->setText(newText);
        }
    });
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
    //    ui->lePdfPath->setText(settings.value("lePdfPath", fileName).toString());
}

void MainWindow::saveSettings()
{
    QSettings settings;
    settings.beginGroup("MainWindow");
    settings.setValue("Geometry", saveGeometry());
    settings.setValue("State", saveState());
    settings.setValue("lePath", ui->lePath->text());
    //    settings.setValue("lePdfPath", ui->lePdfPath->text());
}

void MainWindow::doubleClicked(const QModelIndex& index)
{
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
}

void MainWindow::parse()
{
    delete ui->treeView->model();
    peripherals.clear();
    //    if (QFile::exists(ui->lePdfPath->text())) {
    //        auto AcroPDF = new AcroPDFLib::AcroPDF(this);
    //        ui->gridLayout->addWidget(AcroPDF, 1, 2);
    //        qDebug() << "LoadFile" << AcroPDF->LoadFile(ui->lePdfPath->text());
    //        //        QString app_path = qApp->applicationDirPath();
    //        //#ifdef Q_OS_MACOS
    //        //        QDir app_path_dir(app_path);
    //        //        app_path_dir.cdUp();
    //        //        app_path_dir.cdUp();
    //        //        app_path_dir.cdUp();
    //        //        app_path = app_path_dir.absolutePath();
    //        //#endif
    //        //        auto url = QUrl::fromLocalFile(app_path + "/minified/web/viewer.html");

    //        //        QDir dir(app_path + "/minified/web/");
    //        //        //        setWindowTitle(pdf_path);
    //        //        QString pdf_path = dir.relativeFilePath(ui->lePdfPath->text());

    //        //        m_communicator = new Communicator(this);
    //        //        m_communicator->setUrl(pdf_path);

    //        //        //ui->m_webView = new QWebEngineView(this);

    //        //        QWebChannel* channel = new QWebChannel(this);
    //        //        channel->registerObject(QStringLiteral("communicator"), m_communicator);
    //        //        ui->m_webView->page()->setWebChannel(channel);

    //        //        ui->m_webView->load(url);
    //        //        //        setCentralWidget(m_webView);
    //    }
    if (QFile::exists(ui->lePath->text())) {
        ui->treeView->setModel(new SvdModel { SvdParser(ui->lePath->text(), peripherals), ui->treeView });
        ui->treeView->header()->setSectionResizeMode(QHeaderView::Stretch);
        ui->treeView->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
        peripherals.generate(ui->textEdit);
        ui->textEdit->moveCursor(QTextCursor::Start);
    }
}
