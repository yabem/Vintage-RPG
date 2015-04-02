#include "DelayInSeconds.h"

//Constructor.
//Pre:  finalFrame is not negative.
//Post: Loads the final frame.
DelayInSeconds::DelayInSeconds(float delay){

    this->currentFrame = 0;
    this->ttlFrames = delay * FPS;
}

//Destructor.
DelayInSeconds::~DelayInSeconds(){

    //Default destructor is fine.
}

//Delays the animation playing by the specified amount of time in seconds.
//Pre:  CurrentFrame is not negative.
//Post: Returns false if there are more frames. Returns true when all the
//      frames have been exhausted.
bool DelayInSeconds::play(){

   
    if(currentFrame < ttlFrames){
        
        currentFrame++;
        return false;
    }

    else return true;
}