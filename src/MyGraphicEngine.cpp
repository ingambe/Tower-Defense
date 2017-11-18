#include "MyGraphicEngine.h"
#include <string.h>
using namespace std;

MyGraphicEngine::MyGraphicEngine(const int lignes, const int colonnes){
    damier = DamierFactory().creerDamier(lignes, colonnes);
    nombre_de_case = DamierFactory().nombreDeCases(lignes, colonnes);
}

void MyGraphicEngine::Draw(){
    
}
