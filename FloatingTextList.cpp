#include "FloatingTextList.h"

//Constructor.
FloatingTextList::FloatingTextList(){

}

//Destructor.
FloatingTextList::~FloatingTextList(){

    deleteList();
}

//Loads the FontStore.
void FloatingTextList::loadFontStore(FontStore *fontStore){

    this->fontStore = fontStore;
}

//Inserts a FloatingText connected to a Character.
//Pre:  None.
//Post: Creates a CharacterTimer with a FloatingText and the input Character.
//      The CharacterTimer is pushed to the end of the vector.
void FloatingTextList::addFloatingTextConnection(I_Creature *i_Creature){

    //Create and load the CharacterFloatText.
    CharacterFloatText *characterFloatText = new CharacterFloatText;
    FloatingText *floatingText = 
        new FloatingText(fontStore->getFont("battleFont"));
    
    characterFloatText->floatingText = floatingText;
    characterFloatText->i_Creature = i_Creature;

    floatingText->setFloatingTextToTopOfCreature(i_Creature);

    listOfCharFloatTexts.push_back(characterFloatText);
}

//Gets the specified FloatingText.
//Pre: The selection is within the bounds of the vector.
//Post: Returns a pointer to the FloatingText. If the position is outside of the
//      vector returns NULL.
FloatingText* FloatingTextList::getFloatingTextSelection(int selection){

    if(listOfCharFloatTexts.empty())
        return NULL;

    else{
        std::vector<CharacterFloatText*>::iterator floatingTextsIter 
            = listOfCharFloatTexts.begin();

        //Sets the iterator to the correct delete selection.
        int i = 0;
        while(i < selection && floatingTextsIter != listOfCharFloatTexts.end()){

            i++;
            floatingTextsIter++;
        }

        return listOfCharFloatTexts[selection]->floatingText;
    }
}

//Deletes the specified FloatingText.
//Pre:  The position is within the bounds of the vector.
//Post: Deletes the FloatingText in the position.
//      Returns true if the delete was successful, otherwise
//      returns false.
bool FloatingTextList::deleteSelection(int position){

    if(listOfCharFloatTexts.empty())
        return false;

    else{
        std::vector<CharacterFloatText*>::iterator floatingTextsIter 
            = listOfCharFloatTexts.begin();

        //Sets the iterator to the correct delete position.
        int i = 0;
        while(i < position && floatingTextsIter != listOfCharFloatTexts.end()){

            i++;
            floatingTextsIter++;
        }

        delete listOfCharFloatTexts[position];
        listOfCharFloatTexts.erase(floatingTextsIter);

        return true;
    }
}

//Delete all the CharacterTimers.
//Pre:  None.
//Post: Cycles through the entire list and deletes all
//      FloatingTexts.
void FloatingTextList::deleteList(){

    std::vector<CharacterFloatText*>::iterator floatingTextIter
        = (listOfCharFloatTexts.begin());

    while(floatingTextIter != listOfCharFloatTexts.end()){

        delete (*floatingTextIter);
        listOfCharFloatTexts.erase(floatingTextIter);
        floatingTextIter = listOfCharFloatTexts.begin();
    }
}

//Update FloatTexts.
//Pre:  None.
//Post: Updates all the turnTimers. If the turnTimers are full then
//      the turnTimers are reset.
void FloatingTextList::updateFloatingTexts(){

    for(unsigned int i = 0 ; i < listOfCharFloatTexts.size() ; i++){
        
        listOfCharFloatTexts[i]->floatingText->setFloatingTextToCreatureHealth(
            listOfCharFloatTexts[i]->i_Creature);
    }
}

//Draw all FloatingTexts.
//Pre:  None.
//Post: Draws all the FloatingTexts to the screen.
void FloatingTextList::drawFloatingTexts(){

    for(unsigned int i = 0 ; i < listOfCharFloatTexts.size() ; i++){

        listOfCharFloatTexts[i]->floatingText->draw();
    }
}