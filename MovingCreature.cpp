#include "MovingCreature.h"

MovingCreature::MovingCreature(I_Creature *i_Creature , int ttlFrames){

    this->i_Creature = i_Creature;
    this->ttlFrames = ttlFrames;

    this->w = w;
    this->h = h;
    this->sx = 0;
    this->sy = 0;
    this->dx = i_Creature->getX();
    this->dy = i_Creature->getY();
    this->ex = 0;
    this->ey = 0;
    this->xRate = 0;
    this->yRate = 0; 
    this->currFrame = 0;
    this->initialized = false;
}

MovingCreature::~MovingCreature(){

    //Default destructor is fine.
}

//Draws the animaton. Returns false if not complete. Returns true if complete.
bool MovingCreature::play(){

    bool result = false;
    
    //Move instantly if there are no frames.
    if(ttlFrames == 0){
        i_Creature->setX(ex);
        i_Creature->setY(ey);

        result = true;
    }

    //Check if the animation is done.
    else if(currFrame == ttlFrames){
        result = true;
        initialized = false;
        currFrame = 0;
    }
    
    else{

        i_Creature->setX(dx += xRate);
        i_Creature->setY(dy += yRate);
        currFrame++;    
    }

    return result;
}

//Initialize the start and end locations.
void MovingCreature::initialize(int sx , int sy , int ex , int ey){

    this->sx = sx;
    this->sy = sy;
    this->dx = sx;
    this->dy = sy;
    this->ex = ex;
    this->ey = ey;

    //Cannot divide by 0.
    if(ttlFrames != 0){
        this->xRate = (ex - sx) / ttlFrames;
        this->yRate = (ey - sy) / ttlFrames;
    }

    this->initialized = true;
    this->rotate180Rads = atan2(double(sx - ex) , double(sy - ey));
}