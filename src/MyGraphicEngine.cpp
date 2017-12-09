#include "MyGraphicEngine.h"
#include <string.h>
using namespace std;

void MyGraphicEngine::Draw(){
    if(!damier->partieFinie()){
        damier->dessiner();
    } else {
        GraphicPrimitives::drawText2D("Partie Finie", -0.15f, 0.0f, 0.5f, 0.5f, 0.5f, 1.0f);
        char *stringScore = new char[50];
        sprintf(stringScore, "Votre score est de %d", damier->getScoreJoueur());
        GraphicPrimitives::drawText2D(stringScore, -0.25f, -0.2f, 0.5f, 0.5f, 0.5f, 1.0f);
        if(stringScore != NULL){
            delete[] stringScore;
        }
        stringScore = NULL;
    }
}
