#include "FlashingImage.h"

//Constructor.
FlashingImage::FlashingImage(ALLEGRO_BITMAP *bmap , float sx , float sy,
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
    this->crFrame = 0;
    this->drawToScreen = false;
    this->durationOfFlashInFrames = 5;
}

//Destructor.
FlashingImage::~FlashingImage(){

}

void FlashingImage::setDrawToScreenFalse(){

    this->drawToScreen = false;
}

void FlashingImage::setDrawToScreenTrue(){

    this->drawToScreen = true;
}

//Increases the frame count and moves through the animation sequence.
void FlashingImage::animate(){

    if(this->drawToScreen == true){
        this->crFrame++;
    }
}

//Draws the Scenery to the buffer.
void FlashingImage::draw(){

    if(drawToScreen){

        if(crFrame <= durationOfFlashInFrames)
            al_draw_tinted_bitmap(bmap ,al_map_rgba_f(redTransparency,
                greenTransparency , BlueTransparency , transparencyLevel),
                dx, dy, 0);

        else{
            crFrame = 0;
            drawToScreen = false;
        }
            
    }
}