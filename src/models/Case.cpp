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
        vaisseau = new Vaisseau(x + (width / 2), -y - (height / 2), width / 2, height / 2, 3, 1.0f, 1, 5, width_fenetre, height_fenetre);
    }
}

Case::~Case(){
    if(vaisseau != NULL){
        delete vaisseau;
    }
    vaisseau = NULL;
}

/**
 *  Gestion colision avec missile et vaisseaux
 **/
void Case::colision(Asteroide* asteroide, int lignes){
    if(vaisseau != NULL){
        /**
         * Gestion colision missiles :
         **/
        // on recupere les missiles du vaisseau
        std::queue<Missile*>* missiles = vaisseau->getMissiles();
        // file qui gardera les missiles a ne pas supprimer
        std::queue<Missile*>* iteration = new std::queue<Missile*>();
        // on parcour la files des missiles pour les dessiner un a un
        while (!missiles->empty()) {
            Missile* missile = missiles->front();
            if(asteroide->colision(missile, lignes)){
                asteroide->degatMissile(missile->getDegat());
                delete missile;
                missile = NULL;
            } else {
                iteration->push(missile);
            }
            missiles->pop();
        }
        if(missiles != NULL){
            delete missiles;
        }
        missiles = NULL;
        vaisseau->setMissiles(iteration);
        /**
         * Gestion colision vaisseaux :
         **/
        if(vaisseau->colisionAsteroide(asteroide)){
            vaisseau->retirerVie(asteroide->getDegat());
            if(vaisseau->getVie() <= 0){
                delete vaisseau;
                vaisseau = NULL;
            }
        }
    }
}
