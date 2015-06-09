#pragma once
#include "Character.h"
#include "CharStats.h"

namespace InitEnemies{

    const int RAT_BASE_HP = 5;
    const int RAT_BASE_MP = 0;
    const int RAT_BASE_ATK = 1;
    const int RAT_BASE_DEF = 1;
    const int RAT_BASE_SPEED = 2.8;
    const int RAT_BASE_REWARD_XP = 5;
    const int RAT_BASE_MONEY_REWARD = 1;

    const int WOLF_BASE_HP = 10;
    const int WOLF_BASE_MP = 0;
    const int WOLF_BASE_ATK = 1;
    const int WOLF_BASE_DEF = 1;
    const int WOLF_BASE_SPEED = 4;
    const int WOLF_BASE_REWARD_XP = 15;
    const int WOLF_BASE_MONEY_REWARD = 5;

    const int SOLDIER_BASE_HP = 10;
    const int SOLDIER_BASE_MP = 0;
    const int SOLDIER_BASE_ATK = 1;
    const int SOLDIER_BASE_DEF = 1;
    const int SOLDIER_BASE_SPEED = 3;
    const int SOLDIER_BASE_REWARD_XP = 10;
    const int SOLDIER_BASE_MONEY_REWARD = 10;

    const int ICE_BULL_BASE_HP = 10;
    const int ICE_BULL_BASE_MP = 0;
    const int ICE_BULL_BASE_ATK = 1;
    const int ICE_BULL_BASE_DEF = 1;
    const int ICE_BULL_BASE_SPEED = 3;
    const int ICE_BULL_BASE_REWARD_XP = 10;
    const int ICE_BULL_BASE_MONEY_REWARD = 10;

    const int BLOB_KING_BASE_HP = 10;
    const int BLOB_KING_BASE_MP = 0;
    const int BLOB_KING_BASE_ATK = 1;
    const int BLOB_KING_BASE_DEF = 1;
    const int BLOB_KING_BASE_SPEED = 3;
    const int BLOB_KING_BASE_REWARD_XP = 10;
    const int BLOB_KING_BASE_MONEY_REWARD = 10;

    const int GUARDIAN_BASE_HP = 10;
    const int GUARDIAN_BASE_MP = 0;
    const int GUARDIAN_BASE_ATK = 1;
    const int GUARDIAN_BASE_DEF = 1;
    const int GUARDIAN_BASE_SPEED = 3;
    const int GUARDIAN_BASE_REWARD_XP = 10;
    const int GUARDIAN_BASE_MONEY_REWARD = 10;

    const int DEMON_BASE_HP = 10;
    const int DEMON_BASE_MP = 0;
    const int DEMON_BASE_ATK = 1;
    const int DEMON_BASE_DEF = 1;
    const int DEMON_BASE_SPEED = 3;
    const int DEMON_BASE_REWARD_XP = 10;
    const int DEMON_BASE_MONEY_REWARD = 10;

    //Initialize character based off of the level and type or enemy.
    void init(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);

    //Create the enemy.
    void rat(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void wolf(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void soldier(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void iceBull(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void blobKing(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void guardian(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void demon(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);

    //Figure out rewards.
    std::vector<std::string> ratRewards();
    std::vector<std::string> wolfRewards();
    std::vector<std::string> soldierRewards();
    std::vector<std::string> iceBullRewards();
    std::vector<std::string> blobKingRewards();
    std::vector<std::string> guardianRewards();
    std::vector<std::string> demonRewards();

    //Set the spacing so the enemies are drawn correctly on the screen.
    void initEnemiesSpacing(vector<Character*> theEnemies);
    
};