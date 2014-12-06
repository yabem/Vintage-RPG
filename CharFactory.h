#pragma once
#include "Character.h"
#include <vector>

class CharFactory{

private:

    vector<Character*> characterList;

public:
    
    CharFactory();  //Default constructor.
    ~CharFactory(); //Default desctructor.
    Character* createChar(int selection);


};