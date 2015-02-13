//The enums header file contains all the constant global values
//such as the screen width and height, the FPS, tilesize, etc.

#pragma once
#include <vector>

using namespace std;

enum MYKEYS {UP , RIGHT , DOWN , LEFT , SPACE , Q};
const int MAX_NUM_KEYS = 6;
enum LAYERTYPES {BACKGROUND , CENTERGROUND , FOREGROUND};
enum IMAGES {ATTACK, BLOCK, MAGIC}; //Used for images indexing values.
enum ENEMIES {RAT , WOLF , SOLDIER};
const int MAX_ENEMIES = 3;  //Total number of possible enemies.
const int MAX_ENEMIES_PER_BATTLE = 5; //Total number of enemies per battle.
const int MAX_ENEMY_LEVEL = 3;
const int DIRECTIONS = 4; //Used for collision creation.

const int FPS = 60;
const int rate = 4;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int TILESIZE = 32;
const int maxDirections = 4;

const int MAXTEXTNUMROWS = 6;
const int FONT_HEIGHT = 20;      //Height of the font when drawing text.
const int FONT_WIDTH = 15;       //Width of the font when drawing text.
const int FONT_SIZE = 18;
const int MAXTEXTLENGTH = SCREEN_W / (FONT_SIZE / 1.5);  //Max number of chars that can fit in one line of the textbox.
const int SELWID = 20;          //Width of the selector triangle.
const int SELHGT = 15;          //Height of the selector triangle.

const int BMAPXSTART = 0;       //Default location for starting x coordinate of a bitmap.
const int BMAPYSTART = 0;       //Default location for starting y coordinate of a bitmap.

const int NO_KEY = -1;           //Default for resetting key.
const int STARTCOL = 20;        //Initial starting col.
const int STARTROW = 20;        //Initial starting row.

const int DEFR = 255;           //Default red color.
const int DEFG = 255;           //Default green color.
const int DEFB = 255;           //Default blue color.

const int BATTLESTARTX = SCREEN_W / 10;   //Starting width for enemies on the battle screen.
const int BATTLESTARTY = SCREEN_H / 3;   //Starting height for enemies on the battle screen.


//ALLEGRO_FONT *font18;// = al_load_font("arial.ttf" , 18 , 0);

const int RATBASEHP = 5;
const int RATBASEMP = 0;
const int RATBASEATK = 1;
const int RATBASEDEF = 1;

const int WOLFBASEHP = 10;
const int WOLFBASEMP = 0;
const int WOLFBASEATK = 1;
const int WOLFBASEDEF = 1;

const int SOLDIERBASEHP = 10;
const int SOLDIERBASEMP = 0;
const int SOLDIERBASEATK = 1;
const int SOLDIERBASEDEF = 1;