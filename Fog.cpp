#include "Fog.h"

//Constructor.
Fog::Fog(ALLEGRO_BITMAP *bmap , float sx , float sy,
    float moveRateX , float moveRateY): 
      Scenery(bmap , sx , sy, moveRateX , moveRateY){

    this->bmap = bmap;
    this->transparencyLevel = .95;
    this->transparencyIncrementer = .01;
    this->redTransparency = .5;
    this->greenTransparency = .5;
    this->BlueTransparency = .5;
}

//Destructor.
Fog::~Fog(){

}

//Increases the frame count and moves through the animation sequence.
void Fog::animate(){

    /*
    if(redTransparency <= 0.1 || redTransparency >= .99)
        transparencyIncrementer *= -1;

    redTransparency += transparencyIncrementer;
    greenTransparency += transparencyIncrementer;
    BlueTransparency += transparencyIncrementer;
    */
}

//Draws the Scenery to the buffer.
void Fog::draw(){

    al_draw_tinted_bitmap(bmap ,al_map_rgba_f(redTransparency,
        greenTransparency , BlueTransparency , transparencyLevel), 0, 0, 0);
}