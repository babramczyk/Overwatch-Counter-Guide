#ifndef HERO_H
#define HERO_H

#include <QApplication>

class Hero
{
private:
    int id, score;
    QString name;
    std::vector<int> iCounterIDs, countersMeIDs;
public:
    Hero();
    Hero(int id, QString name);
    QString getName();
    void setName(QString name);
    int getId();
    void setId(int id);
    int getScore();
    std::vector<int>& getICounterIDs();
    std::vector<int>& getCountersMeIDs();
    void calculateScore(std::vector<int> enemyIDs);
};

#endif // HERO_H
