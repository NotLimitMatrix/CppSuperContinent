#include "GUI_MESSAGE.h"

GUI_MESSAGE::GUI_MESSAGE(QRect s)
{
    square = s;

    singleHeight = square.height() / 10;
}

void GUI_MESSAGE::draw(QPainter *painter) {}
