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
    switch (difficultee) {
        case 1:
            vie = 4;
            degat = 2;
            vitesse = 7;
            perimetre = 0.25f;
            score = 2;
            argent = 2;
            break;
        case 2:
            vie = 8;
            degat = 4;
            vitesse = 9;
            perimetre = 0.3f;
            score = 4;
            argent = 3;
            break;
        default:
            vie = 2;
            degat = 1;
            vitesse = 5;
            perimetre = 0.20f;
            score = 1;
            argent = 1;
            break;
    }
    return new Asteroide(vie, x, y, degat, vitesse, perimetre, score, argent);
}

Asteroide* AsteroidesFactory::creerAsteroide(int ligne, int lignes, int difficultee){
    float hauteurCase = 1.8f / lignes;
    Asteroide *asteroide = asteroideDifficultee(difficultee);
    float x = 1.0f + asteroide->getPerimetre();
    asteroide->setX(x);
    // a modifier quand il y aura les cercles a la place des carrees
    asteroide->setY(0.6f - (ligne * hauteurCase) - (hauteurCase / 2.0f)+ (asteroide->getPerimetre() / 2.0f));
    return asteroide;
}

