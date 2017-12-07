//
//  Damier.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 28/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "Damier.hpp"

Damier::~Damier(){
    if(cases != NULL){
        for(int i = 0; i < DamierFactory::nombreDeCases(lignes, colonnes); i++){
            if(cases[i] != NULL){
                delete cases[i];
            }
            cases[i] = NULL;
        }
        delete cases;
    }
    cases = NULL;
}

Case* Damier::recupererCase(int ligne, int colonne){
    return cases[(ligne * colonne) - 1];
}

Case* Damier::recupererCase(int numeroCase){
    return cases[numeroCase];
}

void Damier::dessiner(){
    // on dessine chaque case du damier
    for(int i = 0; i < lignes * colonnes; i++){
        cases[i]->dessiner();
    }
    // on parcour la liste des asteroides pour les dessiner un a un
    Asteroides *iteration = asteroides;
    while (iteration != NULL && iteration->courant != NULL) {
        iteration->courant->dessiner();
        // si l'element suivant n'est plus visible alors on le delete
        if(iteration->suivant != NULL && iteration->suivant->courant != NULL && !(iteration->suivant->courant->estVivant())){
            Asteroides* suivantSuivant = iteration->suivant->suivant;
            delete iteration->suivant;
            iteration->suivant = suivantSuivant;
        } else {
            iteration = iteration->suivant;
        }
    }
}

/*
 *  On ajoute un asteroide a la file des asteroides
 */
void Damier::ajouterAsteroide(Asteroide *asteroide){
    // si c'est le premier asteroide a apparaitre
    if(asteroides->courant == NULL){
        asteroides->courant = asteroide;
    } else {
        // sinon on creer un nouvel element de la file
        Asteroides *nouveauElement = new Asteroides(asteroide);
        nouveauElement->suivant = asteroides;
        asteroides = nouveauElement;
    }
}

int Damier::getNombreLignes(){
    return lignes;
}

int Damier::getNombreCollones(){
    return colonnes;
}
