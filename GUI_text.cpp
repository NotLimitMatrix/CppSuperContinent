#include "GUI_text.h"

GUI_text::GUI_text()
{

}

void GUI_text::draw(QPainter *painter)
{
    QRect temp;
    painter->setBrush(Qt::white);
    painter->drawRect(TEXT_START_X, TEXT_START_Y, TEXT_WIDTH, TEXT_HEIGHT);
    for(int i=0; i<_line_number; i++)
    {
        temp = QRect(TEXT_START_X, TEXT_START_Y + i * TEXT_LINE_HEIGHT,
                     TEXT_WIDTH, TEXT_LINE_HEIGHT);
        // 字符长度不超过21
        // 汉字长度不超过12
        painter->drawText(temp, "汉字长度不超过12");
    }
}
