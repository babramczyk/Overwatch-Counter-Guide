#include "herocontroller.h"
#include <QtSql>
#include <QtSqlVersion>
#include <vector>

HeroController::HeroController() {
    connectDB();
    fetchRoles(roles);
    fetchHeroes(heroes);
}

void HeroController::connectDB() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(QString(MYSQL_HOST));
    db.setDatabaseName(QString(MYSQL_DB));
    db.setUserName(QString(MYSQL_USER));
    db.setPassword(QString(MYSQL_PASS));
    dbConnected = db.open();

    if(!dbConnected) {
        qDebug() << "Failed to connect to database.";
    }
}

//get all heroes from the database
void HeroController::fetchHeroes(std::vector<Hero> &heroCol) {
    if(dbConnected) {
        QSqlQuery qGetHeroes;
        qGetHeroes.exec("SELECT * FROM Heroes");

        while(qGetHeroes.next()) {
            int id = qGetHeroes.value(0).toInt();
            QString name = qGetHeroes.value(1).toString();
            Role role;
            getRoleById(qGetHeroes.value(2).toInt(), role);
            Hero hero(id, name, role);
            heroCol.push_back(hero);
        }
    } else {
        qDebug() << "Could not fetch heroes. Bad DB connection";
    }
}

void HeroController::fetchRoles(std::vector<Role> &roles) {
    if(dbConnected) {
        QSqlQuery qGetRoles;
        qGetRoles.exec("SELECT * FROM Roles");

        while(qGetRoles.next()) {
            int id = qGetRoles.value(0).toInt();
            QString name = qGetRoles.value(1).toString();
            Role role(id, name);
            roles.push_back(role);
        }
    } else {
        qDebug() << "Could not fetch roles. Bad DB connection";
    }
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

void HeroController::getRoleById(int id, Role &r) {
    auto it = std::find_if(roles.begin(),
                           roles.end(),
                           [id](Role &r) {
            return r.getId() == id;
    });

    if(it != roles.end()) {
        r = *it;
    }
}

/**
 * @brief Iterates over all heroes, and updates their 'score' field based on
 *        the current selected team.
 */
void HeroController::calculateAllHeroScores() {
    std::vector<int> enemyIDs;
    for (auto it = enemies.begin(); it != enemies.end(); ++it) {
        enemyIDs.push_back(it->getId());
    }
    for (auto it = heroes.begin(); it != heroes.end(); ++it) {
        it->calculateScore(enemyIDs);
    }
}

/**
 * @brief Will return a vector of heroes with newly populated fields for their
 *        scores with respect to the currently selected team. Only populates
 *        heroes with non-zero scores.
 *
 * @param heroesWithScores The vector to populate.
 */
void HeroController::getHeroScores(std::vector<Hero> &heroesWithScores) {
    calculateAllHeroScores();
    for (auto it = heroes.begin();
         it != heroes.end(); ++it) {
        if (it->getScore() != 0) {
            heroesWithScores.push_back(*it);
        }
    }
    std::sort(heroesWithScores.begin(), heroesWithScores.end(), [](Hero &a, Hero&b) {
        return b.getScore() < a.getScore();
    });
}

void HeroController::addEnemy(Hero enemy) {
    enemies.push_back(enemy);
}

void HeroController::getHeroByName(std::string name, Hero &h) {
    auto it = std::find_if(heroes.begin(),
                           heroes.end(),
                           [name](Hero &h) {
                               return h.getName().toStdString() == name;
                           });

    if (it != heroes.end()) {
        h = *it;
    }
}

void HeroController::clearEnemies() {
    enemies.clear();
}

void HeroController::removeEnemy(Hero removeEnemy) {
    auto it = enemies.begin();
    for (; it != enemies.end(); ++it) {
        if (it->getId() == removeEnemy.getId()) {
            break;
        }
    }
    if (it != enemies.end()) {
        enemies.erase(it);
    }
}

void HeroController::printEnemies() {
    for (auto it = enemies.begin();
         it != enemies.end(); ++it) {
        qDebug() << it->getName() << ": " << it->getId();
    }
}
