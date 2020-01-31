#include "GUI_select.h"

GUI_select::GUI_select()
{
    for(int i=0; i<WAIT_OPTION_NUMBER; i++)
        _showOption.push_back(new SelectOption);
}

void GUI_select::draw(QPainter *painter, int page)
{
    painter->setBrush(Qt::white);

    for(int i=0; i<WAIT_OPTION_NUMBER; i++)
        painter->drawRect(QRect(WAIT_SELECT_START_X, WAIT_SELECT_START_Y+i*WAIT_OPTION_HEIGHT,
                                WAIT_SELECT_WIDTH, WAIT_OPTION_HEIGHT));

    getOptionWithPage(page);
    drawOption(painter);
}

void GUI_select::getOptionWithPage(int page)
{
    int startId = page * WAIT_OPTION_LINE_N;
    getOption(startId, _option1);
    getOption(startId + 1, _option2);
    getOption(startId + 2, _option3);
    getOption(startId + 3, _option4);
    getOption(startId + 4, _option5);
}

void GUI_select::getOption(int ident, SelectOption* opt)
{
    if(ident < _showOption.size())
        opt = _showOption[ident];
    else
        opt->clear();
}

void GUI_select::drawOption(QPainter *painter)
{
    _option1->draw(painter, 0);
    _option2->draw(painter, 1);
    _option3->draw(painter, 2);
    _option4->draw(painter, 3);
    _option5->draw(painter, 4);
}
