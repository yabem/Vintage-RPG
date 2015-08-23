//Moves the character from one location to another.

#pragma once
#include "I_Animation.h"
#include "I_Creature.h"
class MovingCreature : public I_Animation{

private:

    I_Creature *i_Creature;
    int w , h;              //Width and height of the bitmap.
    int sx , sy;            //Start location.
    float dx , dy;            //Draw location.
    int ex , ey;            //Destination location.
    float xRate , yRate;      //Rate at which x and y increase in order to get from sx and sy to
                            //dx and dy within the number of frames.
    int currFrame;          //Frame the animation is currently on.
    float ttlFrames;          //Total number of frames the animation lasts.
    bool initialized;       //Keeps track of whether or not the animation has been set.

public:

    MovingCreature(I_Creature *i_Creature , int ttlFrames);
    virtual ~MovingCreature();
        
    //Initialize the start and end locations.
    void initialize(int sx , int sy , int ex , int ey); 
    virtual bool play();
};