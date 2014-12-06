#pragma once
#include "Character.h"

class Animation{

protected:

    //ALLEGRO_BITMAP *bmap;   //Bitmap.
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

    Animation();
    Animation(int w , int h , float ttlFrames);
    virtual ~Animation();
    virtual bool play();        //Draws the bitmap animation.
    virtual void initialize(int sx , int sy , int ex , int ey);     //Initialize the start and end locations.
    
};