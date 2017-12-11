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
                scoreJoueur += asteroides->front()->getScore();
                argentJoueur += asteroides->front()->getArgent();
                delete asteroides->front();
            }
        }
        asteroides->pop();
    }
    if(asteroides != NULL){
        delete asteroides;
    }
    asteroides = iteration;
    
    // On dessine enssuite les informations utile a l'utilisateur
    
    // Le nombre de vies
    char* str = new char[50];
    if(vieJoueur > 1){
        sprintf(str,"Vie : ");
    } else {
        
        sprintf(str,"Vies : ");
    }
    for(int i = 0; i < vieJoueur; i++){
        sprintf(str, "%s *", str);
    }
    GraphicPrimitives::drawText2D(str, -0.95f, 0.9f, 0.5f, 0.5f, 0.5f);
    if(str != NULL){
        delete[] str;
    }
    str = NULL;
    
    // le score
    str = new char[50];
    sprintf(str,"Score : ");
    sprintf(str, "%s %d", str, scoreJoueur);
    GraphicPrimitives::drawText2D(str, -0.1f, 0.9f, 0.5f, 0.5f, 0.5f);
    if(str != NULL){
        delete[] str;
    }
    str = NULL;
    
    drawSelecteurVaisseau();
}

/**
 *  Fonction qui permet de dessiner les selecteurs de vaisseaux
 **/
void Damier::drawSelecteurVaisseau(){
    for(int i = 0; i < AsteroidesFactory::nombreTypesVaisseaux; i++){
        GraphicPrimitives::drawFillTriangle2D(0.55f + (i * 0.1f), 0.90f, 0.50f + (i * 0.1f), 0.85f, 0.50f + (i * 0.1f), 0.95f, 0.5f, 0.5f, 0.5);
    }
    // on dessine un rectangle autour du vaisseau selectionnee
    switch (vaisseauSelectionneJoueur) {
        case 1:
            GraphicPrimitives::drawOutlinedRect2D(0.58f, 0.85f, 0.09f, 0.1f, 0.5f, 0.5f, 0.5f);
            break;
        case 2:
            GraphicPrimitives::drawOutlinedRect2D(0.68f, 0.85f, 0.09f, 0.1f, 0.5f, 0.5f, 0.5f);
            break;
        default:
            GraphicPrimitives::drawOutlinedRect2D(0.48f, 0.85f, 0.09f, 0.1f, 0.5f, 0.5f, 0.5f);
            break;
    }
}

int Damier::coordoneeChoixVaisseau(float x, float y){
    if(x >= 0.48f && x <= 0.57f && y >= 0.85f && y <= 0.95f){
        return 0;
    } else if(x >= 0.57f && x <= 0.67f && y >= 0.85f && y <= 0.95f){
        return 1;
    } else {
        return 2;
    }
}

void Damier::setVaisseauSelectionne(int selection){
    vaisseauSelectionneJoueur = selection;
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

bool Damier::colisionAvecBord(Asteroide* asteroide){
    return asteroide->getX() <= -1.0f;
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
        /**
         *  Gestion colision bord ecran (vie joueur)
         **/
        if(colisionAvecBord(courant)){
            vieJoueur = vieJoueur - 1;
            // on tue l'asteroide
            courant->tuer();
        }
        iteration->push(courant);
        asteroides->pop();
    }
    if(asteroides != NULL){
        delete asteroides;
    }
    asteroides = iteration;
}

bool Damier::partieFinie(){
    return vieJoueur <= 0;
}

int Damier::getScoreJoueur(){
    return scoreJoueur;
}
