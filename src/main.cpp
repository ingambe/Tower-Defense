#include <iostream>
#include "Engine.h"
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"

int main(int argc, char * argv[]){
    Engine e(argc,argv);
    GraphicEngine* ge = new MyGraphicEngine(1, 5);
    GameEngine* gme = new MyGameEngine();
    ControlEngine* ce = new MyControlEngine();
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    e.start();
    return 0;
}
