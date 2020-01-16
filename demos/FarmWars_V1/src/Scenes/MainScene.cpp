//
// Created by Guido Frissaer on 14/12/2019.
//


#include "../main.h"

int i,j;

MainScene::MainScene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {

}


std::vector<Background *> MainScene::backgrounds() {
    return {bg_moon.get(), /*bg_mountain.get()*/ };
}

std::vector<Sprite *> MainScene::sprites() {

    std::vector<Sprite *> sprites;

    for (auto &b : GameController::getInstance()->userFarm->animals) {
        sprites.push_back(b->getSprite());
    }

    for (auto &b : GameController::getInstance()->cpuFarm->animals) {
        sprites.push_back(b->getSprite());
    }

    sprites.push_back(Base.get());
    sprites.push_back(EnemyBase.get());

    return sprites;
}

void MainScene::load() {

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(
            new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(
            new BackgroundPaletteManager(bg_sharedPal, sizeof(bg_sharedPal)));

    engine->enqueueMusic(Skyrim,Skyrim_bytes);

    SpriteBuilder<Sprite> builder;


    bg_moon = std::unique_ptr<Background>(
            new Background(1, bg_moonTiles, sizeof(bg_moonTiles), bg_moonMap, sizeof(bg_moonMap)));
    bg_moon.get()->useMapScreenBlock(16);


    bg_mountain = std::unique_ptr<Background>(
            new Background(1, bg_mountainTiles, sizeof(bg_mountainTiles), bg_mountainMap, sizeof(bg_mountainMap)));
    bg_mountain.get()->useMapScreenBlock(16);
    //bg_current = std::move(bg_moon);

    Base = builder
            .withData(pixelFarmTiles, sizeof(pixelFarmTiles))
            .withSize(SIZE_64_64)
            .withAnimated(1,0)
            .withLocation(2, 94)
            .buildPtr();

    EnemyBase = builder
            .withData(pixelFarmTiles, sizeof(pixelFarmTiles))
            .withSize(SIZE_64_64)
            .withAnimated(1,0)
            .withLocation(160, 94)
            .buildPtr();


    /*
    TextStream::instance().setText("MainScene::load", 1, 1);
    TextStream::instance().setText(std::to_string(i), 2, 1);
    i++;
     */

    /*
    std::unique_ptr<Animal> cow = std::unique_ptr<Animal>(new Animal(Animal::cow,  Animal::AnimalDirection::right, 2) );
    std::unique_ptr<Animal> rabbit = std::unique_ptr<Animal>(new Animal(Animal::rabbit,  Animal::AnimalDirection::right, 4) );
    std::unique_ptr<Animal> duck = std::unique_ptr<Animal>(new Animal(Animal::duck,  Animal::AnimalDirection::left, 1)  );
    std::unique_ptr<Animal> lama = std::unique_ptr<Animal>(new Animal(Animal::lama,  Animal::AnimalDirection::left, 2) );
    std::unique_ptr<Animal> chicken = std::unique_ptr<Animal>(new Animal(Animal::chicken,  Animal::AnimalDirection::left, 3) );

    animals.push_back(std::move(yoda));
    animals.push_back(std::move(rabbit));
    animals.push_back(std::move(duck));
    animals.push_back(std::move(lama));
    animals.push_back(std::move(chicken));
     */

    //yoda->getSprite()->stopAnimating();

}

int animalSelection = 0;
u16 oldKey;

void MainScene::tick(u16 keys) {
    i = 0;
    j = 0 ;
    if (!_initialized)
    {
        EnemyBase->flipHorizontally(true);
        _initialized = true;
        //Base.get()->setVelocity( -1, 0);
    }
    for (auto &b : GameController::getInstance()->userFarm->animals) {
        i++;
        b->init();
        // b->tick();
    }
    for (auto &c : GameController::getInstance()->cpuFarm->animals) {
        j++;
        c->init();
        // b->tick();
    }
    TextStream::instance().setText(std::to_string(i), 2, 1);


    if(keys & KEY_SELECT) {
        for (auto &b : animals) {
            b->getSprite()->stopAnimating();
        }
        GameController::getInstance()->transitionIntoScene(GameController::Scenes::Select, (int) bg_moon_x*(-1));
    }

    if(keys & KEY_START) {
        oldKey = keys;
    }

    if(!keys && oldKey) {
        oldKey = 0;
        animalSelection++;

        switch (animalSelection) {
            case 1:
                GameController::getInstance()->cpuFarm->addAnimal(Animal::rabbit, Animal::AnimalDirection::left, 1, bg_moon_x*(-1)+416);
                break;
            case 2:
                GameController::getInstance()->cpuFarm->addAnimal(Animal::duck, Animal::AnimalDirection::left, 2, bg_moon_x*(-1)+416);
                break;
            case 3:
                GameController::getInstance()->cpuFarm->addAnimal(Animal::yoda, Animal::AnimalDirection::left, 1, bg_moon_x*(-1)+416);
                break;
            case 4:
                GameController::getInstance()->cpuFarm->addAnimal(Animal::chicken, Animal::AnimalDirection::left, 2, bg_moon_x*(-1)+416);
                break;
            case 5:
                GameController::getInstance()->cpuFarm->addAnimal(Animal::cow, Animal::AnimalDirection::left, 3, bg_moon_x*(-1)+416);
                break;
            case 6:
                GameController::getInstance()->cpuFarm->addAnimal(Animal::lama, Animal::AnimalDirection::left, 1, bg_moon_x*(-1)+416);
                break;
            default:
                animalSelection = 0;

        }
        engine.get()->updateSpritesInScene();
    }
/*


    */
    /*
if(keys & KEY_L) {
    for(auto& b : animals) {
        b->setDestination(0 );
        b->tick();
    }
}
 */


    if(keys & KEY_R && bg_moon_x < 240) {
        bg_moon_x += 1;
        bg_mountain_x += 3;
        for (auto &animal : GameController::getInstance()->userFarm->animals) {
            if(animal->isCollides() == false) {
                animal->getSprite()->setVelocity(0, 0);
            }
            else {
                animal->getSprite()->setVelocity(-1, 0);
            }
        }
        for (auto &animal : GameController::getInstance()->cpuFarm->animals) {
            if(animal->isCollides() == false) {
                animal->getSprite()->setVelocity(-2, 0);
            }
            else {
                animal->getSprite()->setVelocity(-1, 0);
            }
        }
    }
    else if(keys & KEY_L && bg_moon_x > 0) {
        bg_moon_x -= 1;
        bg_mountain_x -= 3;
        for (auto &animal : GameController::getInstance()->userFarm->animals) {
            if(animal->isCollides() == false) {
                animal->getSprite()->setVelocity(2, 0);
            }
            else {
                animal->getSprite()->setVelocity(1, 0);
            }
        }
        for (auto &animal : GameController::getInstance()->cpuFarm->animals) {
            if(animal->isCollides() == false) {
                animal->getSprite()->setVelocity(0, 0);
            }
            else {
                animal->getSprite()->setVelocity(1, 0);
            }
        }
    }
    else {
        for (auto &animal : GameController::getInstance()->userFarm->animals) {
            if(animal->isCollides()== false) {
                animal->getSprite()->setVelocity(1, 0);
            }
            else {
                animal->getSprite()->setVelocity(0, 0);
            }
        }
        for (auto &animal : GameController::getInstance()->cpuFarm->animals) {
            if(animal->isCollides()== false) {
                animal->getSprite()->setVelocity(-1, 0);
            }
            else {
                animal->getSprite()->setVelocity(0, 0);
            }
        }
    }
    //bg_moon_x += 0.1;
    bg_moon.get()->scroll((int) bg_moon_x, 0);
    Base.get()->moveTo((int) bg_moon_x*(-1), 94);
    EnemyBase.get()->moveTo((int) bg_moon_x*(-1)+416, 94);

    //TODO re-engineering code, encapsulate the following code into doAnimalsCollideWithFarm
    //GameController::getInstance()->userFarm->doAnimalsCollideWithFarm(EnemyBase.get());
    //GameController::getInstance()->cpuFarm->doAnimalsCollideWithFarm(Base.get());


    int animalCounter = 0;
    bool animalCollided = false;
    for (auto &animal : GameController::getInstance()->userFarm->animals) {
        if (animal.get()->getSprite()->collidesWith(*EnemyBase.get()))
        {
            animal->getSprite()->setVelocity(0,0) ;
            animal->setCollides(true) ;
            //TODO update stats
            if(animal->getStats().get()->getAttackTimeOut() == 0) {
                GameController::getInstance()->userFarm->stats.get()->addFood(
                        animal->getStats().get()->getFoodGain());         // gain food of userFarm by friendly animal
                GameController::getInstance()->cpuFarm->stats.get()->removeHealth(
                        animal->getStats().get()->getAttackDamage()); // lower health of cpuFarm by attackDamage of animal
                animalCollided = true;
                animal->getStats().get()->setAttackTimeOut(100) ;
                break;
            }
            animal->getStats().get()->minAttackTimeOut() ;
        }
        animalCounter++;
        if(animal->getStats().get()->getHealth() == 0) {
            animal.get()->getSprite()->stopAnimating();
            GameController::getInstance()->userFarm->animals.erase(GameController::getInstance()->userFarm->animals.begin()) ;
        }
    }
    for (auto &animal : GameController::getInstance()->cpuFarm->animals) {
        if (animal.get()->getSprite()->collidesWith(*Base.get()))
        {
            animal->getSprite()->setVelocity(0,0) ;
            animal->setCollides(true) ;
            //TODO update stats
            if(animal->getStats().get()->getAttackTimeOut() == 0) {
                GameController::getInstance()->cpuFarm->stats.get()->addFood(
                        animal->getStats().get()->getFoodGain());         // gain food of userFarm by friendly animal
                GameController::getInstance()->userFarm->stats.get()->removeHealth(
                        animal->getStats().get()->getAttackDamage()); // lower health of cpuFarm by attackDamage of animal
                animalCollided = true;
                animal->getStats().get()->setAttackTimeOut(100) ;
                break;
            }
            animal->getStats().get()->minAttackTimeOut() ;
        }
        animalCounter++;
        if(animal->getStats().get()->getHealth() == 0) {
            animal.get()->getSprite()->stopAnimating();
            GameController::getInstance()->cpuFarm->animals.erase(GameController::getInstance()->cpuFarm->animals.begin()) ;
        }
    }
    /*if (animalCollided)
    {
        animal.get()->getSprite()->stopAnimating();
        GameController::getInstance()->userFarm->animals.erase(GameController::getInstance()->userFarm->animals.begin()+animalCounter);
    }
     */
    if(GameController::getInstance()->cpuFarm->stats.get()->getHealth() <= 0 || GameController::getInstance()->userFarm->stats.get()->getHealth() <= 0) {
        GameController::getInstance()->transitionIntoScene(GameController::Scenes::Intro);
    }

    // print Stats
    TextStream::instance().setText(std::to_string(GameController::getInstance()->userFarm->stats.get()->getHealth()), 1, 1);
    TextStream::instance().setText(std::to_string(GameController::getInstance()->cpuFarm->stats.get()->getHealth()), 1, 25);

    TextStream::instance().setText(std::to_string(GameController::getInstance()->userFarm->stats.get()->getFood()), 2, 1);
    TextStream::instance().setText(std::to_string(GameController::getInstance()->cpuFarm->stats.get()->getFood()), 2, 25);


    //EnemyBase


//    bg_mountain.get()->scroll((int)bg_mountain_x, 0);

    //Yoda->moveTo( bg_mountain_x, floor);

    /*
    TextStream::instance() << tickCounter;
    failure_gba("hi");
    log_text("test");
    */
/*

    if (tickCounter >= 1000)
    {
        //myFarm->move();
        tickCounter = 0;
    }
    tickCounter++;
*/
}

