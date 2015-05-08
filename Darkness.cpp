#include "Darkness.h"

//Constructor.
Darkness::Darkness(ALLEGRO_BITMAP *bmap , float sx , float sy,
    float moveRateX , float moveRateY): 
      Scenery(bmap , sx , sy, moveRateX , moveRateY){

    this->bmap = bmap;
    this->transparencyLevel = .5;
    this->transparencyIncrementer = .01;
    this->redTransparency = 1;
    this->greenTransparency = 1;
    this->BlueTransparency = 1;
}

//Destructor.
Darkness::~Darkness(){

}

//Nothing to increment.
void Darkness::animate(){}

//Draws the Scenery to the buffer.
void Darkness::draw(){

    al_draw_tinted_bitmap(bmap ,al_map_rgba_f(redTransparency,
        greenTransparency , BlueTransparency , transparencyLevel), 0, 0, 0);
}