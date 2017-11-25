//
//  Missile.hpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 22/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#ifndef Missile_hpp
#define Missile_hpp

#include <stdio.h>
#include "GraphicPrimitives.h"

class Missile{
    private:
        float x;
        float y;
        int puissance;
        int vitesse;
        int width_fenetre;
        int height_fenetre;
    public:
        Missile(float x, float y, int puissance, int vitesse, int width_fenetre, int height_fenetre):x(x), y(y), puissance(puissance), vitesse(vitesse), width_fenetre(width_fenetre), height_fenetre(height_fenetre){};
        void dessiner();
        bool isVisible();
};

#endif /* Missile_hpp */
