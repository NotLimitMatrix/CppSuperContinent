#ifndef ZONGINGSOLT_H
#define ZONGINGSOLT_H

#include"Core.h"

class ZongingSolt
{
    int _id;
    QPoint _rc;
    QColor _color;

public:
    ZongingSolt(int id, int r, int c);
    QRect getRect(int startX, int startY, int size);
};

#endif // ZONGINGSOLT_H
