#include "MyGameEngine.h"


void MyGameEngine::idle(){
    if(!damier->partieFinie()){
        tics++;
        if(tics % 100 == 0){
            damier->ajouterAsteroide(AsteroidesFactory::creerAsteroide(rand() % damier->getNombreLignes(), damier->getNombreLignes(), 0));
        }
        damier->gererColisions();
    }
}
