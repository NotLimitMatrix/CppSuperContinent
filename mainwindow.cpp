#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    init();
    initResourcePanel();
    initTechnologyPanel();

    show();
}

MainWindow::~MainWindow()
{

}

void MainWindow::init()
{
    resize(1000, 600);
    setMinimumSize(QSize(1000,600));
    setMaximumSize(QSize(1000,600));
    setWindowTitle("Super Continent");

    textBrowser = new QTextBrowser(this);
    textBrowser->setGeometry(QRect(850, 245, 148, 350));
}

QTableWidget *MainWindow::generateTableWidget(int row, int col, int h_size, int v_size)
{
    QTableWidget *table = new QTableWidget(this);
    table->setRowCount(row);
    table->setColumnCount(col);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionMode(QAbstractItemView::NoSelection);

    QHeaderView *t = table->horizontalHeader();
    t->setVisible(false);
    t->setDefaultSectionSize(h_size);
    t->setHighlightSections(false);

    QHeaderView *v = table->verticalHeader();
    v->setVisible(false);
    v->setDefaultSectionSize(v_size);
    v->setHighlightSections(false);

    for(int r=0; r<row; r++)
        for(int c=0; c<col; c++)
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setTextAlignment(Qt::AlignCenter);
            table->setItem(r,c,item);
        }

    return table;
}

void MainWindow::initResourcePanel()
{
    resourcePanel = generateTableWidget(5,3,48,26);
    resourcePanel->setGeometry(850,3,148,135);
    QString panels[5] = {QString("能量"),QString("矿物"),QString("食物"),QString("物资"),QString("合金")};
    for(int r=0; r<5; r++)
    {
        QTableWidgetItem *item = resourcePanel->item(r, 0);
        item->setText(panels[r]);
    }
}

void MainWindow::initTechnologyPanel()
{
    technologyPanel = generateTableWidget(3,2,73,36);
    technologyPanel->setGeometry(850,135,148,110);
    QString panels[3] = {QString("经济"),QString("军事"),QString("科研")};
    for (int r=0; r<3; r++)
    {
        QTableWidgetItem* item = technologyPanel->item(r,0);
        item->setText(panels[r]);
    }
}
