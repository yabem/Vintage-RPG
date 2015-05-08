#include "HeatWave.h"

//Constructor.
HeatWave::HeatWave(ALLEGRO_BITMAP *bmap , float sx , float sy,
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
HeatWave::~HeatWave(){

}

void HeatWave::setMinTransparency(float minTransparency){
    
    this->minTransparency = minTransparency;
}

void HeatWave::setMaxTransparency(float maxTransparency){
    
    this->maxTransparency = maxTransparency;
}

void HeatWave::setTransparencyIncrementer(float transparencyIncrementer){

    this->transparencyIncrementer = transparencyIncrementer;
}

//Increases the frame count and moves through the animation sequence.
void HeatWave::animate(){

    if(redTransparency <= minTransparency || redTransparency >= maxTransparency)
        transparencyIncrementer *= reverse;

    redTransparency += transparencyIncrementer;
    greenTransparency += transparencyIncrementer;
    BlueTransparency += transparencyIncrementer;
}

//Draws the Scenery to the buffer.
void HeatWave::draw(){

    al_draw_tinted_bitmap(bmap ,al_map_rgba_f(redTransparency,
        greenTransparency , BlueTransparency , transparencyLevel), 0, 0, 0);
}