#ifndef GUI_SELECT_H
#define GUI_SELECT_H

#include"Core.h"

class GUI_select
{   
    QString _string_list[WAIT_LINE_NUMBER];
    QString _display_list[WAIT_OPTION_NUMBER][WAIT_OPTION_LINE_N];
public:
    GUI_select();
    void draw(QPainter *painter);
};

#endif // GUI_SELECT_H
