#ifndef HEROCONTROLLER_H
#define HEROCONTROLLER_H

#include <vector>
#include <string>
#include "hero.h"

class HeroController
{
private:
    std::vector<Hero> heroes;
    std::vector<Hero> enemies;
public:
    HeroController();
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
};

#endif // HEROCONTROLLER_H
