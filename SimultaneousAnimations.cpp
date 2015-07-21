#include "SimultaneousAnimations.h"

//Constructor.
SimultaneousAnimations::SimultaneousAnimations(){

}

//Destructor.
SimultaneousAnimations::~SimultaneousAnimations(){

    std::vector<I_Animation*>::iterator animIter = animations.begin();

    while(animIter != animations.end()){

        delete (*animIter);
        animIter++;
    }

    animations.clear();
}

//Loads an animation.
void SimultaneousAnimations::loadAnimation(I_Animation *i_Animation){

    animations.push_back(i_Animation);
}

//Draws the animaton. Returns false if not complete. Returns true if complete.
bool SimultaneousAnimations::play(){

    std::vector<I_Animation*>::iterator animIter = animations.begin();

    while(animIter != animations.end()){
        
        //Delete the animation if it's not NULL and done.
        if((*animIter) != NULL && (*animIter)->play() == true){

            delete (*animIter);
            (*animIter) = NULL;
        }

        animIter++;
    }

    if(allAnimationsAreNULL()){
        return true;
    }

    else{
        return false;
    }
}

//Determines if all the Animations are set to NULL
//Pre:  None.
//Post: Cycles through all the I_Animation objects in Animations.
//      Returns true if all the I_Animations are NULL. Returns false
//      Otherwise.
bool SimultaneousAnimations::allAnimationsAreNULL(){

    std::vector<I_Animation*>::iterator animIter = animations.begin();

    while(animIter != animations.end()){

        if((*animIter) != NULL){
            return false;
        }
        else{
            animIter++;
        }
    }

    return true;
}