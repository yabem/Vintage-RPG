//Generic interface for manipulations of characters.
//All manipulations inherit from this class.

#pragma once
#include <queue>
#include "FontStore.h"
class Character;
class ImageStore;
class FontStore;
class I_Animation;
class GameManager;
class DrawRepository;
class I_Manager;
struct ALLEGRO_FONT;

class CharacterManipulation{

protected:

    Character *initiator;   //Character that initiates the attack.
    Character *receiver;    //Character that receives the attack.
    ImageStore *imageStore; //Used to retrieve the image.
    FontStore *fontStore;   //Used to retrieve the font.
    DrawRepository *drawRepository;    //Repository of animations.
    ALLEGRO_FONT *font;     //Font for the text.
    I_Manager *battleManager;       //Used for pausing and unpausing.
    bool isHealing;     //Marks the manipulation as healing.

public:

    CharacterManipulation();            //Default constructor.
    virtual ~CharacterManipulation();   //Destructor.

    virtual void loadCharacters(Character *initiator , Character *receiver);
    
    //Initialize to defaults, must loadCharacters before use.
    virtual void initialize(Character *initiator , Character *receiver ,
        ImageStore *imageStore , FontStore *fontStore , 
        DrawRepository *drawRepository , I_Manager *i_Manager);

    virtual void setDamage();   //Sets the damage.
    virtual void loadDelay();   //Loads a delay to the Character
    virtual void execute();     //Executes the manipulation.
};