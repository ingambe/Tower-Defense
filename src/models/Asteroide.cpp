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
    
    vectX.emplace_back(x + (perimetre / 3.0f));
    vectY.emplace_back(y + (perimetre / 2.0f));
    
    vectX.emplace_back(x + (perimetre / 2.0f));
    vectY.emplace_back(y + (perimetre / 3.0f));
    
    vectX.emplace_back(x + (perimetre / 2.5f));
    vectY.emplace_back(y - (perimetre / 3.0f));
    
    vectX.emplace_back(x + (perimetre / 3.0f));
    vectY.emplace_back(y - (perimetre / 2.5f));
    
    vectX.emplace_back(x - (perimetre / 3.0f));
    vectY.emplace_back(y - (perimetre / 2.0f));
    
    vectX.emplace_back(x - (perimetre / 2.0f));
    vectY.emplace_back(y - (perimetre / 3.0f));
    
    vectX.emplace_back(x - (perimetre / 2.5f));
    vectY.emplace_back(y + (perimetre / 3.0f));
    
    vectX.emplace_back(x - (perimetre / 3.0f));
    vectY.emplace_back(y + (perimetre / 2.0f));
    
    GraphicPrimitives::drawFillPolygone2D(vectX, vectY, 0.5f, 0.5f, 0.5f);
    GraphicPrimitives::drawFillRect2D(x - (perimetre / 2.6f), y + (perimetre / 2.3f), perimetre - (perimetre / 4.4f), -perimetre + (perimetre / 5.5f), 0.5f, 0.5f, 0.5f);
    
    //GraphicPrimitives::drawFillRect2D(x, y, perimetre, perimetre, 0.5f, 0.5f, 0.5f);
    
    std::cout << "x : " << x << " y : " << y << std::endl;

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
    float hauteurCase = 1.8f / lignes;
    int compteur = 0;
    for(float k = 0.8f; k > -1.0f; k = k - hauteurCase){
        // le premier cas c'est pour k allant de 1 a 0
        // le second cas est poru k allant de 0 a -1
        if((y <= k && y >= k - hauteurCase) || (y <= k && y >= k + hauteurCase)){
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

void Asteroide::tuer(){
    vie = 0;
}

int Asteroide::getScore(){
    return scoreRapportee;
}

int Asteroide::getArgent(){
    return argent;
}
