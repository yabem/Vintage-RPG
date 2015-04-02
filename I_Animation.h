//Interface for all Animations.

#pragma once
#include "Character.h"
#include <cmath>

const double PI = 3.1415926535897932;

class I_Animation{

public:

    I_Animation();
    virtual ~I_Animation();
    virtual bool play() = 0;        //Draws the bitmap animation.   
};