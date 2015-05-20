//Cutscene when the players lose the battle.

#pragma once
#include "Cutscene.h"

class BattleLoss : public Cutscene{

private:

    int mapSwitch;   //Determines which map to show. 
    AreaMap *currMap;   //Pointer to the current AreaMap that the player exists on.
    CharacterList *listOfPlayers;   //All the players.
    CharacterList *listOfEnemies;   //All the enemies.
    TextBox *textBox;
    I_Manager *gameManager;
    ALLEGRO_FONT *font;

public:

    //Constructor.
    BattleLoss(AreaMap *currMap , CharacterList *listOfPlayers ,
        CharacterList *listOfEnemies , I_Manager *gameManager ,
        ALLEGRO_FONT *font);

    //Destructor.
    virtual ~BattleLoss();

    //Plays the Cutscene until SPACE is pressed.
    virtual bool play(const int pressedKey);
};