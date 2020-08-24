#include "GUI_size.h"

GUI_size::GUI_size(int windowWidth, int windowHeight)
{
    width = windowWidth;
    height = windowHeight;
}

int GUI_size::worldBlockSize(int number)
{
    return WORLD_SQUARE / number;
}

int GUI_size::zoningBlockSize(int number)
{
    return ZONING_SQUARE / number;
}
