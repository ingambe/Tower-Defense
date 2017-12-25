//
//  Asteroide.hpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 05/12/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#ifndef Asteroide_hpp
#define Asteroide_hpp

#include <stdio.h>
#include "GraphicPrimitives.h"
#include "Missile.hpp"
#include "Couleur.hpp"

class Asteroide {
private:
    int vie;
    float x;
    float y;
    int degat;
    int vitesse;
    float perimetre;
    int yToLigne(float y, int lignes);
    int scoreRapportee;
    int argent;
    Couleur couleur;
    
public:
    Asteroide(int vie, float x, float y, int degat, int vitesse, float perimetre, int scoreRapportee, int argent):vie(vie), x(x), y(y), degat(degat), vitesse(vitesse), perimetre(perimetre), scoreRapportee(scoreRapportee), argent(argent), couleur(Couleur::gris){};
    Asteroide(int vie, float x, float y, int degat, int vitesse, float perimetre, int scoreRapportee, int argent, Couleur couleur):vie(vie), x(x), y(y), degat(degat), vitesse(vitesse), perimetre(perimetre), scoreRapportee(scoreRapportee), argent(argent), couleur(couleur){};
    void dessiner();
    bool estVivant();
    float getPerimetre();
    void setX(float x);
    float getX();
    void setY(float y);
    bool colision(Missile *missile, int lignes);
    void degatMissile(int degat);
    int getLigne(int lignes);
    int getDegat();
    void tuer();
    int getScore();
    int getArgent();
};

#endif /* Asteroide_hpp */
