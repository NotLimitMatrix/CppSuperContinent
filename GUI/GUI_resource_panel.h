#ifndef GUI_RESOURCE_PANEL_H
#define GUI_RESOURCE_PANEL_H

#include"Core.h"

class GUI_resource_panel
{
    QString _title[5] = {"能量","矿物","食物","合金","物资"};
public:
    int energy = 0;
    int mineral = 0;
    int food = 0;
    int alloys = 0;
    int consumer_goods = 0;
    QString _storage[5] = {"0","0","0","0","0"};

    int d_energy = 0;
    int d_mineral = 0;
    int d_food = 0;
    int d_alloys = 0;
    int d_consumer_goods = 0;
    QString _daily[5] = {"+0","+0","+0","+0","+0"};

    GUI_resource_panel();
    void draw(QPainter *painter);

    void updateStorageList();
    void updateDailyList();

};

#endif // GUI_RESOURCE_PANEL_H
