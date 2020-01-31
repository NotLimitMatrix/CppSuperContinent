#include "GUI_select.h"

GUI_select::GUI_select()
{
    for(int i=0; i<WAIT_LINE_NUMBER; i++)
        _string_list[i] = "Empty";
    for(int i=0; i<WAIT_OPTION_NUMBER; i++)
        for(int j=0; j<WAIT_OPTION_LINE_N; j++)
            _display_list[i][j] = "Empty";
}

void GUI_select::draw(QPainter *painter)
{
    QRect temp;
    painter->setBrush(Qt::white);

    for(int i=0; i<WAIT_OPTION_NUMBER; i++)
    {
        temp = QRect(WAIT_SELECT_START_X, WAIT_SELECT_START_Y+i*WAIT_OPTION_HEIGHT,
                     WAIT_SELECT_WIDTH, WAIT_OPTION_HEIGHT);

        painter->drawRect(temp);

        for(int j=0; j<WAIT_OPTION_LINE_N; j++)
        {
            temp = QRect(WAIT_SELECT_START_X, WAIT_SELECT_START_Y+i*WAIT_OPTION_HEIGHT+j*WAIT_LINE_HEIGHT,
                         WAIT_SELECT_WIDTH, WAIT_SELECT_HEIGHT);
            painter->drawText(temp, _display_list[i][j]);
        }
    }
}
