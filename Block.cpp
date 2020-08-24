#include "Block.h"

Block::Block(int id, int r, int c, int size)
{
    _id = id;
    _rc = QPoint(r,c);
    _status_id = randomStatus();

    _word = BLOCK_WORD[_status_id];
    _modifier = BLOCK_MODIFIER[_status_id];
    _color = BLOCK_STATUS[_status_id];

    _zoning_number = BLOCK_ZONING[QRandomGenerator::global()->bounded(3)];

    _size = size;

    int helf_size = _size / 2;
    int pos_x = _rc.x() * _size, pos_y = _rc.y() * _size;

    solt_left_button = QRect(WORLD_START_X + pos_x,
                              WORLD_START_Y + pos_y + helf_size,
                              helf_size, helf_size);
    solt_right_button = QRect(WORLD_START_X + pos_x + helf_size,
                              WORLD_START_Y + pos_y + helf_size,
                              helf_size, helf_size);
    solt_left_top = QRect(WORLD_START_X + pos_x,
                          WORLD_START_Y + pos_y,
                          helf_size, helf_size);
    solt_right_top = QRect(WORLD_START_X + pos_x + helf_size,
                           WORLD_START_Y + pos_y,
                           helf_size, helf_size);
}

int Block::randomStatus()
{
    int r = QRandomGenerator::global()->bounded(100);

    if(r >= 0 && r < GENERATOR_LENGTH[0])
        return 0;
    else if(r >= GENERATOR_LENGTH[0] && r < GENERATOR_LENGTH[1])
        return 1;
    else if(r >= GENERATOR_LENGTH[1] && r < GENERATOR_LENGTH[2])
        return 2;
    else if(r >= GENERATOR_LENGTH[2] && r < GENERATOR_LENGTH[3])
        return 3;
    else
        return 4;
}

QRect Block::getRect(int startX, int startY)
{
    int x = startX + _rc.x() * _size;
    int y = startY + _rc.y() * _size;
    return QRect(x, y, _size, _size);
}

QColor Block::getColor()
{
    if(!_visable)
        return BLOCK_NOT_VISIBLE;

    if(!_can_move)
        return BLOCK_NOT_CAN_MOVE;

    return _color;
}


//GUI_zoning *Block::getZoning()
//{
//    // 是否可见： 是，显示地块的区划gui；不是，则默认gui
//    if(_visable)
//        return _zoning;
//    else
//        return new GUI_zoning(ZONING_NUMBER, -1);
//}

void Block::getDisplay(QVector<QString> *vString)
{
    vString->push_back(QString(" [地块] %1: (%2,%3)").arg(_id).arg(_rc.x()).arg(_rc.y()));
    vString->push_back(QString(" [环境] %1: (%2%)").arg(_word).arg(_modifier));
    vString->push_back(QString(" [区划] %1").arg(_zoning_number * _zoning_number));
}

void Block::insertZoning(ZoningSlot *zslot)
{
    zVector.push_back(zslot);
}

void Block::copyZoning(QVector<ZoningSlot *> *recv)
{
    recv->clear();
    for(ZoningSlot *zTemp : zVector){
        recv->push_back(zTemp);
    }
}

void Block::drawButton(QPainter *painter)
{
    painter->drawText(solt_left_button, Qt::AlignCenter, QString::number(_id));
    if(_visable)
    {
        painter->drawText(solt_right_button, Qt::AlignCenter, QString::number(_zoning_number * _zoning_number));
    }
}
