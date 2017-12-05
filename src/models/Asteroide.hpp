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
        int puissance;
        int vitesse;
        float perimetre;
        int width_fenetre;
        int height_fenetre;
    public:
        Asteroide(int vie, float x, float y, int puissance, int vitesse, float perimetre, int width_fenetre, int height_fenetre):vie(vie), x(x), y(y), puissance(puissance), vitesse(vitesse), perimetre(perimetre), width_fenetre(width_fenetre), height_fenetre(height_fenetre){};
        void dessiner();
        bool estVivant();
};

#endif /* Asteroide_hpp */
