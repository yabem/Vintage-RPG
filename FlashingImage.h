//Shows an image briefly on the screen.

#pragma once
#include "Scenery.h"

class FlashingImage : public Scenery{

private:

    float transparencyLevel;
    float transparencyIncrementer;
    float redTransparency;
    float greenTransparency;
    float BlueTransparency;
    float minTransparency;
    float maxTransparency;
    bool drawToScreen;
    int durationOfFlashInFrames;

public:

    FlashingImage(ALLEGRO_BITMAP *bmap , float sx , float sy,
        float moveRateX , float moveRateY);

    virtual ~FlashingImage();

    void setDrawToScreenFalse();
    void setDrawToScreenTrue();

    //Increases the frame count and moves through the animation sequence.
    virtual void animate(); 
    virtual void draw();    //Draws the Scenery to the buffer.
};