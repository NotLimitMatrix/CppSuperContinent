#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Reference.h"
#include "resource.h"

typedef QList<Resource*> RESOURCE_LIST;

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QObject *parent = nullptr);
    void gameLoop();

    RESOURCE_LIST processResourcePanel(RESOURCE_LIST resourcesList);

signals:
    static void sendResourcePanel(RESOURCE_LIST& resourcePanel);

public slots:

};

#endif // CONTROLLER_H
