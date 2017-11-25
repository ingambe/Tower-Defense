//
//  Missiles.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 25/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "Missiles.hpp"

Missiles::Missiles(Missile* missile){
    this->courant = missile;
    this->suivant = NULL;
}

Missiles::Missiles(){
    this->courant = NULL;
    this->suivant = NULL;
}



Missiles::~Missiles(){
    if(courant != NULL){
        delete courant;
    }
    courant = NULL;
    if(suivant != NULL){
        delete suivant;
    }
    suivant = NULL;
}

void Missiles::ajouterMissile(Missile *missile){
    if(courant == NULL){
        courant = missile;
    } else {
        suivant = new Missiles(missile);
    }
}
