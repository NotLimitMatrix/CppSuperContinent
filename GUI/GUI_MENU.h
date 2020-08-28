#ifndef GUI_MENU_H
#define GUI_MENU_H

#include "Dialog/NewGameDialog.h"
#include <QMenu>
#include <QMenuBar>
#include <QWidget>

class GUI_MENU
{
    QMenuBar *menuBar;
    QWidget *widgetParent;

public:
    GUI_MENU();
    GUI_MENU(QWidget *parent, int width, int height);

    void startGameMenu();

    void configNetWorkGame();

    NewGameDialog *newGameDialog = new NewGameDialog();
};

#endif // GUI_MENU_H
