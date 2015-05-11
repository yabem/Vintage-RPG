#include "FilterImage.h"

//Constructor.
FilterImage::FilterImage(ALLEGRO_BITMAP *bmap , float sx , float sy,
    float moveRateX , float moveRateY): 
      Scenery(bmap , sx , sy, moveRateX , moveRateY){

    this->bmap = bmap;
    this->transparencyLevel = .95;
    this->transparencyIncrementer = .01;
    this->redTransparency = .5;
    this->greenTransparency = .5;
    this->blueTransparency = .5;
}

//Destructor.
FilterImage::~FilterImage(){

}

//Nothing to animate.
void FilterImage::animate(){}

void FilterImage::setTransparencyLevel(float transparencyAmount){

    this->transparencyLevel = transparencyAmount;
}

void FilterImage::setTransparencyIncrementer(float transparencyAmount){

    this->transparencyIncrementer = transparencyAmount;
}

void FilterImage::setRedTransparency(float transparencyAmount){

    this->redTransparency = transparencyAmount;
}

void FilterImage::setGreenTransparency(float transparencyAmount){

    this->greenTransparency = transparencyAmount;
}

void FilterImage::setBlueTransparency(float transparencyAmount){

    this->blueTransparency = transparencyAmount;
}

//Draws the Scenery to the buffer.
void FilterImage::draw(){

    al_draw_tinted_bitmap(bmap ,al_map_rgba_f(redTransparency,
        greenTransparency , blueTransparency , transparencyLevel), 0, 0, 0);
}