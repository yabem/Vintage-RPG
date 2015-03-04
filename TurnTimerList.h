//Holds a list of TurnTimers that links the TurnTimer to an I_Creature.

#pragma once
#include "TurnTimer.h"
#include <vector>
#include "Character.h"
#include "I_List.h"
#include "I_Creature.h"
#include "I_Manager.h"

class TurnTimerList : public I_List{    //Change name to CharacterTimerList

private:

    struct CharacterTimer{

        TurnTimer *turnTimer;
        I_Creature *i_Creature;
    };

    I_Manager *battleManager;

    //List of the enemies.
    std::vector<CharacterTimer*> listOfCharTimers;   

    //Sets the variables of the turnTimer.
    void initializeTurnTimerToCharacter(CharacterTimer *characterTimer);
    
public:

    //Constructor.
    TurnTimerList();

    //Destructor.
    virtual ~TurnTimerList();

    //Load I_Manager.
    void loadManager(I_Manager *i_Manager);

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