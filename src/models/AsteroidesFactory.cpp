//
//  AsteroidesFactory.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 06/12/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "AsteroidesFactory.hpp"

Asteroide* AsteroidesFactory::asteroideDifficultee(int difficultee){
    int vie;
    float x;
    float y;
    int degat;
    int vitesse;
    float perimetre;
    switch (difficultee) {
        case 1:
            vie = 3;
            x = 0.0f;
            y = 0.0f;
            degat = 2;
            vitesse = 7;
            perimetre = 0.25f;
            break;
        default:
            vie = 2;
            x = 0.0f;
            y = 0.0f;
            degat = 1;
            vitesse = 5;
            perimetre = 0.20f;
            break;
    }
    return new Asteroide(vie, x, y, degat, vitesse, perimetre);
}

Asteroide* AsteroidesFactory::creerAsteroide(int ligne, int lignes, int difficultee){
    Asteroide *asteroide = asteroideDifficultee(difficultee);
    int x = 1 + asteroide->getPerimetre();
    asteroide->setX(x);
    float hauteurCase = -lignes / 2.0f;
    // a modifier quand il y aura les cercles a la place des carrees
    asteroide->setY((hauteurCase * ligne) + 1.0f + (hauteurCase / 2) - (asteroide->getPerimetre() / 2));
    return asteroide;
}
