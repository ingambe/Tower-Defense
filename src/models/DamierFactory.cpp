//
//  DamierFactory.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 15/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "DamierFactory.hpp"

Case** DamierFactory::creerDamier(int lignes, int colonnes){
    Case** cases = new Case*[nombreDeCases(lignes, colonnes)];
    float largeur = 2.0f / (colonnes + 1);
    float hauteur = 2.0f / (lignes + 1);
    for(int ligne = 0; ligne <= lignes; ligne++){
        for(int colonne = 0; colonne <= colonnes; colonne++){
            cases[(ligne * colonnes) + colonne] = new Case(-1.0f + (colonne * largeur), -1.0f + (ligne * hauteur), largeur, hauteur);
        }
    }
    return cases;
}

int DamierFactory::nombreDeCases(int lignes, int colonnes){
    return (lignes + 1) * (colonnes * 1);
}
