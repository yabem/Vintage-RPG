//Holds a list of Characters that can be traversed. There is a 
//current selection that keeps track of the enemy that is currently chosen.

#pragma once

#include <vector>
#include "Character.h"

class CharacterList{

private:
    //List of the enemies.
    std::vector<Character*>  charList;   

    //Currently selected enemy in the list.
    std::vector<Character*>::iterator currSelection;  
    
public:

    //Constructor.
    CharacterList();

    //Destructor.
    ~CharacterList();

    //Returns a pointer to the currently selected enemy.
    Character* getCurrSelection();  
    
    //Moves the current selection up the list of Characters.
    void moveSelectionUp();

    //Moves the current selection down the list of Characters.
    void moveSelectionDown();

    //Resets the current selection to the top of the list.
    void resetSelection();

    //Inserts a Character the list.
    void loadChar(Character *character);

    //Checks if the list is empty.
    bool isEmpty();

    //Returns the list.
    std::vector<Character*> getList();

    //Checks to see if the currenty Selected Character is dead.
    bool currSelectionIsDead();

    //Deletes the currently selected Character.
    void deleteCurrSelectedCharacter();
};