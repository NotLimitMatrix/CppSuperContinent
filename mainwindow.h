#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "GUI/GUI_MESSAGE.h"
#include "GUI/GUI_PANEL.h"
#include "GUI/GUI_WORLD.h"
#include "GUI/GUI_ZONING.h"
#include "GUI/SizeManager.h"
#include <QFont>
#include <QKeyEvent>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include <QTime>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    SizeManager *sizeManager = new SizeManager();
    GUI_WORLD *world;
    GUI_ZONING *zoning;
    GUI_PANEL *panel;
    GUI_MESSAGE *message;
    QString superContinentTitle = QString("Super Continent");

    QTimer *timeFlower;
    int timeCounter = 0;
    bool isPause = true;

public:
    MainWindow(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void timeflowTitle();
};
#endif // MAINWINDOW_H
