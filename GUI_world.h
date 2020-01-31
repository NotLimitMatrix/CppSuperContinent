#ifndef GUI_WORLD_H
#define GUI_WORLD_H

#include"Core.h"
#include"Block.h"

class GUI_world
{
    int _number;
    QVector<Block> BlockVector;

public:
    GUI_world(int number);
    void draw(QPainter *painter);
};

#endif // GUI_WORLD_H
