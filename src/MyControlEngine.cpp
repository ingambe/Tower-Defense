#include "MyControlEngine.h"

void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int caseCliquee = caseCoordonees(x,y);
        if(caseCliquee < (lignes * colonnes) && caseCliquee != -1){
            damier->ajouterVaisseauCase(caseCliquee);
        } else if(caseCliquee == -1){
            int choixVaisseau = damier->coordoneeChoixVaisseau(2.0f * ((1.0f * x) / glutGet(GLUT_WINDOW_WIDTH)) - 1.0f, 2.0f * ((1.0f * -y) / glutGet(GLUT_WINDOW_HEIGHT)) + 1.0f);
            damier->setVaisseauSelectionne(choixVaisseau);
        } else {
            std::cerr << "Probleme lors du click, out of range" << std::endl;
        }
    }
}

void MyControlEngine::KeyboardCallback(unsigned char key,int x, int y){
    if(damier->vagueFinie() && !damier->partieFinie() && key == '\n'){
        damier->incrementerVague();
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
