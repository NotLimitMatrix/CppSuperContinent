#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "GUI/GUI_MESSAGE.h"
#include "GUI/GUI_PANEL.h"
#include "GUI/GUI_WORLD.h"
#include "GUI/GUI_ZONING.h"
#include "GUI/SizeManager.h"
#include <QFont>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    SizeManager *sizeManager = new SizeManager();
    GUI_WORLD *world;
    GUI_ZONING *zoning;
    GUI_PANEL *panel;
    GUI_MESSAGE *message;

public:
    MainWindow(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
};
#endif // MAINWINDOW_H
