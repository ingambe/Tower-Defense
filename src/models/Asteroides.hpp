//
//  Asteroides.hpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 05/12/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#ifndef Asteroides_hpp
#define Asteroides_hpp

#include <stdio.h>
#include "Asteroide.hpp"

class Asteroides {
    public:
        Asteroide *courant;
        Asteroides *suivant;
        Asteroides(Asteroide* asteroide);
        ~Asteroides();
        Asteroides();
        void ajouterAsteroide(Asteroide* aAjouter);
};

#endif /* Asteroides_hpp */
