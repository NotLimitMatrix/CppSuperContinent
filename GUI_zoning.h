#ifndef GUI_ZONING_H
#define GUI_ZONING_H

#include"Core.h"

class ZSolt
{
    int _id;
    QPoint _rc;
    QColor _color = WHITE;

public:
    ZSolt(int id, int r, int c)
    {
        _id = id;
        _rc = QPoint(r,c);
    }
    QColor getColor(){return _color;}
    QRect getRect(int startX, int startY, int size);
};

class GUI_zoning
{
    int _number;
    int _sum_number;
    int _size;

    QVector<ZSolt*> zVector;

public:

    GUI_zoning(int number);
    void draw(QPainter *painter);
    int getSize(){return _size;}
};

#endif // GUI_ZONING_H
