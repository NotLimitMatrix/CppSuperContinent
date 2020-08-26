#ifndef GUI_ZONING_H
#define GUI_ZONING_H
#include <Core/Block.h>
#include <QRect>
#include <QString>

class GUI_ZONING
{
    QRect square;
    Block *block;

public:
    GUI_ZONING(QRect s, Block *b);
    void setBlock(Block *b) { block = b; }
    void draw(QPainter *painter);
    bool posIn(int x, int y);
};

#endif // GUI_ZONING_H
