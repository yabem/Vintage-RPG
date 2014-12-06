//The Scenery class is for objects that are displayed on the map
//but not interacted with by the character. They have their own
//animations and cycles that can move independently from the character
//movements. Default destructor, copy constructor, and assignment operator
//are used.

#include "Scenery.h"
#include <cmath>

//Constructor.
Scenery::Scenery(ALLEGRO_BITMAP *bmap , int sx , int sy, int w , int h , int moveRateX , int moveRateY){

    this->bmap = bmap;
    this->sx = sx;
    this->sy = sy;
    this->dx = this->sx;
    this->dy = this->sy;
    crFrame = 0;
    this->w = w;
    this->h = h;
    this->moveRateX = moveRateX;
    this->moveRateY = moveRateY;
}

//Increases the frame count and moves through the animation sequence.
void Scenery::animate(){

    dx += moveRateX;
    dy += moveRateY;
    crFrame += 1;

    //Check if the Scenery has gone across the entire screen width.
    if(crFrame * abs(moveRateX) > SCREEN_W + w){

        dx = sx;
        dy = sy;
        crFrame = 0;
    }

    //Check if the Scenery has gone across the entire screen height.
    if(crFrame * abs(moveRateY) > SCREEN_H + h){

        dx = sx;
        dy = sy;
        crFrame = 0;
    }
}

//Draws the Scenery to the buffer.
void Scenery::draw(){
    
    al_draw_bitmap_region(bmap , 
        0 , 0 ,             //X and y draw from on bitmap.
        w , h ,             //X and y draw to on bitmap.
        dx , dy , 0);       //X and y draw to on buffer.
}