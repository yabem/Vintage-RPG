//Shows the heat with a yellow filter that pulses.

#pragma once
#include "Scenery.h"

class Fog : public Scenery{

private:

    float transparencyLevel;
    float transparencyIncrementer;
    float redTransparency;
    float greenTransparency;
    float BlueTransparency;

public:

    Fog(ALLEGRO_BITMAP *bmap , float sx , float sy,
        float moveRateX , float moveRateY);

    virtual ~Fog();

    //Increases the frame count and moves through the animation sequence.
    virtual void animate(); 

    virtual void draw();    //Draws the Scenery to the buffer.
};