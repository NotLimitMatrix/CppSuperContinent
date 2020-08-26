#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Super Continent");
    setWindowState(Qt::WindowMaximized);

    world = new GUI_WORLD(sizeManager->getWorldSquare(), 10);
    zoning = new GUI_ZONING(sizeManager->getZoningSquare(), nullptr);
    panel = new GUI_PANEL(sizeManager->getPanelSquare());
    message = new GUI_MESSAGE(sizeManager->getMessageSquare());
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter *painter = new QPainter;
    painter->begin(this);
    painter->setFont(QFont("宋体", 12, QFont::Bold));

    world->draw(painter);
    zoning->draw(painter);
    panel->draw(painter);
    painter->drawRect(sizeManager->getMessageSquare());

    painter->end();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Qt::MouseButtons b = event->buttons();
    int posX = event->x();
    int posY = event->y();

    if (b == Qt::LeftButton) {
        if (world->posIn(posX, posY)) {
            zoning->setBlock(world->getBlockWithPosition(posX, posY));
        }
    }

    update();
}
