#ifndef SIZEMANAGER_H
#define SIZEMANAGER_H

#include<QRect>

class SizeManager
{
    int width;
    int height;
    int dx = 30;

    int panel_width;
    int zoning_square;

public:
    SizeManager();

    int getWidth() { return width; }
    int getHeight() { return height; }
    int getDX() { return dx; }

    QRect getWorldSquare();
    QRect getZoningSquare();
    QRect getPanelSquare();
    QRect getMessageSquare();
};

#endif // SIZEMANAGER_H
