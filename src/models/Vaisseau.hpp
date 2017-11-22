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

class Vaisseau{
    private:
        float x;
        float y;
        float width;
        float height;
        float frequence;
        int puissance;
        int vitesse;
    public:
        Vaisseau(float x, float y, float width, float height, float frequence, int puissance, int vitesse):x(x), y(y), width(width), height(height), frequence(frequence), puissance(puissance), vitesse(vitesse){};
        void dessiner();
};

#endif /* Vaisseau_hpp */
