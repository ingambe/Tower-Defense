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

class Asteroide {
    private:
        int vie;
        float x;
        float y;
        int degat;
        int vitesse;
        float perimetre;
    
    public:
        Asteroide(int vie, float x, float y, int degat, int vitesse, float perimetre):vie(vie), x(x), y(y), degat(degat), vitesse(vitesse), perimetre(perimetre){};
        void dessiner();
        bool estVivant();
        float getPerimetre();
        void setX(float x);
        void setY(float y);
};

#endif /* Asteroide_hpp */
