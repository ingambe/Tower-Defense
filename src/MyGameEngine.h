#pragma once

#include "Engine.h"
#include "Case.hpp"

class MyGameEngine:public GameEngine {
    
private:
    Case** damier;
    int nombre_de_case;
    
public:
    
    MyGameEngine(Case** damier, int nombre_de_case):damier(damier), nombre_de_case(nombre_de_case){}
    
    virtual void idle();
    
};
