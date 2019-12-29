#ifndef GBA_SPRITE_ENGINE_PROJECT_BULLET_H
#define GBA_SPRITE_ENGINE_PROJECT_BULLET_H

#include <deque>

class Animal {

public:
    enum AnimalType { duck, chicken, cow, rabbit, lama, yoda };
    enum AnimalDirection { left, right };

    Animal(AnimalType type, AnimalDirection direction, int velocity );

    void init();
    void tick();

    Sprite* getSprite() { return sprite.get(); }

    /*
     * void setDestination(int distance);
     * bool isOffScreen() { return sprite->isOffScreen(); }
     */

private:
    /*
     *  std::deque<VECTOR> coords;
     *  VECTOR dest;
     */

    std::shared_ptr<Sprite> sprite;
    std::shared_ptr<SpriteBuilder<Sprite>> spriteBuilder;

    bool isInit = 0;

    AnimalType type;
    AnimalDirection direction;
    int velocity;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_BULLET_H
