//Shows the heat with a yellow filter that pulses.

#pragma once
#include "Scenery.h"

class HeatWave : public Scenery{

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

    HeatWave(ALLEGRO_BITMAP *bmap , float sx , float sy,
        float moveRateX , float moveRateY);

    virtual ~HeatWave();

    void setMinTransparency(float minTransparency);
    void setMaxTransparency(float maxTransparency);
    void setTransparencyIncrementer(float transparencyIncrementer);

    //Increases the frame count and moves through the animation sequence.
    virtual void animate(); 
    virtual void draw();    //Draws the Scenery to the buffer.
};