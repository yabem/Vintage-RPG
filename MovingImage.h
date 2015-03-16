#pragma once
#include "Animation.h"


class MovingImage: public Animation{

private:

    ALLEGRO_BITMAP *bmap;   //Bitmap.

public:

    //Constructor.
    MovingImage(ALLEGRO_BITMAP *bmap , int w , int h , float ttlFrames); 

    //Destuctor.
    virtual~MovingImage();          

    virtual bool play();            //Draws the bitmap animation.
};