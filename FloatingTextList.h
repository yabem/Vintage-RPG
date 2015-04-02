//Holds a list of floating text that can be iterated through.

#pragma once
#include <vector>
#include "I_List.h"
#include "FloatingText.h"
#include "I_Creature.h"
#include "FontStore.h"

class FloatingTextList: public I_List{

private:

    struct CharacterFloatText{

        FloatingText *floatingText;
        I_Creature *i_Creature;
    };

    //List of the FloatingTexts.
    std::vector<CharacterFloatText*> listOfCharFloatTexts;   

    //Sets the variables of the FloatingText.
    void initializeFloatingTextToCharacter(FloatingText *floatingText);

    //Used to get the font.
    FontStore *fontStore;
    
public:

    //Constructor.
    FloatingTextList();

    //Destructor.
    virtual ~FloatingTextList();

    //Loads the FontStore.
    void loadFontStore(FontStore *fontStore);

    //Returns a pointer to the currently selected enemy.
    FloatingText* getCurrSelection();  

    //Inserts a FloatingText connected to a Character.
    void addFloatingTextConnection(I_Creature *i_Creature);

    //Gets the specified FloatingText.
    virtual FloatingText* getFloatingTextSelection(int selection);

    //Deletes the specified FloatingText.
    virtual bool deleteSelection(int selection);

    //Delete all the CharacterTimers.
    virtual void deleteList();

    //Update FloatTexts and resets if full.
    void updateFloatingTexts();

    //Draw all FloatTexts.
    void drawFloatingTexts();
};