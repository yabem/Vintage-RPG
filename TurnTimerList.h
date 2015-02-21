//Holds a list of TurnTimers that links the timer to a TurnTimer.

#pragma once
#include "TurnTimer.h"
#include <vector>
#include "Character.h"
#include "IList.h"

class TurnTimerList : public IList{    //Change name to CharacterTimerList

public:
//private:

    struct CharacterTimer{

        TurnTimer *turnTimer;
        Character *character;
    };

    //List of the enemies.
    std::vector<CharacterTimer*> listOfTimers;   

    //Sets the variables of the turnTimer.
    void initializeTurnTimerToCharacter(CharacterTimer *characterTimer);
    
//public:

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
    void deleteList();



    //Checks if the list is empty.
    //bool isEmpty();

    //Returns the list.
    //std::vector<TurnTimer*> getList();

    //Deletes the currently selected TurnTimer.
    //void deleteCurrSelectedTurnTimer();
};