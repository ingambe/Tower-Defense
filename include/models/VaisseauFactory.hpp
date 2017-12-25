//
//  VaisseauFactory.hpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 11/12/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#ifndef VaisseauFactory_hpp
#define VaisseauFactory_hpp

#include <stdio.h>
#include "Vaisseau.hpp"

class VaisseauFactory {
public:
    static Vaisseau* creerVaisseau(float x, float y, float width, float height, const int type);
};

#endif /* VaisseauFactory_hpp */
