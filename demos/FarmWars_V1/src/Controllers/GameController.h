//
// Created by carlp on 28/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GAMECONTROLLER_H
#define GBA_SPRITE_ENGINE_PROJECT_GAMECONTROLLER_H

#include "../main.h"
#include "../Scenes/IntroScene.h"
#include "../Scenes/MainScene.h"
#include "../Scenes/SelectAnimalScene.h"
#include "../Models/Farm.h"

class GameController {
public:
    GameController();
    IntroScene* introScene;
    MainScene* mainScene_First;
    SelectAnimalScene* selectAnimalScene;
    std::unique_ptr<Farm> userFarm = std::unique_ptr<Farm>(new Farm());
    std::unique_ptr<Farm> cpuFarm = std::unique_ptr<Farm>(new Farm());
    static GameController* getInstance();
    void Init(std::shared_ptr<GBAEngine> engine);
    enum Scenes { Intro, Main, MainNext, Select };
    void transitionIntoScene (Scenes scenes, int Position=0);
    const std::shared_ptr<GBAEngine> &getEngine() const;
    void setEngine(const std::shared_ptr<GBAEngine> &engine);

private:
    static GameController* instance;
    Scene*  currentScene;
    /* Private constructor to prevent instancing. */
    std::shared_ptr<GBAEngine> _engine;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_GAMECONTROLLER_H
