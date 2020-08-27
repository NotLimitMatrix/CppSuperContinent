#ifndef STATIC_H
#define STATIC_H
#include <QPainter>
#include <QRandomGenerator>
#include <QRect>
#include <QString>
const int BLOCK_WEIGHT[5] = {5, 23, 60, 9, 3};
const int GENERATOR_LENGTH_1 = BLOCK_WEIGHT[0];
const int GENERATOR_LENGTH_2 = GENERATOR_LENGTH_1 + BLOCK_WEIGHT[1];
const int GENERATOR_LENGTH_3 = GENERATOR_LENGTH_2 + BLOCK_WEIGHT[2];
const int GENERATOR_LENGTH_4 = GENERATOR_LENGTH_3 + BLOCK_WEIGHT[3];

const QString BLOCK_WORD[5] = {"死寂", "恶劣", "一般", "理想", "仙境"};
const int BLOCK_MODIFIER[5] = {-50, -25, 0, 20, 55};
const int BLOCK_PERCENT[5] = {0, 25, 50, 75, 100};
const int BLOCK_ZONING[5] = {4, 5, 6};

const QString PANEL_TITLE[7] = {"能量", "矿物", "食物", "物资", "合金", "科研", "军事"};

const int TICK_FLOW = 500; // 毫秒

class Methods
{
public:
    static int randomInt(int n) { return QRandomGenerator::global()->bounded(n); }
    static int randomBlockStatus()
    {
        int r = Methods::randomInt(100);
        if (r >= 0 && r < GENERATOR_LENGTH_1)
            return 0;
        else if (r >= GENERATOR_LENGTH_1 && r < GENERATOR_LENGTH_2)
            return 1;
        else if (r >= GENERATOR_LENGTH_2 && r < GENERATOR_LENGTH_3)
            return 2;
        else if (r >= GENERATOR_LENGTH_3 && r < GENERATOR_LENGTH_4)
            return 3;
        else
            return 4;
    }
    static void drawPanelText(QPainter *painter, QRect rect, QString s)
    {
        painter->drawRect(rect);
        painter->drawText(rect, Qt::AlignCenter, s);
    }
    static QString dateFromTimeNumber(int number)
    {
        int all_months = number / 30;
        return QString("%1-%2-%3").arg(all_months / 12 + 3000).arg(all_months % 12).arg(number % 30);
    }
};

#endif // STATIC_H
