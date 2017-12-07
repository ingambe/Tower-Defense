#pragma once
#include "Engine.h"
#include "Case.hpp"
#include "Damier.hpp"
#include "AsteroidesFactory.hpp"

class MyGameEngine:public GameEngine {
    
private:
    Damier* damier;
    int nombre_de_case;
    int tics;
    
public:
    
    MyGameEngine(Damier* damier, int nombre_de_case):damier(damier), nombre_de_case(nombre_de_case), tics(0){}
    
    virtual void idle();
    
};
