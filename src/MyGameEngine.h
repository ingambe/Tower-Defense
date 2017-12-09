#pragma once
#include <time.h>
#include "Engine.h"
#include "Case.hpp"
#include "Damier.hpp"
#include "AsteroidesFactory.hpp"
#include <stdlib.h>

class MyGameEngine:public GameEngine {
    
private:
    Damier* damier;
    int nombre_de_case;
    int tics;
    
public:
    
    MyGameEngine(Damier* damier, int nombre_de_case):damier(damier), nombre_de_case(nombre_de_case), tics(0){
        srand(time(NULL));
    }
    
    virtual void idle();
    
};
