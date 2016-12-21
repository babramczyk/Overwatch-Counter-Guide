///////////////////////////////////////////////////////////////////////////////
// File Name:      mainwindow.cpp
//
// Author0:        Richard Wollack
// CS email:       wollack@cs.wisc.edu
//
// Author1:        Brett Abramczyk
// CS email:       babramczyk@wisc.edu
//
// Description:    MainWindow class implementation
///////////////////////////////////////////////////////////////////////////////

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hero.h"
#include <QMainWindow>
#include <QDebug>

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

    //set up double click events
    connect(ui->heroList, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
                this, SLOT(onHeroListDoubleClicked(QListWidgetItem*)));

    connect(ui->currentTeam, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
                this, SLOT(onEnemyListDoubleClicked(QListWidgetItem*)));

    //populate list of all heroes
    std::vector<Hero>* heroes = hc->getHeroes();
    for(std::vector<Hero>::iterator it = heroes->begin(); it < heroes->end(); ++it) {
        QListWidgetItem* item = new QListWidgetItem(QIcon(":/icons/" + QString::number(it->getId()) + ".png"), it->getName());
        QPixmap pix(":/icons/" + it->getRole().getName().toLower() + ".png");
        QLabel* label = new QLabel();

        item->setTextColor(Qt::white);
        ui->heroList->addItem(item);
        label->setPixmap(pix);
        label->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
        ui->heroList->setItemWidget(item, label);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

//double click event function for hero list
void MainWindow::onHeroListDoubleClicked(QListWidgetItem*) {
    addCurrentHero();
}

//double click event function for enemy list
void MainWindow::onEnemyListDoubleClicked(QListWidgetItem*) {
    removeCurrentHero();
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

//adds the selected hero(s) to the enemy team list
void MainWindow::addCurrentHero() {
    QList<QListWidgetItem*> selectedHeroes = ui->heroList->selectedItems();

    for (int i = 0; i < selectedHeroes.length(); i++) {
        if (ui->currentTeam->count() == TEAM_SIZE) {
            return;
        }

        QListWidgetItem* currentHero = selectedHeroes.at(i);
        Hero newEnemy;

        hc->getHeroByName(currentHero->text().toStdString(), newEnemy);
        hc->addEnemy(newEnemy);
        ui->currentTeam->addItem(new QListWidgetItem(currentHero->icon(), currentHero->text()));
    }

    ui->heroList->setFocus();
    populateCounters();
}

//removes the selected hero(s) from the enemy team list
void MainWindow::removeCurrentHero() {
    QList<QListWidgetItem*> selectedItems = ui->currentTeam->selectedItems();

    for(int i = 0; i < selectedItems.length(); i++) {
        QListWidgetItem* currentHero = selectedItems.at(i);

        if (currentHero == NULL) return;

        Hero removeEnemy;
        hc->getHeroByName(currentHero->text().toStdString(), removeEnemy);
        hc->removeEnemy(removeEnemy);
        delete currentHero;
    }

    populateCounters();
}

//Populates the counters table with an icon, name and composite score for each counter
void MainWindow::populateCounters()  {
    std::vector<Hero> counters;
    std::vector<int> enemyIDs;
    hc->getHeroScores(counters);
    hc->getEnemyIDs(enemyIDs);
    int row = 0;

    ui->counterResultLabel->hide();
    ui->resultTableWidget->show();
    ui->resultTableWidget->setRowCount(counters.size());
    ui->resultTableWidget->setColumnWidth(0, 35);
    ui->resultTableWidget->setColumnWidth(1, 80);
    ui->resultTableWidget->setColumnWidth(2, 100);
    ui->resultTableWidget->setColumnWidth(3, 60);
    ui->resultTableWidget->setColumnWidth(4, 60);
    ui->resultTableWidget->setColumnWidth(5, 60);
    ui->resultTableWidget->setColumnWidth(6, 60);
    ui->resultTableWidget->setColumnWidth(7, 60);
    ui->resultTableWidget->setColumnWidth(8, 60);
    ui->resultTableWidget->setColumnWidth(9, 60);
    clearResultsIcons(counters.size());

    for (std::vector<Hero>::iterator it = counters.begin(); it < counters.end(); ++it) {
        QTableWidgetItem* avatarItem = new QTableWidgetItem();
        QTableWidgetItem* roleItem = new QTableWidgetItem();
        QIcon avatarIcon(":/icons/" + QString::number(it->getId()) + ".png");
        QIcon roleIcon(":/icons/" + it->getRole().getName().toLower() + ".png");
        avatarItem->setIcon(avatarIcon);
        roleItem->setIcon(roleIcon);
        int score = it->getScore();

        ui->resultTableWidget->setRowHeight(row, 50);
        ui->resultTableWidget->setItem(row, 0, roleItem);
        ui->resultTableWidget->setItem(row, 1, avatarItem);
        ui->resultTableWidget->setItem(row, 2, new QTableWidgetItem(it->getName()));
        QTableWidgetItem* scoreCell = generateColoredScoreCell(score);
        ui->resultTableWidget->setItem(row, 3, scoreCell);
        int col = 4;

        for (auto itr = it->getICounterIDs().begin(); itr != it->getICounterIDs().end(); itr++) {
            for (auto enemy = enemyIDs.begin(); enemy != enemyIDs.end(); enemy++) {
                if (*itr == *enemy) {
//                    qDebug() << it->getName() << ": " << *enemy << "; col = " << col << "; " << *itr;
                    QTableWidgetItem* item = new QTableWidgetItem();
                    QIcon icon(":/icons/" + QString::number(*enemy) + ".png");
                    item->setIcon(icon);
                    item->setBackground(QColor(63, 255, 83, 100));
                    if (row == 13 && col == 5) {
                        qDebug() << "Adding: " << it->getName() << " counters " << *enemy;
                    }
                    ui->resultTableWidget->setItem(row, col++, item);
                }
            }
        }

        qDebug() << it->getName() << ": " << it->getCountersMeIDs();
        for (auto itr = it->getCountersMeIDs().begin(); itr != it->getCountersMeIDs().end(); itr++) {
            for (auto enemy = enemyIDs.begin(); enemy != enemyIDs.end(); enemy++) {
                if (*itr == *enemy) {
                    qDebug() << it->getName() << ": " << *enemy << "; col = " << col << "; " << *itr;
                    QTableWidgetItem* item = new QTableWidgetItem();
                    QIcon icon(":/icons/" + QString::number(*enemy) + ".png");
                    item->setIcon(icon);
                    item->setBackground(QColor(255, 84, 63, 100));
                    if (row == 13 && col == 5) {
                        qDebug() << "Adding: " << it->getName() << " countered by  " << *enemy;
                    }
                    ui->resultTableWidget->setItem(row, col++, item);
                }
            }
        }

//        ui->resultTableWidget->setFocusPolicy(Qt::NoFocus);

        row++;
    }

    if (ui->currentTeam->count() == 0) {
        ui->emptyTeamLabel->show();
    }
    if (ui->currentTeam->count() > 0) {
        ui->emptyTeamLabel->hide();
    }
}

void MainWindow::clearResultsIcons(int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 4; j < 10; j++)
        ui->resultTableWidget->setItem(i, j, NULL);
    }
}

//clears the enemy list
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
            if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return) {
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
