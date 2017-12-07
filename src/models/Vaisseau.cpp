//
//  Vaisseau.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 22/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "Vaisseau.hpp"

void Vaisseau::dessiner(){
    float demi_width = width / 2;
    float demi_height = height / 2;
    GraphicPrimitives::drawFillTriangle2D(x + demi_width, y, x - demi_width, y + demi_height, x - demi_width, y - demi_height, 0.5f, 0.5f, 0.5f);
    // temps en seconde, compteur incremente toute les 0,01s
    if(compteur % (temps * 100) == 0){
        tirerMissile();
    }
    compteur++;
    // on parcour la liste des missiles pour les dessiner un a un
    Missiles *iteration = missiles;
    while (iteration != NULL && iteration->courant != NULL) {
        iteration->courant->dessiner();
        // si l'element suivant n'est plus visible alors on le delete
        if(iteration->suivant != NULL && iteration->suivant->courant != NULL && !(iteration->suivant->courant->isVisible())){
            delete iteration->suivant;
            iteration->suivant = NULL;
        }
        iteration = iteration->suivant;
    }
}

/*
 *  On ajoute un missile a la file des missiles
 */
void Vaisseau::tirerMissile(){
    // si c'est le premier missile tiree
    if(missiles->courant == NULL){
        missiles->courant = new Missile(x + width / 2, y, puissance, vitesse, width_fenetre, height_fenetre);
    } else {
        // sinon on creer un nouvel element de la file
        Missiles *nouveauElement = new Missiles(new Missile(x + width / 2, y, puissance, vitesse, width_fenetre, height_fenetre));
        nouveauElement->suivant = missiles;
        missiles = nouveauElement;
    }
}

Vaisseau::~Vaisseau(){
    if(missiles != NULL){
        delete missiles;
    }
    missiles = NULL;
}

Missiles* Vaisseau::getMissiles(){
    return missiles;
}
