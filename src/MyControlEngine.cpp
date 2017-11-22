#include "MyControlEngine.h"

void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int caseCliquee = caseCoordonees(x,y);
        if(caseCliquee < ((lignes + 1) * (colonnes + 1))){
            damier[caseCliquee]->ajouterVaisseau();
        } else {
            std::cerr << "Probleme lors du click, out of range" << std::endl;
        }
    }
}

int MyControlEngine::caseCoordonees(const int x, const int y){
    int hauteurCase = glutGet(GLUT_WINDOW_HEIGHT) / (lignes + 1);
    int largeurCase = glutGet(GLUT_WINDOW_WIDTH) / (colonnes + 1);
    int ligneCase = y / hauteurCase;
    int colonneCase = x / largeurCase;
    return (ligneCase * (colonnes + 1)) + colonneCase;
}
