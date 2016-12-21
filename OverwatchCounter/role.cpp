///////////////////////////////////////////////////////////////////////////////
// File Name:      role.cpp
//
// Author0:        Richard Wollack
// CS email:       wollack@cs.wisc.edu
//
// Author1:        Brett Abramczyk
// CS email:       babramczyk@wisc.edu
//
// Description:    Role class implementation
///////////////////////////////////////////////////////////////////////////////

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
