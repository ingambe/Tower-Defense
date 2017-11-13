#include "MyGraphicEngine.h"
#include <string.h>
using namespace std;
void MyGraphicEngine::Draw(){
    
    GraphicPrimitives::drawLine2D(0.0f,0.5f,1.0f,-0.5f,1.0f,0.0f,1.0f);
    GraphicPrimitives::drawText2D("la",-1.0f,0.9f,0.0f,0.0f, 1.0f);
    
}

