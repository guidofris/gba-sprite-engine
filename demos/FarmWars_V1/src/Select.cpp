//
// Created by Guido Frissaer on 05/12/2019.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "Menu.h"
#include "Select.h"
#include "Game.h"

#include "../sprites/lama_sprite.h"
#include "../sprites/eend_sprite.h"
#include "../sprites/kip_sprite.h"
#include "../sprites/konijn_sprite.h"
#include "../sprites/startscreen.h"
#include "../sprites/koe_sprite.h"
#include "../sprites/yoda_sprite.h"
#include "../sprites/select_sprite.h"
#include "../sprites/sharedpal.h"
#include "FarmBase.h"

std::vector<Background *> Select::backgrounds() {
    return {};
}

std::vector<Sprite *> Select::sprites() {
    return { Cursor.get(), Lama.get(), Konijn.get(), Koe.get(), Kip.get(), Eend.get(), Yoda.get() };
}

void Select::load() {

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

void Select::tick(u16 keys) {
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
<<<<<<< HEAD
            gMyFarm->setAnimaltype(1);
        }
        else if(Cursor->getY() == 100) {
            TextStream::instance().setText("That's a duck", 2, 8);
            gMyFarm->setAnimaltype(2);
=======
            Game::myFarm->setAnimaltype(1);
        }
        else if(Cursor->getY() == 100) {
            TextStream::instance().setText("That's a duck", 2, 8);
            Game::myFarm->setAnimaltype(2);
>>>>>>> moving animals from base (draft)
        }
    }
    else if(Cursor->getX() == 100) {
        if(Cursor->getY() == 50) {
            TextStream::instance().setText("That's a chicken", 2, 8);
<<<<<<< HEAD
            gMyFarm->setAnimaltype(3);
        }
        else if(Cursor->getY() == 100) {
            TextStream::instance().setText("That's a bunny", 2, 8);
            gMyFarm->setAnimaltype(4);
=======
            Game::myFarm->setAnimaltype(3);
        }
        else if(Cursor->getY() == 100) {
            TextStream::instance().setText("That's a bunny", 2, 8);
            Game::myFarm->setAnimaltype(4);
>>>>>>> moving animals from base (draft)
        }
    }
    else if(Cursor->getX() == 150) {
        if(Cursor->getY() == 50) {
            TextStream::instance().setText("That's a cow", 2, 8);
<<<<<<< HEAD
            gMyFarm->setAnimaltype(5);
        }
        else if(Cursor->getY() == 100) {
            TextStream::instance().setText("That's a Yoda", 2, 8);
            gMyFarm->setAnimaltype(6);
=======
            Game::myFarm->setAnimaltype(5);
        }
        else if(Cursor->getY() == 100) {
            TextStream::instance().setText("That's a Yoda", 2, 8);
            Game::myFarm->setAnimaltype(6);
>>>>>>> moving animals from base (draft)
        }
    }

    if(keys & KEY_A) {
        if(!engine->isTransitioning()) {
<<<<<<< HEAD
            //TODO: choose animal

            engine->setScene(new Game(engine));

            gMyFarm->spawn();
=======
            engine->setScene(new Game(engine));

            Game::myFarm->spawnAnimal();
>>>>>>> moving animals from base (draft)
        }
    }
}

void Select::setSelectX(int selectX) {
    SelectX = selectX;
}

void Select::setSelectY(int selectY) {
    SelectY = selectY;
}

int Select::getSelectX() const {
    return SelectX;
}

int Select::getSelectY() const {
    return SelectY;
}