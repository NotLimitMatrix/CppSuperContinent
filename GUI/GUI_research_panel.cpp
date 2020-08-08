#include "GUI_research_panel.h"

GUI_research_panel::GUI_research_panel()
{

}

void GUI_research_panel::drawOneResearch(QPainter *painter, int y, QColor c, QRect& rSch, QRect& rTran, int rate, int sch, QString title)
{
    // 绘制转化比例框
    painter->setBrush(WHITE);
    painter->drawRect(rTran);
    painter->drawText(rTran, Qt::AlignCenter, QString::number(rate));

    // 绘制左半边带颜色进度条
    painter->setBrush(c);
    painter->setPen(c);
    painter->drawRect(QRect(RESEARCH_START_X, y, sch, RESEARCH_T_HEIGHT_SIZE));
    painter->setPen(BLACK);

    // 绘制右半边白色背景条
    painter->setBrush(WHITE);
    painter->setPen(WHITE);
    painter->drawRect(QRect(RESEARCH_START_X + sch, y, 100 - sch, RESEARCH_T_HEIGHT_SIZE));
    painter->setPen(BLACK);

    // 绘制文字信息
    painter->drawText(rSch, Qt::AlignCenter, QString("%1 %2%").arg(title).arg(QString::number(sch)));
}

bool GUI_research_panel::inResearchPanel(int px, int py)
{
    bool bx = (px >= RESEARCH_START_X && px < RESEARCH_END_X);
    bool by = (py >= RESEARCH_START_Y && py < RESEARCH_END_Y);
    return (bx && by);
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
