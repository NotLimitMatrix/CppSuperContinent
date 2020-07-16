#ifndef BLOCK_H
#define BLOCK_H

#include"Core.h"
#include"GUI/GUI_zoning.h"

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

    GUI_zoning *_zoning;

    QRect solt_left_button;
    QRect solt_right_button;
    QRect solt_left_top;
    QRect solt_right_top;

public:
    Block(int id, int r, int c, int size);
    int randomStatus();
    QRect getRect(int startX, int startY);
    QColor getColor();
    int getX(){return _rc.x();}
    int getY(){return _rc.y();}
    int getId(){return _id;}

    void setZoning(GUI_zoning *z){_zoning = z;}
    GUI_zoning *getZoning();

    void getDisplay(QVector<QString> *vString);

    void setVisible(bool v){ _visable = v;}
    void setCanMove(bool cm){ _can_move = cm;}

    void drawButton(QPainter *painter);
    void drawSoltLeftTop(QPainter *painter);
    void drawSoltRightTop(QPainter *painter);
};

#endif // BLOCK_H
