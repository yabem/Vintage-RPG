#pragma once
#include "I_Animation.h"


class MovingImage: public I_Animation{

private:

    ALLEGRO_BITMAP *bmap;   //Bitmap.
    int w , h;              //Width and height of the bitmap.
    int sx , sy;            //Start location.
    float dx , dy;            //Draw location.
    int ex , ey;            //Destination location.
    float xRate , yRate;      //Rate at which x and y increase in order to get from sx and sy to
                            //dx and dy within the number of frames.
    int currFrame;          //Frame the animation is currently on.
    float ttlFrames;          //Total number of frames the animation lasts.
    bool initialized;       //Keeps track of whether or not the animation has been set.
    double rotate180Rads;   //Radians to rotate 180 degrees.

public:

    //Constructor.
    MovingImage(ALLEGRO_BITMAP *bmap , int w , int h , float ttlFrames); 

    //Destuctor.
    virtual~MovingImage();          
    void initialize(int sx , int sy , int ex , int ey); 
    virtual bool play();            //Draws the bitmap animation.
};