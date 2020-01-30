#ifndef CORE_H
#define CORE_H

#include<QString>
#include<QPainter>
#include<QPoint>
#include<QRect>
#include<QMainWindow>
#include<QDebug>

enum posIn{inWorld, inZoning, inWait, inResearch};

const int TIME_FLOW             = 1;

const int GUI_WIDTH             = 1008;
const int GUI_HEIGHT            = 605;
const QString GUI_TITLE         = "Super Continent";

const int WORLD_WIDTH           = 600;
const int WORLD_HEIGHT          = 600;
const int WORLD_START_X         = 1;
const int WORLD_START_Y         = 1;
const int WORLD_END_X           = WORLD_WIDTH + WORLD_START_X;
const int WORLD_END_Y           = WORLD_HEIGHT + WORLD_START_Y;
const int WORLD_NUMBER          = 20;
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

const int RESOURCE_PANEL_WIDTH  = 160;
const int RESOURCE_PANEL_HEIGHT = 100;
const int RESOURCE_PANEL_START_X= ZONING_END_X+3;
const int RESOURCE_PANEL_START_Y= ZONING_START_Y;
const int RESOURCE_PANEL_END_X  = RESOURCE_PANEL_START_X + RESOURCE_PANEL_WIDTH;
const int RESOURCE_PANEL_END_Y  = RESOURCE_PANEL_START_Y + RESOURCE_PANEL_HEIGHT;
const int RESOURCE_PANEL_H_SIZE = 20;

const int POWER_PANEL_WIDTH  = 160;
const int POWER_PANEL_HEIGHT = 60;
const int POWER_PANEL_START_X= RESOURCE_PANEL_START_X;
const int POWER_PANEL_START_Y= RESOURCE_PANEL_END_Y;
const int POWER_PANEL_END_X  = POWER_PANEL_START_X + POWER_PANEL_WIDTH;
const int POWER_PANEL_END_Y  = POWER_PANEL_START_Y + POWER_PANEL_HEIGHT;
const int POWER_PANEL_H_SIZE = 20;

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

#endif // CORE_H
