#include "GUI_research_panel.h"

GUI_research_panel::GUI_research_panel()
{

}

void GUI_research_panel::drawOneResearch(QPainter *painter, int y, QColor c, QRect& rSch, QRect& rTran, int rate, int sch, QString title)
{
    QString tempDisplay;


    painter->setBrush(WHITE);
    painter->drawRect(rSch);
    painter->drawRect(rTran);
    painter->drawText(rTran, Qt::AlignCenter, QString::number(rate));

    drawSchedule(painter, title, y, sch, c);

    painter->drawText(rSch, Qt::AlignCenter,QString("%1 %2%").arg(title).arg(QString::number(sch)));
}

void GUI_research_panel::drawSchedule(QPainter *painter,QString title, int y, int schedule, QColor c)
{
    painter->setBrush(c);
    QRect tempRect(RESEARCH_START_X, y, schedule, RESEARCH_T_HEIGHT_SIZE);
    painter->drawRect(tempRect);

}

void GUI_research_panel::draw(QPainter *painter)
{
    drawOneResearch(painter,
                    RESEARCH_MILITARY_Y,
                    SCHEDULE_MILITARY,
                    rMilitarySchedule,
                    rMilitaryTransform,
                    rateMilitary,
                    scheduleMilitary,
                    titleMilitary);

    drawOneResearch(painter,
                    RESEARCH_CIVIL_Y,
                    SCHEDULE_CIVIL,
                    rCivilSchedule,
                    rCivilTransform,
                    rateCivil,
                    scheduleCivil,
                    titleCivil);

    drawOneResearch(painter,
                    RESEARCH_BEYOND_Y,
                    SCHEDULE_BEYOND,
                    rBeyondSchedule,
                    rBeyondTransform,
                    rateBeyond,
                    scheduleBeyond,
                    titleBeyond);
}
