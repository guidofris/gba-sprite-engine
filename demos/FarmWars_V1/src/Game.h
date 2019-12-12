//
// Created by Guido Frissaer on 05/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GAME_H
#define GBA_SPRITE_ENGINE_PROJECT_GAME_H

#include <libgba-sprite-engine/scene.h>

class Game : public Scene {
private:
    std::unique_ptr<Sprite> Lama ;
    std::unique_ptr<Sprite> Eend ;
    std::unique_ptr<Sprite> Kip ;
    std::unique_ptr<Sprite> Konijn ;
    std::unique_ptr<Sprite> Koe ;
    std::unique_ptr<Sprite> Yoda ;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    Game(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    void load() override;
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_GAME_H