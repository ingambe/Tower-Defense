//
//  Missile.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 22/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "Missile.hpp"

void Missile::dessiner(){
    GraphicPrimitives::drawLine2D((width_fenetre / x) - 1.0f, y - 0.2f, (width_fenetre / x) - 1.0f + (width_fenetre / 100.0), y - 0.2f, 0.5f, 0.5f, 0.5f);
    std::cout << "x1  : " << (width_fenetre / x) - 1.0f << std::endl << "y1  : " << y << std::endl;
    x += vitesse;
}

bool Missile::isVisible(){
    return x <= width_fenetre;
}
