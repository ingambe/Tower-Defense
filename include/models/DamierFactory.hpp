//
//  DamierFactory.hpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 15/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#ifndef DamierFactory_hpp
#define DamierFactory_hpp

#include <stdio.h>
#include "Case.hpp"
#include "Damier.hpp"
#include <iostream>

class DamierFactory {
    public:
        static Damier* creerDamier(const int lignes, const int colonnes);
        static int nombreDeCases(const int lignes, const int colonnes);
};

#endif /* DamierFactory_hpp */
