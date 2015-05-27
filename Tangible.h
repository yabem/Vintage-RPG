//The Tangible class has objects that are independent from the map
//that the character can interact with. The Tangibles have their
//own collision calculations.

#pragma once
#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "GameConfig.h"

class Tangible{

protected:
    
    ALLEGRO_BITMAP *image;  //Image that has all the graphics.
    int dx , dy;            //Draw to location.
    int w , h;              //Height and width of bitmap.
    int cx , cy;            //Start point for collision detection. Unused at the moment.
    int cw , ch;            //Width and height for collision detection. Unused at the moment.
    int sx , sy;            //Need to add this so I can calculate based off of the original start point.
    std::string identifierName;  //Name used to delete the tangible. Optional.
    
public:

    //Constructor.
    Tangible(ALLEGRO_BITMAP *bmap , int sx , int sy);
    
    //Destructor.
    virtual ~Tangible();

    int getSX() const;      //Return SX value.
    int getSY() const;      //Return SY value.
    int getDX() const;      //Return DX value.
    int getDY() const;      //Return DY value.
    int getCX() const;      //Return CX value. Unused at the moment.
    int getCY() const;      //Return CY value. Unused at the moment.
    int getCW() const;      //Return CW value. Unused at the moment.
    int getCH() const;      //Return CH value. Unused at the moment.
    int getH() const;       //Returns the height.
    int getW() const;       //Returns the width.
    std::string getIdentifierName();    //Returns the identifier name.
    
    bool setDX(int dx);     //Set DX to input.
    bool setDY(int dy);     //Set DY to input.
    void setCW(int cw);     //set the collision width.
    void setCH(int ch);     //Sets the collision height.
    bool addToDX(int add);  //Add value to DX.
    bool addToDY(int add);  //Add value to DY.
    void setIdentifierName(std::string identifierName); //Sets the identifier name.
    
    virtual void draw();             //Draw the Tangible to the buffer.
    virtual void playCutscene(int pressedKey);
};