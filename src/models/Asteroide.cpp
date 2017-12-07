//
//  Asteroide.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 05/12/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "Asteroide.hpp"

void Asteroide::dessiner(){
    std::vector<float> vectX;
    std::vector<float> vectY;
    
    vectX.emplace_back(x);
    vectY.emplace_back(y);
    
    vectX.emplace_back(x);
    vectY.emplace_back(y + perimetre);
    
    vectX.emplace_back(x + perimetre);
    vectY.emplace_back(y + perimetre + (2 * perimetre));
    
    vectX.emplace_back(x + perimetre);
    vectY.emplace_back(y + perimetre);
    
    vectX.emplace_back(x + perimetre + (2 * perimetre));
    vectY.emplace_back(y);
    
    vectX.emplace_back(x + perimetre);
    vectY.emplace_back(y - perimetre);
    
    vectX.emplace_back(x + perimetre);
    vectY.emplace_back(y - perimetre - (2 * perimetre));
    
    vectX.emplace_back(x);
    vectY.emplace_back(y - perimetre);
    
    GraphicPrimitives::drawFillPolygone2D(vectX, vectY, 0.5f, 0.5f, 0.5f);

    x -= (vitesse / 1000.0);
    
}

bool Asteroide::estVivant(){
    return vie > 0;
}

float Asteroide::getPerimetre(){
    return perimetre;
}

void Asteroide::setX(float x){
    this->x = x;
}

void Asteroide::setY(float y){
    this->y = y;
}

