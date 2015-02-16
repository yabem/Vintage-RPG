//Generic interface for manipulations of characters.
//All manipulations inherit from this class.

#pragma once
#include <queue>
class Character;
class ImageStore;
class FontStore;
class Animation;
class GameManager;
class DrawRepository;
struct ALLEGRO_FONT;

class CharacterManipulation{

protected:

    Character *initiator;   //Character that initiates the attack.
    Character *receiver;    //Character that receives the attack.
    ImageStore *imageStore; //Used to retrieve the image.
    FontStore *fontStore;   //Used to retrieve the font.
    DrawRepository *drawRepository;    //Repository of animations.
    ALLEGRO_FONT *font;     //Font for the text.

public:

    CharacterManipulation();            //Default constructor.
    virtual ~CharacterManipulation();   //Destructor.

    virtual void loadCharacters(Character *initiator , Character *receiver);
    
    //Initialize to defaults, must loadCharacters before use.
    virtual void initialize(Character *initiator , Character *receiver ,
        ImageStore *imageStore , FontStore *fontStore , 
        DrawRepository *drawRepository);
    
    virtual void execute();             //Executes the manipulation.
};