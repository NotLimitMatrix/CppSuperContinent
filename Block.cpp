#include "Block.h"

Block::Block(int id, int r, int c)
{
    _id = id;
    _rc = QPoint(r,c);
    _status_id = randomStatus();

    _word = BLOCK_WORD[_status_id];
    _modifier = BLOCK_MODIFIER[_status_id];
    _color = BLOCK_STATUS[_status_id];
    _zoning_number = BLOCK_ZONING[QRandomGenerator::global()->bounded(3)];

    setZoning(new GUI_zoning(_zoning_number, _id));
}

int Block::randomStatus()
{
    int r = QRandomGenerator::global()->bounded(100);

    if(r >= 0 && r < W1)
        return 0;
    else if(r >= W1 && r < W2)
        return 1;
    else if(r >= W2 && r < W3)
        return 2;
    else if(r >= W3 && r < W4)
        return 3;
    else
        return 4;
}

Block Block::newBlock(int id, int size)
{
    int r = id / size;
    int c = id % size;
    return Block(id, r, c);
}

Block Block::newBlock(int r, int c, int size)
{
    int id = r * size + c;
    return Block(id, r, c);
}

QRect Block::getRect(int startX, int startY, int size)
{
    int x = startX + _rc.x() * size;
    int y = startY + _rc.y() * size;
    return QRect(x, y, size, size);
}

QColor Block::getColor()
{
    if(!_visable)
        return BLOCK_NOT_VISIBLE;

    if(!_can_move)
        return BLOCK_NOT_CAN_MOVE;

    return _color;
}

GUI_zoning *Block::getZoning()
{
    // 是否可见： 是，显示地块的区划gui；不是，则默认gui
    if(_visable)
        return _zoning;
    else
        return new GUI_zoning(ZONING_NUMBER, -1);
}

void Block::getDisplay(QVector<QString> *vString)
{
    vString->clear();

    vString->push_back(QString(" [地块] %1: (%2,%3)").arg(_id).arg(_rc.x()).arg(_rc.y()));
    vString->push_back(QString(" [环境] %1: (%2%)").arg(_word).arg(_modifier));
    vString->push_back(QString(" [区划] %1").arg(_zoning_number * _zoning_number));
}
