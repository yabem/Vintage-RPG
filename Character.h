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
#include <string>
#include "GameConfig.h"
#include "Tangible.h"
#include "Stats.h"
#include "I_Creature.h"
#include "I_AI.h"
#include "I_InfoBox.h"
class Menu;

class Character: public I_Creature{

private:

    ALLEGRO_BITMAP *image;   //Bitmap to draw from.
    int facing;             //Direction the character is facing.
    int x , y;              //The x and y values of the upper left corner to start drawing from.
    int crFrame;            //Frame the character is currently on.
    int sequence;           //The animation section the character is on.
    int framesPerSequence;  //The number of frames per animation section.
    int numSequence;        //The total number of animation sections..
    int w, h;               //The width and the height of the bitmap to draw from.
    int moveRate;           //The number of x and y values that the player increases when moving.
    bool collCheck[DIRECTIONS]; //Bool of collisions for up, down, left, and right.
    bool playable;        //Determines if the Character can be played by the user.

    //These variables move along the coordinate plane which means whenever there is movement, either by the
    //player or the map, these values increase and decrease.
    int upperLeftX , upperLeftY;  //Upper left coordinates. 
    int upperRightX , upperRightY;  //Upper right coordinates.
    int lowerRightX , lowerRightY;  //Lower right coordinates.
    int lowerLeftX , lowerLeftY;  //Lower left coordinates.

    Stats *stats;   //Pointer to character statistics.
    Menu *menu;     //Stores the menu.
    std::string abilities;    //The Character's abilities.
    I_AI *AI;       //Stores the AI logic.
    std::string identifierName; //Used for retrieval.

public:

    //Default constructor.
    Character();

    //Constructor.
    Character(ALLEGRO_BITMAP *image , int w , int h , 
        int framesPerSequence , int numSequence , int moveRate); 
   
    //Destructor.
    ~Character();

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
    bool isPlayable() const;                    //Returns if the player is playable.
    bool getCollision(int direction);           //Return the collision value for the direction.
    bool hasCollision() const;                  //Determine if there is a collision.
    Stats* getStats();                          //Return a pointer to the character stats.
    void deleteStats();                         //Deletes the character stats.

    virtual int getCurrHP();                    //Returns the current HP.
    virtual int getTtlHP();                     //Returns the total HP.

    int getAttack() const;                      //Returns the attack stat for the Character.
    int getDefense() const;                     //Returns the defense stat for the Character.
    void addToRemainingHP(int amount);          //Adds the value to the Character's remaining hitpoints.
    void addToTotalXP(int amount);              //Adds to the Character's total xp.
    virtual bool isDead();                      //Returns the dead status of the Character.
    void makePlayable();                        //Makes the Character Playable.
    void makeDead();                            //Makes the Character dead.
    void makeAlive();                           //Makes the Character alive.

    virtual void setImage(ALLEGRO_BITMAP *image);         //Set bitmap to input.
    virtual void setX(int x);                   //Set x to input.
    virtual void setY(int y);                   //Set y to input.
    void setW(int w);                           //Set w to input.
    virtual void setH(int h);                   //Set h to input.
    void addToAllCornerX(int add);              //Add value to all x coordinates.
    void addToAllCornerY(int add);              //Add value to all y coordinates
    bool setFacing(int direction);                  //Set facing direction.
    bool setColl(int index);                    //Set collision index to true.
    void setStats(Stats *stats);                //Set stats pointer to input.
    void resetSequence();                       //Resets the sequence.
    
    void setIdentifierName(std::string identifierName); //Sets the IdentifierName
    std::string getIdentifierName();            //Returns the identifierName.

    void resetColl();                           //Reset all collisions to false.
    void refreshCorners();                      //Recalculate corners based off of x and y values.

    void draw() const;                           //Draw to buffer.
    void animate();                             //Increase frame count.
    int move(bool *keys , int keyPressed);      //Move character based off of keys.

    void loadAbilities(std::string abilities);  //Loads the choices for the Menu.
    void addAbility(std::string ability);       //Adds an ability to the Character's abilities.
    Menu* getMenu();                            //Retrieves the Menu.
    std::string getAbilities();                 //Gets abilities.

    virtual void executeRandomAttack();         //Executes a random attack.

    virtual int getXPReward();
    virtual int getMoneyReward();

};