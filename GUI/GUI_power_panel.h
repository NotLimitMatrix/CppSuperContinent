#ifndef GUI_POWER_PANEL_H
#define GUI_POWER_PANEL_H

#include"Core.h"

class GUI_power_panel
{
    QString _title[3] = {"科研", "军事","民用"};
public:
    int research_points = 100;
    int military_power = 0;
    int civil_power = 0;
    QString _powers[3] = {"100", "0", "0"};

    void updatePowser();
    void draw(QPainter *painter);

    GUI_power_panel();

    QString displayNumber(int number);
};

#endif // GUI_POWER_PANEL_H
