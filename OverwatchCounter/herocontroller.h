#ifndef HEROCONTROLLER_H
#define HEROCONTROLLER_H

#include "hero.h"

class HeroController
{
private:
    std::vector<Hero> heroes;
public:
    HeroController();
    void fetchHeroes(std::vector<Hero> &heroCol);
    Hero* getHero(int id);
    std::vector<Hero>* getHeroes();
    void getCounters(std::vector<Hero> &heroCol);
    void getHeroById(int id, Hero &h);
};

#endif // HEROCONTROLLER_H
