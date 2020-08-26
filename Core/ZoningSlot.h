#ifndef ZONINGSLOT_H
#define ZONINGSLOT_H

#include <QColor>
#include <QPainter>
#include <QPoint>

class ZoningSlot
{
    int blockId;
    QPoint position;
    QColor color = Qt::white;

public:
    ZoningSlot(int b, QPoint p) : blockId(b), position(p) {}

    QPoint getPosition() { return position; }
};

#endif // ZONINGSLOT_H
