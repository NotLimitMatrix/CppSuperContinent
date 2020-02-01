#ifndef MAINGUI_H
#define MAINGUI_H

#include"Core.h"

#include"GUI_world.h"
#include"GUI_zoning.h"
#include"GUI_select.h"
#include"GUI_resource_panel.h"
#include"GUI_power_panel.h"
#include"GUI_research_panel.h"
#include"GUI_text.h"

#include"Block.h"

class MainGui : public QMainWindow
{
    Q_OBJECT

    int _world_number = WORLD_NUMBER;
    GUI_world *_world = new GUI_world(_world_number);
    int _zoning_number = ZONING_NUMBER;
    GUI_zoning *_zoning = new GUI_zoning(_zoning_number, -1);
    GUI_select *_wait_select = new GUI_select;
    GUI_resource_panel *_resource_panel = new GUI_resource_panel;
    GUI_power_panel *_power_panel = new GUI_power_panel;
    GUI_research_panel *_research_panel = new GUI_research_panel;
    GUI_text *_text_browser = new GUI_text;

    QVector<QString> _displayText;

public:
    MainGui(QWidget *parent = nullptr);
    ~MainGui();

    void setZoning(GUI_zoning *z){_zoning = z;}

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

    void display(int px, int py);
};
#endif // MAINGUI_H
