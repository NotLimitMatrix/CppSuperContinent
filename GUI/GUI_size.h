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

    Square *getWorldSquare();
    void setSquare(int w, int h){
        width = w;
        height = h;
    }

    int WORLD_SQUARE                = height;
    int MESSAGE_WIDTH               = width - height;
    int ZONING_SQUARE               = MESSAGE_WIDTH * 2 / 3;
    int PANEL_WIDTH                 = MESSAGE_WIDTH - ZONING_SQUARE;
    int MESSAGE_HEIGHT              = height - ZONING_SQUARE;
    int PANEL_ITEM_HEIGHT           = ZONING_SQUARE / 10;
    int PANEL_LABEL_WIDTH           = 40;
    int PANEL_POWER_WIDTH           = PANEL_WIDTH - PANEL_LABEL_WIDTH;
    int PANEL_RESOURCE_WIDTH        = PANEL_POWER_WIDTH / 2;
    int RESEARCH_PROCESS_T_WIDTH    = MESSAGE_WIDTH / 10;
    int RESEARCH_PROCESS_WIDTH      = MESSAGE_WIDTH - RESEARCH_PROCESS_T_WIDTH;
    int MESSAGE_LINE_NUMBER         = 20;
    int MESSAGE_LINE_HEIGHT         = MESSAGE_HEIGHT / MESSAGE_LINE_NUMBER;

    int WORLD_START_X = 0;
    int WORLD_START_Y = 0;
    int WORLD_END_X = WORLD_START_X + WORLD_SQUARE;
    int WORLD_END_Y = WORLD_START_Y + WORLD_SQUARE;

    int ZONING_START_X = WORLD_END_X + 1;
    int ZONING_START_Y = WORLD_START_Y;
    int ZONING_END_X = ZONING_START_X + ZONING_SQUARE;
    int ZONING_END_Y = ZONING_START_Y + ZONING_SQUARE;

    int worldBlockSize(int number);
    int zoningBlockSize(int number);
};

#endif // GUI_SIZE_H
