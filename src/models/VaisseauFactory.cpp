//
//  VaisseauFactory.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 11/12/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "VaisseauFactory.hpp"

Vaisseau* VaisseauFactory::creerVaisseau(float x, float y, float width, float height, const int type){
    int vie;
    int frequence;
    int puissance;
    int vitesse;
    Couleur couleur;
    switch (type) {
        case 1:
            vie = 3;
            frequence = 4;
            puissance = 2;
            vitesse = 10;
            couleur = Couleur::blanc;
            break;
        case 2:
            vie = 4;
            frequence = 2;
            puissance = 4;
            vitesse = 15;
            couleur = Couleur::rouge;
            break;
        default:
            vie = 2;
            frequence = 6;
            puissance = 1;
            vitesse = 5;
            couleur = Couleur::bleue;
            break;
    }
    return new Vaisseau(x, y, width, height, vie, frequence, puissance, vitesse, couleur);
}
