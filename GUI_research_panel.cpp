#include "GUI_research_panel.h"

GUI_research_panel::GUI_research_panel()
{

}

void GUI_research_panel::draw(QPainter *painter)
{
    QString tempDisplay;
    QRect tempRect;

    painter->setBrush(Qt::white);
    painter->drawRect(rMilitarySchedule);
    painter->drawRect(rMilitaryTransform);
    painter->drawText(rMilitaryTransform, Qt::AlignCenter, QString::number(rateMilitary));
    tempRect = QRect(RESEARCH_START_X, RESEARCH_MILITARY_Y,scheduleMilitary, RESEARCH_T_HEIGHT_SIZE);
    painter->setBrush(Qt::red);
    painter->drawRect(tempRect);
    tempDisplay = QString("%1 %2%").arg(titleMilitary).arg(QString::number(scheduleMilitary));
    painter->drawText(rMilitarySchedule, Qt::AlignCenter, tempDisplay);

    painter->setBrush(Qt::white);
    painter->drawRect(rCivilSchedule);
    painter->drawRect(rCivilTransform);
    painter->drawText(rCivilTransform, Qt::AlignCenter, QString::number(rateCivil));
    tempRect = QRect(RESEARCH_START_X, RESEARCH_CIVIL_Y, scheduleCivil, RESEARCH_T_HEIGHT_SIZE);
    painter->setBrush(Qt::blue);
    painter->drawRect(tempRect);
    tempDisplay = QString("%1 %2%").arg(titleCivil).arg(QString::number(scheduleCivil));
    painter->drawText(rCivilSchedule, Qt::AlignCenter, tempDisplay);

    painter->setBrush(Qt::white);
    painter->drawRect(rBeyondSchedule);
    painter->drawRect(rBeyondTransform);
    painter->drawText(rBeyondTransform, Qt::AlignCenter, QString::number(rateBeyond));
    tempRect = QRect(RESEARCH_START_X, RESEARCH_BEYOND_Y, scheduleBeyond, RESEARCH_T_HEIGHT_SIZE);
    painter->setBrush(Qt::yellow);
    painter->drawRect(tempRect);
    tempDisplay = QString("%1 %2%").arg(titleBeyond).arg(QString::number(scheduleBeyond));
    painter->drawText(rBeyondSchedule, Qt::AlignCenter, tempDisplay);
}
