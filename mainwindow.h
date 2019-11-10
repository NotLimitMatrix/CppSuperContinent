#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <iostream>
#include <QPushButton>
#include <QtCore>
#include <QTextBrowser>
#include <QRect>
#include <QTableWidget>
#include <QHeaderView>

#include "Reference.h"

typedef QMap<QString, QPushButton>  STRING_BUTTON_DICT;
typedef QMap<QString, STRING_BUTTON_DICT> STRING_SBUTTON_DICT;
typedef QList<QPushButton*> BUTTON_LIST;

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    QTextBrowser* textBrowser;
    QTableWidget* resourcePanel;
    QTableWidget* technologyPanel;
    //BUTTON_LIST zoningList;
    //STRING_SBUTTON_DICT technologistsButtons;
    //STRING_BUTTON_DICT technologistsLabels;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init();
    QTableWidget *generateTableWidget(int row, int col, int h_size, int v_size);
    void initResourcePanel();
    void initTechnologyPanel();
};
#endif // MAINWINDOW_H
