#include "GUI_resource_panel.h"

GUI_resource_panel::GUI_resource_panel()
{

}

void GUI_resource_panel::draw(QPainter *painter)
{
    updateStorageList();
    updateDailyList();

    for(int i=0; i<=4; i++)
    {
        QRect rTitle(RESOURCE_PANEL_START_X, RESOURCE_PANEL_START_Y + i * RESOURCE_PANEL_H_SIZE, 40, 20);
        painter->drawRect(rTitle);
        painter->drawText(rTitle, Qt::AlignCenter,_title[i]);

        QRect rStorage(RESOURCE_PANEL_START_X+40, RESOURCE_PANEL_START_Y + i * RESOURCE_PANEL_H_SIZE, 60,20);
        painter->drawRect(rStorage);
        painter->drawText(rStorage, Qt::AlignCenter, _storage[i]);

        QRect rDaily(RESOURCE_PANEL_START_X+100, RESOURCE_PANEL_START_Y + i * RESOURCE_PANEL_H_SIZE, 60,20);
        painter->drawRect(rDaily);
        painter->drawText(rDaily, Qt::AlignCenter, _daily[i]);
    }
}

void GUI_resource_panel::updateStorageList()
{
    _storage[0] = formatNumber(energy);
    _storage[1] = formatNumber(mineral);
    _storage[2] = formatNumber(food);
    _storage[3] = formatNumber(alloys);
    _storage[4] = formatNumber(consumer_goods);
}

void GUI_resource_panel::updateDailyList()
{
    _daily[0] = formatNumber(d_energy);
    _daily[1] = formatNumber(d_mineral);
    _daily[2] = formatNumber(d_food);
    _daily[3] = formatNumber(d_alloys);
    _daily[4] = formatNumber(d_consumer_goods);
}
