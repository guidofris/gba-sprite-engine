//
// Created by Guido Frissaer on 05/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_FARMBASE_H
#define GBA_SPRITE_ENGINE_PROJECT_FARMBASE_H

class FarmBase
{
private:

    int m_food = 100;     // food is used to spawn animales
    int m_health = 100;   // if health is 0 => dead
    int m_direction = 1;
    int m_position = 0;
    int m_animaltype = 0;

public:
    int getAnimaltype() const;

    void setAnimaltype(int animaltype);
    void spawn();
    void move();

public:
    FarmBase(int direction, int position);

    int getDirection();
};

FarmBase* gMyFarm = nullptr;
FarmBase* gAIFarm = nullptr;

#endif //GBA_SPRITE_ENGINE_PROJECT_FARMBASE_H
