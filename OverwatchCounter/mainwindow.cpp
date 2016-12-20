#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hero.h"
#include <QMainWindow>
#include <QApplication>
#include <QDebug>

QColor *gc = new QColor(0, 255, 0);
QColor *rc = new QColor(255, 0, 0);
QBrush *green = new QBrush(*gc);
QBrush *red = new QBrush(*rc);

QTableWidgetItem* generateColoredScoreCell(int score) {
    QString scoreStr;
    if (score > 0) {
        scoreStr = "+" + QString::number(score);
    } else {
        scoreStr = QString::number(score); // Negative sign already present
    }
    QTableWidgetItem* scoreCell = new QTableWidgetItem(scoreStr);
    if (score > 0) {
        scoreCell->setForeground(Qt::green);
    } else if (score < 0) {
        scoreCell->setForeground(Qt::red);
    }
    return scoreCell;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //set up ui stuff
    ui->setupUi(this);
    qApp->installEventFilter(this);
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
    addCurrentHero();
}

//remove button click event - removes a hero from the current team list
void MainWindow::on_removeHeroBtn_clicked()
{
    removeCurrentHero();
}

//clear button click event - clears the result list
void MainWindow::on_clearResultsBtn_clicked(){
    reset();
}

void MainWindow::addCurrentHero() {
    if (ui->currentTeam->count() == TEAM_SIZE) {
        return;
    }

    QListWidgetItem* currentHero = ui->heroList->currentItem();
    Hero newEnemy;
    hc->getHeroByName(currentHero->text().toStdString(), newEnemy);
    hc->addEnemy(newEnemy);

    ui->heroList->removeItemWidget(currentHero); // Currently doesn't work (?)
    ui->currentTeam->addItem(new QListWidgetItem(currentHero->icon(), currentHero->text()));

    populateCounters();
}

void MainWindow::removeCurrentHero() {
    QListWidgetItem* currentHero = ui->currentTeam->currentItem();
    if (currentHero == NULL) return;

    Hero removeEnemy;
    hc->getHeroByName(currentHero->text().toStdString(), removeEnemy);
    hc->removeEnemy(removeEnemy);
    delete currentHero;

    populateCounters();
}

void MainWindow::populateCounters()  {
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
        item->setIcon(icon);
        int score = it->getScore();

        ui->resultTableWidget->setRowHeight(counter, 50);
        ui->resultTableWidget->setItem(counter, 0, item);
        ui->resultTableWidget->setItem(counter, 1, new QTableWidgetItem(it->getName()));
        QTableWidgetItem* scoreCell = generateColoredScoreCell(score);
        ui->resultTableWidget->setItem(counter, 2, scoreCell);
        ui->resultTableWidget->setFocusPolicy(Qt::NoFocus);

        counter++;
    }

    if (ui->currentTeam->count() == 0) {
        ui->emptyTeamLabel->show();
    }
    if (ui->currentTeam->count() > 0) {
        ui->emptyTeamLabel->hide();
    }
}

void MainWindow::reset() {
    ui->currentTeam->clear();
    ui->resultTableWidget->clear();
    ui->counterResultLabel->show();
    ui->heroList->setFocus();
    hc->clearEnemies();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        if (obj == ui->heroList) {
            if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return
                    || keyEvent->key() == Qt::Key_Control) {
                addCurrentHero();
            } else if (keyEvent->key() == Qt::Key_Delete || keyEvent->key() == Qt::Key_Backspace) {

            }
        } else if (obj == ui->currentTeam) {
            if (keyEvent->key() == Qt::Key_Delete || keyEvent->key() == Qt::Key_Backspace) {
                removeCurrentHero();
            } else if (keyEvent->key() == Qt::Key_Tab) {
                ui->currentTeam->setFocus();
            }
        }
        if (keyEvent->key() == Qt::Key_Escape) {
            reset();
        }
    }
    return QObject::eventFilter(obj, event);
}
