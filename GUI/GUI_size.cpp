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

Square *GUI_size::getZoningSquare()
{
    int square = (width - height) * 2 / 3;
    return new Square(height, 0, square, square);
}
