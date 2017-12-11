//
//  Case.hpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 15/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#ifndef Case_hpp
#define Case_hpp

#include <stdio.h>
#include "GraphicPrimitives.h"
#include "Vaisseau.hpp"
#include "VaisseauFactory.hpp"
#include "AsteroidesFactory.hpp"
#include "Asteroide.hpp"

class Case{
    private:
        float x;
        float y;
        float width;
        float height;
        Vaisseau *vaisseau = NULL;
    public:
        Case(float x, float y, float width, float height):x(x),y(y),width(width), height(height){};
        Case(float x, float y, float width, float height, Vaisseau *vaisseau):x(x),y(y),width(width), height(height), vaisseau(vaisseau){};
        Case(){};
        ~Case();
        void dessiner();
        void ajouterVaisseau(int type);
        void colision(Asteroide* asteroide, int lignes);
        float getX();
        float getY();
        float getWidth();
        float getHeight();
};

#endif /* Case_hpp */
