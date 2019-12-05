//
// Created by Guido Frissaer on 05/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MENU_H
#define GBA_SPRITE_ENGINE_PROJECT_MENU_H

#include <libgba-sprite-engine/scene.h>

class Menu : public Scene {
private:
    bool pressingAorB = false;
    std::unique_ptr<Sprite> Lama ;
public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    Menu(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    void load() override;
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_MENU_H
