#ifndef BLOCK_H
#define BLOCK_H

#include"Core.h"
#include"ZoningSlot.h"

class Block
{
    int _id;
    QPoint _rc;
    bool _visable = true;
    bool _can_move = true;
    int _size;

    int _status_id;
    QString _word;
    double _modifier;
    int _zoning_number;
    QColor _color;

    QRect solt_left_button;
    QRect solt_right_button;
    QRect solt_left_top;
    QRect solt_right_top;

public:
    QVector<ZoningSlot*> zVector;
    int zoning_size;

    Block(int id, int r, int c, int size);
    int randomStatus();
    QRect getRect(int startX, int startY);
    QColor getColor();
    int getX(){return _rc.x();}
    int getY(){return _rc.y();}
    int getId(){return _id;}
    int getZoningNumber(){return _zoning_number;}

    void getDisplay(QVector<QString> *vString);

    void setVisible(bool v){ _visable = v;}
    void setCanMove(bool cm){ _can_move = cm;}

    void insertZoning(ZoningSlot* zslot);
    void clearZoning(){zVector.clear();}
    void copyZoning(QVector<ZoningSlot*> *recv);

    void drawButton(QPainter *painter);
    void drawSoltLeftTop(QPainter *painter);
    void drawSoltRightTop(QPainter *painter);
};

#endif // BLOCK_H
