#include "Player.h"

Player::Player(QString name, int number)
{
    playerNickname = name;
    int blockId = Methods::randomInt(number) * number + Methods::randomInt(number);
}
