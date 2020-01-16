//
// Created by carlp on 29/12/2019.
//

#include "FarmStats.h"

FarmStats::FarmStats(int food, int health) : _food(food), _health(health) {

}

void FarmStats::addFood(int food) {
    _food += food;
}

void FarmStats::removeFood(int food) {
    _food -= food;
}

void FarmStats::removeHealth(int health) {
    _health -= health;
}

int FarmStats::getHealth() const {
    return _health;
}

int FarmStats::getFood() const {
    return _food;
}
