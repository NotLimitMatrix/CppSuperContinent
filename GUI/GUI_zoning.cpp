#include "GUI_ZONING.h"

GUI_ZONING::GUI_ZONING(QRect s, Block *b)
{
    square = s;
    block = b;
}

void GUI_ZONING::draw(QPainter *painter)
{
    if (block != nullptr) {
        int zoningSlotNumber = block->getZoningNumber();
        int size = square.width() / zoningSlotNumber;
        QPoint point;

        painter->setPen(BLACK);
        for (ZoningSlot *zTemp : block->usingZoningSlotVector()) {
            painter->setBrush(WHITE);
            point = zTemp->getPosition();
            painter->drawRect(
                QRect(square.x() + size * point.x(), square.y() + size * point.y(), size, size));
        }
        painter->setBrush(WHITE);
    } else {
        painter->setPen(BLACK);
        painter->drawRect(QRect(square.x(), square.y(), square.width(), square.height()));
        painter->setBrush(WHITE);
    }
}

bool GUI_ZONING::posIn(int x, int y)
{
    bool bx = (x > square.x()) && (x < square.x() + square.width());
    bool by = (y > square.y()) && (x < square.y() + square.height());
    return bx && by;
}
