#include "FallingImage.h"

//Constructor.
FallingImage::FallingImage(ALLEGRO_BITMAP *bmap , float sx , float sy,
    float moveRateX , float moveRateY): 
      Scenery(bmap , sx , sy, moveRateX , moveRateY){
}

//Destructor.
FallingImage::~FallingImage(){

}

//Increases the frame count and moves through the animation sequence.
void FallingImage::animate(){

    dx += moveRateX;
    dy += moveRateY;

    //Check if the Scenery has gone across the entire screen width.
    if(dy >= 0){

        dx = sx;
        dy = sy;
    }
}