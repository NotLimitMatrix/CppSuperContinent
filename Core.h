#ifndef CORE_H
#define CORE_H

#include<QString>
#include<QPainter>
#include<QPoint>
#include<QRect>
#include<QMainWindow>
#include<QDebug>
#include<QVector>
#include<QColor>
#include<QPen>
#include<QRandomGenerator>

static QString displayNumber(int number)
{
    if(number > 100000000)
        return "1G";

    if(number < 0)
        return "-"+displayNumber(-number);

    if(number<1000)
        return QString::number(number);
    else if(number > 1000 && number < 1000000)
        return QString::number(number/1000) + "K";
    else if(number > 1000000 && number < 1000000000)
        return QString::number(number/1000000) + "M";
    else
        return "1G";
}

enum posIn{inWorld, inZoning, inWait, inResearch};

const QColor BLACK              = Qt::black;
const QColor WHITE              = Qt::white;
const QColor DEAD_BLOCK         = QColor(255, 105, 180);
const QColor BAD_BLOCK          = QColor(255, 165, 0);
const QColor NORMAL_BLOCK       = QColor(0, 255, 255);
const QColor GOOD_BLOCK         = QColor(100, 149, 237);
const QColor IDEAL_BLOCK        = QColor(0, 255, 127);
const QColor SCHEDULE_MILITARY  = QColor(135,206,250);
const QColor SCHEDULE_CIVIL     = QColor(244,164,96);
const QColor SCHEDULE_BEYOND    = QColor(186,85,211);

const int TIME_FLOW             = 1;

const int GUI_WIDTH             = 1010;
const int GUI_HEIGHT            = 605;
const QString GUI_TITLE         = "Super Continent";

const int WORLD_WIDTH           = 600;
const int WORLD_HEIGHT          = 600;
const int WORLD_START_X         = 1;
const int WORLD_START_Y         = 1;
const int WORLD_END_X           = WORLD_WIDTH + WORLD_START_X;
const int WORLD_END_Y           = WORLD_HEIGHT + WORLD_START_Y;
const int WORLD_NUMBER          = 10;
const int WORLD_SQUARE_SIZE     = WORLD_WIDTH / WORLD_NUMBER;

const int ZONING_WIDTH          = 240;
const int ZONING_HEIGHT         = 240;
const int ZONING_START_X        = WORLD_END_X + 3;
const int ZONING_START_Y        = WORLD_START_X;
const int ZONING_END_X          = ZONING_WIDTH + ZONING_START_X;
const int ZONING_END_Y          = ZONING_HEIGHT + ZONING_START_Y;
const int ZONING_NUMBER         = 5;
const int ZONING_SQUARE_SIZE    = ZONING_WIDTH / ZONING_NUMBER;

const int WAIT_SELECT_WIDTH     = 240;
const int WAIT_SELECT_HEIGHT    = 360;
const int WAIT_SELECT_START_X   = ZONING_START_X;
const int WAIT_SELECT_START_Y   = ZONING_END_Y + 3;
const int WAIT_LINE_NUMBER      = 20;
const int WAIT_LINE_HEIGHT      = WAIT_SELECT_HEIGHT / WAIT_LINE_NUMBER;
const int WAIT_OPTION_LINE_N    = 4;
const int WAIT_OPTION_NUMBER    = WAIT_LINE_NUMBER / WAIT_OPTION_LINE_N;
const int WAIT_OPTION_HEIGHT    = WAIT_OPTION_LINE_N * WAIT_LINE_HEIGHT;

const int RESOURCE_PANEL_WIDTH  = 160;
const int RESOURCE_PANEL_HEIGHT = 100;
const int RESOURCE_PANEL_START_X= ZONING_END_X+3;
const int RESOURCE_PANEL_START_Y= ZONING_START_Y;
const int RESOURCE_PANEL_END_X  = RESOURCE_PANEL_START_X + RESOURCE_PANEL_WIDTH;
const int RESOURCE_PANEL_END_Y  = RESOURCE_PANEL_START_Y + RESOURCE_PANEL_HEIGHT;
const int RESOURCE_PANEL_H_SIZE = 20;

const int POWER_PANEL_WIDTH     = 160;
const int POWER_PANEL_HEIGHT    = 60;
const int POWER_PANEL_START_X   = RESOURCE_PANEL_START_X;
const int POWER_PANEL_START_Y   = RESOURCE_PANEL_END_Y;
const int POWER_PANEL_END_X     = POWER_PANEL_START_X + POWER_PANEL_WIDTH;
const int POWER_PANEL_END_Y     = POWER_PANEL_START_Y + POWER_PANEL_HEIGHT;
const int POWER_PANEL_H_SIZE    = 20;

const int RESEARCH_HEIGHT_SIZE  = 20;
const int RESEARCH_WIDTH_SIZE   = 100;
const int RESEARCH_T_WIDTH_SIZE = 53;
const int RESEARCH_DX           = 6;
const int RESEARCH_T_HEIGHT_SIZE= RESEARCH_HEIGHT_SIZE;
const int RESEARCH_START_X      = POWER_PANEL_START_X;
const int RESEARCH_T_START_X    = RESEARCH_START_X + RESEARCH_WIDTH_SIZE + RESEARCH_DX;
const int RESEARCH_MILITARY_Y   = POWER_PANEL_END_Y + RESEARCH_DX;
const int RESEARCH_MILITARY_T_Y = RESEARCH_MILITARY_Y;
const int RESEARCH_CIVIL_Y      = RESEARCH_MILITARY_Y + RESEARCH_HEIGHT_SIZE + RESEARCH_DX;
const int RESEARCH_CIVIL_T_Y    = RESEARCH_CIVIL_Y;
const int RESEARCH_BEYOND_Y     = RESEARCH_CIVIL_Y + RESEARCH_HEIGHT_SIZE + RESEARCH_DX;
const int RESEARCH_BEYOND_T_Y   = RESEARCH_BEYOND_Y;

const int TEXT_START_X          = RESEARCH_START_X;
const int TEXT_START_Y          = WAIT_SELECT_START_Y;
const int TEXT_WIDTH            = POWER_PANEL_WIDTH;
const int TEXT_HEIGHT           = WAIT_SELECT_HEIGHT;
const int TEXT_LINE_HEIGHT      = 20;
const int TEXT_LINE_NUMBER      = TEXT_HEIGHT / TEXT_LINE_HEIGHT;

const QColor BLOCK_STATUS[5]    = {DEAD_BLOCK, BAD_BLOCK, NORMAL_BLOCK, GOOD_BLOCK, IDEAL_BLOCK};
const QString BLOCK_WORD[5]     = {"死寂","恶劣","一般","优秀","理想"};
const int BLOCK_WEIGHT[5]       = {5, 23, 60, 9, 3};
const int BLOCK_MODIFIER[5]     = {-50, -25, 0, 25, 50};
//const int BLOCK_PERCENT[5]      = {0, 25, 50, 75, 100};
const int BLOCK_ZONING[5]       = {4,5,6};

#endif // CORE_H
