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
    HeroController();
    void connectDB();
    void fetchHeroes(std::vector<Hero> &heroCol);
    Hero* getHero(int id);
    std::vector<Hero>* getHeroes();
    void getHeroById(int id, Hero &h);
    void getHeroByName(std::string name, Hero &h);
    void getHeroScores(std::vector<Hero> &heroesWithScores);
    void calculateAllHeroScores();
    void addEnemy(Hero enemy);
    void removeEnemy(Hero removeEnemy);
    void clearEnemies();
    void printEnemies();
    void fetchRoles(std::vector<Role> &roles);
    void getRoleById(int id, Role &r);
};

#endif // HEROCONTROLLER_H
