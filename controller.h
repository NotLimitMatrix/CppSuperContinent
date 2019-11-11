#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Reference.h"
#include "resourcepanel.h"

class Controller : public QObject
{
    Q_OBJECT

    RESOURCE_LIST resourceList;

public:
    explicit Controller(QObject *parent = nullptr);

    ResourcePanel *rp;
    bool noStop;

public slots:
    void doWork();

signals:
    void sendResourcePanel(ResourcePanel rp);
};

#endif // CONTROLLER_H
