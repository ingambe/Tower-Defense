//
//  Missiles.hpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 25/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#ifndef Missiles_hpp
#define Missiles_hpp

#include <stdio.h>
#include "Missile.hpp"

/*
 *  Représente une liste de missiles
 */
class Missiles{
    public :
        // pointeur vers le missile courant
        Missile* courant;
        // pointeur vers le reste de la liste de missiles
        Missiles* suivant;
        Missiles(Missile* missile);
        Missiles();
        ~Missiles();
        void ajouterMissile(Missile *missile);
};

#endif /* Missiles_hpp */
