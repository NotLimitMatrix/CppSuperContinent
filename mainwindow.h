#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPushButton>
#include <QtCore>
#include <QTextBrowser>
#include <QRect>
#include <QTableWidget>
#include <QHeaderView>
#include <QListWidget>
#include <QLabel>
#include <QPainter>
#include <QPaintEvent>

#include "Reference.h"
#include "resource.h"
#include "controller.h"

typedef QList<QPushButton*> BUTTON_LIST;
typedef QList<QLabel*> LABEL_LIST;
typedef QList<Resource*> RESOURCE_LIST;

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    QTextBrowser* textBrowser;
    QTableWidget* resourcePanel;
    QTableWidget* technologyPanel;
    BUTTON_LIST zoningList;

    LABEL_LIST technologyLabels;
    BUTTON_LIST setRateButtonList;
    BUTTON_LIST transformResearchList;

    QListWidget* waitSelectList;

    QThread* backendLoop;
    Controller* backendController;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init();
    QTableWidget *generateTableWidget(int row, int col, int h_size, int v_size);
    void initResourcePanel();
    void initTechnologyPanel();
    void initZoningButtons();
    void initTechnologyLabel();
    void initSetRateButtonList();
    void initTransformResearchList();
    void initWaitSelectList();
    void initTextBrowser();
    void initGameLoop();

    void paintEvent(QPaintEvent *event);
};
#endif // MAINWINDOW_H
