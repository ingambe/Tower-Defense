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
    return cases[(ligne * colonnes) + colonne];
}

Case* Damier::recupererCase(int numeroCase){
    return cases[numeroCase];
}

void Damier::dessiner(){
    // on dessine chaque case du damier
    for(int i = 0; i < lignes * colonnes; i++){
        cases[i]->dessiner();
    }
    // on fait comme pour la file des missiles
    // file qui gardera les asteroide a ne pas supprimer
    std::queue<Asteroide*>* iteration = new std::queue<Asteroide*>();
    // on parcour la files des asteroides pour les dessiners un a un
    while (!asteroides->empty()) {
        if(asteroides->front()->estVivant()){
            asteroides->front()->dessiner();
            iteration->push(asteroides->front());
        } else {
            if(asteroides->front() != NULL){
                delete asteroides->front();
            }
        }
        asteroides->pop();
    }
    if(asteroides != NULL){
        delete asteroides;
    }
    asteroides = iteration;
}
/*
 *  On ajoute un asteroide a la file des asteroides
 */
void Damier::ajouterAsteroide(Asteroide *asteroide){
    asteroides->push(asteroide);
}

int Damier::getNombreLignes(){
    return lignes;
}

int Damier::getNombreCollones(){
    return colonnes;
}

/**
 * Fonction de gestion de la colision
 * On parcours les asteroides
 * On recupere la ligne de l'asteroide
 * On parcours toutes les cases de la ligne
 * Et on leur passe l'asteroide pour qu'il gere une eventielle colision
 **/
void Damier::gererColisions(){
    // file qui gardera les asteroide a ne pas supprimer
    std::queue<Asteroide*>* iteration = new std::queue<Asteroide*>();
    while (!asteroides->empty()) {
        Asteroide* courant = asteroides->front();
        // on recupere la ligne
        int ligne = courant->getLigne(lignes);
        for(int i = 0; i < colonnes; i++){
             recupererCase(ligne, i)->colision(courant, lignes);
        }
        iteration->push(courant);
        asteroides->pop();
    }
    if(asteroides != NULL){
        delete asteroides;
    }
    asteroides = iteration;
}
