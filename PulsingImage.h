//Shows a pulsing image that fluctuates up and down between transparent
//and opaque.

#pragma once
#include "Scenery.h"

class PulsingImage : public Scenery{

private:

    float transparencyLevel;
    float transparencyIncrementer;
    float redTransparency;
    float greenTransparency;
    float BlueTransparency;
    float minTransparency;
    float maxTransparency;
    float reverse;

public:

    PulsingImage(ALLEGRO_BITMAP *bmap , float sx , float sy,
        float moveRateX , float moveRateY);

    virtual ~PulsingImage();

    void setMinTransparency(float minTransparency);
    void setMaxTransparency(float maxTransparency);
    void setTransparencyIncrementer(float transparencyIncrementer);

    //Increases the frame count and moves through the animation sequence.
    virtual void animate(); 
    virtual void draw();    //Draws the Scenery to the buffer.
};