#include "herocontroller.h"
#include <QtSql>
#include <QtSqlVersion>
#include <vector>

HeroController::HeroController() {
    fetchHeroes(heroes);
}

//get all heroes from the database
void HeroController::fetchHeroes(std::vector<Hero> &heroCol) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("overwatch_counter_guide");
    db.setUserName("root");
    db.setPassword("Bb240824");
    bool dbOpen = db.open();

    if(dbOpen) {
        QSqlQuery qGetHeroes;
        qGetHeroes.exec("SELECT * FROM Heroes");

        while(qGetHeroes.next()) {
            int id = qGetHeroes.value(0).toInt();
            QString name = qGetHeroes.value(1).toString();
            Hero hero(id, name);
            heroCol.push_back(hero);
            qDebug() << "ID: " << hero.getId() << " Name: " << hero.getName();
        }
    } else {
        qDebug() << "NO HEROES!!!";
    }

    qDebug() << "Total Heroes: " << heroCol.size();
}

//getter for hero list
std::vector<Hero>* HeroController::getHeroes() {
    if(heroes.size() < 1) {
        fetchHeroes(heroes);
    }

    return &heroes;
}

//get a hero from the vector of heroes by id
void HeroController::getHeroById(int id, Hero &h) {
    auto it = std::find_if(heroes.begin(),
                      heroes.end(),
                      [id](Hero &h) {
            return h.getId() == id;
    });

    if(it != heroes.end()) {
        h = *it;
    }
}

//get a list of counters
void HeroController::getCounters(std::vector<Hero> &hs) {
    //my thought here was to run a query and then poulate the return vector with hero
    //objects retrieved from the original vector of heros using id's returned from the db
    //maybe not the best way to do it...
    Hero h;
    for(int i = 1; i < 10; i++) {
        getHeroById(i, h);
        hs.push_back(h);
    }
}
