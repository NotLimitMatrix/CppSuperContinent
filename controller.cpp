#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{

}

void Controller::gameLoop()
{
    while(true)
    {
        QThread::msleep(TIME_FLOW);
    }
}
