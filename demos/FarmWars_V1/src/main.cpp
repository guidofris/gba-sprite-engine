//
// Created by Guido Frissaer on 05/12/2019.
//

#include "main.h"

int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

     auto gameController = GameController::getInstance();

     gameController->Init(engine);

    while (true) {
        engine->update();
        engine->delay(1000);
    }

    return 0;
}