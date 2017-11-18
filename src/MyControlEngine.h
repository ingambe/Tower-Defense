#pragma once
#include "Engine.h"
#include "Case.hpp"

class MyControlEngine:public ControlEngine {
    
private:
    int lignes;
    int colonnes;
    Case** damier;
    int caseCoordonees(const int x, const int y);
    
public:
    MyControlEngine(Case** damier, int lignes, int colonnes):damier(damier),lignes(lignes),colonnes(colonnes){}
    virtual void MouseCallback(int button, int state, int x, int y) ;
};
