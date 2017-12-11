#include "MyControlEngine.h"

void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int caseCliquee = caseCoordonees(x,y);
        if(caseCliquee < (lignes * colonnes) && caseCliquee != -1){
            damier->recupererCase(caseCliquee)->ajouterVaisseau(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
        } else if(caseCliquee == 1){
            std::cout << "Click bandeau d'info" << std::endl;
        } else {
            std::cerr << "Probleme lors du click, out of range" << std::endl;
        }
    }
}

int MyControlEngine::caseCoordonees(const int x, const int y){
    int hauteurFenetre = glutGet(GLUT_WINDOW_HEIGHT);
    int largeurFenetre = glutGet(GLUT_WINDOW_WIDTH);
    int yDebutDamier = floor(hauteurFenetre * 0.1);
    // si on a clique dans le bandeau d'information
    if(y < yDebutDamier){
        return -1;
    }
    
    int hauteurCase = (hauteurFenetre - yDebutDamier)/ lignes;
    int largeurCase = largeurFenetre / colonnes;
    int ligneCase = (y - yDebutDamier) / hauteurCase;
    int colonneCase = x / largeurCase;
    return (ligneCase * colonnes) + colonneCase;
}
