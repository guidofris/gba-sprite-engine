//
// Created by Guido Frissaer on 05/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SELECT_H
#define GBA_SPRITE_ENGINE_PROJECT_SELECT_H

#include <libgba-sprite-engine/scene.h>
#include "Game.h"

class Select : public Scene {
private:
    std::unique_ptr<Sprite> Lama ;
    std::unique_ptr<Sprite> Eend ;
    std::unique_ptr<Sprite> Kip ;
    std::unique_ptr<Sprite> Konijn ;
    std::unique_ptr<Sprite> Koe ;
    std::unique_ptr<Sprite> Yoda ;
    std::unique_ptr<Sprite> Cursor ;
    int SelectX = 50;
    int SelectY = 50;
    std::shared_ptr<int> Spawn ;

public:
    int getSelectX() const;
    int getSelectY() const;
    void setSelectY(int selectY);
    void setSelectX(int selectX);

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    Select(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    void load() override;
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_SELECT_H