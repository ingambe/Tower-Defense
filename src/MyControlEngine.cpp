#include "MyControlEngine.h"

void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int caseCliquee = caseCoordonees(x,y);
        if(caseCliquee < (lignes * colonnes)){
            damier->recupererCase(caseCliquee)->ajouterVaisseau(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
        } else {
            std::cerr << "Probleme lors du click, out of range" << std::endl;
        }
    }
}

int MyControlEngine::caseCoordonees(const int x, const int y){
    int hauteurCase = glutGet(GLUT_WINDOW_HEIGHT) / lignes;
    int largeurCase = glutGet(GLUT_WINDOW_WIDTH) / colonnes;
    int ligneCase = y / hauteurCase;
    int colonneCase = x / largeurCase;
    return (ligneCase * colonnes) + colonneCase;
}
