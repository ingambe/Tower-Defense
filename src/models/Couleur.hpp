//
//  Couleur.hpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 12/12/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#ifndef Couleur_hpp
#define Couleur_hpp

#include <stdio.h>

class Couleur{
    
    private:
        float red;
        float green;
        float blue;
    
    public:
        Couleur():red(0.0f), green(0.0f), blue(0.0f){}
        Couleur(float red, float green, float blue):red(red),green(green),blue(blue){}
        float getRed();
        void setRed(float red);
        float getGreen();
        void setGreen(float green);
        float getBlue();
        void setBlue(float blue);
        static Couleur bleue;
        static Couleur blanc;
        static Couleur rouge;
};

#endif /* Couleur_hpp */
