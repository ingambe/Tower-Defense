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
    std::cout << "compteur : " << compteur << std::endl;
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
    
}
