#include "RightToLeftImage.h"

//Constructor.
RightToLeftImage::RightToLeftImage(ALLEGRO_BITMAP *bmap , float sx , float sy,
    float moveRateX , float moveRateY): 
      Scenery(bmap , sx , sy, moveRateX , moveRateY){
}

//Destructor.
RightToLeftImage::~RightToLeftImage(){

}

//Increases the frame count and moves through the animation sequence.
void RightToLeftImage::animate(){

    dx += moveRateX;
    dy += moveRateY;

    //Check if the Scenery has gone across the entire screen height.
    if(dx <= -640){

        dx = sx;
        dy = sy;
    }
}