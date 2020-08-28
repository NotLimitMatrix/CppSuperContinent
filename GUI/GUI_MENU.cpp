#include "GUI_MENU.h"

GUI_MENU::GUI_MENU()
{
    
}

GUI_MENU::GUI_MENU(QWidget *parent, int width, int height)
{
    menuBar = new QMenuBar(parent);
    menuBar->setGeometry(0, 0, width, height);
    widgetParent = parent;

    startGameMenu();
}

void GUI_MENU::startGameMenu()
{
    QMenu *startGame = new QMenu("开始游戏");

    QAction *createConnection = new QAction("网络连接", widgetParent);
    startGame->addAction(createConnection);
    //QObject::connect(createConnection, SIGNAL(triggered()), newGameDialog, SLOT(show()));
    QObject::connect(createConnection, &QAction::triggered, newGameDialog, &QWidget::show);

    //    QAction *singleGame = new QAction("单机游戏", parent);
    //    startGame->addAction(singleGame);

    menuBar->addMenu(startGame);
}
