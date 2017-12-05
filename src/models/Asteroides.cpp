//
//  Asteroides.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 05/12/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "Asteroides.hpp"

Asteroides::Asteroides(Asteroide* asteroide){
    this->courant = asteroide;
    this->suivant = NULL;
}

Asteroides::Asteroides(){
    this->courant = NULL;
    this->suivant = NULL;
}

Asteroides::~Asteroides(){
    if(courant != NULL){
        delete courant;
    }
    courant = NULL;
    if(suivant != NULL){
        delete suivant;
    }
    suivant = NULL;
}

void Asteroides::ajouterAsteroide(Asteroide* aAjouter){
    if(courant == NULL){
        courant = aAjouter;
    } else {
        suivant = new Asteroides(aAjouter);
    }
}
