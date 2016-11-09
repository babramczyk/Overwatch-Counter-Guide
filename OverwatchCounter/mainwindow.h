#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "herocontroller.h"

const int TEAM_SIZE = 6;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addHeroBtn_clicked();

    void on_removeHeroBtn_clicked();

    void on_findCountersBtn_clicked();

    void on_clearResultsBtn_clicked();

private:
    Ui::MainWindow *ui;
    HeroController *hc;
};

#endif // MAINWINDOW_H
