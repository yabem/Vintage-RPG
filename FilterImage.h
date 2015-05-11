

#pragma once
#include "Scenery.h"

class FilterImage : public Scenery{

private:

    float transparencyLevel;
    float transparencyIncrementer;
    float redTransparency;
    float greenTransparency;
    float blueTransparency;

public:

    FilterImage(ALLEGRO_BITMAP *bmap , float sx , float sy,
        float moveRateX , float moveRateY);

    virtual ~FilterImage();

    //Increases the frame count and moves through the animation sequence.
    virtual void animate(); 
    void setTransparencyLevel(float transparencyAmount);
    void setTransparencyIncrementer(float transparencyAmount);
    void setRedTransparency(float transparencyAmount);
    void setGreenTransparency(float transparencyAmount);
    void setBlueTransparency(float transparencyAmount);

    virtual void draw();    //Draws the Scenery to the buffer.
};