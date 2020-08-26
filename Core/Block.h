#ifndef BLOCK_H
#define BLOCK_H

#include <QColor>
#include <QPoint>
#include <QVector>

#include "Const/COLOR.h"
#include "Const/STATIC.h"
#include "ZoningSlot.h"

class Block
{
    int id;
    QPoint point;
    QColor color = Qt::white;

    int zoningNumber;
    QVector<ZoningSlot *> zVector;

public:
    Block(int i, QPoint p);

    QColor getColor() { return color; }
    QPoint getPosition() { return point; }
    int getZoningNumber() { return zoningNumber; }
    QVector<ZoningSlot *> usingZoningSlotVector() { return zVector; }
};

#endif // BLOCK_H
