//
// Created by Guido Frissaer on 05/12/2019.
//

#include "../main.h"


std::vector<Background *> SelectAnimalScene::backgrounds() {
    return {};
}

std::vector<Sprite *> SelectAnimalScene::sprites() {
    return { Cursor.get(), Lama.get(), Konijn.get(), Koe.get(), Kip.get(), Eend.get(), Yoda.get() };
}

void SelectAnimalScene::load() {

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    //backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(FarmWarResizedPal, sizeof(FarmWarResizedPal)));

    SpriteBuilder<Sprite> builder;

    Cursor = builder
            .withData(selectTiles, sizeof(selectTiles))
            .withSize(SIZE_32_32)
            .withLocation(getSelectX(), getSelectY())
            .buildPtr();

    Lama = builder
            .withData(lamaTiles, sizeof(lamaTiles))
            .withSize(SIZE_32_32)
            .withAnimated(4, 9)
            .withLocation(50, 50)
            .buildPtr();

    Kip = builder
            .withData(kipTiles, sizeof(kipTiles))
            .withSize(SIZE_32_32)
            .withAnimated(2, 15)
            .withLocation(100, 50)
            .buildPtr();

    Eend = builder
            .withData(eendTiles, sizeof(eendTiles))
            .withSize(SIZE_32_32)
            .withAnimated(2, 15)
            .withLocation(50, 100)
            .buildPtr();

    Konijn = builder
            .withData(konijnTiles, sizeof(konijnTiles))
            .withSize(SIZE_32_32)
            .withAnimated(2, 15)
            .withLocation(100, 100)
            .buildPtr();

    Koe = builder
            .withData(koeTiles, sizeof(koeTiles))
            .withSize(SIZE_32_32)
            .withAnimated(2, 15)
            .withLocation(150, 50)
            .buildPtr();

    Yoda = builder
            .withData(yodaTiles, sizeof(yodaTiles))
            .withSize(SIZE_32_32)
            .withAnimated(2, 15)
            .withLocation(150, 100)
            .buildPtr();
}

void SelectAnimalScene::tick(u16 keys) {

    bool Control = TRUE ;

    if(keys & KEY_LEFT && Control && Cursor->getX() > 50) {
        Cursor->moveTo(getSelectX()-50, getSelectY()) ;
        Control = FALSE ;
    }
    else if(keys & KEY_RIGHT && Control && Cursor->getX() < 150) {
        Cursor->moveTo(getSelectX()+50, getSelectY()) ;
        Control = FALSE ;

    }
    else if(keys & KEY_UP && Control && Cursor->getY() > 50) {
        Cursor->moveTo(getSelectX(), getSelectY()-50) ;
        Control = FALSE ;

    }
    else if(keys & KEY_DOWN && Control && Cursor->getY() < 100) {
        Cursor->moveTo(getSelectX(), getSelectY()+50) ;
        Control = FALSE ;
    }
    else {
        Control = TRUE;
        setSelectX(Cursor->getX());
        setSelectY(Cursor->getY());
    }

    if(Cursor->getX() == 50) {
        if(Cursor->getY() == 50) {
            TextStream::instance().setText("That's a lama", 2, 8);
            TextStream::instance().setText("Cost: 80", 3, 8);
        }
        else if(Cursor->getY() == 100) {
            TextStream::instance().setText("That's a duck", 2, 8);
            TextStream::instance().setText("Cost: 40", 3, 8);
        }
    }
    else if(Cursor->getX() == 100) {
        if(Cursor->getY() == 50) {
            TextStream::instance().setText("That's a chicken", 2, 8);
            TextStream::instance().setText("Cost: 20", 3, 8);
        }
        else if(Cursor->getY() == 100) {
            TextStream::instance().setText("That's a rabbit", 2, 8);
            TextStream::instance().setText("Cost: 10", 3, 8);
        }
    }
    else if(Cursor->getX() == 150) {
        if(Cursor->getY() == 50) {
            TextStream::instance().setText("That's a cow", 2, 8);
            TextStream::instance().setText("Cost: 60", 3, 8);
        }
        else if(Cursor->getY() == 100) {
            TextStream::instance().setText("That's a Yoda", 2, 8);
            TextStream::instance().setText("Cost: 100", 3, 8);
            //TODO: remove velocity
            //GameController::getInstance()->userFarm->addAnimal(Animal::yoda,Animal::AnimalDirection::right,1);

            //std::unique_ptr<Animal> yoda = std::unique_ptr<Animal>(new Animal(Animal::yoda,Animal::AnimalDirection::right,1));
            //GameController::getInstance()->userFarm->animals.push_back(std::move(yoda));

        }
    }

    if(keys & KEY_A) {
        if (Cursor->getX() == 50) {
            if (Cursor->getY() == 50 && GameController::getInstance()->userFarm->stats->getFood() >= 80) {
                GameController::getInstance()->userFarm->addAnimal(Animal::lama, Animal::AnimalDirection::right, 1, position);
                GameController::getInstance()->userFarm->stats->removeFood(80) ;
            } else if (Cursor->getY() == 100 && GameController::getInstance()->userFarm->stats->getFood() >= 40) {
                GameController::getInstance()->userFarm->addAnimal(Animal::duck, Animal::AnimalDirection::right, 1, position);
                GameController::getInstance()->userFarm->stats->removeFood(40) ;
            }
        } else if (Cursor->getX() == 100) {
            if (Cursor->getY() == 50 && GameController::getInstance()->userFarm->stats->getFood() >= 20) {
                GameController::getInstance()->userFarm->addAnimal(Animal::chicken, Animal::AnimalDirection::right, 1, position);
                GameController::getInstance()->userFarm->stats->removeFood(20) ;
            } else if (Cursor->getY() == 100 && GameController::getInstance()->userFarm->stats->getFood() >= 10) {
                GameController::getInstance()->userFarm->addAnimal(Animal::rabbit, Animal::AnimalDirection::right, 1, position);
                GameController::getInstance()->userFarm->stats->removeFood(10) ;
            }
        } else if (Cursor->getX() == 150) {
            if (Cursor->getY() == 50 && GameController::getInstance()->userFarm->stats->getFood() >= 60) {
                GameController::getInstance()->userFarm->addAnimal(Animal::cow, Animal::AnimalDirection::right, 1, position);
                GameController::getInstance()->userFarm->stats->removeFood(60) ;
            } else if (Cursor->getY() == 100 && GameController::getInstance()->userFarm->stats->getFood() >= 100) {
                GameController::getInstance()->userFarm->addAnimal(Animal::yoda, Animal::AnimalDirection::right, 1, position);
                GameController::getInstance()->userFarm->stats->removeFood(100) ;
            }
        }
        GameController::getInstance()->transitionIntoScene(GameController::Scenes::MainNext);
    }
}

void SelectAnimalScene::setSelectX(int selectX) {
    SelectX = selectX;
}

void SelectAnimalScene::setSelectY(int selectY) {
    SelectY = selectY;
}

int SelectAnimalScene::getSelectX() const {
    return SelectX;
}

int SelectAnimalScene::getSelectY() const {
    return SelectY;
}

SelectAnimalScene::~SelectAnimalScene() {
    engine->deleteCurrentScene() ;
}
