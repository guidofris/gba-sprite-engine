//
// Created by Guido Frissaer on 05/12/2019.
//

#include "FarmBase.h"
#include "Animal.h"

FarmBase::FarmBase(int direction, int position) : m_direction{direction}, m_position{position} {

}

int FarmBase::getDirection() {
    return m_direction;
}

int FarmBase::getAnimaltype() const {
    return m_animaltype;
}

void FarmBase::setAnimaltype(int animaltype) {
    m_animaltype = animaltype;
}

void FarmBase::spawn() {
    // TODO add the 'correct type of animal' (m_animaltype) to the vector of animals
    switch (m_animaltype)
    {
        case 1:
            break;
        case 6:
            Animal* yoda = new Yoda();
    }
    // TODO add to the vector
}

void FarmBase::move() {
    // TODO: move function => move naar elke animal
    //for each(iel in animals)
    //Animal* yoda = new Yoda();
    //yoda->move(this);
}


