#include "ZongingSolt.h"

ZongingSolt::ZongingSolt(int id, int r, int c)
{
    _id = id;
    _rc = QPoint(r,c);
    _color = WHITE;
}

QRect ZongingSolt::getRect(int startX, int startY, int size)
{
    int x = startX + _rc.x() * size;
    int y = startY + _rc.y() * size;
    return QRect(x, y, size, size);
}
