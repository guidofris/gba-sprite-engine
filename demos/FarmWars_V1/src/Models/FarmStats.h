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
    void removeHealth(int health);

private:
    int _food = 100;
public:
    int getFood() const;

private:
    int _health = 1000;
public:
    int getHealth() const;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_FARMSTATS_H
