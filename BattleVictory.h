#pragma once
#include "Cutscene.h"
#include "Draw.h"
#include "TextBox.h"
#include "Map.h"
#include <allegro5/allegro_font.h>
#include "I_Manager.h"
#include "GameConfig.h"
#include "TreasureBox.h"
#include "Conversion.h"
struct ALLEGRO_FONT;

class BattleVictory: public Cutscene{

private:

    BattleVictory(const BattleVictory& rhs);
    BattleVictory& operator=(BattleVictory& rhs);
    int mapSwitch;   //Determines which map to show. 
    AreaMap *currMap;   //Pointer to the current AreaMap that the player exists on.
    CharacterList *characterList;   //Pointer to the player.
    std::vector<Character*> playersForVictoryCelebration;
    TextBox *textBox;
    std::vector<std::string> levelUpSummary;
    I_Manager *i_Manager;
    TreasureBox *treasureBox;
    ALLEGRO_FONT *font;

public:
    BattleVictory();
    BattleVictory(AreaMap *currMap , CharacterList *characterList ,
        I_Manager *i_Manager , TreasureBox *treasureBox , ALLEGRO_FONT *font ,
        std::vector<std::string> levelUpSummary);
    virtual ~BattleVictory();
    void createCelebratingPlayers();
    void playCelebratingPlayers();
    void deletePlayers();
    void createVictoryMessage();
    virtual bool play(const int pressedKey);
};