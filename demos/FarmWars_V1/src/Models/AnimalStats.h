//
// Created by carlp on 29/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ANIMALSTATS_H
#define GBA_SPRITE_ENGINE_PROJECT_ANIMALSTATS_H

#include "FarmStats.h"

class AnimalStats {

public:

    AnimalStats(int health, int attackDamage, int foodCost, int foodGain);

    bool attack(AnimalStats other);

    FarmStats* farmState;

    void setFarmStats(FarmStats *farmState);
    void spawn();
    void die();

    FarmStats *getFarmStats() const;

private:

    // statics type animal
    int foodCost;
public:
    int getAttackDamage() const;

private:
    int attackDamage;
    int foodGain;
public:
    int getFoodGain() const;

public:
    FarmStats *getFarmState() const;

private:
    int velocity;

    // dynamics
    int health;
public:

};


#endif //GBA_SPRITE_ENGINE_PROJECT_ANIMALSTATS_H
