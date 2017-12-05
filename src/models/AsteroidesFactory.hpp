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
#include "Asteroides.hpp"

class AsteroidesFactory {
    private:
        Asteroide* asteroideDifficultee(int difficultee);
    public :
        Asteroide* creerAsteroide(int ligne, int lignes, int difficultee);
};

#endif /* AsteroidesFactory_hpp */
