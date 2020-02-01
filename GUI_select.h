#ifndef GUI_SELECT_H
#define GUI_SELECT_H

#include"Core.h"

class SelectOption
{
    int _id;
public:
    QString line1;
    QString line2;
    QString line3;
    QString line4;
    SelectOption(int id)
    {
        _id = id;
        line1 = QString("");
        line2 = QString("");
        line3 = QString("");
        line4 = QString("");
    }

    int getId(){return _id;}

    inline void drawOne(QPainter *painter, int i, int j, QString line)
    {
        painter->drawText(QRect(WAIT_SELECT_START_X,
                                WAIT_SELECT_START_Y + i * WAIT_OPTION_HEIGHT + j * WAIT_LINE_HEIGHT,
                                WAIT_SELECT_WIDTH,
                                WAIT_LINE_HEIGHT), line);
    }

    void draw(QPainter *painter, int i)
    {
        drawOne(painter, i, 0, line1);
        drawOne(painter, i ,1, line2);
        drawOne(painter, i, 2, line3);
        drawOne(painter, i ,4, line4);
    }

    void setString(QString &l1, QString &l2, QString &l3, QString &l4)
    {
        line1 = l1;
        line2 = l2;
        line3 = l3;
        line4 = l4;
    }

    void clear()
    {
        line1 = QString("");
        line2 = QString("");
        line3 = QString("");
        line4 = QString("");
    }

    void getDisplay(QVector<QString> *vString);

};

typedef QVector<SelectOption*> vSelect;
typedef QVector<vSelect*> multVSelect;

class GUI_select
{   
    vSelect _showOption;

    SelectOption *_option1 = new SelectOption(0);
    SelectOption *_option2 = new SelectOption(1);
    SelectOption *_option3 = new SelectOption(2);
    SelectOption *_option4 = new SelectOption(3);
    SelectOption *_option5 = new SelectOption(4);

public:
    GUI_select();
    void draw(QPainter *painter, int page=0);
    void getOptionWithPage(int page);

    void _clear()
    {
        _option1->clear();
        _option2->clear();
        _option3->clear();
        _option4->clear();
        _option5->clear();
    }
    void getOption(int ident, SelectOption *opt);
    void drawOption(QPainter *painter);

    bool inSelect(int x, int y);
    int getIdWithPos(int y);
    SelectOption *getOptionWithId(int id);
};

#endif // GUI_SELECT_H
