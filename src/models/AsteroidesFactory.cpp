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
            x = 0;
            y= 0;
            degat = 2;
            vitesse = 7;
            perimetre = 0.25f;
            break;
        default:
            vie = 2;
            x = 0;
            y= 0;
            degat = 1;
            vitesse = 5;
            perimetre = 0.20f;
            break;
    }
    return new Asteroide(vie, x, y, degat, vitesse, perimetre);
}

Asteroide* AsteroidesFactory::creerAsteroide(int ligne, int difficultee){
    Asteroide *asteroide = asteroideDifficultee(difficultee);
    int x = 
}
Asteroide* AsteroidesFactory::creerAsteroide(int difficultee){
    
}
