//The Character class has all the information for a character such as
//the bitmap and the draw location. It also stores an animation feature
//and the location to draw the character to the buffer. Default destructor,
//copy constructor, and assignment operator.

#pragma once
#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "Enums.h"
#include "Tangible.h"

//Forward declarations.
class Stats;

class Character{

private:

    ALLEGRO_BITMAP *bmap;   //Bitmap to draw from.
    int facing;             //Direction the character is facing.
    int x , y;              //The x and y values of the upper left corner to start drawing from.
    int crFrame;            //Frame the character is currently on.
    int sequence;           //The animation section the character is on.
    int framesPerSequence;  //The number of frames per animation section.
    int numSequence;        //The total number of animation sections..
    int w, h;               //The width and the height of the bitmap to draw from.
    int moveRate;           //The number of x and y values that the player increases when moving.
    bool collCheck[DIRECTIONS]; //Bool of collisions for up, down, left, and right.

    //These variables move along the coordinate plane which means whenever there is movement, either by the
    //player or the map, these values increase and decrease.
    int upperLeftX , upperLeftY;  //Upper left coordinates. 
    int upperRightX , upperRightY;  //Upper right coordinates.
    int lowerRightX , lowerRightY;  //Lower right coordinates.
    int lowerLeftX , lowerLeftY;  //Lower left coordinates.

    Stats *stats;   //Pointer to character statistics.

public:

    //Default constructor.
    Character();

    //Constructor.
    Character(ALLEGRO_BITMAP *bmap , int w , int h , 
        int framesPerSequence , int numSequence , int moveRate); 
   
    //~Character();

    int getX() const;                           //Return x value.   
    int getY() const;                           //Return y value.
    int getW() const;                           //Return width.
    int getH() const;                           //Return height.
    int getFacing() const;                      //Return facing.
    int getUpperRightX() const;                 //Return upper right x value.
    int getUpperRightY() const;                 //Return upper right y value.
    int getUpperLeftX() const;                  //Return upper left x value.
    int getUpperLeftY() const;                  //Return upper left y value.
    int getLowerRightX() const;                 //Return lower right x value.
    int getLowerRightY() const;                 //Return lower right y value.
    int getLowerLeftX() const;                  //Return lower left x value.
    int getLowerLeftY() const;                  //Return lower left y value.
    bool getCollision(int direction);           //Return the collision value for the direction.
    Stats* getStats();                          //Return a pointer to the character stats.

    void setBmap(ALLEGRO_BITMAP *bmap);         //Set bitmap to input.
    void setX(int x);                           //Set x to input.
    void setY(int y);                           //Set y to input.
    void setW(int w);                           //Set w to input.
    void setH(int h);                           //Set h to input.
    void addToAllCornerX(int add);              //Add value to all x coordinates.
    void addToAllCornerY(int add);              //Add value to all y coordinates
    bool setFacing(int dir);                    //Set facing direction.
    bool setColl(int index);                    //Set collision index to true.
    void setStats(Stats *stats);               //Set stats pointer to input.

    void resetColl();                           //Reset all collisions to false.
    void refreshCorners();                      //Recalculate corners based off of x and y values.

    int draw() const;                                 //Draw to buffer.
    void animate();                             //Increase frame count.
    int move(bool *keys , int keyPressed);      //Move character based off of keys.
};