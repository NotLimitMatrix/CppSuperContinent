#ifndef GUI_WORLD_H
#define GUI_WORLD_H

#include"Core.h"
#include"Block.h"

class GUI_world
{
    int _number;
    int _sum_number;
    int _size;

    QVector<Block*> BlockVector;

public:
    GUI_world(int number);
    void draw(QPainter *painter);

    bool inWorld(int x, int y);
    int getIdWithPos(int x, int y);
    Block getBlockWithId(int id);
    GUI_zoning *getZoningWithPos(int x, int y);
};

#endif // GUI_WORLD_H
