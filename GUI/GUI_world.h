#ifndef GUI_WORLD_H
#define GUI_WORLD_H

#include <QPainter>
#include <QRect>

#include "Core/Block.h"

class GUI_WORLD
{
    QRect square;
    int blockNumber;
    int playerMaxNumber;

    QVector<Block *> bVector;

public:
    GUI_WORLD(QRect sqe, int number);
    void draw(QPainter *painter);
    void drawPlayer(QPainter *painter, int x, int y, int size);
    bool posIn(int x, int y);
    Block *getBlockWithPosition(int x, int y);
};

#endif // GUI_WORLD_H
