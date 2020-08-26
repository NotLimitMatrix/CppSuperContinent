#ifndef GUI_WORLD_H
#define GUI_WORLD_H

#include <QPainter>
#include <QRect>

#include "Core/Block.h"

class GUI_WORLD
{
    QRect square;
    int blockNumber;

    QVector<Block *> bVector;

public:
    GUI_WORLD(QRect sqe, int number);
    void draw(QPainter *painter);
    bool posIn(int x, int y);
    Block *getBlockWithPosition(int x, int y);
};

#endif // GUI_WORLD_H
