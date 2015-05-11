#include "Rain.h"

//Constructor.
Rain::Rain(ALLEGRO_BITMAP *bmap , float sx , float sy,
    float moveRateX , float moveRateY): 
      FallingImage(bmap , sx , sy, moveRateX , moveRateY){
}

//Destructor.
Rain::~Rain(){

}

void Rain::draw(){

    al_draw_tinted_bitmap(bmap ,al_map_rgba_f(.5,
        .5 , .5, .5), dx, dy, 0);
}