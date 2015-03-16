#include "Animation.h"

//Default constructor.
Animation::Animation(){

    //this->bmap = NULL;
    this->w = 0;
    this->h = 0;
    this->sx = 0;
    this->sy = 0;
    this->dx = 0;
    this->dy = 0;
    this->ex = 0;
    this->ey = 0;
    this->xRate = 0;
    this->yRate = 0;
    this->ttlFrames = 0;
    this->currFrame = 0;
    this->initialized = false;
}

//Constructor with parameters.
Animation::Animation(int w , int h , float ttlFrames){

}

Animation::~Animation(){

    //Default is fine.
}

//Draws the animaton. Returns false if not complete. Returns true if complete.
bool Animation::play(){

    return false;
}

//Initialize the start and end locations.
void Animation::initialize(int sx , int sy , int ex , int ey){

    this->sx = sx;
    this->sy = sy;
    this->dx = sx;
    this->dy = sy;
    this->ex = ex;
    this->ey = ey;

    this->xRate = (ex - sx) / ttlFrames;
    this->yRate = (ey - sy) / ttlFrames;

    this->initialized = true;
    this->rotate180Rads = atan2(double(sx - ex) , double(sy - ey));
}