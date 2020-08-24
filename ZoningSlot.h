#ifndef ZONINGSLOT_H
#define ZONINGSLOT_H
#include"Core.h"

class ZoningSlot
{

    int _id;
    QPoint _rc;
    int _build_id = -1;

    int _block_id;
    QColor _background = WHITE;
    QColor _build_color = BLACK;

public:
    ZoningSlot(int id, int r, int c, int block){
        _id = id;
        _rc = QPoint(r, c);
        _block_id = block;
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

    void getDisplay(QVector<QString> *vString);
    QRect getRect(int startX, int startY, int size);
};

#endif // ZONINGSLOT_H
