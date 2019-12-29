//
// Created by carlp on 29/12/2019.
//

#include "AnimalStats.h"

AnimalStats::AnimalStats(int health, int attackDamage, int foodCost, int foodGain) :
        health(health), attackDamage(attackDamage), foodCost(foodCost), foodGain(foodGain)
{

}

void AnimalStats::spawn() {
    farmState->removeFood(foodCost);
}

bool AnimalStats::attack(AnimalStats other) {
    health -= other.getAttackDamage();
    if (health <= 0)
    {
        other.getFarmStats()->addFood(foodGain);
    }
    return (health > 0);
}

void AnimalStats::die() {
    return;
}

int AnimalStats::getAttackDamage() const {
    return attackDamage;
}

FarmStats *AnimalStats::getFarmStats() const {
    return farmState;
}

void AnimalStats::setFarmStats(FarmStats *farmState) {
    AnimalStats::farmState = farmState;
}






