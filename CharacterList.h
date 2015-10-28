//Holds a list of Characters that can be traversed. There is a 
//current selection that keeps track of the enemy that is currently chosen.

#pragma once

#include <vector>
#include "Character.h"
#include "I_List.h"

class CharacterList : virtual public I_List{

private:
    //List of the enemies.
    std::vector<Character*> charList;   

    //Currently selected enemy in the list.
    std::vector<Character*>::iterator currSelection;  

    //Used for deletions.
    int currPosition;

    //List of added lists.
    vector<I_List*> addedLists;

    //List of timers.
    I_List *timerList;

    //Size of the list.
    int size;
    
public:

    //Constructor.
    CharacterList();

    //Destructor.
    virtual ~CharacterList();

    //Returns a pointer to the currently selected enemy.
    Character* getCurrSelection();  

    //Sets the current selection to the specific character.
    void setCurrSelection(Character *character);

    //Returns a pointer to the specified position.
    Character* getCharacterSelection(int position);
    
    //Moves the current selection up the list of Characters.
    void moveSelectionUp();

    //Moves the current selection down the list of Characters.
    void moveSelectionDown();

    //Resets the current selection to the top of the list.
    void resetSelection();

    //Checks if the selection is at the end of the list.
    bool lastCharOfList();

    //Inserts a Character the list.
    void loadChar(Character *character);

    //Loads a list to the depencen.
    void loadList(I_List *i_List);

    //Checks if the list is empty.
    bool isEmpty();

    //Returns the size of the list.
    virtual int getSize() const;

    //Returns the list.
    std::vector<Character*> getList();

    //Checks to see if the currenty Selected Character is dead.
    bool currSelectionIsDead();

    //Deletes the currently selected Character.
    void deleteCurrSelectedCharacter();

    //Delete the Character in the current position.
    virtual bool deleteSelection(int position);    

    //Removes all the Characters in the charList.
    void deleteCharList();

    //Removes all the elements from the dependency lists.
    virtual void deleteList();

    //Removes all of the dependencies from the list.
    void deleteAddedLists();
};