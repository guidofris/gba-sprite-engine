//
// Created by carlp on 28/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GAMECONTROLLER_H
#define GBA_SPRITE_ENGINE_PROJECT_GAMECONTROLLER_H

#include "../main.h"
#include "../Scenes/IntroScene.h"
#include "../Scenes/MainScene.h"
#include "../Scenes/SelectAnimalScene.h"

class GameController {
public:
    GameController();

    static GameController* getInstance();

    void Init(std::shared_ptr<GBAEngine> engine);

    IntroScene* introScene;
    MainScene* mainScene;
    SelectAnimalScene* selectAnimalScene;

    Scene*  currentScene;

    enum Scenes { Intro, Main, Select };

    void transitionIntoScene (Scenes scenes);

private:
    static GameController* instance;

    /* Private constructor to prevent instancing. */

    std::shared_ptr<GBAEngine> _engine;
public:
    const std::shared_ptr<GBAEngine> &getEngine() const;

public:
    void setEngine(const std::shared_ptr<GBAEngine> &engine);

};


#endif //GBA_SPRITE_ENGINE_PROJECT_GAMECONTROLLER_H
