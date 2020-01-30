#include "GUI_select.h"

GUI_select::GUI_select()
{

}

void GUI_select::draw(QPainter *painter)
{
    painter->drawRect(WAIT_SELECT_START_X, WAIT_SELECT_START_Y,
                      WAIT_SELECT_WIDTH, WAIT_SELECT_HEIGHT);
}
