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
#include "Asteroides.hpp"
#include "DamierFactory.hpp"

class Damier {
    private:
        Case** cases;
        Asteroides *asteroides;
        int lignes;
        int colonnes;
    public:
        Damier(Case** cases, int lignes, int colonnes):cases(cases), lignes(lignes), colonnes(colonnes){};
        ~Damier();
        Case* recupererCase(int ligne, int colonne);
        Case* recupererCase(int numeroCase);
        void dessiner();
};

#endif /* Damier_hpp */
