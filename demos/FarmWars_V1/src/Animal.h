//
// Created by Guido Frissaer on 05/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ANIMAL_H
#define GBA_SPRITE_ENGINE_PROJECT_ANIMAL_H


#include <libgba-sprite-engine/sprites/sprite.h>
#include "FarmBase.h"

class Animal
{

private:
    std::unique_ptr<Sprite> sprite;

    int m_foodCost; // if an animal is spawned the foodCost reduces the base food
    int m_foodGain; // if an animal dies the foodGain is added to the base food
    int m_health;   // current health state
    int m_damage;   // how much damage an animal does
    int m_speed;    // how fast an animal moves
    int m_position;
    int m_animaltype;

public:
    Animal(int foodCost, int foodGain, int health, int damage, int speed) : m_foodCost{foodCost}, m_foodGain{foodGain}, m_health{health}, m_damage{damage}, m_speed{speed}
    {

    }

    void attack(Animal* enemy);
    bool isDead();
    bool isAlive();
    void move(FarmBase* base);

};

class Yoda : public Animal {

public:
    Yoda() : Animal(100,200, 100, 100, 10)
    {

    }
};

class Lama : public Animal {

public:
    Lama() : Animal(50, 100, 200, 50, 1)
    {

    }
};

#endif //GBA_SPRITE_ENGINE_PROJECT_ANIMAL_H

