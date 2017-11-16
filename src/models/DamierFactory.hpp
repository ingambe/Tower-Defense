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

class DamierFactory {
    public:
        Case** creerDamier(int lignes, int colonnes);
    private:
        int nombreDeCases(int lignes, int colonnes);
};


#endif /* DamierFactory_hpp */
