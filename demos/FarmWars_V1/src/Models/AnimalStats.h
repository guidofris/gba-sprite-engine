//
// Created by carlp on 29/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ANIMALSTATS_H
#define GBA_SPRITE_ENGINE_PROJECT_ANIMALSTATS_H

#include "FarmStats.h"

class AnimalStats {

public:
    AnimalStats(int health, int attackDamage, int foodCost, int foodGain, int attackTimeOut);
    FarmStats* farmState;
    bool attack(AnimalStats other);
    void setFarmStats(FarmStats *farmState);
    void spawn();
    void die();
    FarmStats *getFarmStats() const;
    int getAttackDamage() const;
    void setAttackTimeOut(int attackTimeOut);
    int getAttackTimeOut() const;
    void minAttackTimeOut();
    int getFoodGain() const;
    FarmStats *getFarmState() const;
    int getHealth() const;
private:
    // statics type animal
    int foodCost;
    int attackDamage;
    int foodGain;
    int attackTimeOut ;
    int velocity;
    // dynamics
    int health;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ANIMALSTATS_H
