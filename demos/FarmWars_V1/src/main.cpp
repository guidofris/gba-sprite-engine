//
// Created by Guido Frissaer on 05/12/2019.
//

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/palette/palette_manager.h>
#include <libgba-sprite-engine/allocator.h>

#include "Menu.h"

/**
 * shared palette extracted from grit
 * ./../grit piskel.png piskel2.png kul.png -ftc -pS -gB8 -O shared.c
 * assumes 8bpp sprites
 */
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define REG_DEBUG_ENABLE (vu16*) 0x4FFF780
#define REG_DEBUG_FLAGS (vu16*) 0x4FFF700
#define REG_DEBUG_STRING (char*) 0x4FFF600

int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    Menu* menuScene = new Menu(engine);
    engine->setScene(menuScene);

    while (true) {
        engine->update();
        engine->delay(1000);
    }

    return 0;
}