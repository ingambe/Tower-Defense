#pragma once
#include "Engine.h"

class MyControlEngine:public ControlEngine {
    
public:
    MyControlEngine(){}
   
    virtual void MouseCallback(int button, int state, int x, int y) ;
};
