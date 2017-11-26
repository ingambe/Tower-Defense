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
    std::cout << "x1  : " << x << std::endl << "y1  : " << y << std::endl;
    std::cout << "x2  : " << x + 0.1f << std::endl << "y2  : " << y << std::endl;
    x += 0.005f;
}

bool Missile::isVisible(){
    return x <= 1;
}
