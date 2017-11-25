//
//  Missile.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 22/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "Missile.hpp"

void Missile::dessiner(){
    // seul le cas x > width_fenetre nous interresse
    // mais au cas ou, on prend en compte le y
    if(x > width_fenetre || x < 0 || y > height_fenetre || y < 0){
        // si on sort du cadre de l'ecran on se supprimer
        delete this;
    } else {
        GraphicPrimitives::drawLine2D(x, y, x + width_fenetre / 100.0, y + height_fenetre / 800.0, 0.5f, 0.5f, 0.5f);
        x += vitesse;
    }
}

bool Missile::isVisible(){
    return x <= 1.0f;
}
