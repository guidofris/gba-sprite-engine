//
// Created by Guido Frissaer on 05/12/2019.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "Menu.h"
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

std::vector<Background *> Game::backgrounds() {
    return {};
}

std::vector<Sprite *> Game::sprites() {
    return { Select.get(), Lama.get(), Konijn.get(), Koe.get(), Kip.get(), Eend.get(), Yoda.get() };
}

void Game::load() {

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    //backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(FarmWarResizedPal, sizeof(FarmWarResizedPal)));

    SpriteBuilder<Sprite> builder;

    Select = builder
            .withData(selectTiles, sizeof(selectTiles))
            .withSize(SIZE_32_32)
            .withLocation(getSelectX(), getSelectY())
            .buildPtr();

    Lama = builder
            .withData(lamaTiles, sizeof(lamaTiles))
            .withSize(SIZE_32_32)
            .withAnimated(6, 3)
            .withLocation(50, 50)
            .buildPtr();

    Kip = builder
            .withData(kipTiles, sizeof(kipTiles))
            .withSize(SIZE_32_32)
            .withAnimated(2, 9)
            .withLocation(100, 50)
            .buildPtr();

    Eend = builder
            .withData(eendTiles, sizeof(eendTiles))
            .withSize(SIZE_32_32)
            .withAnimated(2, 9)
            .withLocation(50, 100)
            .buildPtr();

    Konijn = builder
            .withData(konijnTiles, sizeof(konijnTiles))
            .withSize(SIZE_32_32)
            .withAnimated(7, 3)
            .withLocation(100, 100)
            .buildPtr();

    Koe = builder
            .withData(koeTiles, sizeof(koeTiles))
            .withSize(SIZE_32_32)
            .withAnimated(5, 10)
            .withLocation(150, 50)
            .buildPtr();

    Yoda = builder
            .withData(yodaTiles, sizeof(yodaTiles))
            .withSize(SIZE_32_32)
            .withAnimated(5, 3)
            .withLocation(150, 100)
            .buildPtr();
}

void Game::tick(u16 keys) {
    bool Control = TRUE ;

    if(keys & KEY_LEFT && Control && Select->getX() > 50) {
        Select->moveTo(getSelectX()-50, getSelectY()) ;
        Control = FALSE ;
    }
    else if(keys & KEY_RIGHT && Control && Select->getX() < 150) {
        Select->moveTo(getSelectX()+50, getSelectY()) ;
        Control = FALSE ;

    }
    else if(keys & KEY_UP && Control && Select->getY() > 50) {
        Select->moveTo(getSelectX(), getSelectY()-50) ;
        Control = FALSE ;

    }
    else if(keys & KEY_DOWN && Control && Select->getY() < 100) {
        Select->moveTo(getSelectX(), getSelectY()+50) ;
        Control = FALSE ;
    }
    else {
        Control = TRUE;
        setSelectX(Select->getX());
        setSelectY(Select->getY());
    }

    if(keys & KEY_A) {
        if(Select->getX() == 50) {
            if(Select->getY() == 50) {
                TextStream::instance().setText("That's a lama", 2, 8);
            }
            else if(Select->getY() == 100) {
                TextStream::instance().setText("That's a duck", 2, 8);
            }
        }
        else if(Select->getX() == 100) {
            if(Select->getY() == 50) {
                TextStream::instance().setText("That's a chicken", 2, 8);
            }
            else if(Select->getY() == 100) {
                TextStream::instance().setText("That's a bunny", 2, 8);
            }
        }
        else if(Select->getX() == 150) {
            if(Select->getY() == 50) {
                TextStream::instance().setText("That's a cow", 2, 8);
            }
            else if(Select->getY() == 100) {
                TextStream::instance().setText("That's a Yoda", 2, 8);
            }
        }
    }
}

void Game::setSelectX(int selectX) {
    SelectX = selectX;
}

void Game::setSelectY(int selectY) {
    SelectY = selectY;
}

int Game::getSelectX() const {
    return SelectX;
}

int Game::getSelectY() const {
    return SelectY;
}
