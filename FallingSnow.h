//Falling snow is snow that goes from the top of the screen to
//the bottom.

#pragma once
#include "Scenery.h"

class FallingSnow : public Scenery{

private:

public:

    FallingSnow(ALLEGRO_BITMAP *bmap , float sx , float sy,
        float moveRateX , float moveRateY);

    virtual ~FallingSnow();

    //Increases the frame count and moves through the animation sequence.
    virtual void animate(); 
};