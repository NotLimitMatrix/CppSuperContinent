#include "GUI_text.h"

GUI_text::GUI_text()
{

}

void GUI_text::draw(QPainter *painter, QVector<QString> &vString)
{
    // 字符长度不超过52
    // 汉字长度不超过30
    QRect temp;
    painter->setBrush(Qt::white);
    painter->drawRect(TEXT_START_X, TEXT_START_Y, TEXT_WIDTH, TEXT_HEIGHT);

    for(int i=0; i<vString.size(); i++)
    {
        temp = QRect(TEXT_START_X, TEXT_START_Y + i * TEXT_LINE_HEIGHT,
                     TEXT_WIDTH, TEXT_LINE_HEIGHT);
        painter->drawText(temp, vString[i]);
    }
}

bool GUI_text::inTextBrowser(int px, int py)
{
    bool bx = (px >= TEXT_START_X && py < TEXT_END_X);
    bool by = (py >= TEXT_START_Y && py < TEXT_END_Y);
    return (bx && by);
}
