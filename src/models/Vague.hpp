//
//  Vague.hpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 12/12/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#ifndef Vague_hpp
#define Vague_hpp

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "Asteroide.hpp"
#include "AsteroidesFactory.hpp"

class Vague{
    
private:
    int vagueNumero = 1;
    int tics = 0;
    int interval;
    int nbAsteroideRestantCreer;
    int lignes;
    
public:
    Vague(int lignes){
        srand(time(NULL));
        nbAsteroideRestantCreer = 5 * vagueNumero +  (rand() % vagueNumero);
        interval = floor(100 / (2 * vagueNumero));
    }
    Asteroide* creerAsteroide();
    bool vagueFinie();
    void incrementerVague();
};

#endif /* Vague_hpp */
