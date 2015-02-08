//Used to execute commands to character/s. Theactions will be
//done using the action specified by the user.

#pragma once
#include <vector>
#include <map>
#include "Enums.h"
#include <string>
#include <allegro5/allegro_font.h>  //Used for al_load_bitmap().
#include "CharacterManipulation.h"

class CharacterManipulationStore{

private:

      
    void addAllManipulations();     //Adds all the manipulations to the store.

    //Collection of images.
    std::map<std::string , CharacterManipulation*> characterManipulations;

public:

    CharacterManipulationStore();        //No parameter constructor.
    ~CharacterManipulationStore();      //Destructor.

    //Load a single CharacterManipulation to the store.
    void loadCharacterManipulation(std::string name , 
        CharacterManipulation *characterManipulation); 
    
    //Loads all of the default CharacterManipulation.
    void loadAllDefaultCharacterManipulations();    

    //Retrieves a pointer to the CharacterManipulation.
    CharacterManipulation* getBitMap(std::string characterManipulationName);  
};