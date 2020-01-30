#ifndef GUI_ZONING_H
#define GUI_ZONING_H

#include"Core.h"

class GUI_zoning
{
    int _number;
public:
    GUI_zoning(int number);
    void draw(QPainter *painter);
};

#endif // GUI_ZONING_H
