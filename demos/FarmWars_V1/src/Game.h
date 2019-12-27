//
// Created by Guido Frissaer on 14/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GAME_H
#define GBA_SPRITE_ENGINE_PROJECT_GAME_H

#include <libgba-sprite-engine/scene.h>
#include "FarmBase.h"


class Game : public Scene {
private:
    std::shared_ptr<int> Spawn ;
    std::unique_ptr<Background> bg;
    int scrollX = 0;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    static FarmBase *myFarm;
    static FarmBase *aiFarm;

    Game(std::shared_ptr<GBAEngine> engine);

    void load() override;
    void tick(u16 keys) override;

    int tickCounter = 0;


};


#endif //GBA_SPRITE_ENGINE_PROJECT_GAME_H