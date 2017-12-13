//
//  Vague.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 12/12/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "Vague.hpp"

/**
 *  Fonction appeler a chaque tick, peut renvoier un asteroide si egal a l'interval ou NULL sinon
 **/
Asteroide* Vague::creerAsteroide(){
    if(vagueNumero > 0){
    tics = (tics + 1) % interval;
    int difficultee = 0;
    if(tics == 0 && nbAsteroideRestantCreer > 0){
        // on reduit le nombre d'asteroide restant a creer
        nbAsteroideRestantCreer--;
        if(vagueNumero <= 5 ){
            // 25% de chance d'avoir une difficultee de 1
            // sinon une difficultee de 0
            // on augmente les chances d'avoir des asteroides plus difficile au fur et a mesure jusqu'a 30%
            if(rand() % 100 >= 23 + (2 * vagueNumero)){
                difficultee = 0;
            } else {
                difficultee = 1;
            }
        } else if (vagueNumero > 5 && vagueNumero <= 10){
            // 30% de chance d'avoir une difficultee de 2
            // sinon une difficultee de 1
            // on augmente les chances d'avoir des asteroides plus difficile au fur et a mesure jusqu'a 30%
            if(rand() % 100 >= 20 + (2 * vagueNumero)){
                difficultee = 1;
            } else {
                difficultee = 2;
            }
        } else {
            // 8% de chance d'avoir une difficultee de 1 au debut
            // sinon une difficultee de 2
            // on augmente les chances d'avoir des asteroides plus difficile au fur et a mesure jusqu'a avoir 100% de chance de tomber sur
            // un asteroide tres difficile a la vague 15
            if(rand() % 100 >= 30 - (2 * vagueNumero)){
                difficultee = 2;
            } else {
                difficultee = 1;
            }
        }
        return AsteroidesFactory::creerAsteroide(rand() % lignes, lignes, difficultee);
    }
    }
    // si ce n'est pas le moment de creer un asteroide on renvoit NULL
    // il ne sera pas ajouter a la liste des asteroides
    return NULL;
}

bool Vague::vagueFinie(){
    // soit il n'y a plus d'asteroides a creer, soit on a pas encore commence
    return nbAsteroideRestantCreer <= 0 || vagueNumero == 0;
}

void Vague::incrementerVague(){
    vagueNumero++;
    tics = 0;
    nbAsteroideRestantCreer = 5 * vagueNumero +  (rand() % vagueNumero);
    interval = floor(100 / (2 * vagueNumero));
}

int Vague::getNumeroVague(){
    return vagueNumero;
}
