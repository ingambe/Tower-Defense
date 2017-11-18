//
//  Case.hpp
//  Projet_CPlusPlus
//
//  Created by Pierre TASSEL on 15/11/2017.
//  Copyright © 2017 Pierre TASSEL. All rights reserved.
//

#ifndef Case_hpp
#define Case_hpp

#include <stdio.h>
#include "GraphicPrimitives.h"

class Case{
    private:
        float x;
        float y;
        float width;
        float height;
    public:
        Case(float x, float y, float width, float height):x(x),y(y),width(width), height(height){}
        Case();
        void dessiner();
};

#endif /* Case_hpp */
