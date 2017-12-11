//
//  Vaisseau.hpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 22/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#ifndef Vaisseau_hpp
#define Vaisseau_hpp

#include <stdio.h>
#include "GraphicPrimitives.h"
#include "Missile.hpp"
#include <queue>
#include "Asteroide.hpp"

class Vaisseau{
    private:
        float x;
        float y;
        float width;
        float height;
        int vie;
        int temps;
        int puissance;
        int vitesse;
        std::queue<Missile*>* missiles;
        int compteur = 0;
    
    public:
        // temps = 1 / frequence
        Vaisseau(float x, float y, float width, float height, int vie, float frequence, int puissance, int vitesse):x(x), y(y), width(width), height(height), vie(vie), temps(1 / frequence), puissance(puissance), vitesse(vitesse){
            missiles = new std::queue<Missile*>();
        };
        ~Vaisseau();
        void dessiner();
        void tirerMissile();
        std::queue<Missile*>* getMissiles();
        void setMissiles(std::queue<Missile*>* missiles);
        bool colisionAsteroide(Asteroide* asteroide);
        void retirerVie(int degat);
        int getVie();
};

#endif /* Vaisseau_hpp */
