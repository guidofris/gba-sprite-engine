//
// Created by Guido Frissaer on 05/12/2019.
//

#include <libgba-sprite-engine/background/text_stream.h>
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

void FarmBase::spawnAnimal() {
    // TODO add the 'correct type of animal' (m_animaltype) to the vector of animals
    Animal* animal;

    switch (m_animaltype)
    {

        case 1:
            animal = new Lama();
            break;
        case 2:
            animal = new Kip();
            break;
        case 3:
            animal = new Koe();
            break;
        case 4:
            animal = new Eend();
            break;
        case 5:
            animal = new Konijn();
            break;
        case 6:
            animal = new Yoda();
            break;
    }

    // TODO add to the vector
    TextStream::instance().setText(std::to_string(m_animaltype), 3, 1);

    animalList.push_back(animal);
}

void FarmBase::move() {
    // TODO: move function => move naar elke animal
    int i=0;
    std::vector<Animal *>::iterator ptr;
    for (ptr = animalList.begin(); ptr < animalList.end(); ptr++)
    {
        (*ptr)->move((this->m_direction));
        //TextStream::instance().setText(std::to_string((*ptr)->getMPosition()), 4, (i * 6)+3);
        i++;
    }
}


