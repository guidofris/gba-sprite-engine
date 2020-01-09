//
// Created by carlp on 29/12/2019.
//

#include "../main.h"

Farm::Farm() {
    stats = std::unique_ptr<FarmStats>(new FarmStats(100,1000));
}

void Farm::addAnimal(Animal::AnimalType type, Animal::AnimalDirection direction, int velocity) {
    /* TODO: search in animals vector for this animal-type
     * if the animal exists use this sprite to create a new animal
    */
    Sprite *sprite = nullptr;
    for(auto& b : animals) {
        if (b->getType() == type)
        {
            sprite = b->getSprite();
            break;
        }
    }

    if (sprite == nullptr)
    {
        std::unique_ptr<Animal> animal = std::unique_ptr<Animal>(new Animal(type,direction,velocity));
        animals.push_back(std::move(animal));
    }
    else
    {
        std::unique_ptr<Animal> animal = std::unique_ptr<Animal>(new Animal(sprite, type,direction,velocity));
        animals.push_back(std::move(animal));
    }

}

