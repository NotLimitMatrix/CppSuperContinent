#include "GUI_select.h"

GUI_select::GUI_select()
{

}

void GUI_select::draw(QPainter *painter)
{
    QRect temp;
    int x=0,y=0;
    painter->setBrush(Qt::white);

    for(int i=0; i<WAIT_OPTION_NUMBER; i++)
    {
        x = WAIT_SELECT_START_X;
        y = WAIT_SELECT_START_Y+i*WAIT_OPTION_HEIGHT;
        temp = QRect(x, y,WAIT_SELECT_WIDTH, WAIT_OPTION_HEIGHT);

        painter->drawRect(temp);

        for(int j=0; j<WAIT_OPTION_LINE_N; j++)
        {
            x = WAIT_SELECT_START_X;
            y = WAIT_SELECT_START_Y + (WAIT_OPTION_LINE_N * i + j) * WAIT_LINE_HEIGHT;
            temp = QRect(x, y, WAIT_SELECT_WIDTH, WAIT_LINE_HEIGHT);

            painter->drawText(temp, Qt::AlignCenter, "Test option;");
        }
    }
}
