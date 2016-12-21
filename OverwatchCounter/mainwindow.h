///////////////////////////////////////////////////////////////////////////////
// File Name:      mainwindow.h
//
// Author0:        Richard Wollack
// CS email:       wollack@cs.wisc.edu
//
// Author1:        Brett Abramczyk
// CS email:       babramczyk@wisc.edu
//
// Description:    The header file for the MainWindow class
///////////////////////////////////////////////////////////////////////////////

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
    /**
     * @brief Click event for addHeroBtn.
     */
    void on_addHeroBtn_clicked();

    /**
     * @brief Adds the currently selected hero or heroes to the enemy
     *  from the list of all heroes.
     */
    void addCurrentHero();

    /**
     * @brief Click event for removeHeroBtn.
     */
    void on_removeHeroBtn_clicked();

    /**
     * @brief Removes the currently selected hero or heroes from the
     *        enemy team list.
     */
    void removeCurrentHero();

    /**
     * @brief Populates the results table with counters for the current
     *        enemy team.
     */
    void populateCounters();

    /**
     * @brief Click event for clearResultsBtn.
     */
    void on_clearResultsBtn_clicked();

    /**
     * @brief Clears the entire enemy team.
     */
    void reset();

    /**
     * @brief Double click event for the list of all heroes.
     *
     * @param QListWidgetItem - The item that was double clicked.
     */
    void onHeroListDoubleClicked(QListWidgetItem*);

    /**
     * @brief Double click event for the enemy team list.
     *
     * @param QListWidgetItem - The item that was double clicked.
     */
    void onEnemyListDoubleClicked(QListWidgetItem*);

    /**
     * @brief Clears all the cells from last results table.
     *
     * @param rows - Number of rows in the table
     */
    void clearResultsIcons(int rows);

private:
    Ui::MainWindow *ui;
    HeroController *hc;

protected:
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // MAINWINDOW_H
