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
#include "Enums.h"

class Scenery{

private:

    ALLEGRO_BITMAP *bmap;       //Bitmap with graphics.
    int sx , sy;                //Start location.
    int dx , dy;                //Draw to location.
    int crFrame;                //Frame the Scenery is currently on.
    int w, h;                   //Width and height of the bitmap graphic.
    int moveRateX , moveRateY;  //Rate at which the animation moves.

public:

    //Constructor.
    Scenery(ALLEGRO_BITMAP *bmap , int sx , int sy , int moveRateX , int moveRateY);
    
    void animate(); //Increases the frame count and moves through the animation sequence.
    void setDX(int DX);   //Sets the draw X.
    void setDY(int DY);   //Sets the draw Y.
    void draw();    //Draws the Scenery to the buffer.
};