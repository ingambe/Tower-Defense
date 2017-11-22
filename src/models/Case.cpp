//
//  Case.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 15/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "Case.hpp"

Case::Case(){
    
}

void Case::dessiner(){
    GraphicPrimitives::drawOutlinedRect2D(x, y, width, height, 0.5f, 0.5f, 0.5f);
    if(vaisseau != NULL){
        vaisseau->dessiner();
    }
}

void Case::ajouterVaisseau(){
    std::cout << "y : " << y << std::endl;
    vaisseau = new Vaisseau(x + (width / 2), -y - (height / 2), width / 2, height / 2, 1.0f, 1, 5);
}
