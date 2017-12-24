//
//  Couleur.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 12/12/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "Couleur.hpp"

Couleur Couleur::bleue(0.1f, 0.1f, 1.0f);
Couleur Couleur::blanc(1.0f, 1.0f, 1.0f);
Couleur Couleur::rouge(1.0f, 0.1f, 0.1f);
Couleur Couleur::gris(0.5f, 0.5f, 0.5f);
Couleur Couleur::jaune(1.0f, 1.0f, 0.2f);
Couleur Couleur::vert(0.1f, 1.0f, 0.1f);

float Couleur::getRed(){
    return red;
}

void Couleur::setRed(float red){
    this->red = red;
}

float Couleur::getGreen(){
    return green;
}

void Couleur::setGreen(float green){
    this->green = green;
}

float Couleur::getBlue(){
    return blue;
}

void Couleur::setBlue(float blue){
    this->blue = blue;
}
