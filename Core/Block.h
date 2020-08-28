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

    int pioneerId = 1;
    int armyId = 1;
    int playerId = 0;
    bool visible = false;

public:
    Block(int i, QPoint p);

    QColor getColor();
    QPoint getPosition() { return point; }
    int getZoningNumber() { return zoningNumber; }

    bool getPionner() { return bool(pioneerId); }
    bool getArmy() { return bool(armyId); }
    bool getPlayer() { return bool(playerId); }

    void setVisible(bool b) { visible = b; }

    QVector<ZoningSlot *> usingZoningSlotVector() { return zVector; }
};

#endif // BLOCK_H
