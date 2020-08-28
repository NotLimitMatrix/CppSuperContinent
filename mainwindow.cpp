#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(superContinentTitle);
    setWindowState(Qt::WindowMaximized);

    world = new GUI_WORLD(sizeManager->getWorldSquare(), 30);
    zoning = new GUI_ZONING(sizeManager->getZoningSquare(), nullptr);
    panel = new GUI_PANEL(sizeManager->getPanelSquare());
    message = new GUI_MESSAGE(sizeManager->getMessageSquare());

    timeFlower = new QTimer(this);
    timeFlower->start();
    timeFlower->setInterval(TICK_FLOW);

    connect(timeFlower, &QTimer::timeout, this, &MainWindow::timeflowTitle);
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
    if (b == Qt::RightButton) {
        world = new GUI_WORLD(sizeManager->getWorldSquare(), 10);
    }

    update();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Space: {
        isPause = !isPause;
        break;
    }
    }
}

void MainWindow::timeflowTitle()
{
    if (isPause) {
        superContinentTitle = QString("Super Continent [%1] 暂停")
                                  .arg(Methods::dateFromTimeNumber(timeCounter));
    } else {
        timeCounter++;
        superContinentTitle = QString("Super Continent [%1]")
                                  .arg(Methods::dateFromTimeNumber(timeCounter));
    }

    setWindowTitle(superContinentTitle);
    update();
}
