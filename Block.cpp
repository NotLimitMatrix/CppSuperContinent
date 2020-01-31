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
}

int Block::randomStatus()
{
    int r = QRandomGenerator::global()->bounded(100);
    if(r >= 0 && r < BLOCK_WEIGHT[0])
        return 0;
    else if(r >= BLOCK_WEIGHT[0] && r < BLOCK_WEIGHT[1])
        return 1;
    else if(r >= BLOCK_WEIGHT[1] && r < BLOCK_WEIGHT[2])
        return 2;
    else if(r >= BLOCK_WEIGHT[2] && r < BLOCK_WEIGHT[3])
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
