#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QWidget>

class NewGameDialog : public QWidget
{
    QWidget *widgetParent;
    QString title = QString("游戏配置");

    QLineEdit *nickname = new QLineEdit(this);
    QLineEdit *host = new QLineEdit(this);
    QLineEdit *port = new QLineEdit(this);
    QPushButton *submit = new QPushButton(this);

public:
    NewGameDialog(QWidget *parent);
    void setUi();
    void pushButtonSubmit();

    void sendNewGameData(QString, QString, QString);
};

#endif // NEWGAMEDIALOG_H
