//
// Created by Guido Frissaer on 05/12/2019.
//

#include "../main.h"


std::vector<Background *> IntroScene::backgrounds() {
    return { bg.get() };
}

std::vector<Sprite *> IntroScene::sprites() {
    return {   };
}

void IntroScene::load() {
    //foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(FarmWarPal, sizeof(FarmWarPal)));


    TextStream::instance().setText("PRESS START", 15, 10);

    //engine->getTimer()->start();
    //engine->enqueueMusic(Skyrim,Skyrim_bytes);


   bg = std::unique_ptr<Background>(new Background(1, FarmWarTiles, sizeof(FarmWarTiles), FarmWarMap, sizeof(FarmWarMap)));
   bg.get()->useMapScreenBlock(16);
}

void IntroScene::tick(u16 keys) {
    if(keys & KEY_START) {

        GameController::getInstance()->transitionIntoScene(GameController::Scenes::Main);

        /*
        if(!engine->isTransitioning()) {
            //engine->enqueueSound(zelda_secret_16K_mono, zelda_secret_16K_mono_bytes);
           engine->transitionIntoScene(new MainScene(engine), new FadeOutScene(2));
        }
         */
    }
    /*
    TextStream::instance().setText(engine->getTimer()->to_string(), 18, 1);


    if(pressingAorB && !((keys & KEY_A) || (keys & KEY_B))) {
        engine->getTimer()->toggle();
        pressingAorB = false;
    }

    if(keys & KEY_START) {
        if(!engine->isTransitioning()) {
            //engine->enqueueSound(zelda_secret_16K_mono, zelda_secret_16K_mono_bytes);

            TextStream::instance() << "entered: starting next scene";

            engine->transitionIntoScene(new MainScene(engine), new FadeOutScene(2));
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
     */
}
