#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QKeyEvent>
#include "ui_mainwindow.h"
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
    void addCurrentHero();

    void on_removeHeroBtn_clicked();
    void removeCurrentHero();

    void populateCounters();

    void on_clearResultsBtn_clicked();
    void reset();

    void onHeroListDoubleClicked(QListWidgetItem* item);
    void onEnemyListDoubleClicked(QListWidgetItem* item);

private:
    Ui::MainWindow *ui;
    HeroController *hc;

protected:
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // MAINWINDOW_H
