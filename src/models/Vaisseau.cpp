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
    if(compteur % (temps * 100) == 0){
        std::cout << " compteur : " << compteur << " temps : " << temps * 100 << std::endl;
        tirerMissile();
    }
    float demi_width = width / 2;
    float demi_height = height / 2;
    GraphicPrimitives::drawFillTriangle2D(x + demi_width, y, x - demi_width, y + demi_height, x - demi_width, y - demi_height, 0.5f, 0.5f, 0.5f);
    Missiles *iteration = missiles;
    while (iteration != NULL && iteration->courant != NULL) {
        iteration->courant->dessiner();
        iteration = iteration->suivant;
    }
}

void Vaisseau::tirerMissile(){
    Missiles *iterMissiles = missiles;
    while(iterMissiles->suivant != NULL && iterMissiles->courant != NULL){
        iterMissiles = iterMissiles->suivant;
    }
    if(iterMissiles->suivant == NULL){
        iterMissiles->suivant = new Missiles(new Missile(x + width / 2, y, puissance, vitesse, width_fenetre, height_fenetre));
    } else {
        iterMissiles->courant = new Missile(x + width / 2, y, puissance, vitesse, width_fenetre, height_fenetre);
    }
}
