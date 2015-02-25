//Holds a list of TurnTimers that links the TurnTimer to an I_Creature.

#pragma once
#include "TurnTimer.h"
#include <vector>
#include "Character.h"
#include "I_List.h"
#include "I_Creature.h"

class TurnTimerList : virtual public I_List{    //Change name to CharacterTimerList

private:

    struct CharacterTimer{

        TurnTimer *turnTimer;
        I_Creature *i_Creature;
    };

    //List of the enemies.
    std::vector<CharacterTimer*> listOfTimers;   

    //Sets the variables of the turnTimer.
    void initializeTurnTimerToCharacter(CharacterTimer *characterTimer);
    
public:

    //Constructor.
    TurnTimerList();

    //Destructor.
    virtual ~TurnTimerList();

    //Returns a pointer to the currently selected enemy.
    TurnTimer* getCurrSelection();  

    //Inserts a TurnTimer connected to a Character.
    void addConnection(I_Creature *i_Creature);

    //Deletes the specified TurnTimer.
    virtual bool deleteSelection(int selection);

    //Delete all the CharacterTimers.
    virtual void deleteList();

    //Update turnTimers and resets if full.
    void updateTurnTimers();

    //Draw all timers.
    void drawTurnTimers();
};