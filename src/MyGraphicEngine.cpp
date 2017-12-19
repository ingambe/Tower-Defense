#include "MyGraphicEngine.h"
#include <string.h>
using namespace std;

void MyGraphicEngine::Draw(){
    if(!damier->partieFinie()){
        damier->dessiner();
        if(damier->vagueFinie()){
            GraphicPrimitives::drawText2D("Appuyer sur Entree pour lancer une nouvelle vague", -0.5f, 0.0f, 1.0f, 1.0f, 1.0f);
        }
    } else {
        GraphicPrimitives::drawText2D("Partie Finie", -0.10f, 0.2f, 1.0f, 1.0f, 1.0f, 1.0f);
        char *stringScore = new char[50];
        sprintf(stringScore, "Votre score est de %d", damier->getScoreJoueur());
        GraphicPrimitives::drawText2D(stringScore, -0.20f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
        if(damier->getNumeroVague() == 1){
            sprintf(stringScore, "Vous avez survecu a %d vague", damier->getNumeroVague());
        } else {
            sprintf(stringScore, "Vous avez survecu a %d vagues", damier->getNumeroVague());
        }
        GraphicPrimitives::drawText2D(stringScore, -0.30f, -0.2f, 1.0f, 1.0f, 1.0f, 1.0f);
        GraphicPrimitives::drawText2D("Cree par Pierre TASSEL", 0.45f, -0.85f, 1.0f, 1.0f, 1.0f, 0.5f);
        if(stringScore != NULL){
            delete[] stringScore;
        }
        stringScore = NULL;
        /**
        if(damier != NULL){
            delete damier;
        }
        damier = NULL;
         **/
    }
}
