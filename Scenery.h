//The Scenery class is for objects that are displayed on the map
//but not interacted with by the character. They have their own
//animations and cycles that can move independently from the character
//movements. Default destructor, copy constructor, and assignment operator
//are used.

#pragma once
#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "GameConfig.h"

class Scenery{

protected:

    ALLEGRO_BITMAP *bmap;       //Bitmap with graphics.
    float sx , sy;                //Start location.
    float dx , dy;                //Draw to location.
    int crFrame;                //Frame the Scenery is currently on.
    int w, h;                   //Width and height of the bitmap graphic.
    float moveRateX , moveRateY;  //Rate at which the animation moves.

public:

    //Constructor.
    Scenery(ALLEGRO_BITMAP *bmap , float sx , float sy , float moveRateX , float moveRateY);
    
    //Destructor.
    virtual ~Scenery();
    
    virtual void animate(); //Increases the frame count and moves through the animation sequence.
    void setDX(int DX);   //Sets the draw X.
    void setDY(int DY);   //Sets the draw Y.
    virtual void draw();    //Draws the Scenery to the buffer.
};