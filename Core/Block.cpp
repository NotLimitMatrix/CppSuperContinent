#include "Block.h"

Block::Block(int i, QPoint p)
{
    id = i;
    point = p;
    color = BLOCK_STATUS[Methods::randomBlockStatus()];
    zoningNumber = BLOCK_ZONING[Methods::randomInt(3)];

    zVector.clear();
    for (int i = 0; i < zoningNumber; i++)
        for (int j = 0; j < zoningNumber; j++) {
            zVector.push_back(new ZoningSlot(id, QPoint(j, i)));
        }
}

QColor Block::getColor()
{
    if (visible)
        return color;
    else
        return Qt::gray;
}
