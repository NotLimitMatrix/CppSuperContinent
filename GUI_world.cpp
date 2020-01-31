#include "GUI_world.h"

GUI_world::GUI_world(int number)
{
    _number = number;
    _sum_number = _number * _number;
    _size = WORLD_WIDTH / _number;

    BlockVector.clear();

    for(int i=0; i<_sum_number; i++)
    {
        int r = i / _number;
        int c = i % _number;
        BlockVector.push_back(new Block(i, c, r));
    }
}

void GUI_world::draw(QPainter *painter)
{
    QRect rTemp;
    QString stringTemp;

    for(Block* bTemp : BlockVector)
    {
        painter->setBrush(bTemp->getColor());

        rTemp = bTemp->getRect(WORLD_START_X, WORLD_START_Y, _size);
        painter->drawRect(rTemp);

        //stringTemp = QString("%3(%1,%2)").arg(bTemp->getX()).arg(bTemp->getY()).arg(bTemp->getId());
        painter->drawText(rTemp, Qt::AlignCenter, stringTemp);
    }
}

bool GUI_world::inWorld(int x, int y)
{
    bool bx = (x >= WORLD_START_X && x < WORLD_END_X);
    bool by = (y >= WORLD_START_Y && y < WORLD_END_Y);
    return (bx && by);
}

int GUI_world::getIdWithPos(int x, int y)
{
    int ix = x / _size;
    int iy = y / _size;
    return iy * _number + ix;
}

Block GUI_world::getBlockWithId(int id)
{
    for(Block *bTemp : BlockVector)
        if(bTemp->getId() == id)
            return *bTemp;
    return Block(0,0,0);
}

GUI_zoning *GUI_world::getZoningWithPos(int x, int y)
{
    return getBlockWithId(getIdWithPos(x,y)).getZoning();
}
