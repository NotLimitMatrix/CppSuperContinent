#ifndef GUI_PANEL_H
#define GUI_PANEL_H
#include "Const/COLOR.h"
#include "Const/STATIC.h"
#include <QPainter>
#include <QRect>

class GUI_PANEL
{
    QRect square;
    int singleHeight;
    int titleWidth = 80;
    int resourceWidth;
    int powerWidth;
    int processWidth;
    int distWidth;

public:
    GUI_PANEL(QRect square);

    void draw(QPainter *painter);
    void drawResource(QPainter *painter);
    void drawPower(QPainter *painter);
    void drawTechnology(QPainter *painter);
    void drawSchedule(
        QPainter *painter, QRect rect, QString name, int process, QColor color, int rate);
};

#endif // GUI_PANEL_H
