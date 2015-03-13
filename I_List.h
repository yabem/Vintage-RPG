//An interface that holds a list of objects.

#pragma once
#include <stdio.h>
class Menu;
class Character;
class CharacterManipulationStore;

class I_List{

private:

public:

    virtual ~I_List();
    virtual bool deleteSelection(int position) = 0;
    virtual void deleteList() = 0;
    virtual Menu* getSelection(int selection);
    virtual int getSize() const;

    //Used to get the player for Draw.
    virtual Character* getCharacterSelection(int position); 


    //virtual void loadMenu(Menu *menu);
    //virtual void pauseBattle();
    //virtual void unPauseBattle();
};