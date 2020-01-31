#ifndef GUI_SELECT_H
#define GUI_SELECT_H

#include"Core.h"

class SelectOption
{
public:
    QString line1 = QString("");
    QString line2 = QString("");
    QString line3 = QString("");
    QString line4 = QString("");

    SelectOption();

    inline void drawOne(QPainter *painter, int i, int j, QString line)
    {
        painter->drawText(QRect(WAIT_SELECT_START_X,
                                WAIT_SELECT_START_Y + i * WAIT_OPTION_HEIGHT + j * WAIT_LINE_HEIGHT,
                                WAIT_SELECT_WIDTH,
                                WAIT_LINE_HEIGHT), line);
    }

    void draw(QPainter *painter, int i)
    {
        drawOne(painter, i, 0, line1);
        drawOne(painter, i ,1, line2);
        drawOne(painter, i, 2, line3);
        drawOne(painter, i ,4, line4);
    }

};

class GUI_select
{   
    QString _string_list[WAIT_LINE_NUMBER];
    QString _display_list[WAIT_OPTION_NUMBER][WAIT_OPTION_LINE_N];

public:
    GUI_select();
    void draw(QPainter *painter);
};

#endif // GUI_SELECT_H
