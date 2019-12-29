//
// Created by Guido Frissaer on 05/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_INTROSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_INTROSCENE_H

#include "../main.h"



class IntroScene : public Scene {
private:
    bool pressingAorB = false;
    std::unique_ptr<Background> bg;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    IntroScene(std::shared_ptr<GBAEngine> engine) : Scene(engine) { }

    void load() override;
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_INTROSCENE_H
