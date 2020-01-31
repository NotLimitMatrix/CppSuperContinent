#ifndef BLOCK_H
#define BLOCK_H

#include"Core.h"
#include"GUI_zoning.h"

class Block
{
    int _id;
    QPoint _rc;

    int _status_id;
    QString _word;
    double _modifier;
    int _zoning_number;
    QColor _color;

    GUI_zoning *_zoning;

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

    void setZoning(GUI_zoning *z){_zoning = z;}
    GUI_zoning *getZoning(){return _zoning;}

    void getDisplay(QVector<QString> *vString);

};

#endif // BLOCK_H
