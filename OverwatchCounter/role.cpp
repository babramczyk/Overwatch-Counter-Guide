#include "role.h"

Role::Role() {}

Role::Role(int id, QString name)
{
    Role::id = id;
    Role::name = name;
}

void Role::setId(int id) {
    this->id = id;
}

int Role::getId() {
    return id;
}

QString Role::getName() {
    return name;
}

void Role::setName(QString name) {
    this->name = name;
}
