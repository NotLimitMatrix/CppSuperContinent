#ifndef GUI_WORLD_H
#define GUI_WORLD_H

#include"Core.h"

class GUI_world
{
    int _number;

public:
    GUI_world(int number);
    void draw(QPainter *painter);
};

#endif // GUI_WORLD_H
