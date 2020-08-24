#ifndef GUI_SIZE_H
#define GUI_SIZE_H

#include"Core.h"

class GUI_size
{
    int width;
    int height;
    int dx = 30;
public:
    GUI_size();

    void setSquare(int w, int h){
        width = w;
        height = h;
    }

    Square *getWorldSquare();
    Square *getZoningSquare();
};

#endif // GUI_SIZE_H
