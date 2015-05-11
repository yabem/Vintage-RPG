//Falling image goes from the top of the screen to the bottom.

#pragma once
#include "Scenery.h"

class FallingImage : public Scenery{

private:

public:

    FallingImage(ALLEGRO_BITMAP *bmap , float sx , float sy,
        float moveRateX , float moveRateY);

    virtual ~FallingImage();

    //Increases the frame count and moves through the animation sequence.
    virtual void animate(); 
};