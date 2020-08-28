#ifndef GUI_MENU_H
#define GUI_MENU_H

#include <QMenu>
#include <QMenuBar>
#include <QWidget>

class GUI_MENU
{
    QMenuBar *menuBar;

    QMenu *startGame = new QMenu("开始游戏");
    QMenu *importOutpot = new QMenu("网络连接");

public:
    GUI_MENU();
    GUI_MENU(QWidget *parent, int width, int height);
};

#endif // GUI_MENU_H
