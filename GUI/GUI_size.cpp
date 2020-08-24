#include "GUI_size.h"

#include<QScreen>
#include<QGuiApplication>

GUI_size::GUI_size()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect display = screen->availableGeometry();

    width = display.width() - dx;
    height = display.height() - dx;
}

Square *GUI_size::getWorldSquare()
{
    return new Square(0, 0, height, height);
}

int GUI_size::worldBlockSize(int number)
{
    return WORLD_SQUARE / number;
}

int GUI_size::zoningBlockSize(int number)
{
    return ZONING_SQUARE / number;
}
