#include "MyGameEngine.h"


void MyGameEngine::idle(){
    tics++;
    if(tics % 100 == 0){
        damier->ajouterAsteroide(AsteroidesFactory::creerAsteroide(0, damier->getNombreLignes(), 0));
    }
    damier->gererColisions();
}
