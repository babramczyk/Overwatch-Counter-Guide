#ifndef ROLE_H
#define ROLE_H

#include <QApplication>

class Role
{
private:
    int id;
    QString name;
public:
    Role();
    Role(int id, QString name);
    QString getName();
    void setName(QString name);
    int getId();
    void setId(int id);
};

#endif // ROLE_H
