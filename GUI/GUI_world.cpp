#include "GUI_world.h"

GUI_world::GUI_world(int number, Square *square)
{
    _number = number;
    _sum_number = _number * _number;
    _square = square;

    _size = _square->width / _number;

    BlockVector.clear();

    int zoning_id = 0;
    int zoning_number = 0;
    for(int i=0; i<_sum_number; i++)
    {
        Block *bTemp = new Block(i, i / _number, i % _number, _size);
        BlockVector.push_back(bTemp);
        zoning_number = bTemp->getZoningNumber();
        bTemp->clearZoning();
        int power_zoning = zoning_number * zoning_number;

        for(int j=0; j<power_zoning; j++)
        {
            bTemp->insertZoning(new ZoningSlot(zoning_id, j / zoning_number, j % zoning_number, i));
            zoning_id++;
        }
    }
}

void GUI_world::draw(QPainter *painter)
{
    QRect rTemp;
    QString stringTemp;

    for(Block* bTemp : BlockVector)
    {
        painter->setBrush(bTemp->getColor());

        rTemp = bTemp->getRect(_square->x, _square->y);
        painter->drawRect(rTemp);
        bTemp->drawButton(painter);

        //stringTemp = QString("%3(%1,%2)").arg(bTemp->getX()).arg(bTemp->getY()).arg(bTemp->getId());
        //painter->drawText(rTemp, Qt::AlignCenter, stringTemp);
    }
}

bool GUI_world::inWorld(int x, int y)
{
    bool bx = (x >= _square->x && x < _square->x+_square->width);
    bool by = (y >= _square->y && y < _square->y+_square->height);
    return (bx && by);
}

int GUI_world::getIdWithPos(int x, int y)
{
    int ix = x / _size;
    int iy = y / _size;
    return iy * _number + ix;
}

Block* GUI_world::getBlockWithId(int id)
{
    for(Block *bTemp : BlockVector)
        if(bTemp->getId() == id)
            return bTemp;
    return nullptr;
}
