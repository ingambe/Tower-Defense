//
//  Vaisseau.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 22/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "Vaisseau.hpp"

void Vaisseau::dessiner(){
    compteur++;
    if(compteur % temps == 0){
        tirerMissile();
    }
    float demi_width = width / 2;
    float demi_height = height / 2;
    GraphicPrimitives::drawFillTriangle2D(x + demi_width, y, x - demi_width, y + demi_height, x - demi_width, y - demi_height, 0.5f, 0.5f, 0.5f);
    Missiles *iteration = missiles;
    while (iteration != NULL && iteration->courant != NULL) {
        iteration->courant->dessiner();
        if(iteration->suivant != NULL && iteration->suivant->courant != NULL && !(iteration->suivant->courant->isVisible())){
            delete iteration->suivant;
            iteration->suivant = NULL;
        }
        iteration = iteration->suivant;
    }
}

void Vaisseau::tirerMissile(){
    Missiles *iterMissiles = missiles;
    while(iterMissiles != NULL && iterMissiles->courant != NULL){
        iterMissiles = iterMissiles->suivant;
    }
    if(iterMissiles == NULL){
        iterMissiles = new Missiles(new Missile(x + width / 2, y, puissance, vitesse, width_fenetre, height_fenetre));
    } else {
        iterMissiles->courant = new Missile(x + width / 2, y, puissance, vitesse, width_fenetre, height_fenetre);
    }
}
