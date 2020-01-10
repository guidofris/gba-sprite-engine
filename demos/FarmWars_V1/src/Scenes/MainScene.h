//
// Created by Guido Frissaer on 14/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MAINSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_MAINSCENE_H

#include "../main.h"
#include "../Models/Animal.h"

class MainScene : public Scene {
private:
    std::shared_ptr<int> Spawn ;

    std::shared_ptr<Background> bg_current;

    std::shared_ptr<Background> bg_moon;
    double bg_moon_x = 0;

    std::shared_ptr<Background> bg_mountain;
    double bg_mountain_x = 0;

    std::shared_ptr<Background> bg_flowers;
    double bg_flowers_x = 0;

    int selectMode = 0;

    std::unique_ptr<Sprite> Base ;
    std::unique_ptr<Sprite> EnemyBase ;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    MainScene(std::shared_ptr<GBAEngine> engine);

    void load() override;
    void tick(u16 keys) override;

    std::vector<std::shared_ptr<Animal>> animals;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_MAINSCENE_H