#include "GUI_zoning.h"

GUI_zoning::GUI_zoning(int number, int belong)
{
    _number = number;
    _sum_number = _number * _number;
    _size = ZONING_WIDTH / _number;
    _build_dx = _size / 4;
    _belong_id = belong;

    for(int i=0; i<_sum_number; i++)
        zVector.push_back(new ZSolt(i, i % _number, i / _number, _belong_id));
}

void GUI_zoning::draw(QPainter *painter)
{
    for(ZSolt *zTemp : zVector)
    {
        painter->setBrush(zTemp->getBackGroundColor());
        painter->drawRect(zTemp->getRect(ZONING_START_X, ZONING_START_Y, _size));
        painter->setBrush(zTemp->getBuildColor());

        painter->setPen(zTemp->getBuildColor());
        painter->drawRect(zTemp->getBuildRect(ZONING_START_X, ZONING_START_Y, _size, _build_dx));
        painter->setPen(BLACK);
    }
}

QRect ZSolt::getRect(int startX, int startY, int size)
{
    int x = startX + _rc.x() * size;
    int y = startY + _rc.y() * size;
    return QRect(x, y, size, size);
}

QRect ZSolt::getBuildRect(int startX, int startY, int size, int dx)
{
    int x = startX + _rc.x() * size + dx;
    int y = startY + _rc.y() * size + dx;
    return QRect(x, y, size - dx * 2, size - dx * 2);
}

void ZSolt::getDisplay(QVector<QString> *vString)
{
    vString->clear();

    vString->push_back(QString(" [区划] %1: (%2,%3)").arg(_id).arg(_rc.x()).arg(_rc.y()));
    vString->push_back(QString(" [所属地块] %1").arg(_belong_id));
}

bool GUI_zoning::inZoning(int x, int y)
{
    bool bx = (x >= ZONING_START_X && x < ZONING_END_X);
    bool by = (y >= ZONING_START_Y && y < ZONING_END_Y);
    return (bx && by);
}

int GUI_zoning::getIdWithPos(int x, int y)
{
    int ix = (x - ZONING_START_X) / _size;
    int iy = (y - ZONING_START_Y) / _size;
    return iy * _number + ix;
}

ZSolt *GUI_zoning::getSoltWithId(int id)
{
    for(ZSolt *zTemp : zVector)
        if(zTemp->getId() == id)
            return zTemp;
    return nullptr;
}
