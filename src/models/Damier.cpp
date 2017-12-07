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

/**
 * Recupere tous les missiles des differents vaisseau du plateau et les fusionnes
 **/
Missiles* Damier::getMissilesCases(){
    // le pointeur qui stockera les missiles
    Missiles* resultat = new Missiles();
    // le pointeur qu'on va modifier pour concatener les files de missiles
    Missiles* copieIteration = resultat;
    for(int i = 0; i < lignes * colonnes; i++){
        if(recupererCase(i)->getMissiles() != NULL){
            // on recupere les missiles de la case
            copieIteration->suivant = recupererCase(i)->getMissiles();
            // copie iteration devient le bout de la liste
            while(copieIteration->suivant != NULL){
                copieIteration = copieIteration->suivant;
            }
        }
    }
    // on renvoie le suivant le premier etant une coquille vide
    return resultat->suivant;
}

// TODO : deporte cette focntion dans le moteur pour gerer les score et la monnaie
void Damier::gererColisions(){
    // gestions colisions avec missiles
    Asteroides *iteration = asteroides;
    Missiles *missiles = getMissilesCases();
    while (iteration != NULL && iteration->courant != NULL) {
        /**
         * on creer une "coquille" vide sur le premier element des missiles
         * cela permet de travailler sur les suivants et donc de supprimer un
         * element beaucoup plus facilement
         **/
        Missiles *iterationMissiles = new Missiles();
        iterationMissiles->suivant = missiles;
        // on s'en fout de sauter le premier element, c'est une coquille vide
        while (iterationMissiles != NULL && iterationMissiles->suivant != NULL && iterationMissiles->suivant->courant != NULL) {
            /**
             * On lui envoi le missile et le nombre de lignes dans le damier
             * On rappel que le nombre de ligne sert a determiner la ligne ou se trouve
             * Le missile et l'asteroide
             **/
            if(iteration->courant->colision(iterationMissiles->suivant->courant, lignes)){
                Missiles *aSupprimer = iterationMissiles->suivant;
                iterationMissiles->suivant = aSupprimer->suivant;
                delete aSupprimer;
                aSupprimer = NULL;
            }
            iterationMissiles = iterationMissiles->suivant;
        }
        iteration = iteration->suivant;
    }
}
