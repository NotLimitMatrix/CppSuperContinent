#include "GUI_zoning.h"

GUI_zoning::GUI_zoning(int number)
{
    _number = number;
    _sum_number = _number * _number;
    _size = ZONING_WIDTH / _number;

    for(int i=0; i<_sum_number; i++)
        zVector.push_back(new ZSolt(i, i % _number, i / _number));
}

void GUI_zoning::draw(QPainter *painter)
{
    for(ZSolt *zTemp : zVector)
    {
        painter->setBrush(zTemp->getColor());
        painter->drawRect(zTemp->getRect(ZONING_START_X, ZONING_START_Y, _size));
    }
}

QRect ZSolt::getRect(int startX, int startY, int size)
{
    int x = startX + _rc.x() * size;
    int y = startY + _rc.y() * size;
    return QRect(x, y, size, size);
}
