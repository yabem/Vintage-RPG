#include "PulsingImage.h"

//Constructor.
PulsingImage::PulsingImage(ALLEGRO_BITMAP *bmap , float sx , float sy,
    float moveRateX , float moveRateY): 
      Scenery(bmap , sx , sy, moveRateX , moveRateY){

    this->bmap = bmap;
    this->transparencyLevel = .05;
    this->transparencyIncrementer = .01;
    this->redTransparency = .5;
    this->greenTransparency = .5;
    this->BlueTransparency = .5;
    this->minTransparency = 0.1;
    this->maxTransparency = .99;
    this->reverse = -1;
}

//Destructor.
PulsingImage::~PulsingImage(){

}

void PulsingImage::setMinTransparency(float minTransparency){
    
    this->minTransparency = minTransparency;
}

void PulsingImage::setMaxTransparency(float maxTransparency){
    
    this->maxTransparency = maxTransparency;
}

void PulsingImage::setTransparencyIncrementer(float transparencyIncrementer){

    this->transparencyIncrementer = transparencyIncrementer;
}

//Increases the frame count and moves through the animation sequence.
void PulsingImage::animate(){

    if(redTransparency <= minTransparency || redTransparency >= maxTransparency)
        transparencyIncrementer *= reverse;

    redTransparency += transparencyIncrementer;
    greenTransparency += transparencyIncrementer;
    BlueTransparency += transparencyIncrementer;
}

//Draws the Scenery to the buffer.
void PulsingImage::draw(){

    al_draw_tinted_bitmap(bmap ,al_map_rgba_f(redTransparency,
        greenTransparency , BlueTransparency , transparencyLevel), 0, 0, 0);
}