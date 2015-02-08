//Generic interface for manipulations of characters.
//All manipulations inherit from this class.

#pragma once

class CharacterManipulation{

private:

public:
    CharacterManipulation();            //Default constructor.
    virtual ~CharacterManipulation();   //Destructor.
    virtual void execute();             //Executes the manipulation.
};