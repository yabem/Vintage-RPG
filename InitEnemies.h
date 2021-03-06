#pragma once
#include "Character.h"
#include "CharStats.h"

namespace InitEnemies{

    //Modifiers
    const int HP_MOD_FOR_EASY_ENEMIES = 0;
    const int ATK_MOD_FOR_EASY_ENEMIES = 0;
    const int DEF_MOD_FOR_EASY_ENEMIES = 0;
    const int SPD_MOD_FOR_EASY_ENEMIES = 0;

    const int HP_MOD_FOR_MEDIUM_ENEMIES = 0;
    const int ATK_MOD_FOR_MEDIUM_ENEMIES = 0;
    const int DEF_MOD_FOR_MEDIUM_ENEMIES = 0;
    const int SPD_MOD_FOR_MEDIUM_ENEMIES = 0;

    const int HP_MOD_FOR_HARD_ENEMIES = 0;
    const int ATK_MOD_FOR_HARD_ENEMIES = 0;
    const int DEF_MOD_FOR_HARD_ENEMIES = 0;
    const int SPD_MOD_FOR_HARD_ENEMIES = 0;

    const float EASY_ENEMY_SPEED = 2;
    const float MEDIUM_ENEMY_SPEED = 2.5;
    const float HARD_ENEMY_SPEED = 3;

    const int SOUTHERN_FOREST_BASE_ATTACK = 8;
    const int WESTERN_DESERT_BASE_ATTACK = 16;
    const int NORTHERN_SNOW_BASE_ATTACK = 26;
    const int EASTERN_CASTLE_BASE_ATTACK = 38;
    const int INSIDE_CASTLE_BASE_ATTACK = 50;

    //Southern Forest
    const int WERERAT_BASE_HP = 10;
    const int WERERAT_BASE_MP = 0;
    const int WERERAT_BASE_ATK = SOUTHERN_FOREST_BASE_ATTACK;
    const int WERERAT_BASE_DEF = 0;
    const float WERERAT_BASE_SPEED = EASY_ENEMY_SPEED;
    const int WERERAT_BASE_REWARD_XP = 10;
    const int WERERAT_BASE_MONEY_REWARD = 5;

    const int BABY_BLOB_BASE_HP = 10;
    const int BABY_BLOB_BASE_MP = 0;
    const int BABY_BLOB_BASE_ATK = SOUTHERN_FOREST_BASE_ATTACK;
    const int BABY_BLOB_BASE_DEF = 0;
    const float BABY_BLOB_BASE_SPEED = EASY_ENEMY_SPEED;
    const int BABY_BLOB_BASE_REWARD_XP = 10;
    const int BABY_BLOB_BASE_MONEY_REWARD = 5;

    const int GOO_CUBE_BASE_HP = 20;
    const int GOO_CUBE_BASE_MP = 0;
    const int GOO_CUBE_BASE_ATK = SOUTHERN_FOREST_BASE_ATTACK * 2;
    const int GOO_CUBE_BASE_DEF = 0;
    const float GOO_CUBE_BASE_SPEED = MEDIUM_ENEMY_SPEED;
    const int GOO_CUBE_BASE_REWARD_XP = 20;
    const int GOO_CUBE_BASE_MONEY_REWARD = 10;

    const int MUSHROOM_MAN_BASE_HP = 20;
    const int MUSHROOM_MAN_BASE_MP = 0;
    const int MUSHROOM_MAN_BASE_ATK = SOUTHERN_FOREST_BASE_ATTACK * 2;
    const int MUSHROOM_MAN_BASE_DEF = 0;
    const float MUSHROOM_MAN_BASE_SPEED = MEDIUM_ENEMY_SPEED;
    const int MUSHROOM_MAN_BASE_REWARD_XP = 20;
    const int MUSHROOM_MAN_BASE_MONEY_REWARD = 10;

    const int WOLF_BASE_HP = 30;
    const int WOLF_BASE_MP = 0;
    const int WOLF_BASE_ATK = SOUTHERN_FOREST_BASE_ATTACK * 3;
    const int WOLF_BASE_DEF = 0;
    const float WOLF_BASE_SPEED = HARD_ENEMY_SPEED;
    const int WOLF_BASE_REWARD_XP = 30;
    const int WOLF_BASE_MONEY_REWARD = 15;

    const int BLOB_KING_BASE_HP = 200;
    const int BLOB_KING_BASE_MP = 0;
    const int BLOB_KING_BASE_ATK = 35;
    const int BLOB_KING_BASE_DEF = 0;
    const float BLOB_KING_BASE_SPEED = 1.6;
    const int BLOB_KING_BASE_REWARD_XP = 300;
    const int BLOB_KING_BASE_MONEY_REWARD = 150;

    //Western Desert
    const int RAT_BASE_HP = 30;
    const int RAT_BASE_MP = 0;
    const int RAT_BASE_ATK = WESTERN_DESERT_BASE_ATTACK;
    const int RAT_BASE_DEF = 0;
    const float RAT_BASE_SPEED = EASY_ENEMY_SPEED;
    const int RAT_BASE_REWARD_XP = 30;
    const int RAT_BASE_MONEY_REWARD = 15;

    const int CACTUS_BASE_HP = 30;
    const int CACTUS_BASE_MP = 0;
    const int CACTUS_BASE_ATK = WESTERN_DESERT_BASE_ATTACK;
    const int CACTUS_BASE_DEF = 0;
    const float CACTUS_BASE_SPEED = EASY_ENEMY_SPEED;
    const int CACTUS_BASE_REWARD_XP = 30;
    const int CACTUS_BASE_MONEY_REWARD = 15;

    const int ZOMBIE_BASE_HP = 40;
    const int ZOMBIE_BASE_MP = 0;
    const int ZOMBIE_BASE_ATK = WESTERN_DESERT_BASE_ATTACK * 2;
    const int ZOMBIE_BASE_DEF = 0;
    const float ZOMBIE_BASE_SPEED = MEDIUM_ENEMY_SPEED;
    const int ZOMBIE_BASE_REWARD_XP = 40;
    const int ZOMBIE_BASE_MONEY_REWARD = 20;

    const int FIRE_CUBE_BASE_HP = 40;
    const int FIRE_CUBE_BASE_MP = 0;
    const int FIRE_CUBE_BASE_ATK = WESTERN_DESERT_BASE_ATTACK * 2;
    const int FIRE_CUBE_BASE_DEF = 0;
    const float FIRE_CUBE_BASE_SPEED = MEDIUM_ENEMY_SPEED;
    const int FIRE_CUBE_BASE_REWARD_XP = 40;
    const int FIRE_CUBE_BASE_MONEY_REWARD = 20;

    const int SHIELD_SKELETON_BASE_HP = 50;
    const int SHIELD_SKELETON_BASE_MP = 0;
    const int SHIELD_SKELETON_BASE_ATK = WESTERN_DESERT_BASE_ATTACK * 3;
    const int SHIELD_SKELETON_BASE_DEF = 0;
    const float SHIELD_SKELETON_BASE_SPEED = HARD_ENEMY_SPEED;
    const int SHIELD_SKELETON_BASE_REWARD_XP = 50;
    const int SHIELD_SKELETON_BASE_MONEY_REWARD = 25;

    const int DEMON_BASE_HP = 400;
    const int DEMON_BASE_MP = 0;
    const int DEMON_BASE_ATK = 999;
    const int DEMON_BASE_DEF = 0;
    const float DEMON_BASE_SPEED = 1.9;
    const int DEMON_BASE_REWARD_XP = 500;
    const int DEMON_BASE_MONEY_REWARD = 250;

    //Northern Snow
    const int ICE_CUBE_BASE_HP = 50;
    const int ICE_CUBE_BASE_MP = 0;
    const int ICE_CUBE_BASE_ATK = NORTHERN_SNOW_BASE_ATTACK;
    const int ICE_CUBE_BASE_DEF = 0;
    const float ICE_CUBE_BASE_SPEED = EASY_ENEMY_SPEED;
    const int ICE_CUBE_BASE_REWARD_XP = 50;
    const int ICE_CUBE_BASE_MONEY_REWARD = 25;

    const int WALRUS_BASE_HP = 50;
    const int WALRUS_BASE_MP = 0;
    const int WALRUS_BASE_ATK = NORTHERN_SNOW_BASE_ATTACK;
    const int WALRUS_BASE_DEF = 0;
    const float WALRUS_BASE_SPEED = EASY_ENEMY_SPEED;
    const int WALRUS_BASE_REWARD_XP = 50;
    const int WALRUS_BASE_MONEY_REWARD = 25;

    const int CARROT_RAT_BASE_HP = 60;
    const int CARROT_RAT_BASE_MP = 0;
    const int CARROT_RAT_BASE_ATK = NORTHERN_SNOW_BASE_ATTACK * 2;
    const int CARROT_RAT_BASE_DEF = 0;
    const float CARROT_RAT_BASE_SPEED = MEDIUM_ENEMY_SPEED;
    const int CARROT_RAT_BASE_REWARD_XP = 60;
    const int CARROT_RAT_BASE_MONEY_REWARD = 30;

    const int OLDMAN_AXE_BASE_HP = 60;
    const int OLDMAN_AXE_BASE_MP = 0;
    const int OLDMAN_AXE_BASE_ATK = NORTHERN_SNOW_BASE_ATTACK * 2;
    const int OLDMAN_AXE_BASE_DEF = 0;
    const float OLDMAN_AXE_BASE_SPEED = MEDIUM_ENEMY_SPEED;
    const int OLDMAN_AXE_BASE_REWARD_XP = 60;
    const int OLDMAN_AXE_BASE_MONEY_REWARD = 30;

    const int RED_REAPER_BASE_HP = 70;
    const int RED_REAPER_BASE_MP = 0;
    const int RED_REAPER_BASE_ATK = NORTHERN_SNOW_BASE_ATTACK * 3;
    const int RED_REAPER_BASE_DEF = 0;
    const float RED_REAPER_BASE_SPEED = HARD_ENEMY_SPEED;
    const int RED_REAPER_BASE_REWARD_XP = 70;
    const int RED_REAPER_BASE_MONEY_REWARD = 35;

    const int ICE_BULL_BASE_HP = 700;
    const int ICE_BULL_BASE_MP = 0;
    const int ICE_BULL_BASE_ATK = 125;
    const int ICE_BULL_BASE_DEF = 0;
    const float ICE_BULL_BASE_SPEED = 1.65;
    const int ICE_BULL_BASE_REWARD_XP = 700;
    const int ICE_BULL_BASE_MONEY_REWARD = 350;

    //Eastern Castle
    const int SOLDIER_BASE_HP = 70;
    const int SOLDIER_BASE_MP = 0;
    const int SOLDIER_BASE_ATK = EASTERN_CASTLE_BASE_ATTACK;
    const int SOLDIER_BASE_DEF = 0;
    const float SOLDIER_BASE_SPEED = EASY_ENEMY_SPEED;
    const int SOLDIER_BASE_REWARD_XP = 70;
    const int SOLDIER_BASE_MONEY_REWARD = 35;

    const int KUNGFOO_DOG_BASE_HP = 70;
    const int KUNGFOO_DOG_BASE_MP = 0;
    const int KUNGFOO_DOG_BASE_ATK = EASTERN_CASTLE_BASE_ATTACK;
    const int KUNGFOO_DOG_BASE_DEF = 0;
    const float KUNGFOO_DOG_BASE_SPEED = EASY_ENEMY_SPEED;
    const int KUNGFOO_DOG_BASE_REWARD_XP = 70;
    const int KUNGFOO_DOG_BASE_MONEY_REWARD = 35;

    const int NINJA_FOX_BASE_HP = 80;
    const int NINJA_FOX_BASE_MP = 0;
    const int NINJA_FOX_BASE_ATK = EASTERN_CASTLE_BASE_ATTACK * 2;
    const int NINJA_FOX_BASE_DEF = 0;
    const float NINJA_FOX_BASE_SPEED = MEDIUM_ENEMY_SPEED;
    const int NINJA_FOX_BASE_REWARD_XP = 80;
    const int NINJA_FOX_BASE_MONEY_REWARD = 40;

    const int FANGED_FOX_BASE_HP = 80;
    const int FANGED_FOX_BASE_MP = 0;
    const int FANGED_FOX_BASE_ATK = EASTERN_CASTLE_BASE_ATTACK * 2;
    const int FANGED_FOX_BASE_DEF = 0;
    const float FANGED_FOX_BASE_SPEED = MEDIUM_ENEMY_SPEED;
    const int FANGED_FOX_BASE_REWARD_XP = 80;
    const int FANGED_FOX_BASE_MONEY_REWARD = 40;

    const int SHEEP_BASE_HP = 90;
    const int SHEEP_BASE_MP = 0;
    const int SHEEP_BASE_ATK = EASTERN_CASTLE_BASE_ATTACK * 3;
    const int SHEEP_BASE_DEF = 0;
    const float SHEEP_BASE_SPEED = HARD_ENEMY_SPEED;
    const int SHEEP_BASE_REWARD_XP = 90;
    const int SHEEP_BASE_MONEY_REWARD = 45;

    const int GUARDIAN_BASE_HP = 900;
    const int GUARDIAN_BASE_MP = 0;
    const int GUARDIAN_BASE_ATK = 200;
    const int GUARDIAN_BASE_DEF = 0;
    const float GUARDIAN_BASE_SPEED = 2.0;
    const int GUARDIAN_BASE_REWARD_XP = 900;
    const int GUARDIAN_BASE_MONEY_REWARD = 450;

    //Inside Castle
    const int SPIDER_BASE_HP = 90;
    const int SPIDER_BASE_MP = 0;
    const int SPIDER_BASE_ATK = INSIDE_CASTLE_BASE_ATTACK;
    const int SPIDER_BASE_DEF = 0;
    const float SPIDER_BASE_SPEED = EASY_ENEMY_SPEED;
    const int SPIDER_BASE_REWARD_XP = 90;
    const int SPIDER_BASE_MONEY_REWARD = 45;

    const int SPIDER_EGG_BASE_HP = 90;
    const int SPIDER_EGG_BASE_MP = 0;
    const int SPIDER_EGG_BASE_ATK = INSIDE_CASTLE_BASE_ATTACK;
    const int SPIDER_EGG_BASE_DEF = 0;
    const float SPIDER_EGG_BASE_SPEED = EASY_ENEMY_SPEED;
    const int SPIDER_EGG_BASE_REWARD_XP = 90;
    const int SPIDER_EGG_BASE_MONEY_REWARD = 45;

    const int SPIDER_WEB_BASE_HP = 100;
    const int SPIDER_WEB_BASE_MP = 0;
    const int SPIDER_WEB_BASE_ATK = INSIDE_CASTLE_BASE_ATTACK * 2;
    const int SPIDER_WEB_BASE_DEF = 0;
    const float SPIDER_WEB_BASE_SPEED = MEDIUM_ENEMY_SPEED;
    const int SPIDER_WEB_BASE_REWARD_XP = 100;
    const int SPIDER_WEB_BASE_MONEY_REWARD = 50;

    const int ECHIDNA_BASE_HP = 100;
    const int ECHIDNA_BASE_MP = 0;
    const int ECHIDNA_BASE_ATK = INSIDE_CASTLE_BASE_ATTACK * 2;
    const int ECHIDNA_BASE_DEF = 0;
    const float ECHIDNA_BASE_SPEED = MEDIUM_ENEMY_SPEED;
    const int ECHIDNA_BASE_REWARD_XP = 100;
    const int ECHIDNA_BASE_MONEY_REWARD = 50;

    const int TENTACLE_MAGE_BASE_HP = 110;
    const int TENTACLE_MAGE_BASE_MP = 0;
    const int TENTACLE_MAGE_BASE_ATK = INSIDE_CASTLE_BASE_ATTACK * 3;
    const int TENTACLE_MAGE_BASE_DEF = 0;
    const float TENTACLE_MAGE_BASE_SPEED = HARD_ENEMY_SPEED;
    const int TENTACLE_MAGE_BASE_REWARD_XP = 110;
    const int TENTACLE_MAGE_BASE_MONEY_REWARD = 65;

    const int UMGAR_THE_WORLD_DESTROYER_BASE_HP = 2000;
    const int UMGAR_THE_WORLD_DESTROYER_BASE_MP = 0;
    const int UMGAR_THE_WORLD_DESTROYER_BASE_ATK = 195;
    const int UMGAR_THE_WORLD_DESTROYER_BASE_DEF = 0;
    const float UMGAR_THE_WORLD_DESTROYER_BASE_SPEED = 1.5;
    const int UMGAR_THE_WORLD_DESTROYER_BASE_REWARD_XP = 1200;
    const int UMGAR_THE_WORLD_DESTROYER_BASE_MONEY_REWARD = 600;

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
    void carrotRat(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void walrus(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void gooCube(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void iceCube(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void fireCube(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void shieldSkeleton(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void wererat(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void cactus(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void oldmanAxe(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void mushroomMan(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void zombie(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void babyBlob(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void sheep(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void kungfooDog(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void fangedFox(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void ninjaFox(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void redReaper(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void spider(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void spiderEgg(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void spiderWeb(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void tentacleMage(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void echidna(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void umgarTheWorldDestroyer(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);

    //Figure out rewards.
    std::vector<std::string> ratRewards();
    std::vector<std::string> wolfRewards();
    std::vector<std::string> soldierRewards();
    std::vector<std::string> iceBullRewards();
    std::vector<std::string> blobKingRewards();
    std::vector<std::string> guardianRewards();
    std::vector<std::string> demonRewards();
    std::vector<std::string> carrotRatRewards();
    std::vector<std::string> walrusRewards();
    std::vector<std::string> gooCubeRewards();
    std::vector<std::string> iceCubeRewards();
    std::vector<std::string> fireCubeRewards();
    std::vector<std::string> shieldSkeletonRewards();
    std::vector<std::string> wereratRewards();
    std::vector<std::string> cactusRewards();
    std::vector<std::string> oldmanAxeRewards();
    std::vector<std::string> mushroomManRewards();
    std::vector<std::string> zombieRewards();
    std::vector<std::string> babyBlobRewards();
    std::vector<std::string> sheepRewards();
    std::vector<std::string> kungfooDogRewards();
    std::vector<std::string> fangedFoxRewards();
    std::vector<std::string> ninjaFoxRewards();
    std::vector<std::string> redReaperRewards();
    std::vector<std::string> spiderRewards();
    std::vector<std::string> spiderEggRewards();
    std::vector<std::string> spiderWebRewards();
    std::vector<std::string> tentacleMageRewards();
    std::vector<std::string> echidnaRewards();
    std::vector<std::string> umgarTheWorldDestroyerRewards();

    //Set the spacing so the enemies are drawn correctly on the screen.
    void initEnemiesSpacing(vector<Character*> theEnemies);
};