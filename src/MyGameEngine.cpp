#include "MyGameEngine.h"


void MyGameEngine::idle(){
    if(!damier->partieFinie()){
        damier->gererVague();
        damier->gererColisions();
    }
}
