#ifndef BLOCK_H
#define BLOCK_H

#include"Core.h"

class Block
{
    int _id;
    QPoint _rc;

    int _status_id;
    QString _word;
    double _modifier;
    int _zoning_number;
    QColor _color;

public:
    Block(int id, int r, int c);
    int randomStatus();
    static Block newBlock(int id, int size);
    static Block newBlock(int r, int c, int size);
    QRect getRect(int startX, int startY, int size);
    QColor getColor(){return _color;}
    int getX(){return _rc.x();}
    int getY(){return _rc.y();}
    int getId(){return _id;}
};

#endif // BLOCK_H
