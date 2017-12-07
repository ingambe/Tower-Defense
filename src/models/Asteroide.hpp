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
    
    public:
        Asteroide(int vie, float x, float y, int degat, int vitesse, float perimetre, int scoreRapportee):vie(vie), x(x), y(y), degat(degat), vitesse(vitesse), perimetre(perimetre), scoreRapportee(scoreRapportee){};
        void dessiner();
        bool estVivant();
        float getPerimetre();
        void setX(float x);
        void setY(float y);
        bool colision(Missile *missile, int lignes);
};

#endif /* Asteroide_hpp */
