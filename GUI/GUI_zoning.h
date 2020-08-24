#ifndef GUI_ZONING_H
#define GUI_ZONING_H

#include"Core.h"
#include"ZoningSlot.h"

class GUI_zoning
{
    int _number;
    int _sum_number;
    int _size;
    int _build_dx;
    Square *_square;
    int _belong_id;

public:
    QVector<ZoningSlot*> zVector;

    GUI_zoning(int number, int belong, Square *square);
    void draw(QPainter *painter);
    int getSize(){return _size;}

    bool inZoning(int x, int y);
    int getIdWithPos(int x, int y);
    ZoningSlot *getSoltWithId(int id);

};

#endif // GUI_ZONING_H
