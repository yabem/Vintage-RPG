//The cursor class creates a horizontal triangle cursor that can point to the
//left or the right. The cursor can move up or down.

#pragma once
#include <allegro5/allegro_primitives.h>
#include "GameConfig.h"  //Used for UP, RIGHT, DOWN, LEFT enumerations.

const int DEFAULT_HEIGHT = 20;
const int DEFAULT_WIDTH = 15;

class Cursor{

private:

    int topX, topY; //The top point.
    int midX, midY; //The middle point.
    int botX, botY; //The bottom point.

    //Red, green, and blue values for the fill color.
    int fillR , fillG , fillB;  
    
    //Red, green, and blue values for the border color.
    int borderR , borderG , borderB;  

    //The direction that the cursor is pointing.
    int pointingDirection;  

public:

    //Creates a Cursor with default values that points to the left.
    Cursor();   

    //Destructor.
    ~Cursor();

    //Draws the cursor to the buffer.
    void draw() const;

    //Moves the cursor to point at the specified location.
    void move(int xCoord , int yCoord); 

    //Swaps the direction of the cursor.
    void reverseDirection();

    //Returns the current direction the cursor is pointing.
    int getPointingDirection() const;
};