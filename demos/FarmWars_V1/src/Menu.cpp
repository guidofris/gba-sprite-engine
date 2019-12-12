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

#include "../sprites/startscreen.h"


std::vector<Background *> Menu::backgrounds() {
    return { bg.get() };
}

std::vector<Sprite *> Menu::sprites() {
    return {   };
}

void Menu::load() {
    //foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(FarmWarPal, sizeof(FarmWarPal)));

    SpriteBuilder<Sprite> builder;

    TextStream::instance().setText("PRESS START", 15, 10);

    engine->getTimer()->start();
    //engine->enqueueMusic(zelda_music_16K_mono, zelda_music_16K_mono_bytes);

    bg = std::unique_ptr<Background>(new Background(1, FarmWarTiles, sizeof(FarmWarTiles), FarmWarMap, sizeof(FarmWarMap)));
    bg.get()->useMapScreenBlock(16);
}

void Menu::tick(u16 keys) {
    TextStream::instance().setText(engine->getTimer()->to_string(), 18, 1);


    if(pressingAorB && !((keys & KEY_A) || (keys & KEY_B))) {
        engine->getTimer()->toggle();
        pressingAorB = false;
    }

    if(keys & KEY_START) {
        if(!engine->isTransitioning()) {
            //engine->enqueueSound(zelda_secret_16K_mono, zelda_secret_16K_mono_bytes);

            TextStream::instance() << "entered: starting next scene";

            engine->transitionIntoScene(new Game(engine), new FadeOutScene(2));
        }
    } else if(keys & KEY_LEFT) {
        //Lama->flipHorizontally(true);
    } else if(keys & KEY_RIGHT) {
        //Lama->flipHorizontally(false);
    } else if(keys & KEY_UP) {
        //Lama->flipVertically(true);
    } else if(keys & KEY_DOWN) {
        //Lama->flipVertically(false);
    } else if((keys & KEY_A) || (keys & KEY_B)) {
        pressingAorB = true;
    }
}
