#ifndef MAINGUI_H
#define MAINGUI_H

#include <QMainWindow>

class MainGui : public QMainWindow
{
    Q_OBJECT

public:
    MainGui(QWidget *parent = nullptr);
    ~MainGui();
};
#endif // MAINGUI_H
