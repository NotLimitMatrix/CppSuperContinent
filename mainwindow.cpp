#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    init();
    initResourcePanel();
    initTechnologyPanel();
    initZoningButtons();
    initTechnologyLabel();
    initSetRateButtonList();
    initTransformResearchList();

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
    textBrowser->setGeometry(QRect(850, 315, 148, 285));
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

void MainWindow::initZoningButtons()
{
    int ZONING_NUMBER = 6;

    int x_base = 600, y_base = 0;
    int z_SIZE = 40, b_SIZE = 50;

    for(int r=0; r<ZONING_NUMBER; r++)
        for(int c=0; c<ZONING_NUMBER; c++){
            QPushButton* b = new QPushButton(this);
            b->setGeometry(x_base+c*z_SIZE, y_base+r*z_SIZE, b_SIZE, b_SIZE);
            b->setText(QString(""));
            zoningList.append(b);
        }
}

void MainWindow::initTechnologyLabel()
{
    int x_base = 850, y_base = 247;
    int l_SIZE = 23;

    QString style = "font: 10pt ;border-width: 1px;border-style: solid;border-color: rgb(0, 0, 0)";
    for(int r=0; r<3; r++)
    {
        QLabel *label = new QLabel(this);
        label->setGeometry(x_base, y_base+r*l_SIZE, 100, 20);
        label->setStyleSheet(style);
        label->setText(QString("没有研究"));
        technologyLabels.append(label);
    }
}

void MainWindow::initSetRateButtonList()
{
    int x_base = 950, y_base = 243;
    int b_SIZE = 30, dy = 22;
    int rates[3] = {3,3,4};
    for(int r=0; r<3; r++)
    {
        QPushButton *b = new QPushButton(this);
        b->setGeometry(x_base, y_base+r*dy, b_SIZE, b_SIZE);
        b->setText(QString::number(rates[r], 10));
        setRateButtonList.append(b);
    }
}

void MainWindow::initTransformResearchList()
{
    int x_base = 970, y_base = 243;
    int b_SIZE = 30, dy = 22;
    for(int r=0; r<3; r++)
    {
        QPushButton *b = new QPushButton(this);
        b->setGeometry(x_base, y_base+r*dy, b_SIZE, b_SIZE);
        b->setText("T");
        transformResearchList.append(b);
    }
}
