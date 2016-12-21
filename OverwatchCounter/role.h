///////////////////////////////////////////////////////////////////////////////
// File Name:      role.h
//
// Author0:        Richard Wollack
// CS email:       wollack@cs.wisc.edu
//
// Author1:        Brett Abramczyk
// CS email:       babramczyk@wisc.edu
//
// Description:    The header file for the Role class
///////////////////////////////////////////////////////////////////////////////

#ifndef ROLE_H
#define ROLE_H

#include <QApplication>

class Role
{
private:
    int id;
    QString name;
public:
    /**
     * @brief A constructor with no parameters.
     *
     */
    Role();

    /**
     * @brief A constructor with parameters.
     *
     * @param id - the role id
     * @param name - the role name
     */
    Role(int id, QString name);

    /**
     * @brief Getter for role name
     *
     * @return The role name
     */
    QString getName();

    /**
     * @brief Setter for role name
     *
     * @param name - the role name
     */
    void setName(QString name);

    /**
     * @brief Getter for role id
     *
     * @return The role id
     */
    int getId();

    /**
     * @brief Setter for role id
     *
     * @param id - the role id
     */
    void setId(int id);
};

#endif // ROLE_H
