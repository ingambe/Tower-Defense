//
//  AsteroidesFactory.hpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 06/12/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#ifndef AsteroidesFactory_hpp
#define AsteroidesFactory_hpp

#include <stdio.h>
#include "Asteroide.hpp"

class AsteroidesFactory {
    private:
        static Asteroide* asteroideDifficultee(int difficultee);
    public :
        static Asteroide* creerAsteroide(int ligne, int lignes, int difficultee);
};

#endif /* AsteroidesFactory_hpp */
