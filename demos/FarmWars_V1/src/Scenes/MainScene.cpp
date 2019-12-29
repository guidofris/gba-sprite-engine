//
// Created by Guido Frissaer on 14/12/2019.
//


#include "../main.h"
#include "MainScene.h"


const int floor = 127;
int i;

std::vector<Background *> MainScene::backgrounds() {
    return { bg_moon.get(), /*bg_mountain.get()*/ };
}

std::vector<Sprite *> MainScene::sprites() {
    /*
    if (Yoda) return { Yoda->getSprite() };

    return {};
    */

    if (selectMode == 1)
    {
        return {};
    }
    else
    {
        std::vector<Sprite*> sprites;
        for(auto& b : animals) {
            sprites.push_back(b->getSprite());
        }
        return sprites;
    }

}

void MainScene::load() {

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(bg_sharedPal, sizeof(bg_sharedPal)));

    SpriteBuilder<Sprite> builder;

    bg_moon = std::unique_ptr<Background>(new Background(1, bg_moonTiles, sizeof(bg_moonTiles), bg_moonMap, sizeof(bg_moonMap)));
    bg_moon.get()->useMapScreenBlock(16);

    /*
    bg_mountain = std::unique_ptr<Background>(new Background(2, bg_mountainTiles, sizeof(bg_mountainTiles), bg_mountainMap, sizeof(bg_mountainMap)));
    bg_mountain.get()->useMapScreenBlock(16);
    bg_current = std::move(bg_moon);
     */

    /*
    TextStream::instance().setText("MainScene::load", 1, 1);
    TextStream::instance().setText(std::to_string(i), 2, 1);
    i++;
     */

    std::unique_ptr<Animal> yoda = std::unique_ptr<Animal>(new Animal(Animal::yoda,Animal::AnimalDirection::right,1));
    std::unique_ptr<Animal> cow = std::unique_ptr<Animal>(new Animal(Animal::cow,  Animal::AnimalDirection::right, 2) );
    std::unique_ptr<Animal> rabbit = std::unique_ptr<Animal>(new Animal(Animal::rabbit,  Animal::AnimalDirection::right, 4) );

    std::unique_ptr<Animal> duck = std::unique_ptr<Animal>(new Animal(Animal::duck,  Animal::AnimalDirection::left, 1)  );
    std::unique_ptr<Animal> lama = std::unique_ptr<Animal>(new Animal(Animal::lama,  Animal::AnimalDirection::left, 2) );
    std::unique_ptr<Animal> chicken = std::unique_ptr<Animal>(new Animal(Animal::chicken,  Animal::AnimalDirection::left, 3) );

    animals.push_back(std::move(cow));
    animals.push_back(std::move(yoda));
    animals.push_back(std::move(rabbit));
    animals.push_back(std::move(duck));
    animals.push_back(std::move(lama));
    animals.push_back(std::move(chicken));

    //yoda->getSprite()->stopAnimating();

}

void MainScene::tick(u16 keys) {

    for(auto& b : animals) {
        b->init();
       // b->tick();
    }

    if(keys & KEY_SELECT) {
        for(auto& b : animals) {
            b->getSprite()->stopAnimating();
        }
        GameController::getInstance()->transitionIntoScene(GameController::Scenes::Select);
    }
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

    }
    if(keys & KEY_L && bg_moon_x > 0) {
        bg_moon_x -= 1;
        bg_mountain_x -= 3;

    }
    bg_moon_x += 0.1;
    bg_moon.get()->scroll((int)bg_moon_x, 0);



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

MainScene::MainScene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {

}

