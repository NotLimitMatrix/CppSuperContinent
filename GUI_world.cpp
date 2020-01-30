#include "GUI_world.h"

GUI_world::GUI_world(int number)
{
    _number = number;
}

void GUI_world::draw(QPainter *painter)
{
    for(int i=0; i<=_number; i++)
    {
        painter->drawLine(WORLD_START_X+i*WORLD_SQUARE_SIZE, WORLD_START_Y,
                          WORLD_START_X+i*WORLD_SQUARE_SIZE, WORLD_END_Y);
        painter->drawLine(WORLD_START_X, WORLD_START_Y+i*WORLD_SQUARE_SIZE,
                          WORLD_END_Y, WORLD_START_Y+i*WORLD_SQUARE_SIZE);
    }
}
