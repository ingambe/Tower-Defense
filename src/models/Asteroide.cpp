//
//  Asteroide.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 05/12/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "Asteroide.hpp"

void Asteroide::dessiner(){
    /**
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
     **/
    GraphicPrimitives::drawFillRect2D(x, y, perimetre, perimetre, 0.5f, 0.5f, 0.5f);

    x -= (vitesse / 1000.0);
    
}

bool Asteroide::estVivant(){
    return vie > 0 && x >= -1.0f;
}

float Asteroide::getPerimetre(){
    return perimetre;
}

void Asteroide::setX(float x){
    this->x = x;
}

float Asteroide::getX(){
    return x;
}

void Asteroide::setY(float y){
    this->y = y;
}

/**
 *  Fonction qui converti un y en numero de ligne
 **/
int Asteroide::yToLigne(float y, int lignes){
    int hauteurCase = 2.0f / lignes;
    int compteur = 0;
    for(float k = 1.0f; k > -1.0f; k = k - hauteurCase){
        if(y <= k && y >= k - hauteurCase){
            return compteur;
        }
        compteur++;
    }
    return lignes - 1;
}

bool Asteroide::colision(Missile *missile, int lignes){
    return missile->getX() >= this->x && (yToLigne(missile->getY(), lignes) == yToLigne(this->y, lignes));
}

void Asteroide::degatMissile(int degat){
    vie = vie - degat;
}

/**
 *  Renvoi la ligne ou se trouve l'asteroide
 **/
int Asteroide::getLigne(int lignes){
    return yToLigne(y, lignes);
}

int Asteroide::getDegat(){
    return degat;
}
