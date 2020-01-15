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

Animal::Animal(AnimalType type, AnimalDirection direction, int velocity, int position ): type(type), direction(direction), velocity(velocity) {

    //spriteBuilder = std::unique_ptr<SpriteBuilder<Sprite>>(new SpriteBuilder<Sprite>);

    switch( type )
    {
        case AnimalType::rabbit:
            sprite = spriteBuilder
                    ->withData(konijnTiles, sizeof(konijnTiles))
                    .withSize(SIZE_32_32)
                    .withAnimated(2, 15)
                    .withLocation(position, 135)
                    .buildPtr();

            stats = std::unique_ptr<AnimalStats>(new AnimalStats(10,10,10,12));
            break;

        case AnimalType::chicken:
            sprite = spriteBuilder
                    ->withData(kipTiles, sizeof(kipTiles))
                    .withSize(SIZE_32_32)
                    .withAnimated(2, 15)
                    .withLocation(position, 135)
                    .buildPtr();

            stats = std::unique_ptr<AnimalStats>(new AnimalStats(20,20,20,24));
            break;

        case AnimalType::duck:
            sprite = spriteBuilder
                    ->withData(eendTiles, sizeof(eendTiles))
                    .withSize(SIZE_32_32)
                    .withAnimated(2, 15)
                    .withLocation(position, 133)
                    .buildPtr();

            stats = std::unique_ptr<AnimalStats>(new AnimalStats(40,40,40,48));
            break;

        case AnimalType::cow:
            sprite = spriteBuilder
                    ->withData(koeTiles, sizeof(koeTiles))
                    .withSize(SIZE_32_32)
                    .withAnimated(2, 15)
                    .withLocation(position, 131)
                    .buildPtr();

            stats = std::unique_ptr<AnimalStats>(new AnimalStats(60,60,60,72));
            break;

        case AnimalType::lama:
            sprite = spriteBuilder
                    ->withData(lamaTiles, sizeof(lamaTiles))
                    .withSize(SIZE_32_32)
                    .withAnimated(2, 15)
                    .withLocation(position, 127)
                    .buildPtr();

            stats = std::unique_ptr<AnimalStats>(new AnimalStats(80,80,80,96));
            break;

        case AnimalType::yoda:
            sprite = spriteBuilder
                           ->withData(yodaTiles, sizeof(yodaTiles))
                           .withSize(SIZE_32_32)
                           .withAnimated(2, 15)
                           .withLocation(position, 127)
                           .buildPtr();

            stats = std::unique_ptr<AnimalStats>(new AnimalStats(100,100,100,120));
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

Animal::AnimalType Animal::getType() const {
    return type;
}


Animal::Animal(Sprite *pSprite, AnimalType type, AnimalDirection direction, int i, int position) : type(type), direction(direction), velocity(i) {
    sprite = spriteBuilder
            ->buildWithDataOf(*pSprite);

    sprite->makeAnimated(2, 15);
    sprite->moveTo(position, 127);
    sprite->update();
}



