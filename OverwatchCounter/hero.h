#ifndef HERO_H
#define HERO_H

#include <QApplication>
#include "role.h"

class Hero
{
private:
    int id, score;
    QString name;
    Role role;
public:
    Hero();
    Hero(int id, QString name, Role role);
    QString getName();
    void setName(QString name);
    int getId();
    void setId(int id);
    int getScore();
    void calculateScore(std::vector<int> enemyIDs);
    Role getRole();
    void setRole(Role role);
};

#endif // HERO_H
