#include "Cursor.h"

//Creates a Cursor with default values.
//Pre:  None.
//Post: Creates a cursor with a 
Cursor::Cursor(){

    this->topX = 1;
    this->topY = 1;
    this->midX = topX + DEFAULT_WIDTH;
    this->midY = topY + (DEFAULT_HEIGHT / 2);
    this->botX = 1;
    this->botY = DEFAULT_HEIGHT; 

    //Default fill blue color.
    fillR = 150;
    fillG = 150;
    fillB = 150;

    //Default border white color.
    borderR = 255;
    borderG = 255;
    borderB = 255;

    pointingDirection = RIGHT;  
}

//Destructor.
Cursor::~Cursor(){

    //Default is fine.
}


//Draws the cursor to the buffer.
//Pre:  None.
//Post: Draws the filled in triangle to the buffer first then draws the
//      border triangle.
void Cursor::draw() const{

    //Filled in triangle.
    al_draw_filled_triangle(
        topX, topY,     //Upper point
        midX , midY,    //Middle point
        botX, botY,     //Lower point
        al_map_rgb(fillR, fillG, fillB));
                       
    //Triangle border.
    al_draw_triangle(
        topX, topY,     //Upper point
        midX , midY,    //Middle point
        botX, botY,     //Lower point
        al_map_rgb(borderR, borderG, borderB) , 2);
}

//Moves the cursor to point at the specified location.
//Pre:  None.
//Post: Updates all of the coordinates so the cursor mid point
//      points to the destination specified by xCoord
//      and yCoord by calculating the offset and applying it to
//      all other points.
void Cursor::move(int xCoord , int yCoord){

    int offsetX = xCoord - midX;
    int offsetY = yCoord - midY;

    topX += offsetX;
    topY += offsetY;
    midX += offsetX;
    midY += offsetY;
    botX += offsetX;
    botY += offsetY;
}

//Swaps the direction of the cursor.
//Pre:  None.
//Post: Changes the direction by calculating the X offset
//      coordinate by subtracting the current mid point from the
//      vertical line of the triangle. The difference is then subtracted
//      twice from the midX to reverse the direction.
void Cursor::reverseDirection(){
    
    int offsetX = abs(topX - midX) * 2;

    //Change cursor to point right.
    if(pointingDirection == LEFT){
        midX += offsetX;
        pointingDirection = RIGHT;
    }
    
    //Change cursor to point left.
    else{ 
        midX -= offsetX;
        pointingDirection = LEFT;
    }
}

//Returns the current direction the cursor is pointing.
//Pre:  None.
//Post: Returns the integer value that the cursor is currently
//      pointing to. For the meanings of the values see "GameConfig.h"
int Cursor::getPointingDirection() const{

    return pointingDirection;
}