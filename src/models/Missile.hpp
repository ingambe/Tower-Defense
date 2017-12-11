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
        int degat;
        int vitesse;
        bool colision;
    
    public:
        Missile(float x, float y, int degat, int vitesse):x(x), y(y), degat(degat), vitesse(vitesse), colision(false){};
        const float width_missile = 0.1f;
        void dessiner();
        bool isVisible();
        float getX();
        float getY();
        void collision();
        bool isASupprimer();
        int getDegat();
};

#endif /* Missile_hpp */
