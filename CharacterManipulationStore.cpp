#include "CharacterManipulationStore.h"

//No parameter constructor.
CharacterManipulationStore::CharacterManipulationStore(){

}

//Destructor.
CharacterManipulationStore::~CharacterManipulationStore(){

    std::map<std::string , CharacterManipulation*>::iterator iter =
        characterManipulations.begin();

    while(iter != characterManipulations.end()){

        delete (iter->second);
        characterManipulations.erase(iter);
        iter = characterManipulations.begin();
    }
}

//Loads the image store.
void CharacterManipulationStore::loadImageStore(ImageStore *imageStore){

    this->imageStore = imageStore;
}

//Loads the gameManager.
void CharacterManipulationStore::loadGameManager(GameManager *gameManager){

    this->gameManager = gameManager;
}

//Loads the fontStore.
//Pre:  None.
//Post: Loads the pointer to the fontStore.
void CharacterManipulationStore::loadFontStore(FontStore *fontStore){

    this->fontStore = fontStore;
}

//Loads the drawRepository.
//Pre:  None.
//Post: Loads the pointer to the drawRepository.
void CharacterManipulationStore::loadDrawRepository(
    DrawRepository *drawRepository){

    this->drawRepository = drawRepository;
}
//Loads the battleManager which is an I_Manager.
//Pre:  None.
//Post: Loads the specified I_Manager pointer.
void CharacterManipulationStore::loadBattleManager(I_Manager *battleManager){

    this->battleManager = battleManager;
}

//Load a single CharacterManipulation to the store.
//Pre:  The charManip is valid.
//Post: The key (name) and value (CharacterManipulation) are loaded
//      into the characterManipulations map.
void CharacterManipulationStore::loadManipulation(std::string name , 
    CharacterManipulation *charManip){

    //Don't add anything if pointer is NULL.
    if(charManip == NULL || name == "")
        return;

    else characterManipulations.insert
        (std::pair<std::string , CharacterManipulation*>(name , charManip));
}

//Loads all of the default CharacterManipulation.
//Pre:  None.
//Post: Loads all the CharacterManipulations into the 
//      characterManipulations map.
void CharacterManipulationStore::loadAllDefaultManipulations(){

    CharacterManipulation *charManip = new CharacterAttack;

    //add i_Manager *battleManager here
    charManip->initialize(NULL , NULL , imageStore , fontStore , 
        drawRepository , battleManager);
    loadManipulation("Attack" , charManip);

    charManip = new ThrowRock;
    charManip->initialize(NULL , NULL , imageStore , fontStore ,
        drawRepository , battleManager);
    loadManipulation("Rock" , charManip);

    charManip = new Fireball;
    charManip->initialize(NULL , NULL , imageStore , fontStore ,
        drawRepository , battleManager);
    loadManipulation("Fireball" , charManip);

    charManip = new Fire2;
    charManip->initialize(NULL , NULL , imageStore , fontStore ,
        drawRepository , battleManager);
    loadManipulation("Fire2" , charManip);

    charManip = new Fire3;
    charManip->initialize(NULL , NULL , imageStore , fontStore ,
        drawRepository , battleManager);
    loadManipulation("Fire3" , charManip);

    charManip = new Skewer;
    charManip->initialize(NULL , NULL , imageStore , fontStore ,
        drawRepository , battleManager);
    loadManipulation("Skewer" , charManip);

    charManip = new Jump;
    charManip->initialize(NULL , NULL , imageStore , fontStore ,
        drawRepository , battleManager);
    loadManipulation("Jump" , charManip);

    charManip = new FuryOfTheFang;
    charManip->initialize(NULL , NULL , imageStore , fontStore ,
        drawRepository , battleManager);
    loadManipulation("Fury Of The Fang" , charManip);

    charManip = new Recover;
    charManip->initialize(NULL , NULL , imageStore , fontStore ,
        drawRepository , battleManager);
    loadManipulation("Recover" , charManip);

    charManip = new Potion;
    charManip->initialize(NULL , NULL , imageStore , fontStore ,
        drawRepository , battleManager);
    loadManipulation("Potion" , charManip);

    charManip = new Lance;
    charManip->initialize(NULL , NULL , imageStore , fontStore ,
        drawRepository , battleManager);
    loadManipulation("Lance" , charManip);

    charManip = new Staff;
    charManip->initialize(NULL , NULL , imageStore , fontStore ,
        drawRepository , battleManager);
    loadManipulation("Staff" , charManip);

    charManip = new Dagger;
    charManip->initialize(NULL , NULL , imageStore , fontStore ,
        drawRepository , battleManager);
    loadManipulation("Dagger" , charManip);

    charManip = new Backstab;
    charManip->initialize(NULL , NULL , imageStore , fontStore ,
        drawRepository , battleManager);
    loadManipulation("Backstab" , charManip);

    charManip = new KnifeBarrage;
    charManip->initialize(NULL , NULL , imageStore , fontStore ,
        drawRepository , battleManager);
    loadManipulation("Knife Barrage" , charManip);

    charManip = new ShadeOfTheCrescent;
    charManip->initialize(NULL , NULL , imageStore , fontStore ,
        drawRepository , battleManager);
    loadManipulation("Shade of the Crescent" , charManip);

    charManip = new Sword;
    charManip->initialize(NULL , NULL , imageStore , fontStore ,
        drawRepository , battleManager);
    loadManipulation("Sword" , charManip);

    charManip = new Headbutt;
    charManip->initialize(NULL , NULL , imageStore , fontStore ,
        drawRepository , battleManager);
    loadManipulation("Headbutt" , charManip);

    charManip = new ShieldBash;
    charManip->initialize(NULL , NULL , imageStore , fontStore ,
        drawRepository , battleManager);
    loadManipulation("Shield Bash" , charManip);

    charManip = new EarthShatter;
    charManip->initialize(NULL , NULL , imageStore , fontStore ,
        drawRepository , battleManager);
    loadManipulation("Earth Shatter" , charManip);
}

//Retrieves a pointer to the CharacterManipulation.
//Pre:  None.
//Post: Returns a CharacterManipulation pointer.
CharacterManipulation* CharacterManipulationStore::getManip
    (std::string charManip){

    //Create iterator for testing if the element exists.
    std::map<std::string , CharacterManipulation*>::iterator iter
        = characterManipulations.begin();

    iter = characterManipulations.find(charManip);

    if(iter == characterManipulations.end()){

        //Element not found, return default.
        iter = characterManipulations.find("Attack");
        return iter->second;   
    }

    else return iter->second;
}

//Executes the manipulation.
//Pre:  None.
//Post: Executes the manipulation based off of the receiver.
void CharacterManipulationStore::executeManipulation(Character *initiator ,
    Character *receiver , std::string manipulation){

    CharacterManipulation *charManip = getManip(manipulation);

    charManip->loadCharacters(initiator , receiver);
    charManip->execute();
}

//Executes a random manipulation.
//Pre:  None.
//Post: Executes the random manipulation based off of the receiver.
void CharacterManipulationStore::executeRandomManipulation(Character *initiator ,
    Character *receiver){

    int randomNum = rand() % characterManipulations.size();

    std::map<std::string , CharacterManipulation*>::iterator iter
        = characterManipulations.begin();

    for(int i = 0 ; i < randomNum ; i++)
        iter++;

    CharacterManipulation *charManip = getManip(iter->first);
    charManip->loadCharacters(initiator , receiver);
    charManip->execute();
}

//Determines if the selection is valid.
//Pre:  None.
//Post: Returns true if the manipulation is within the store. Returns false
//      otherwise.
bool CharacterManipulationStore::isValidManipulation(std::string manipulation){

    //Create iterator for testing if the element exists.
    std::map<std::string , CharacterManipulation*>::iterator iter
        = characterManipulations.begin();

    iter = characterManipulations.find(manipulation);

    if(iter == characterManipulations.end()){

        //Element not found, return false.
        return false;
    }

    else return true;
}