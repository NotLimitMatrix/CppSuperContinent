#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    noStop = true;
    //qRegisterMetaType<RESOURCE_LIST>("RESOURCE_LIST");

    /*rp = new ResourcePanel(
                new Resource(1000,-200),
                new Resource(1000, 320),
                new Resource(2000, 100),
                new Resource(999000, 999000),
                new Resource(23185, -10)
                );*/
    Resource *energy = new Resource(1000, -200);
    Resource *minertal = new Resource(1000, 320);
    Resource *food = new Resource(2310, 342);
    Resource *consumerGoods = new Resource(1023,-324);
    Resource *alloys = new Resource(2402123,32043);
    ResourcePanel(energy, minertal, food, consumerGoods, alloys);
}

void Controller::doWork()
{
    int i = 0;
    while(noStop)
    {
        std::cout << i << std::endl;
        i++;
        emit sendResourcePanel(*rp);
        QThread::msleep(500);
    }
}
