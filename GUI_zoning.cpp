#include "GUI_zoning.h"

GUI_zoning::GUI_zoning(int number)
{
    _number = number;
    _sum_number = _number * _number;
    _size = ZONING_WIDTH / _number;
}

void GUI_zoning::draw(QPainter *painter)
{

    for(int i=0; i<= _number; i++)
    {
        painter->drawLine(ZONING_START_X+i*ZONING_SQUARE_SIZE, ZONING_START_Y,
                          ZONING_START_X+i*ZONING_SQUARE_SIZE, ZONING_END_Y);
        painter->drawLine(ZONING_START_X, ZONING_START_Y+i*ZONING_SQUARE_SIZE,
                          ZONING_END_X, ZONING_START_Y+i*ZONING_SQUARE_SIZE);
    }
}

QRect ZSolt::getRect(int startX, int startY, int size)
{
    int x = startX + _rc.x() * size;
    int y = startY + _rc.y() * size;
    return QRect(x, y, size, size);
}
