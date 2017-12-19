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
        sprintf(str,"Vies : ");
    } else {
        sprintf(str,"Vie : ");
    }
    for(int i = 0; i < vieJoueur; i++){
        sprintf(str, "%s *", str);
    }
    GraphicPrimitives::drawText2D(str, -0.95f, 0.88f, 1.0f, 1.0f, 1.0f);
    if(str != NULL){
        delete[] str;
    }
    str = NULL;
    
    // le score
    str = new char[50];
    sprintf(str,"Score : ");
    sprintf(str, "%s %d", str, scoreJoueur);
    GraphicPrimitives::drawText2D(str, -0.55f, 0.88f, 1.0f, 1.0f, 1.0f);
    if(str != NULL){
        delete[] str;
    }
    str = NULL;
    
    
    // le numero de vague
    str = new char[50];
    sprintf(str,"Vague : ");
    sprintf(str, "%s %d", str, vague->getNumeroVague());
    GraphicPrimitives::drawText2D(str, -0.15f, 0.88f, 1.0f, 1.0f, 1.0f);
    if(str != NULL){
        delete[] str;
    }
    str = NULL;
    
    // l'argent du joueur
    str = new char[50];
    sprintf(str,"Argent : ");
    sprintf(str, "%s %d", str, argentJoueur);
    GraphicPrimitives::drawText2D(str, 0.20f, 0.88f, 1.0f, 1.0f, 1.0f);
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
    Couleur couleur;
    for(int i = 0; i < AsteroidesFactory::nombreTypesVaisseaux; i++){
        switch (i) {
            case 1:
                couleur = Couleur::blanc;
                break;
            case 2:
                couleur = Couleur::rouge;
                break;
            default:
                couleur = Couleur::bleue;
                break;
        }
        GraphicPrimitives::drawFillTriangle2D(0.55f + (i * 0.1f), 0.90f, 0.50f + (i * 0.1f), 0.85f, 0.50f + (i * 0.1f), 0.95f, couleur.getRed(), couleur.getGreen(), couleur.getBlue());
    }
    // on dessine un rectangle autour du vaisseau selectionnee
    switch (vaisseauSelectionneJoueur) {
        case 1:
            GraphicPrimitives::drawOutlinedRect2D(0.58f, 0.85f, 0.09f, 0.1f, 1.0f, 1.0f, 1.0f);
            break;
        case 2:
            GraphicPrimitives::drawOutlinedRect2D(0.68f, 0.85f, 0.09f, 0.1f, 1.0f, 1.0f, 1.0f);
            break;
        default:
            GraphicPrimitives::drawOutlinedRect2D(0.48f, 0.85f, 0.09f, 0.1f, 1.0f, 1.0f, 1.0f);
            break;
    }
    // on affiche les infos sur le vaisseau
    
    // une string par ligne d'information sur les vaisseaux
    char* str1 = new char[50];
    char* str2 = new char[50];
    char* str3 = new char[50];
    char* str4 = new char[50];
    switch(vaisseauSelectionneJoueur){
        case 1:
            sprintf(str1, "degat : %d", 2);
            sprintf(str2, "vitesse : %d", 4);
            sprintf(str3, "vie : %d", 3);
            sprintf(str4, "cout : %d", 5);
            break;
        case 2:
            sprintf(str1, "degat : %d", 4);
            sprintf(str2, "vitesse : %d", 6);
            sprintf(str3, "vie : %d", 4);
            sprintf(str4, "cout : %d", 10);
            break;
        default:
            sprintf(str1, "degat : %d", 1);
            sprintf(str2, "vitesse : %d", 2);
            sprintf(str3, "vie : %d", 2);
            sprintf(str4, "cout : %d", 3);
            break;
    }
    // On les affiches en suite a droite de la selection
    GraphicPrimitives::drawText2D(str1, 0.78f, 0.95f, 1.0f, 1.0f, 1.0f);
    GraphicPrimitives::drawText2D(str2, 0.78f, 0.90f, 1.0f, 1.0f, 1.0f);
    GraphicPrimitives::drawText2D(str3, 0.78f, 0.85f, 1.0f, 1.0f, 1.0f);
    // pour l'argent, si on en a pas assez, on l'affiche en rouge
    if(vaisseauSelectionneJoueur == 0 && argentJoueur < 3){
        GraphicPrimitives::drawText2D(str4, 0.78f, 0.80f, 1.0f, 0.5f, 0.5f);
    } else if (vaisseauSelectionneJoueur == 1 && argentJoueur < 5){
        GraphicPrimitives::drawText2D(str4, 0.78f, 0.80f, 1.0f, 0.5f, 0.5f);
    } else if (vaisseauSelectionneJoueur == 2 && argentJoueur < 10){
        GraphicPrimitives::drawText2D(str4, 0.78f, 0.80f, 1.0f, 0.5f, 0.5f);
    } else {
        // sinon on l'affiche en vert
        GraphicPrimitives::drawText2D(str4, 0.78f, 0.80f, 0.5f, 1.0f, 0.5f);
    }
    if(str1 != NULL){
        delete[] str1;
    }
    str1 = NULL;
    if(str2 != NULL){
        delete[] str2;
    }
    str2 = NULL;
    if(str3 != NULL){
        delete[] str3;
    }
    str3 = NULL;
    if(str4 != NULL){
        delete[] str4;
    }
    str4 = NULL;
}

/**
 *  Renvoie le vaisseau choisis en fonction des coordonees du click de l'utilisateur
 **/
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

/**
 * Fonction utilise pour ajouter un vaisseau et reduire l'argent du joueur
 *  Renvoi faux si le joueur n'a pas assez d'argent pour poser le vaisseau
 **/
bool Damier::ajouterVaisseauCase(int caseSelectionne){
    bool assezArgent = false;
    switch (vaisseauSelectionneJoueur) {
            // on verifie qu'il y a assez d'argent et qu'il n'y est pas deja un vaisseau sur la case
        case 1:
            assezArgent = argentJoueur >= 5;
            if(assezArgent && !recupererCase(caseSelectionne)->dejaUnVaisseau()){
                argentJoueur = argentJoueur - 5;
                recupererCase(caseSelectionne)->ajouterVaisseau(vaisseauSelectionneJoueur);
            }
            break;
        case 2:
            assezArgent = argentJoueur >= 10;
            if(assezArgent && !recupererCase(caseSelectionne)->dejaUnVaisseau()){
                argentJoueur = argentJoueur - 10;
                recupererCase(caseSelectionne)->ajouterVaisseau(vaisseauSelectionneJoueur);
            }
            break;
        default:
            assezArgent = argentJoueur >= 3;
            if(assezArgent && !recupererCase(caseSelectionne)->dejaUnVaisseau()){
                argentJoueur = argentJoueur - 3;
                recupererCase(caseSelectionne)->ajouterVaisseau(vaisseauSelectionneJoueur);
            }
            break;
    }
    return assezArgent;
}

/*
 *  On ajoute un asteroide a la file des asteroides
 */
void Damier::ajouterAsteroide(Asteroide *asteroide){
    if(asteroide != NULL){
        asteroides->push(asteroide);
    }
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

void Damier::incrementerVague(){
    if(vague->vagueFinie()){
        vague->incrementerVague();
    }
}

bool Damier::plusAsteroide(){
    return asteroides->empty();
}

bool Damier::vagueFinie(){
    return vague->vagueFinie() && plusAsteroide();
}

void Damier::gererVague(){
    ajouterAsteroide(vague->creerAsteroide());
}

int Damier::getNumeroVague(){
    return vague->getNumeroVague();
}
