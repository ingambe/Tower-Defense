//
//  DamierFactory.cpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 15/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#include "DamierFactory.hpp"

/*
 *  On cree les cases en gardant 0.2f en haut pour les infos du joueur et le choix du type de vaisseau
 */
Damier* DamierFactory::creerDamier(int lignes, int colonnes){
    Case** cases = new Case*[nombreDeCases(lignes, colonnes)];
    float largeur = 2.0f / colonnes;
    float hauteur = 1.8f / lignes;
    for(int ligne = 0; ligne < lignes; ligne++){
        for(int colonne = 0; colonne < colonnes; colonne++){
            cases[(ligne * colonnes) + colonne] = new Case(-1.0f + (colonne * largeur), -1.0f + (ligne * hauteur), largeur, hauteur);
        }
    }
    return new Damier(cases, lignes, colonnes);
}

int DamierFactory::nombreDeCases(int lignes, int colonnes){
    return lignes * colonnes;
}
