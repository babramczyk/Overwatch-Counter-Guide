#include <vector>
#include "hero.h"
#include <QtSql>
#include <QtSqlVersion>
#include <string>

Hero::Hero() {}

Hero::Hero(int id, QString name) {
    Hero::id = id;
    Hero::name = name;
    score = 0;

}

QString Hero::getName() {
    return name;
}

void Hero::setName(QString name) {
    Hero::name = name;
}

int Hero::getId() {
    return id;
}

void Hero::setId(int id) {
    Hero::id = id;
}

int Hero::getScore() {
    return score;
}

std::vector<int>& Hero::getICounterIDs() {
    return iCounterIDs;
}

std::vector<int>& Hero::getCountersMeIDs() {
    return countersMeIDs;
}

void Hero::calculateScore(std::vector<int> enemyIDs) {
    score = 0; // Reset score

    // Counts heroes that this one counters, and adds it to composite score
    QSqlQuery qCalcScore;
    qCalcScore.exec("SELECT * FROM Counters WHERE heroId0 = " +
                            QString::number(id));
    while (qCalcScore.next()) {
        int currID = qCalcScore.value(2).value<int>();
        iCounterIDs.push_back(currID);
        // Adds 1 to score for every enemy ID that matches the current row
        // saying that 'this' hero wins a 'counter battle'
        score += std::count(enemyIDs.begin(), enemyIDs.end(), currID);
    }

    // Counts heroes that counter this one, and subtracts from composite
    // score
    qCalcScore.exec("SELECT * FROM Counters WHERE heroId1 = " +
                            QString::number(id));
    while (qCalcScore.next()) {
        int currID = qCalcScore.value(1).value<int>();
        countersMeIDs.push_back(currID);
        score -= std::count(enemyIDs.begin(), enemyIDs.end(), currID);
    }
}
