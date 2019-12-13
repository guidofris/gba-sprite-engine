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
    return { Lama.get(), Konijn.get(), Koe.get(), Kip.get(), Eend.get(), Yoda.get(), Select.get() };
}

void Game::load() {

    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    //backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(FarmWarResizedPal, sizeof(FarmWarResizedPal)));

    SpriteBuilder<Sprite> builder;

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

    Select = builder
            .withData(selectTiles, sizeof(selectTiles))
            .withSize(SIZE_32_32)
            .withLocation(getSelectX(), getSelectY())
            .buildPtr();
}

void Game::tick(u16 keys) {

    if(keys & KEY_LEFT) {
        setSelectX(getSelectX() - 50)  ;
        Select->moveTo(getSelectX(), getSelectY()) ;
    }
    else if(keys & KEY_RIGHT) {
        setSelectX(getSelectX() + 50) ;
        Select->moveTo(getSelectX(), getSelectY()) ;
    }
    else if(keys & KEY_UP) {
        setSelectY(getSelectY() - 50) ;
        Select->moveTo(getSelectX(), getSelectY()) ;
    }
    else if(keys & KEY_DOWN) {
        setSelectY(getSelectY() + 50) ;
        Select->moveTo(getSelectX(), getSelectY()) ;
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
