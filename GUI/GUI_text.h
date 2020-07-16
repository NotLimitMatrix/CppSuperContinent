#ifndef GUI_TEXT_H
#define GUI_TEXT_H

#include"Core.h"

class GUI_text
{
    int _line_number = TEXT_LINE_NUMBER;
public:
    GUI_text();
    void draw(QPainter *painter, QVector<QString>& vString);
};

#endif // GUI_TEXT_H
