#include"ZoningSlot.h"

void ZoningSlot::getDisplay(QVector<QString> *vString)
{
    vString->push_back(QString(" [区划] %1").arg(_id));
    vString->push_back(QString(" [所属地块] %1").arg(_block_id));
}

QRect ZoningSlot::getRect(int startX, int startY, int size)
{
    int x = startX + _rc.x() * size;
    int y = startY + _rc.y() * size;
    return QRect(x, y, size, size);
}
