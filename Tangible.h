//The Tangible class has objects that are independent from the map
//that the character can interact with. The Tangibles have their
//own collision calculations.

#pragma once
#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "Enums.h"

class Tangible{

private:
    
    ALLEGRO_BITMAP *bmap;   //Bitmap that has all the graphics.
    int dx , dy;            //Draw to location.
    int w , h;              //Height and width of bitmap.
    int cx , cy;            //Start point for collision detection.
    int cw , ch;            //Width and height for collision detection.
    int sx , sy;            //Need to add this so I can calculate based off of the original start point.
    
public:

    //Constructor.
    Tangible(ALLEGRO_BITMAP *bmap , int sx , int sy , int w , int h , int cx , int cy , int cw , int ch);
    
    int getSX() const;      //Return SX value.
    int getSY() const;      //Return SY value.
    int getDX() const;      //Return DX value.
    int getDY() const;      //Return DY value.
    int getCX() const;      //Return CX value.
    int getCY() const;      //Return CY value.
    int getCW() const;      //Return CW value.
    int getCH() const;      //Return CH value.
    
    bool setDX(int dx);     //Set DX to input.
    bool setDY(int dy);     //Set DY to input.
    bool addToDX(int add);  //Add value to DX.
    bool addToDY(int add);  //Add vaue to DY.
    
    void draw();             //Draw the Tangible to the buffer.
};