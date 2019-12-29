//
// Created by carlp on 29/12/2019.
//

#include "FarmStats.h"

FarmStats::FarmStats(int food, int health) : food(food), health(health) {

}

void FarmStats::addFood(int food) {
    food += food;
}

void FarmStats::removeFood(int food) {
    food -= food;
}

