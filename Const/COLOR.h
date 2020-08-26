#ifndef COLOR_H
#define COLOR_H
#include <QColor>
const QColor BLACK = Qt::black;
const QColor WHITE = Qt::white;
const QColor DEAD_BLOCK = QColor(255, 105, 180);
const QColor BAD_BLOCK = QColor(255, 165, 0);
const QColor NORMAL_BLOCK = QColor(0, 255, 255);
const QColor GOOD_BLOCK = QColor(100, 149, 237);
const QColor IDEAL_BLOCK = QColor(0, 255, 127);
const QColor SCHEDULE_MILITARY = QColor(135, 206, 250);
const QColor SCHEDULE_CIVIL = QColor(244, 164, 96);
const QColor SCHEDULE_BEYOND = QColor(186, 85, 211);
const QColor BLOCK_NOT_CAN_MOVE = Qt::gray;
const QColor BLOCK_NOT_VISIBLE = WHITE;

const QColor BLOCK_STATUS[5] = {DEAD_BLOCK, BAD_BLOCK, NORMAL_BLOCK, GOOD_BLOCK, IDEAL_BLOCK};
#endif // COLOR_H
