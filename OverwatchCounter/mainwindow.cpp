#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hero.h"
#include <QMainWindow>
#include <QApplication>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //set up ui stuff
    ui->setupUi(this);
    ui->heroList->setIconSize(QSize(50, 50));
    ui->currentTeam->setIconSize(QSize(75, 75));
    ui->resultTableWidget->setIconSize(QSize(50, 50));
    ui->currentTeam->setViewMode(QListWidget::IconMode);

    hc = new HeroController();

    //populate list of all heroes
    std::vector<Hero>* heroes = hc->getHeroes();
    for(std::vector<Hero>::iterator it = heroes->begin(); it < heroes->end(); ++it) {
        QListWidgetItem* item = new QListWidgetItem(QIcon(":/icons/" + QString::number(it->getId()) + ".png"), it->getName());
        item->setTextColor(Qt::white);
        ui->heroList->addItem(item);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

//add button click event - adds a hero to the current team list
void MainWindow::on_addHeroBtn_clicked()
{
    if(ui->currentTeam->count() == TEAM_SIZE) {
        return;
    }

    QListWidgetItem* currentHero = ui->heroList->currentItem();
    Hero newEnemy;
    hc->getHeroByName(currentHero->text().toStdString(), newEnemy);
    hc->addEnemy(newEnemy);

    ui->heroList->removeItemWidget(currentHero); // Currently doesn't work (?)
    ui->currentTeam->addItem(new QListWidgetItem(currentHero->icon(), currentHero->text()));

    if(ui->currentTeam->count() > 0) {
        ui->emptyTeamLabel->hide();
    }
}

//remove button click event - removes a hero from the current team list
void MainWindow::on_removeHeroBtn_clicked()
{
    QListWidgetItem* currentHero = ui->currentTeam->currentItem();
    Hero removeEnemy;
    hc->getHeroByName(currentHero->text().toStdString(), removeEnemy);
    hc->removeEnemy(removeEnemy);
    hc->printEnemies();
    delete currentHero;

    if(ui->currentTeam->count() == 0) {
        ui->emptyTeamLabel->show();
    }
}

//gets list of counters and populates the results table view
void MainWindow::on_findCountersBtn_clicked()
{
    std::vector<Hero> counters;
    hc->getHeroScores(counters);
    int counter = 0;

    ui->counterResultLabel->hide();
    ui->resultTableWidget->show();
    ui->resultTableWidget->setRowCount(counters.size());
    ui->resultTableWidget->setColumnCount(3);
    ui->resultTableWidget->setColumnWidth(0, 100);

    for(std::vector<Hero>::iterator it = counters.begin(); it < counters.end(); ++it) {
        QTableWidgetItem* item = new QTableWidgetItem();
        QIcon icon(":/icons/" + QString::number(it->getId()) + ".png");
        int score = it->getScore();
        QString scoreStr;
        if (score > 1) {
            scoreStr = "+" + QString::number(score);
        } else {
            scoreStr = QString::number(score); // Negative sign already present
        }

        item->setIcon(icon);

        ui->resultTableWidget->setRowHeight(counter, 50);
        ui->resultTableWidget->setItem(counter, 0, item);
        ui->resultTableWidget->setItem(counter, 1, new QTableWidgetItem(it->getName()));
        ui->resultTableWidget->setItem(counter, 2, new QTableWidgetItem(scoreStr));

        counter++;
    }
}

//clear button click event - clears the result list
void MainWindow::on_clearResultsBtn_clicked()
{
    qDebug() << "Clear";
    ui->resultTableWidget->clear();
    ui->counterResultLabel->show();
    hc->clearEnemies();
}

