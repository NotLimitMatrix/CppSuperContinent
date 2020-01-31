#ifndef GUI_RESEARCH_PANEL_H
#define GUI_RESEARCH_PANEL_H

#include"Core.h"

class GUI_research_panel
{
    QRect rMilitarySchedule = QRect(RESEARCH_START_X, RESEARCH_MILITARY_Y,
                                    RESEARCH_WIDTH_SIZE, RESEARCH_HEIGHT_SIZE);
    QRect rMilitaryTransform = QRect(RESEARCH_T_START_X, RESEARCH_MILITARY_T_Y,
                                     RESEARCH_T_WIDTH_SIZE, RESEARCH_T_HEIGHT_SIZE);

    QRect rCivilSchedule = QRect(RESEARCH_START_X, RESEARCH_CIVIL_Y,
                                 RESEARCH_WIDTH_SIZE, RESEARCH_HEIGHT_SIZE);
    QRect rCivilTransform = QRect(RESEARCH_T_START_X, RESEARCH_CIVIL_T_Y,
                                  RESEARCH_T_WIDTH_SIZE, RESEARCH_T_HEIGHT_SIZE);

    QRect rBeyondSchedule = QRect(RESEARCH_START_X, RESEARCH_BEYOND_Y,
                                   RESEARCH_WIDTH_SIZE, RESEARCH_HEIGHT_SIZE);
    QRect rBeyondTransform = QRect(RESEARCH_T_START_X, RESEARCH_BEYOND_T_Y,
                                   RESEARCH_T_WIDTH_SIZE, RESEARCH_T_HEIGHT_SIZE);

public:
    int rateMilitary = 3;
    int scheduleMilitary = 35;
    QString titleMilitary = "暂无研究";

    int rateCivil = 3;
    int scheduleCivil = 67;
    QString titleCivil = "暂无研究";

    int rateBeyond = 4;
    int scheduleBeyond = 12;
    QString titleBeyond = "暂无研究";


    GUI_research_panel();
    void draw(QPainter *painter);
};

#endif // GUI_RESEARCH_PANEL_H
