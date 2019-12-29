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
            //MainScene::myFarm->setAnimaltype(1);
        }
        else if(Cursor->getY() == 100) {
            TextStream::instance().setText("That's a duck", 2, 8);
            //MainScene::myFarm->setAnimaltype(2);
        }
    }
    else if(Cursor->getX() == 100) {
        if(Cursor->getY() == 50) {
            TextStream::instance().setText("That's a chicken", 2, 8);
            //MainScene::myFarm->setAnimaltype(3);
        }
        else if(Cursor->getY() == 100) {
            TextStream::instance().setText("That's a bunny", 2, 8);
            //MainScene::myFarm->setAnimaltype(4);
        }
    }
    else if(Cursor->getX() == 150) {
        if(Cursor->getY() == 50) {
            TextStream::instance().setText("That's a cow", 2, 8);
            //MainScene::myFarm->setAnimaltype(5);
        }
        else if(Cursor->getY() == 100) {
            TextStream::instance().setText("That's a Yoda", 2, 8);
            //MainScene::myFarm->setAnimaltype(6);
        }
    }

    if(keys & KEY_A) {
        GameController::getInstance()->transitionIntoScene(GameController::Scenes::MainNext);
    }

    /*
        if(!engine->isTransitioning()) {
            engine->setScene(new MainScene(engine));

            MainScene::myFarm->spawnAnimal();
        }
    */

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
