#ifndef GUI_ZONING_H
#define GUI_ZONING_H

#include"Core.h"

class ZSolt
{
    int _id;
    int _build_id = -1;

    int _belong_id;
    QPoint _rc;
    QColor _background = WHITE;
    QColor _build_color = BLACK;

public:
    ZSolt(int id, int r, int c, int belong)
    {
        _id = id;
        _rc = QPoint(r,c);
        _belong_id = belong;
    }
    QColor getBackGroundColor(){return _background;}
    QColor getBuildColor()
    {
        if(_build_id == -1)
            return WHITE;
        else
            return _build_color;
    }
    int getId(){return _id;}
    QRect getRect(int startX, int startY, int size);
    QRect getBuildRect(int startX, int startY, int size, int dx);

    void getDisplay(QVector<QString> *vString);
};

class GUI_zoning
{
    int _number;
    int _sum_number;
    int _size;
    int _build_dx;

    int _belong_id;

    QVector<ZSolt*> zVector;

public:

    GUI_zoning(int number, int belong);
    void draw(QPainter *painter);
    int getSize(){return _size;}

    bool inZoning(int x, int y);
    int getIdWithPos(int x, int y);
    ZSolt *getSoltWithId(int id);

};

#endif // GUI_ZONING_H
