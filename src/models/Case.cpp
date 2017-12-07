//
//  Case.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 15/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "Case.hpp"

void Case::dessiner(){
    GraphicPrimitives::drawOutlinedRect2D(x, y, width, height, 0.5f, 0.5f, 0.5f);
    if(vaisseau != NULL){
        vaisseau->dessiner();
    }
}

void Case::ajouterVaisseau(int width_fenetre, int height_fenetre){
    if(vaisseau == NULL){
        vaisseau = new Vaisseau(x + (width / 2), -y - (height / 2), width / 2, height / 2, 1.0f, 1, 5, width_fenetre, height_fenetre);
    }
}

Case::~Case(){
    if(vaisseau != NULL){
        delete vaisseau;
    }
    vaisseau = NULL;
}

Missiles* Case::getMissiles(){
    if(vaisseau != NULL){
        return vaisseau->getMissiles();
    }
    return NULL;
}
