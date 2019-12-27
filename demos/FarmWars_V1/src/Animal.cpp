//
// Created by Guido Frissaer on 05/12/2019.
//

#include "Animal.h"

void Animal::attack(Animal *enemy) {
    enemy->m_health -= m_damage;
}

bool Animal::isDead() {
    return m_health <= 0;
}

bool Animal::isAlive() {
    return m_health >= 0;
}

void Animal::move(int position) {
    m_position += (position * m_speed);
}

int Animal::getMPosition() const {
    return m_position;
}

void Animal::setMPosition(int mPosition) {
    m_position = mPosition;
}

