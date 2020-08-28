#include "GUI_MENU.h"

GUI_MENU::GUI_MENU()
{
    
}

GUI_MENU::GUI_MENU(QWidget *parent, int width, int height)
{
    menuBar = new QMenuBar(parent);
    menuBar->setGeometry(0, 0, width, height);
    menuBar->addMenu(startGame);
    menuBar->addMenu(importOutpot);
}
