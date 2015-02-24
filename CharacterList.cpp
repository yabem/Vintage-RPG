#include "CharacterList.h"

//Constructor.
CharacterList::CharacterList(){

    currPosition = 0;
    timerList = NULL;
}

//Destructor.
CharacterList::~CharacterList(){

    //Default is fine.
}

//Returns a pointer to the currently selected Character.
//Pre:  None.
//Post: Returns a pointer to the currently selected Character. 
Character* CharacterList::getCurrSelection(){

    if(!charList.empty())
        return *currSelection;

    else return NULL;
}
    
//Moves the current selection up the list of Characters.
//Pre:  None.
//Post: Moves the currSelection pointer back one location.
//      If the currSelection is already at the front of the list,
//      nothing happens.
void CharacterList::moveSelectionUp(){

    if(currSelection != charList.begin()){
        currSelection--;
        currPosition--;
    }
        
    else{
        //Do nothing.   
    }
}

//Moves the current selection down the list of enemies.
//Pre:  None.
//Post: Moves the currSelection pointer up one location.
//      If the currSelection is already at the end of the list,
//      nothing happens.
void CharacterList::moveSelectionDown(){

    //Make sure the increment won't take 
    //currSelection out of the vector bounds.
    if(currSelection + 1 != charList.end()){
        currSelection++;
        currPosition++;
    }
    
    else {
        //Do nothing
    }
}

//Resets the current selection to the top of the list.
//Pre:  None.
//Post: Sets the currSelecton and currPosition to the beginning of the list.
void CharacterList::resetSelection(){

    currSelection = charList.begin();
    currPosition = 0;
}

//Checks if the selection is at the end of the list.
//Pre:  None.
//Post: Returns true if the current selection is the last Character
//      of the list otherwise returns false.
bool CharacterList::lastCharOfList(){

    if(currSelection + 1 == charList.end())
        return true;

    else return false;
}

//Inserts a Character the list.
//Pre:  None.
//Post: The Character pointer is added to the end of the
//      charList vector.
void CharacterList::loadChar(Character *character){

    charList.push_back(character);
}

//Loads a companion list.
//Pre:  The I_List is not NULL. 
//Post: Adds the I_List to timerList.
void CharacterList::loadList(I_List *i_List){

    this->timerList = i_List;
}

//Checks if the list is empty.
//Pre:  None.
//Post: Returns TRUE if the list is empty. Returns FALSE
//      if at least one Character is in the list.
bool CharacterList::isEmpty(){

    if(charList.empty())
        return true;

    else return false;
}

//Returns the list.
std::vector<Character*> CharacterList::getList(){

    return charList;
}

//Checks to see if the currenty Selected Character is dead.
//Pre:  None.
//Post: Returns TRUE if the currently selected Character is dead.
//      Returns FALSE otherwise.
bool CharacterList::currSelectionIsDead(){

    return (*currSelection)->isDead();
}

//Deletes the currently selected Character.
//Pre:  None.
//Post: Deallocates the Character and removes the pointer
//      from the vector. Resets currSelection to the beginning of the
//      vector.
void CharacterList::deleteCurrSelectedCharacter(){

    delete (*currSelection)->getStats();
    delete *currSelection;
    charList.erase(currSelection);

    //Delete dependencies.
    if(timerList != NULL)
        timerList->deleteSelection(currPosition);

    resetSelection();
}

//Delete the Character in the current position.
//Pre:  None.
//Post: Iterates through the vector to get to the position
//      and then deletes it.
bool CharacterList::deleteSelection(int position){

    if(position > charList.size())
        return false;

    else{
        vector<Character*>::iterator charIter = charList.begin();

        //Sets the iterator to the correct delete position.
        int i = 0;
        while(i < position && charIter != charList.end()){

            i++;
            charIter++;
        }

        charList.erase(charIter);

        return true;
    }
}

//Removes all of the Characters from the list.
//Pre:  None.
//Post: Uses clear to remove all the elements from the list.
void CharacterList::deleteList(){

    charList.clear();
}