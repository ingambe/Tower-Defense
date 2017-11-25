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
#include "Missiles.hpp"

class Vaisseau{
    private:
        float x;
        float y;
        float width;
        float height;
        int temps;
        int puissance;
        int vitesse;
        int width_fenetre;
        int height_fenetre;
        Missiles *missiles;
        int compteur = 0;
    public:
        // temps = 1 / frequence
        Vaisseau(float x, float y, float width, float height, float frequence, int puissance, int vitesse, int width_fenetre, int height_fenetre):x(x), y(y), width(width), height(height), temps(1 / frequence), puissance(puissance), vitesse(vitesse), width_fenetre(width_fenetre), height_fenetre(height_fenetre){
            missiles = new Missiles();
        };
        void dessiner();
        void tirerMissile();
};

#endif /* Vaisseau_hpp */
