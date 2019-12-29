//
// Created by carlp on 29/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_FARMSTATS_H
#define GBA_SPRITE_ENGINE_PROJECT_FARMSTATS_H

class FarmStats {
public:
    FarmStats(){}
    FarmStats(int food, int health);

    void addFood(int food);
    void removeFood(int food);

private:
    int food = 100;
    int health = 1000;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_FARMSTATS_H
