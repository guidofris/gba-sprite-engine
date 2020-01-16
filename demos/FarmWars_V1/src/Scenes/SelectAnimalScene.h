//
// Created by Guido Frissaer on 05/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SELECTANIMALSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_SELECTANIMALSCENE_H

#include "../main.h"

class SelectAnimalScene : public Scene {
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
    int position ;
    //std::shared_ptr<int> Spawn ;
public:
    virtual ~SelectAnimalScene();
    int getSelectX() const;
    int getSelectY() const;
    void setSelectY(int selectY);
    void setSelectX(int selectX);

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    SelectAnimalScene(std::shared_ptr<GBAEngine> engine, int position) : Scene(engine), position(position) {}

    void load() override;
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_SELECTANIMALSCENE_H