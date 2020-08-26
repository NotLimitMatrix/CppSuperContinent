#ifndef GUI_MESSAGE_H
#define GUI_MESSAGE_H

#include <QPainter>
#include <QRect>
#include <QString>

class GUI_MESSAGE
{
    QRect square;
    QString text = QString("");

    int singleHeight;

public:
    GUI_MESSAGE(QRect s);
    void setText(QString t) { text = t; }
    void draw(QPainter *painter);
};

#endif // GUI_MESSAGE_H
