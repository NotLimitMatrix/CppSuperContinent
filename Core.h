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
#include<QMouseEvent>

class Square
{
public:
    int x;
    int y;
    int width;
    int height;
    Square(int _x, int _y, int _width, int _height):x(_x), y(_y), width(_width),height(_height){}
};

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
const QColor BLOCK_NOT_CAN_MOVE = Qt::gray;
const QColor BLOCK_NOT_VISIBLE  = WHITE;

const int TICK_FLOW             = 1;

const int GUI_WIDTH             = 1010;
const int GUI_HEIGHT            = 605;
const QString GUI_TITLE         = "Super Continent";

const int WORLD_WIDTH           = 600;
const int WORLD_HEIGHT          = 600;
const int WORLD_START_X         = 0;
const int WORLD_START_Y         = 0;
const int WORLD_END_X           = WORLD_WIDTH + WORLD_START_X;
const int WORLD_END_Y           = WORLD_HEIGHT + WORLD_START_Y;
const int WORLD_NUMBER          = 10;
const int WORLD_SQUARE_SIZE     = WORLD_WIDTH / WORLD_NUMBER;

const int ZONING_WIDTH          = 240;
const int ZONING_HEIGHT         = 240;
const int ZONING_START_X        = WORLD_END_X + 3;
const int ZONING_START_Y        = WORLD_START_Y;
const int ZONING_END_X          = ZONING_WIDTH + ZONING_START_X;
const int ZONING_END_Y          = ZONING_HEIGHT + ZONING_START_Y;
const int ZONING_NUMBER         = 1;
const int ZONING_SQUARE_SIZE    = ZONING_WIDTH / ZONING_NUMBER;
const int ZONING_BUILD_DX       = ZONING_SQUARE_SIZE / 4;

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
const int RESEARCH_END_X        = RESEARCH_T_START_X + RESEARCH_T_WIDTH_SIZE;
const int RESEARCH_MILITARY_Y   = POWER_PANEL_END_Y + RESEARCH_DX;
const int RESEARCH_MILITARY_T_Y = RESEARCH_MILITARY_Y;
const int RESEARCH_CIVIL_Y      = RESEARCH_MILITARY_Y + RESEARCH_HEIGHT_SIZE + RESEARCH_DX;
const int RESEARCH_CIVIL_T_Y    = RESEARCH_CIVIL_Y;
const int RESEARCH_BEYOND_Y     = RESEARCH_CIVIL_Y + RESEARCH_HEIGHT_SIZE + RESEARCH_DX;
const int RESEARCH_BEYOND_T_Y   = RESEARCH_BEYOND_Y;
const int RESEARCH_START_Y      = RESEARCH_MILITARY_Y;
const int RESEARCH_END_Y        = RESEARCH_BEYOND_Y + RESEARCH_HEIGHT_SIZE;

const int TEXT_START_X          = ZONING_START_X;
const int TEXT_START_Y          = ZONING_END_Y + 3;
const int TEXT_WIDTH            = 403;
const int TEXT_HEIGHT           = 360;
const int TEXT_END_X            = TEXT_START_X + TEXT_WIDTH;
const int TEXT_END_Y            = TEXT_START_Y + TEXT_HEIGHT;
const int TEXT_LINE_HEIGHT      = 20;
const int TEXT_LINE_NUMBER      = TEXT_HEIGHT / TEXT_LINE_HEIGHT;

const QColor BLOCK_STATUS[5]    = {DEAD_BLOCK, BAD_BLOCK, NORMAL_BLOCK, GOOD_BLOCK, IDEAL_BLOCK};
const QString BLOCK_WORD[5]     = {"死寂","恶劣","一般","理想","仙境"};
const int BLOCK_WEIGHT[5]       = {5, 23, 60, 9, 3}; // The sum is 100
const int GENERATOR_LENGTH[5]   = {BLOCK_WEIGHT[0],
                                  BLOCK_WEIGHT[0]+BLOCK_WEIGHT[1],
                                  BLOCK_WEIGHT[0]+BLOCK_WEIGHT[1]+BLOCK_WEIGHT[2],
                                  BLOCK_WEIGHT[0]+BLOCK_WEIGHT[1]+BLOCK_WEIGHT[2]+BLOCK_WEIGHT[3],
                                  100};
const int BLOCK_MODIFIER[5]     = {-50, -25, 0, 20, 55};
//const int BLOCK_PERCENT[5]      = {0, 25, 50, 75, 100};
const int BLOCK_ZONING[5]       = {4,5,6};

#endif // CORE_H
