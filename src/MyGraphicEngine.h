#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Case.hpp"
#include "DamierFactory.hpp"

class MyGraphicEngine:public GraphicEngine {
private:
    Case** damier;
    int nombre_de_case;
    
public:
    MyGraphicEngine(Case** damier, int nombre_de_case):damier(damier), nombre_de_case(nombre_de_case){}
    virtual void Draw();
};
