//Holds a list of TurnTimers that links the timer to a TurnTimer.

#pragma once
#include "TurnTimer.h"
#include <vector>
#include "Character.h"
#include "IList.h"

class TurnTimerList : public IList{    //Change name to CharacterTimerList

private:

    struct CharacterTimer{

        TurnTimer *turnTimer;
        Character *character;
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
    void addConnection(Character *character);

    //Deletes the specified TurnTimer.
    virtual bool deleteSelection(int selection);

    //Delete all the CharacterTimers.
    virtual void deleteList();

    //Update turnTimers and resets if full.
    void updateTurnTimers();
};