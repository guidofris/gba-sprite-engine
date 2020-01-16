//
// Created by carlp on 29/12/2019.
//

#include "AnimalStats.h"

AnimalStats::AnimalStats(int health, int attackDamage, int foodCost, int foodGain, int attackTimeOut) :
        health(health), attackDamage(attackDamage), foodCost(foodCost), foodGain(foodGain), attackTimeOut(attackTimeOut)
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

FarmStats *AnimalStats::getFarmState() const {
    return farmState;
}

int AnimalStats::getFoodGain() const {
    return foodGain;
}

int AnimalStats::getHealth() const {
    return health;
}

void AnimalStats::minAttackTimeOut() {
    AnimalStats::attackTimeOut-- ;
}

int AnimalStats::getAttackTimeOut() const {
    return attackTimeOut;
}

void AnimalStats::setAttackTimeOut(int attackTimeOut) {
    AnimalStats::attackTimeOut = attackTimeOut;
}






