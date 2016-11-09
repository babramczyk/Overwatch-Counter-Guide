#ifndef HERO_H
#define HERO_H

#include <QApplication>

class Hero
{
private:
    int id;
    QString name;
public:
    Hero();
    Hero(int id, QString name);
    QString getName();
    void setName(QString name);
    int getId();
    void setId(int id);
};

#endif // HERO_H
