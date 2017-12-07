#include "MyGraphicEngine.h"
#include <string.h>
using namespace std;

void MyGraphicEngine::Draw(){
    for(int i = 0; i < nombre_de_case; i++){
        damier->recupererCase(i)->dessiner();
    }
}
