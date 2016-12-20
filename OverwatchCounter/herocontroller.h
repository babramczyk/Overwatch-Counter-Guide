///////////////////////////////////////////////////////////////////////////////
// File Name:      herocontroller.h
//
// Author0:        Richard Wollack
// CS email:       wollack@cs.wisc.edu
//
// Author1:        Brett Abramczyk
// CS email:       babramczyk@wisc.edu
//
// Description:    The header file for the HeroController class
///////////////////////////////////////////////////////////////////////////////

#ifndef HEROCONTROLLER_H
#define HEROCONTROLLER_H

#include <vector>
#include <string>
#include "hero.h"
#include "role.h"

class HeroController
{
private:
    std::vector<Hero> heroes;
    std::vector<Hero> enemies;
    std::vector<Role> roles;
    bool dbConnected;
public:
    /**
     * @brief Constructor with no parameters
     *
     * @return HeroController
     */
    HeroController();

    /**
     * @brief Sets up the database connection.
     */
    void connectDB();

    /**
     * @brief Queries the database for all heroes and stores
     *        them in a vector reference which is passed in.
     *
     * @param vector of heroes to store the query results
     */
    void fetchHeroes(std::vector<Hero> &heroCol);

    /**
     * @brief Getter for heroes vector property.
     *
     * @return pointer to the vector containing heroes.
     */
    std::vector<Hero>* getHeroes();

    /**
     * @brief Gets a hero by name
     *
     * @param name - the name of the hero
     * @param h - hero to return
     */
    void getHeroByName(std::string name, Hero &h);

    /**
     * @brief Will return a vector of heroes with newly populated fields for their
     *        scores with respect to the currently selected team. Only populates
     *        heroes with non-zero scores.
     *
     * @param heroesWithScores The vector to populate.
     */
    void getHeroScores(std::vector<Hero> &heroesWithScores);

    /**
     * @brief Iterates over all heroes, and updates their 'score' field based on
     *        the current selected team.
     */
    void calculateAllHeroScores();

    /**
     * @brief Adds a hero to the enemy team.
     *
     * @param enemy - The hero to add to the enemy team
     */
    void addEnemy(Hero enemy);

    /**
     * @brief Removes a hero from the enemy team.
     *
     * @param removeEnemy - The hero to remove from the enemy team.
     */
    void removeEnemy(Hero removeEnemy);

    /**
     * @brief Clears the entire enemy list.
     */
    void clearEnemies();

    /**
     * @brief Used for debugging. Prints the enemy team to the console.
     */
    void printEnemies();

    /**
     * @brief Queries the database for all roles and stores them in a vector.
     *
     * @param roles - The vector to store the roles.
     */
    void fetchRoles(std::vector<Role> &roles);

    /**
     * @brief Gets a role by id.
     *
     * @param id - The role id
     * @param r - Reference to a Role for the return value.
     */
    void getRoleById(int id, Role &r);
};

#endif // HEROCONTROLLER_H
