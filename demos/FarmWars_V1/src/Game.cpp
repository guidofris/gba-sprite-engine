//
// Created by Guido Frissaer on 14/12/2019.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "Game.h"
#include "Select.h"
#include "../sprites/farm.h"

std::vector<Background *> Game::backgrounds() {
    return { bg.get() };
}

std::vector<Sprite *> Game::sprites() {
    return {};
}

void Game::load() {

    //foregroundPalette = std::unique_ptr<ForegroundPaletteManager> new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(FarmLandscapePal, sizeof(FarmLandscapePal)));

    SpriteBuilder <Sprite> builder;

    bg = std::unique_ptr<Background>(new Background(1, FarmLandscapeTiles, sizeof(FarmLandscapeTiles), FarmLandscapeMap, sizeof(FarmLandscapeMap)));
    bg.get()->useMapScreenBlock(16);
}

void Game::tick(u16 keys) {
    if(keys & KEY_SELECT) {
        if(!engine->isTransitioning()) {
            engine->setScene(new Select(engine));
        }
    }

    if(keys & KEY_R && scrollX < 240) {
        scrollX += 3;
    }
    if(keys & KEY_L && scrollX > 0) {
        scrollX -= 3;
    }

    bg.get()->scroll(scrollX, 0);
}
