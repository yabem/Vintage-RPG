//The enums header file contains all the constant global values
//such as the screen width and height, the FPS, tilesize, etc.

#pragma once
#include <vector>

using namespace std;

enum MYKEYS {UP , RIGHT , DOWN , LEFT , SPACE , Q , U , C , L , I , O};
const int MAX_NUM_KEYS = 11;
enum LAYERTYPES {BACKGROUND , CENTERGROUND , FOREGROUND};
const int MAX_CHARACTER_LEVEL = 10;
enum IMAGES {ATTACK, BLOCK, MAGIC}; //Used for images indexing values.
enum ENEMIES {RAT , WOLF , SOLDIER , ICE_BULL , BLOB_KING , GUARDIAN , DEMON ,
    CARROT_RAT , WALRUS , GOO_CUBE , ICE_CUBE ,FIRE_CUBE , SHIELD_SKELETON , 
    WERERAT , CACTUS , OLDMAN_AXE , MUSHROOM_MAN , ZOMBIE , BABY_BLOB , SHEEP , 
    KUNGFOO_DOG , FANGED_FOX , NINJA_FOX , RED_REAPER , SPIDER , SPIDER_EGG , SPIDER_WEB ,
    TENTACLE_MAGE , ECHIDNA , UMGAR_THE_WORLD_DESTROYER};
const int SCREEN_TEXT_WIDTH_BUFFER = 75;
const int MAX_ENEMIES = 3;  //Total number of possible enemies.
const int MAX_ENEMIES_PER_BATTLE = 4; //Total number of enemies per battle.
const int MAX_PLAYERS_PER_BATTLE = 4;
const int MAX_ENEMY_LEVEL = 3;
const int DIRECTIONS = 4; //Used for collision creation.
const int DEAD = 5; //Used to set the facing direction to dead.
const int CELEBRATE = 4; //Used to set the facing direction to dead.

const int FPS = 60;
const int PLAYER_MOVE_RATE = 4;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int AREA_MAP_SIZE = 2500;
const int BATTLE_MAP_SIZE = 300; 
const int TILE_SIZE = 32;
const int maxDirections = 4;

const int MAXTEXTNUMROWS = 6;
const int FONT_HEIGHT = 20;      //Height of the font when drawing text.
const int FONT_WIDTH = 15;       //Width of the font when drawing text.
const int FONT_SIZE = 18;
const int MAXTEXTLENGTH = SCREEN_W / (FONT_SIZE / 2);  //Max number of chars that can fit in one line of the textbox.
const int SELWID = 20;          //Width of the selector triangle.
const int SELHGT = 15;          //Height of the selector triangle.

const int BMAPXSTART = 0;       //Default location for starting x coordinate of a bitmap.
const int BMAPYSTART = 0;       //Default location for starting y coordinate of a bitmap.

const int NO_KEY = -1;           //Default for resetting key.
const int STARTCOL = 20;        //Initial starting col.
const int STARTROW = 20;        //Initial starting row.

const int DEFR = 0;           //Default red color.
const int DEFG = 0;           //Default green color.
const int DEFB = 0;           //Default blue color.

const int DEFAULT_RED = 0;    //Red for text above players' heads during battle.
const int DEFAULT_GREEN = 0;  //Green for text above players' heads during battle.
const int DEFAULT_BLUE = 0;   //Blue for text above players' heads during battle.

//Starting width for enemies on the battle screen.
const int BATTLE_START_X_ENEMIES = SCREEN_W / 10;  

//Starting height for enemies on the battle screen.
const int BATTLE_START_Y_ENEMIES = SCREEN_H / 3;   

//Starting width for players on the battle screen.
const int BATTLE_START_X_PLAYERS = SCREEN_W - BATTLE_START_X_ENEMIES * 2;  

//Starting height for players on the battle screen.
const int BATTLE_START_Y_PLAYERS = SCREEN_H / 3;   

const int DEFAULT_BAR_WIDTH = 60;   //Default TurnTimer width.
const int DEFAULT_BAR_HEIGHT = 15;  //Default TurnTimer height.
const int DEFAULT_HEALTH_HEIGHT = 15;  //Default player health height.

//Inventory Constants
const std::string MONEY_TYPE = "Gold";  //Currency type for the game.
const std::string EXPERIENCE_TYPE = "XP";  

const int DEFAULT_ITEM_CAPACITY = 99;