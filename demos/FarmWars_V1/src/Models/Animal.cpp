//
// Created by Wouter Groeneveld on 09/08/18.
//

#include "../main.h"
#include "Animal.h"

/*
 * void Animal::setDestination(int distance) {
    return;
    auto currentPos = sprite->getPosAsVector();

    VECTOR destination;
    destination.x = sprite->getX() + distance;
    destination.y = sprite->getY();

    this->dest = destination;
    this->coords = currentPos.bresenhamLineTo(destination);
}

void Animal::tick() {
    return;
    if(coords.empty()) {
        return;
    }

    sprite->moveTo(coords.front());
    coords.pop_front();
}
*/

Animal::Animal(AnimalType type, AnimalDirection direction, int velocity ): type(type), direction(direction), velocity(velocity) {

    spriteBuilder = std::unique_ptr<SpriteBuilder<Sprite>>(new SpriteBuilder<Sprite>);

    switch( type )
    {
        case AnimalType::duck:
            sprite = spriteBuilder
                    ->withData(eendTiles, sizeof(eendTiles))
                    .withSize(SIZE_32_32)
                    .withAnimated(2, 15)
                    .withLocation(32, 133)
                    .buildPtr();

            break;

        case AnimalType::cow:
            sprite = spriteBuilder
                    ->withData(koeTiles, sizeof(koeTiles))
                    .withSize(SIZE_32_32)
                    .withAnimated(2, 15)
                    .withLocation(-32, 131)
                    .buildPtr();
            break;

        case AnimalType::lama:
            sprite = spriteBuilder
                    ->withData(lamaTiles, sizeof(lamaTiles))
                    .withSize(SIZE_32_32)
                    .withAnimated(2, 15)
                    .withLocation(240, 127)
                    .buildPtr();
            break;

        case AnimalType::rabbit:
            sprite = spriteBuilder
                    ->withData(konijnTiles, sizeof(konijnTiles))
                    .withSize(SIZE_32_32)
                    .withAnimated(2, 15)
                    .withLocation(-32, 135)
                    .buildPtr();
            break;

        case AnimalType::chicken:
            sprite = spriteBuilder
                    ->withData(kipTiles, sizeof(kipTiles))
                    .withSize(SIZE_32_32)
                    .withAnimated(2, 15)
                    .withLocation(-32, 135)
                    .buildPtr();
            break;

        case AnimalType::yoda:
            sprite = spriteBuilder
                           ->withData(yodaTiles, sizeof(yodaTiles))
                           .withSize(SIZE_32_32)
                           .withAnimated(2, 15)
                           .withLocation(-32, 127)
                           .buildPtr();
            break;
    }

}

void Animal::init() {
    if (isInit) return;

    if (direction == AnimalDirection::left)
    {
        sprite->flipHorizontally(true);
        sprite->setVelocity(velocity * -1, 0);
    }
    else
    {
        sprite->setVelocity(velocity , 0);
    }

    isInit = 1;
}

