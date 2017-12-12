//
//  Damier.hpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 28/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#ifndef Damier_hpp
#define Damier_hpp

#include <stdio.h>
#include "Case.hpp"
#include <queue>
#include "DamierFactory.hpp"
#include "AsteroidesFactory.hpp"
#include "Asteroide.hpp"
#include "Vague.hpp"

class Damier {
    
    private:
        Case** cases;
        std::queue<Asteroide*>* asteroides = new std::queue<Asteroide*>();
        int lignes;
        int colonnes;
        int vieJoueur = 3;
        int scoreJoueur = 0;
        int argentJoueur = 10;
        int vaisseauSelectionneJoueur = 0;
        void drawSelecteurVaisseau();
        Case* recupererCase(int ligne, int colonne);
        Case* recupererCase(int numeroCase);
        Vague* vague;
    
    public:
        Damier(Case** cases, int lignes, int colonnes):cases(cases), lignes(lignes), colonnes(colonnes){
            vague = new Vague(colonnes);
        }
        ~Damier();
        void dessiner();
        void ajouterAsteroide(Asteroide *asteroide);
        int getNombreLignes();
        int getNombreCollones();
        void gererColisions();
        bool colisionAvecBord(Asteroide *asteroide);
        bool partieFinie();
        void augmenterScoreJoueur(int ajouter);
        int getScoreJoueur();
        void modifieeVaisseauSelectionneJoueur(int vaisseau);
        int coordoneeChoixVaisseau(float x, float y);
        void setVaisseauSelectionne(int selection);
        bool ajouterVaisseauCase(int caseSelectionne);
        void incrementerVague();
        bool vagueFinie();
        void gererVague();
        bool plusAsteroide();
};

#endif /* Damier_hpp */
