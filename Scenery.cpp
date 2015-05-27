//The Scenery class is for objects that are displayed on the map
//but not interacted with by the character. They have their own
//animations and cycles that can move independently from the character
//movements. Default destructor, copy constructor, and assignment operator
//are used.

#include "Scenery.h"
#include <cmath>

//Default constructor.
Scenery::Scenery(){

    this->bmap = NULL;
    this->sx = 0;
    this->sy = 0;
    this->dx = 0;
    this->dy = 0;
    crFrame = 0;
    this->w = 0;
    this->h = 0;
    this->moveRateX = 0;
    this->moveRateY = 0;
}

//Constructor.
Scenery::Scenery(ALLEGRO_BITMAP *bmap , float sx , float sy,
    float moveRateX , float moveRateY){

    this->bmap = bmap;
    this->sx = sx;
    this->sy = sy;
    this->dx = this->sx;
    this->dy = this->sy;
    crFrame = 0;
    this->w = al_get_bitmap_width(bmap);
    this->h = al_get_bitmap_height(bmap);
    this->moveRateX = moveRateX;
    this->moveRateY = moveRateY;
}

//Destructor.
Scenery::~Scenery(){

}

//Sets the draw X.
void Scenery::setDX(int DX){

    this->dx = DX;
}

//Sets the draw Y.
void Scenery::setDY(int DY){

    this->dy = DY;
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