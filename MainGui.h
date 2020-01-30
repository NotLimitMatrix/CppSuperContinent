#ifndef MAINGUI_H
#define MAINGUI_H

#include"Core.h"

#include"GUI_world.h"
#include"GUI_zoning.h"
#include"GUI_select.h"
#include"GUI_resource_panel.h"

class MainGui : public QMainWindow
{
    Q_OBJECT

    int _world_number = WORLD_NUMBER;
    GUI_world *_world = new GUI_world(_world_number);
    int _zoning_number = ZONING_NUMBER;
    GUI_zoning *_zoning = new GUI_zoning(_zoning_number);
    GUI_select *_wait_select = new GUI_select;
    GUI_resource_panel *_resource_panel = new GUI_resource_panel;

public:
    MainGui(QWidget *parent = nullptr);
    ~MainGui();

    void paintEvent(QPaintEvent *event);
};
#endif // MAINGUI_H