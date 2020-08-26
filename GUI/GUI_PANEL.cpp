#include "GUI_PANEL.h"

GUI_PANEL::GUI_PANEL(QRect s)
{
    square = s;

    singleHeight = square.height() / 10;
    powerWidth = square.width() - titleWidth;
    resourceWidth = powerWidth / 2;
    distWidth = square.width() / 9;
    processWidth = square.width() - distWidth;
}

void GUI_PANEL::draw(QPainter *painter)
{
    painter->setPen(BLACK);
    painter->setBrush(WHITE);

    drawResource(painter);
    drawPower(painter);
    drawTechnology(painter);
}

void GUI_PANEL::drawResource(QPainter *painter)
{
    for (int i = 0; i < 5; i++) {
        // draw Title
        Methods::drawPanelText(painter,
                               QRect(square.x(),
                                     square.y() + i * singleHeight,
                                     titleWidth,
                                     singleHeight),
                               PANEL_TITLE[i]);
        // draw storage
        Methods::drawPanelText(painter,
                               QRect(square.x() + titleWidth,
                                     square.y() + i * singleHeight,
                                     resourceWidth,
                                     singleHeight),
                               QString("0"));
        // draw daily
        Methods::drawPanelText(painter,
                               QRect(square.x() + titleWidth + resourceWidth,
                                     square.y() + i * singleHeight,
                                     resourceWidth,
                                     singleHeight),
                               QString("+10"));
    }
}

void GUI_PANEL::drawPower(QPainter *painter)
{
    // draw technology power
    Methods::drawPanelText(painter,
                           QRect(square.x(), square.y() + 5 * singleHeight, titleWidth, singleHeight),
                           PANEL_TITLE[5]);
    Methods::drawPanelText(painter,
                           QRect(square.x() + titleWidth,
                                 square.y() + 5 * singleHeight,
                                 powerWidth,
                                 singleHeight),
                           QString("233k"));
    // draw armor power
    Methods::drawPanelText(painter,
                           QRect(square.x(), square.y() + 6 * singleHeight, titleWidth, singleHeight),
                           PANEL_TITLE[6]);
    Methods::drawPanelText(painter,
                           QRect(square.x() + titleWidth,
                                 square.y() + 6 * singleHeight,
                                 powerWidth,
                                 singleHeight),
                           QString("5420K"));
}

void GUI_PANEL::drawTechnology(QPainter *painter)
{
    int startY = square.y() + singleHeight * 7;

    // 1
    drawSchedule(painter,
                 QRect(square.x(), startY, processWidth, singleHeight),
                 QString("军事科技"),
                 45,
                 SCHEDULE_MILITARY,
                 3);

    // 2
    drawSchedule(painter,
                 QRect(square.x(), startY + singleHeight, processWidth, singleHeight),
                 QString("民用科技"),
                 21,
                 SCHEDULE_CIVIL,
                 3);

    //3
    drawSchedule(painter,
                 QRect(square.x(), startY + singleHeight * 2, processWidth, singleHeight),
                 QString("超越科技"),
                 74,
                 SCHEDULE_BEYOND,
                 4);
}

void GUI_PANEL::drawSchedule(
    QPainter *painter, QRect rect, QString name, int process, QColor color, int rate)
{
    Methods::drawPanelText(painter,
                           QRect(rect.x() + processWidth, rect.y(), distWidth, rect.height()),
                           QString("%1").arg(rate));

    painter->setBrush(color);
    int processLength = processWidth * process / 100;
    painter->drawRect(QRect(rect.x(), rect.y(), processLength, rect.height()));
    painter->setBrush(WHITE);
    painter->drawRect(
        QRect(rect.x() + processLength, rect.y(), processWidth - processLength, rect.height()));
    painter->drawText(rect, Qt::AlignCenter, name);
}
