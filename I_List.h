//An interface that holds a list of objects.

#pragma once
#include <stdio.h>
class Menu;
class Character;
class CharacterManipulationStore;
class FloatingText;

class I_List{

private:

public:

    virtual ~I_List();
    virtual bool deleteSelection(int position) = 0;
    virtual void deleteList();
    
    virtual int getSize() const;

    virtual Menu* getSelection(int selection);
    virtual Character* getCharacterSelection(int position); 
    virtual FloatingText* getFloatingTextSelection(int selection);
};