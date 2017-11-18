#include <iostream>
#include "Engine.h"
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"

int main(int argc, char * argv[]){
    Engine e(argc,argv);
    const int lignes = 1;
    const int colonnes = 10;
    
    Case** damier = DamierFactory().creerDamier(lignes, colonnes);
    int nombre_de_case = DamierFactory().nombreDeCases(lignes, colonnes);
    
    GraphicEngine* ge = new MyGraphicEngine(damier, nombre_de_case);
    ControlEngine* ce = new MyControlEngine(damier, lignes, colonnes);
    GameEngine* gme = new MyGameEngine();
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    e.start();
    return 0;
}
