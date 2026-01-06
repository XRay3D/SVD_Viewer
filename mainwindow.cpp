#include "mainwindow.h"
#include "cpphighlighter.h"
#include "ui_mainwindow.h"

#include <QClipboard>
#include <QFile>
#include <QSettings>
#include <QShortcut>
#include <QSortFilterProxyModel>

#include "Types.h"
#include "tree.h"
#include "xrxmlser.hpp"

class ProxyModel : public QSortFilterProxyModel {
    // Q_OBJECT

public:
    using QSortFilterProxyModel::QSortFilterProxyModel;

    // Установка фильтров
    void setValueFilter(const QString& text) {
        filter.back() = text;
        re.setPattern(text);
        invalidate();
    }
    void setNameFilter(const QString& text) {
        filter.front() = text;
        invalidate();
    }

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex& source_parent) const override {
        if(!sourceModel()) return false;

        // Получаем индексы для текущей строки
        const std::array columnIndex{
            sourceModel()->index(source_row, 0, source_parent),
            sourceModel()->index(source_row, 1, source_parent),
        };

        std::array match{true, true}; // Если фильтр не задан, считаем что совпадает

        // Проверка первого столбца (точное совпадение)
        if(filter.front().size()) {
            QString text = sourceModel()->data(columnIndex.front()).toString();
            match.front() = (text == filter.front()); // ExactMatch
        }

        // Проверка второго столбца (частичное совпадение)
        if(filter.back().size() && re.isValid()) {
            QString text = sourceModel()->data(columnIndex.back()).toString();
            // match.back() = text.contains(filter.back(), Qt::CaseInsensitive);
            match.back() = re.match(text).hasMatch();
        }

        // Также проверяем детей (если строка содержит подчиненные элементы)
        bool childrenAccepted = false;
        int childCount = sourceModel()->rowCount(columnIndex.front());
        for(int i: v::iota(0, childCount)) {
            if(filterAcceptsRow(i, columnIndex.front())) {
                childrenAccepted = true;
                break;
            }
        }

        // Строка отображается, если:
        // 1. Она удовлетворяет всем фильтрам
        // 2. ИЛИ если хотя бы один из ее детей удовлетворяет фильтрам
        return (match.front() && match.back()) || childrenAccepted;
    }

private:
    std::array<QString, 2> filter;

    QRegularExpression re;
};

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    proxyModel = new ProxyModel{ui->treeView};
    ui->treeView->setModel(proxyModel);

    cppHighlighter = new CppHighlighter(ui->textEdit->document());
    ui->textEdit->setFont({u"JetBrains Mono Light"_s, 10});
    const int tabStop = 4; // 4 characters

    QFontMetricsF metrics(ui->textEdit->font());
    ui->textEdit->setTabStopDistance(tabStop * metrics.averageCharWidth());

    connect(ui->pbOpen, &QPushButton::clicked, this, &MainWindow::parse);
    connect(ui->treeView, &QTreeView::doubleClicked, this, &MainWindow::doubleClicked);

    connect(ui->leQueryName, &QLineEdit::textChanged,
        proxyModel, &ProxyModel::setNameFilter);

    // connect(ui->leQueryName, &QLineEdit::editingFinished,
    //     ui->treeView, &QTreeView::expandAll);

    connect(ui->leQueryValue, &QLineEdit::textChanged,
        proxyModel, &ProxyModel::setValueFilter);

    // connect(ui->leQueryValue, &QLineEdit::editingFinished,
    //     ui->treeView, &QTreeView::expandAll);

    connect(ui->pbCollapse, &QPushButton::clicked, this,
        [this] { ui->treeView->collapseAll(/*ui->treeView->currentIndex()*/); });

    connect(ui->pbExpand, &QPushButton::clicked, this,
        [this] { ui->treeView->expandRecursively(ui->treeView->currentIndex()); });

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
    ui->lePath->setText(settings.value("lePath").toString());
    ui->leQueryValue->setText(settings.value("leQueryValue").toString());
    ui->leQueryName->setText(settings.value("leQueryName").toString());
    ui->splitter->restoreState(settings.value("splitter").toByteArray());
    ui->treeView->header()->restoreState(settings.value("treeView").toByteArray());
}

void MainWindow::saveSettings() {
    QSettings settings;
    settings.beginGroup("MainWindow");
    settings.setValue("Geometry", saveGeometry());
    settings.setValue("State", saveState());
    settings.setValue("lePath", ui->lePath->text());
    settings.setValue("leQueryValue", ui->leQueryValue->text());
    settings.setValue("leQueryName", ui->leQueryName->text());
    settings.setValue("splitter", ui->splitter->saveState());
    settings.setValue("treeView", ui->treeView->header()->saveState());
}

void MainWindow::doubleClicked(const QModelIndex& index) {
    qApp->clipboard()->setText(index.data().toString());
    /*
    class TreeView : public QTreeView {
    public:
        TreeView(const QModelIndex& index) {
            // setModel(new SvdModel{static_cast<SvdNode*>(index.internalPointer()), this});
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
    if(index.data().toString() == u"peripheral") new TreeView(index);
*/
}

void MainWindow::parse() {
    if(QFile::exists(ui->lePath->text())) {
        static Generated::Device device{};
        XML::Serializer(ui->lePath->text().toUtf8().data()) >> device;

        delete proxyModel->sourceModel();
        proxyModel->setSourceModel(new TreeModel{device, ui->treeView});

        ui->treeView->expandAll();
        ui->treeView->header()->sectionResizeMode(QHeaderView::ResizeToContents);
    }
}
