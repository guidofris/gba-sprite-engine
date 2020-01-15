//
// Created by carlp on 28/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MAIN_H
#define GBA_SPRITE_ENGINE_PROJECT_MAIN_H

#include <vector>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include <libgba-sprite-engine/background/background.h>
#include <libgba-sprite-engine/background/text_stream.h>

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>

#include <libgba-sprite-engine/gba/tonc_memdef.h>

#include "../sprites/lama.c"
#include "../sprites/eend.c"
#include "../sprites/kip.c"
#include "../sprites/konijn.c"
#include "../sprites/koe.c"
#include "../sprites/yoda.c"
#include "../sprites/select.c"
#include "../sprites/turret.c"
#include "../sprites/pixelFarm.c"

#include "../sprites/shared.c"

#include "Controllers/GameController.h"

#include "../sprites/startscreen.h"

#include "../sprites/bg_mountain.c"
#include "../sprites/bg_moon.c"
#include "../sprites/bg_shared.c"

#include "Models/Animal.h"
#include "Models/AnimalStats.h"
#include "Models/Farm.h"
#include "Models/FarmStats.h"

#include "../audio/Skyrim.h"


#endif //GBA_SPRITE_ENGINE_PROJECT_MAIN_H
