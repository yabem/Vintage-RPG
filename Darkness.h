//Puts a shadow filter over the screen.

#pragma once
#include "Scenery.h"

class Darkness : public Scenery{

private:

    float transparencyLevel;
    float transparencyIncrementer;
    float redTransparency;
    float greenTransparency;
    float BlueTransparency;

public:

    Darkness(ALLEGRO_BITMAP *bmap , float sx , float sy,
        float moveRateX , float moveRateY);

    virtual ~Darkness();

    //Increases the frame count and moves through the animation sequence.
    virtual void animate(); 

    virtual void draw();    //Draws the Scenery to the buffer.
};