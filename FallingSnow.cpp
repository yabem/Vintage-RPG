#include "FallingSnow.h"

//Constructor.
FallingSnow::FallingSnow(ALLEGRO_BITMAP *bmap , float sx , float sy,
    float moveRateX , float moveRateY): 
      Scenery(bmap , sx , sy, moveRateX , moveRateY){
}

//Destructor.
FallingSnow::~FallingSnow(){

}

//Increases the frame count and moves through the animation sequence.
void FallingSnow::animate(){

    dx += moveRateX;
    dy += moveRateY;

    //Check if the Scenery has gone across the entire screen width.
    //if(crFrame * abs(moveRateX) > SCREEN_W + w){
    if(dy >= 0){

        dx = sx;
        dy = sy;
    }
}