#include "MovingImage.h"

MovingImage::MovingImage(ALLEGRO_BITMAP *bmap , int w , int h , float ttlFrames){

    this->bmap = bmap;
    this->w = w;
    this->h = h;
    this->sx = 0;
    this->sy = 0;
    this->dx = 0;
    this->dy = 0;
    this->ex = 0;
    this->ey = 0;
    this->xRate = 0;
    this->yRate = 0;
    this->ttlFrames = ttlFrames;
    this->currFrame = 0;
    this->initialized = false;
}

MovingImage::~MovingImage(){

    //Default destructor is fine.
}

//Draws the animaton. Returns false if not complete. Returns true if complete.
bool MovingImage::play(){

    bool result = false;
    currFrame++;    //Increase the frame.

    //Check if the animation is done.
    if(currFrame == ttlFrames){
        result = true;
        initialized = false;
        currFrame = 0;
    }
    
    else{

        dx += xRate;
        dy += yRate;

        //Draw bitmap to the buffer.
        al_draw_bitmap_region(bmap , 
            BMAPXSTART , BMAPYSTART ,             //X and y draw from on bitmap.
            w , h ,                               //X and y draw to on bitmap.
            dx , dy , 0);                         //X and y draw to on buffer.
    }

    return result;
}