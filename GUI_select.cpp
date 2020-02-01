#include "GUI_select.h"

GUI_select::GUI_select()
{
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

bool GUI_select::inSelect(int x, int y)
{
    bool bx = (x >= WAIT_SELECT_START_X && x < WAIT_SELECT_END_X);
    bool by = (y >= WAIT_SELECT_START_Y && y < WAIT_SELECT_END_Y);
    return (bx && by);
}

int GUI_select::getIdWithPos(int y)
{
    return (y - WAIT_SELECT_START_Y) / WAIT_OPTION_HEIGHT;
}

SelectOption *GUI_select::getOptionWithId(int id)
{
    if(id == 0)
        return _option1;
    else if(id == 1)
        return _option2;
    else if(id == 2)
        return _option3;
    else if(id == 3)
        return _option4;
    else if(id == 4)
        return _option5;
    else
        return nullptr;
}

void SelectOption::getDisplay(QVector<QString> *vString)
{
    vString->push_back(QString(" [选项]  %1").arg(_id));
}
