#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Damier.hpp"
#include "DamierFactory.hpp"

class MyGraphicEngine:public GraphicEngine {
private:
    Damier* damier;
    int nombre_de_case;
    
public:
    MyGraphicEngine(Damier* damier, int nombre_de_case):damier(damier), nombre_de_case(nombre_de_case){}
    virtual void Draw();
};
