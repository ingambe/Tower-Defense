//
//  AsteroidesFactory.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 06/12/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "AsteroidesFactory.hpp"

int AsteroidesFactory::nombreTypesVaisseaux = 3;

Asteroide* AsteroidesFactory::asteroideDifficultee(int difficultee){
    int vie;
    float x = 0.0f;
    float y = 0.0f;
    int degat;
    int vitesse;
    float perimetre;
    int score;
    int argent;
    Couleur couleur;
    switch (difficultee) {
        case 1:
            vie = 4;
            degat = 2;
            vitesse = 7;
            perimetre = 0.25f;
            score = 2;
            argent = 2;
            couleur = Couleur::jaune;
            break;
        case 2:
            vie = 8;
            degat = 4;
            vitesse = 9;
            perimetre = 0.3f;
            score = 4;
            argent = 3;
            couleur = Couleur::vert;
            break;
        default:
            vie = 2;
            degat = 1;
            vitesse = 5;
            perimetre = 0.20f;
            score = 1;
            argent = 1;
            couleur = Couleur::gris;
            break;
    }
    return new Asteroide(vie, x, y, degat, vitesse, perimetre, score, argent, couleur);
}

Asteroide* AsteroidesFactory::creerAsteroide(int ligne, int lignes, int difficultee){
    float hauteurCase = 1.8f / lignes;
    Asteroide *asteroide = asteroideDifficultee(difficultee);
    float x = 1.0f + asteroide->getPerimetre();
    asteroide->setX(x);
    asteroide->setY(0.7f - (ligne * hauteurCase) - (hauteurCase / 1.8f) + (asteroide->getPerimetre() / 1.8f));
    return asteroide;
}

