#ifndef GBA_SPRITE_ENGINE_PROJECT_BULLET_H
#define GBA_SPRITE_ENGINE_PROJECT_BULLET_H

#include <deque>
#include "AnimalStats.h"

class Animal {

public:
    enum AnimalType { duck, chicken, cow, rabbit, lama, yoda };
    enum AnimalDirection { left, right };
    Animal(AnimalType type, AnimalDirection direction, int velocity, int position );
    Animal(Sprite *pSprite, AnimalType type, AnimalDirection direction, int i, int position);
    void init();
    void tick();
    Sprite* getSprite() { return sprite.get(); }
    /*
     * void setDestination(int distance);
     * bool isOffScreen() { return sprite->isOffScreen(); }
     */
    const std::shared_ptr<AnimalStats> &getStats() const;
    bool isCollides() const;
    void setCollides(bool collides);
    AnimalType getType() const;
private:
    /*
     *  std::deque<VECTOR> coords;
     *  VECTOR dest;
     */
    bool isInit = 0;
    bool collides = false ;
    int velocity;
    std::shared_ptr<Sprite> sprite;
    std::shared_ptr<AnimalStats> stats;
    AnimalType type;
    AnimalDirection direction;
    std::shared_ptr<SpriteBuilder<Sprite>> spriteBuilder = std::unique_ptr<SpriteBuilder<Sprite>>(new SpriteBuilder<Sprite>);
};


#endif //GBA_SPRITE_ENGINE_PROJECT_BULLET_H
