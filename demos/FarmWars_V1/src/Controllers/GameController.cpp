//
// Created by carlp on 28/12/2019.
//

#include "../main.h"

/* Null, because instance will be initialized on demand. */
GameController* GameController::instance = 0;

GameController* GameController::getInstance()
{
    if (instance == 0)
    {
        instance = new GameController();
    }
    return instance;
}

GameController::GameController()
{}

void GameController::setEngine(const std::shared_ptr<GBAEngine> &engine) {
    _engine = engine;
}

const std::shared_ptr<GBAEngine> &GameController::getEngine() const {
    return _engine;
}

void GameController::Init(std::shared_ptr<GBAEngine> engine) {
    _engine = engine;

    introScene = nullptr;

    transitionIntoScene(Scenes::Intro);
}

void GameController::transitionIntoScene(GameController::Scenes scene) {

    switch (scene) {
        case Scenes::Intro :
            introScene = new IntroScene(_engine);
            _engine.get()->setScene(introScene);
            currentScene = introScene;
            break;
        case Scenes::Main :
            mainScene = new MainScene(_engine);
            //if (!_engine.get()->isTransitioning()) _engine.get()->setScene(mainScene);
            _engine->transitionIntoScene(mainScene, new FadeOutScene(10));
            currentScene = mainScene;
            break;
        case Scenes::Select :
            selectAnimalScene = new SelectAnimalScene(_engine);
            //if (!_engine.get()->isTransitioning()) _engine.get()->setScene(selectAnimalScene);
            //_engine.get()->setScene(selectAnimalScene);
            _engine->transitionIntoScene(selectAnimalScene, new FadeOutScene(10));
            currentScene = selectAnimalScene;
            break;
    }



}

