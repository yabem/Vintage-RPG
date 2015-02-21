//Used to execute commands to character/s. Theactions will be
//done using the action specified by the user.

#pragma once
#include <vector>
#include <map>
#include "Enums.h"
#include <string>
#include <allegro5/allegro_font.h>  //Used for al_load_bitmap().
#include "CharacterManipulation.h"
#include "CharacterAttack.h"
#include "GameManager.h"
#include "ThrowRock.h"
class Character;
class ImageStore;
class DrawRepository;

class CharacterManipulationStore{

private:

    ImageStore *imageStore;
    FontStore *fontStore;
    GameManager *gameManager;
    DrawRepository *drawRepository;

    void addAllManipulations();     //Adds all the manipulations to the store.

    //Collection of images.
    std::map<std::string , CharacterManipulation*> characterManipulations;

public:

    CharacterManipulationStore();       //No parameter constructor.
    ~CharacterManipulationStore();      //Destructor.

    void loadImageStore(ImageStore *imageStore);
    void loadGameManager(GameManager *gameManager);
    void loadFontStore(FontStore*fontStore);
    void loadDrawRepository(DrawRepository *drawRepository);

    //Load a single CharacterManipulation to the store.
    void loadManipulation(std::string name , 
        CharacterManipulation *characterManipulation); 

    //Loads all of the default CharacterManipulation.
    void loadAllDefaultManipulations(); 
    
    //Executes the manipulation.
    void executeManipulation(Character *initiator , Character *receiver ,
        std::string manipulation);

    //Retrieves a pointer to the CharacterManipulation.
    CharacterManipulation* getManip(std::string charManip);  
};