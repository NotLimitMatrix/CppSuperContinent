#ifndef PLAYER_H
#define PLAYER_H

#include "Block.h"
#include "Core/BLOCK_STATIC.h"
#include <QString>
#include <QVector>

class Player
{
    QString playerNickname;
    QVector<int> territoryBlockVector;
    QVector<int> discoveryBlockVector;

public:
    Player(QString name, int number);
};

#endif // PLAYER_H
