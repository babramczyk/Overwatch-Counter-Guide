///////////////////////////////////////////////////////////////////////////////
// File Name:      hero.h
//
// Author0:        Richard Wollack
// CS email:       wollack@cs.wisc.edu
//
// Author1:        Brett Abramczyk
// CS email:       babramczyk@wisc.edu
//
// Description:    The header file for the Hero class
///////////////////////////////////////////////////////////////////////////////

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
    /**
     * @brief A constructor with no parameters.
     *
     */
    Hero();

    /**
     * @brief A constructor with parameters.
     *
     * @param id - the hero id
     * @param name - the hero name
     * @param role - the hero role
     */
    Hero(int id, QString name, Role role);

    /**
     * @brief Getter for hero name
     *
     * @return the hero name
     */
    QString getName();

    /**
     * @brief Setter for hero name
     *
     * @param name - the hero name
     */
    void setName(QString name);

    /**
     * @brief Getter for hero id
     *
     * @return the hero id
     */
    int getId();

    /**
     * @brief Setter for hero id
     *
     * @param id - the hero id
     */
    void setId(int id);

    /**
     * @brief Getter for hero score
     *
     * @return the hero score
     */
    int getScore();

    /**
     * @brief Calculates the composite score for a hero by querying
     *        the database with enemy ids
     *
     * @param enemyIds - a list of enemy id's to calculate the score against.
     */
    void calculateScore(std::vector<int> enemyIDs);

    /**
     * @brief Getter for role
     *
     * @return the hero role
     */
    Role getRole();

    /**
     * @brief Setter for hero role
     *
     * @param role - the hero role
     */
    void setRole(Role role);
};

#endif // HERO_H
