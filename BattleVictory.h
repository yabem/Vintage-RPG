#pragma once
#include "Cutscene.h"
#include "Draw.h"
#include "TextBox.h"
#include "Map.h"
#include <allegro5/allegro_font.h>
#include "I_Manager.h"
#include "GameConfig.h"
#include "TreasureBox.h"
struct ALLEGRO_FONT;

class BattleVictory: public Cutscene{

private:

    int mapSwitch;   //Determines which map to show. 
    AreaMap *currMap;   //Pointer to the current AreaMap that the player exists on.
    CharacterList *characterList;   //Pointer to the player.
    std::vector<Character*> playersForVictoryCelebration;
    TextBox textBox;
    I_Manager *i_Manager;
    TreasureBox *treasureBox;

public:
    BattleVictory();
    BattleVictory(AreaMap *currMap , CharacterList *characterList ,
        I_Manager *i_Manager , TreasureBox *treasureBox);
    virtual ~BattleVictory();
    void createCelebratingPlayers();
    void playCelebratingPlayers();
    void deletePlayers();
    void createVictoryMessage();
    virtual bool play(const int pressedKey);
};