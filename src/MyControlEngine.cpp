#include "MyControlEngine.h"


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int caseCliquee = caseCoordonees(x,y);
    }
}

int MyControlEngine::caseCoordonees(const int x, const int y){
    int hauteurCase = 800 / (lignes + 1);
    int largeurCase = 800 / (colonnes + 1);
    int ligneCase = y / hauteurCase;
    int colonneCase = x / largeurCase;
    return (ligneCase * (colonnes + 1)) + colonneCase;
}
