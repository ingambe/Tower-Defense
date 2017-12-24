//
//  Vaisseau.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 22/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "Vaisseau.hpp"

void Vaisseau::dessiner(){
    // utile pour centrer les vaisseaux
    float demi_width = width / 2;
    float demi_height = height / 2;
    // max 0.0f au cas ou pour pas descendre en dessous de 0.1f (visible)
    GraphicPrimitives::drawFillTriangle2D(x + demi_width, y, x - demi_width, y + demi_height, x - demi_width, y - demi_height, std::max(0.0f, couleur.getRed() - (0.2f * degatSubit)), std::max(0.0f, couleur.getGreen() - (0.2f * degatSubit)), std::max(0.0f, couleur.getBlue() - (0.2f * degatSubit)));
    // temps en seconde, compteur incremente toute les 0,01s
    if(compteur % (temps * 10) == 0){
        tirerMissile();
    }
    compteur++;
    // file qui gardera les missiles a ne pas supprimer
    std::queue<Missile*>* iteration = new std::queue<Missile*>();
    // on parcour la files des missiles pour les dessiner un a un
    while (!missiles->empty()) {
        if(!missiles->front()->isASupprimer()){
            missiles->front()->dessiner();
            iteration->push(missiles->front());
        } else {
            if(missiles->front() != NULL){
                delete missiles->front();
            }
        }
        missiles->pop();
    }
    if(missiles != NULL){
        delete missiles;
    }
    missiles = iteration;
}

/*
 *  On ajoute un missile a la file des missiles
 */
void Vaisseau::tirerMissile(){
    missiles->push(new Missile(x + width / 2, y, puissance, vitesse, couleur, portee));
}

Vaisseau::~Vaisseau(){
    if(missiles != NULL){
        delete missiles;
    }
    missiles = NULL;
}

std::queue<Missile*>* Vaisseau::getMissiles(){
    return missiles;
}

void Vaisseau::setMissiles(std::queue<Missile*>* missiles){
    this->missiles = missiles;
}

/**
 *  Renvoi s'il y a eu ou non colision avec un asteroide donne
 **/
bool Vaisseau::colisionAsteroide(Asteroide* asteroide){
    return asteroide->getX() <= x + width / 2;
}

void Vaisseau::retirerVie(int degat){
    vie = vie - degat;
    degatSubit += degat;
}

int Vaisseau::getVie(){
    return vie;
}
