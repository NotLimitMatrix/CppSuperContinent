#ifndef REFERENCE_H
#define REFERENCE_H

#include <QString>
#include <QMap>
#include <iostream>
#include <QObject>
#include <QList>
#include <QThread>
#include <QMetaType>
#include <QtDebug>

#define SPEED 2
#define TIME_FLOW (1000/SPEED)
#define DEFAULT_MAX 50000

namespace Reference {
QString displayNumberWithUnit(int number);
}

#endif // REFERENCE_H
