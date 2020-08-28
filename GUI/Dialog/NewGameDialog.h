#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QWidget>

class NewGameDialog : public QWidget
{
    QString title = QString("游戏配置");

    QLineEdit *nickname = new QLineEdit(this);
    QLineEdit *host = new QLineEdit(this);
    QLineEdit *port = new QLineEdit(this);

public:
    NewGameDialog();
    void setUi();
};

#endif // NEWGAMEDIALOG_H
