#include "GUI_world.h"

GUI_world::GUI_world(int number)
{
    _number = number;
    _sum_number = _number * _number;

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

        rTemp = bTemp->getRect(WORLD_START_X, WORLD_START_Y, WORLD_SQUARE_SIZE);
        painter->drawRect(rTemp);

        stringTemp = QString("%3(%1,%2)").arg(bTemp->getX()).arg(bTemp->getY()).arg(bTemp->getId());
        painter->drawText(rTemp, Qt::AlignCenter, stringTemp);
    }
}
