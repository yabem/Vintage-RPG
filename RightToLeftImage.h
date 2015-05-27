//Falling image goes from the top of the screen to the bottom.

#pragma once
#include "Scenery.h"

class RightToLeftImage : public Scenery{

private:

public:

    RightToLeftImage(ALLEGRO_BITMAP *bmap , float sx , float sy,
        float moveRateX , float moveRateY);

    virtual ~RightToLeftImage();

    //Increases the frame count and moves through the animation sequence.
    virtual void animate(); 
};