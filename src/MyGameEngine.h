#pragma once
#include "Engine.h"
#include "Case.hpp"
#include "Damier.hpp"
#include "AsteroidesFactory.hpp"

class MyGameEngine:public GameEngine {
    
private:
    Damier* damier;
    int nombre_de_case;
    
public:
    
    MyGameEngine(Damier* damier, int nombre_de_case):damier(damier), nombre_de_case(nombre_de_case){}
    
    virtual void idle();
    
};
