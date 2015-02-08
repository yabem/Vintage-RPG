#pragma once
#include "Animation.h"


class MovingImage: public Animation{

private:

    ALLEGRO_BITMAP *bmap;   //Bitmap.

public:

    MovingImage(ALLEGRO_BITMAP *bmap , int w , int h , float ttlFrames); //Constructor.
    virtual~MovingImage();          //Destuctor.

    virtual bool play();            //Draws the bitmap animation.
};