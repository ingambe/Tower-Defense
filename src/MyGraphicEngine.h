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
    MyGraphicEngine(const int lignes, const int colonnes);
    virtual void Draw();
};
