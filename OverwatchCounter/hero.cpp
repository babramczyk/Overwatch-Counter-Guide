#include "hero.h"

Hero::Hero() {}

Hero::Hero(int id, QString name) {
    Hero::id = id;
    Hero::name = name;
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
