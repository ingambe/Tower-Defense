//
//  Missile.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 22/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "Missile.hpp"

void Missile::dessiner(){
    GraphicPrimitives::drawLine2D(x, y, x + 0.1f, y, 0.5f, 0.5f, 0.5f);
    x += 0.005f;
}

bool Missile::isVisible(){
    return x <= 1;
}
