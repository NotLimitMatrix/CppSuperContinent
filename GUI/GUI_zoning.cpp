#include "GUI_zoning.h"

GUI_zoning::GUI_zoning(int number, int belong, Square *square)
{
    _number = number;
    _square = square;
    _build_dx = _size / 4;
    _belong_id = belong;

    zVector.clear();
}

void GUI_zoning::draw(QPainter *painter)
{
    if(zVector.empty())
    {
        painter->setBrush(WHITE);
        painter->setPen(BLACK);
        painter->drawRect(QRect(_square->x, _square->y, _square->width, _square->height));
    }
    else
    {
        for(ZoningSlot *zTemp : zVector)
        {
            painter->setBrush(zTemp->getBackGroundColor());
            painter->drawRect(zTemp->getRect(_square->x, _square->y, 10));
    //        painter->setBrush(zTemp->getBuildColor());

    //        painter->setPen(zTemp->getBuildColor());
    //        painter->drawRect(zTemp->getBuildRect(_square->x, _square->y, _size, _build_dx));
            painter->setPen(BLACK);
        }
    }
}


bool GUI_zoning::inZoning(int x, int y)
{
    bool bx = (x >= _square->x && x < _square->x+_square->width);
    bool by = (y >= _square->y && y < _square->y+_square->height);
    return (bx && by);
}

int GUI_zoning::getIdWithPos(int x, int y)
{
    int ix = (x - _square->x) / _size;
    int iy = (y - _square->y) / _size;
    return iy * _number + ix;
}

ZoningSlot *GUI_zoning::getSoltWithId(int id)
{
    for(ZoningSlot *zTemp : zVector)
        if(zTemp->getId() == id)
            return zTemp;
    return nullptr;
}
