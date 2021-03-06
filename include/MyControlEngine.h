#pragma once
#include "Engine.h"
#include "Case.hpp"
#include "Damier.hpp"
#include <math.h>

class MyControlEngine:public ControlEngine {
    
private:
    int lignes;
    int colonnes;
    Damier* damier;
    int caseCoordonees(const int x, const int y);
    
public:
    MyControlEngine(Damier* damier, int lignes, int colonnes):damier(damier),lignes(lignes),colonnes(colonnes){}
    virtual void MouseCallback(int button, int state, int x, int y) ;
    virtual void KeyboardCallback(unsigned char key,int x, int y);
};
