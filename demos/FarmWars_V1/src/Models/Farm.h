//
// Created by carlp on 29/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_FARM_H
#define GBA_SPRITE_ENGINE_PROJECT_FARM_H

#include "../main.h"

class Farm {
public:
    Farm();

    std::unique_ptr<FarmStats> stats;
    std::vector<std::unique_ptr<Animal>> animals;

    void addAnimal( Animal::AnimalType type, Animal::AnimalDirection direction, int velocity, int position);
    void removeAnimalByIndex(int position);
};


#endif //GBA_SPRITE_ENGINE_PROJECT_FARM_H
