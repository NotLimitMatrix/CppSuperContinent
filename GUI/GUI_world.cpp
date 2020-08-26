#include "GUI_WORLD.h"

GUI_WORLD::GUI_WORLD(QRect sqe, int number)
{
    square = sqe;
    blockNumber = number;

    bVector.clear();
    for (int i = 0; i < blockNumber; i++)
        for (int j = 0; j < blockNumber; j++) {
            bVector.push_back(new Block(i * number + j, QPoint(j, i)));
        }
}

void GUI_WORLD::draw(QPainter *painter)
{
    int size = square.width() / blockNumber;
    QPoint point;
    QRect rectTemp;

    painter->setPen(BLACK);
    for (Block *bTemp : bVector) {
        painter->setBrush(bTemp->getColor());
        point = bTemp->getPosition();
        rectTemp = QRect(square.x() + size * point.x(), square.y() + size * point.y(), size, size);
        painter->drawRect(rectTemp);
        painter->drawText(rectTemp, Qt::AlignCenter, QString("%1,%2").arg(point.x()).arg(point.y()));
    }
    painter->setBrush(WHITE);
}

bool GUI_WORLD::posIn(int x, int y)
{
    bool bx = (x > square.x()) && (x < square.x() + square.width());
    bool by = (y > square.y()) && (x < square.y() + square.height());
    return bx && by;
}

Block *GUI_WORLD::getBlockWithPosition(int x, int y)
{
    int size = square.width() / blockNumber;
    int r = x / size;
    int c = y / size;
    QPoint point;

    for (Block *bTemp : bVector) {
        point = bTemp->getPosition();
        if (point.x() == r && point.y() == c)
            return bTemp;
    }
    return nullptr;
}
