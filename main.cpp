#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <vector>
#include <queue>
#include "Controls.h"
#include "Scenery.h"
#include "Tangible.h"
#include "Character.h"
#include "Layer.h"
#include "AreaMap.h"
#include "Collision.h"
#include "Movement.h"
#include "Draw.h"
#include "AreaMapLayouts.h"
#include <time.h>
#include <stdlib.h>
#include "TextBox.h"
#include "I_Animation.h"
#include "MovingImage.h"
#include "MovingText.h"
#include "Stats.h"
#include "CharStats.h"

#include "InitEnemies.h"
#include "Cutscene.h"
#include "GameManager.h"
#include "Menu.h"
#include "ImageStore.h"
#include "CharacterAttack.h"
#include "Cursor.h"
#include "BattleManager.h"
#include "CharacterManipulationStore.h"
#include "FontStore.h"
#include "DrawRepository.h"
#include "PlayerEntity.h"
#include "Intro.h"
#include "Instruct.h"

#include "HomeTown.h"
#include "LoadExitsForHomeTown.h"
#include "HomeTownShop.h"
#include "LoadExitsForHomeTownShop.h"
#include "HomeTownBattleScreen.h"
#include "NorthernSnow.h"
#include "LoadExitsForNorthernSnow.h"
#include "BattleTransitionScreen.h"

//testing
#include "FloatingText.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//To do:
//Make controls a class
//Get rid of setStart() dupe function and create a colToX() and rowToY() functions
//Get rid of #includes
//Make tangible collision better so you can't go through objects.

//Tiles taken from http://opengameart.org/content/tiled-terrains
//Images taken from http://rpg.hamsterrepublic.com/ohrrpgce/Free_Sprites
//Fireblast taken from http://opengameart.org/content/fire-blast
#define ttfaddon

int checkInit();
void displayVariables(ALLEGRO_FONT *theFont , int theKey , Character *thePlayer , Layer &layer);

int main(int argc, char **argv){
    {
    //Memory leak checks.
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG | _CRTDBG_MODE_WNDW);
    
   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;
    
   //List of all the keys.
   bool keys[8] = {false , false , false , false , false , false , false , false};

   int theKey = -1;
   
   //Check initializations.
   if(checkInit() == -1)
       return -1;

   display = al_create_display(SCREEN_W , SCREEN_H);

   if(!display)
       return -1;
 
   al_init_primitives_addon();
   event_queue = al_create_event_queue();
   timer = al_create_timer(1.0 / FPS);
   al_init_font_addon();

#ifdef ttfaddon
   al_init_ttf_addon();

#endif 
   
    al_init_image_addon();

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    //Create imageStore and load all known bitmaps.
    ImageStore imageStore;
    imageStore.loadAllDefaultImages();

    //Loads the information for the player.
    PlayerEntity playerEntity(&imageStore);
    playerEntity.loadBackpack();
    playerEntity.loadDefaultPlayers();

    HomeTown homeTown(&imageStore);
    homeTown.loadDefaults();

    HomeTownShop homeTownShop(&imageStore);
    homeTownShop.loadDefaults();

    HomeTownBattleScreen homeTownBattleScreen(&imageStore);
    homeTownBattleScreen.loadDefaults();

    NorthernSnow northernSnow(&imageStore);
    northernSnow.loadDefaults();

    BattleTransitionScreen battleTransitionScreen(&imageStore);
    battleTransitionScreen.loadDefaults();
    /*
    //Characters
    Character thePlayer(imageStore.getBitMap("player") , 32 , 32 , 30 , 2 , rate);
    thePlayer.setFacing(DOWN);
    Character thePlayer2(imageStore.getBitMap("warrior") , 32 , 32 , 30 , 2 , rate);
    Character thePlayer3(imageStore.getBitMap("thief") , 32 , 32 , 30 , 2 , rate);
    Character thePlayer4(imageStore.getBitMap("mage") , 32 , 32 , 30 , 2 , rate);

    thePlayer.loadAbilities("Attack,Jump,Item|Potion;Recover;");
    thePlayer2.loadAbilities("Attack,Shield Bash,Item|Potion;Recover;");
    thePlayer3.loadAbilities("Attack,Backstab,Item|Potion;Recover;");
    thePlayer4.loadAbilities("Attack,Magic|Fire1,Fire2,Fire3;Item|Potion;Recover;");
   
    CharacterList thePlayers;
    thePlayers.loadChar(&thePlayer);
    thePlayers.loadChar(&thePlayer2);
    thePlayers.loadChar(&thePlayer3);
    thePlayers.loadChar(&thePlayer4);

    std::vector<std::string> emptyStringVector;

    //Character stats
    CharStats playerStats(1 , 1 , 10 , 100 , 10 , 1 , 100 , 10 , 1.8 , 0 , 0 ,
        emptyStringVector);
    thePlayer.setStats(&playerStats);

    CharStats playerStats2(1 , 5 , 10 , 100 , 10 , 1 , 100 , 10 , 1.9 , 0 , 0 ,
        emptyStringVector);
    thePlayer2.setStats(&playerStats2);

    CharStats playerStats3(1 , 1 , 10 , 100 , 10 , 1 , 100 , 10 , 2.0 , 0 , 0,
        emptyStringVector);
    thePlayer3.setStats(&playerStats3);

    CharStats playerStats4(1 , 5 , 10 , 100 , 10 , 1 , 100 , 10 , 1.3 , 0 , 0,
        emptyStringVector);
    thePlayer4.setStats(&playerStats4);

    //Character vectors
    vector<Character*> players;
    vector<Character*> enemies;

    players.push_back(&thePlayer);
    */

    //Animations queue
    //queue<I_Animation*> animations;

    Tangible theRock1(imageStore.getBitMap("rock") , 60 , 60 , 32 , 32 , 60 , 60 , 32 , 32);
    Tangible theRock2(imageStore.getBitMap("rock") , 888 , 888 , 32 , 32 , 888 , 888 , 32 , 32);

    /*
    Scenery cloud1(imageStore.getBitMap("cloud") , SCREEN_W , 0 , -4 , 1);
    cloud1.setDX(80);    cloud1.setDY(0);
    Scenery cloud2(imageStore.getBitMap("cloud") , SCREEN_W , 40 , -8 , 0);
    cloud2.setDX(500);    cloud2.setDY(40);
    Scenery cloud3(imageStore.getBitMap("cloud") , SCREEN_W , 80 , -6 , 0);
    cloud3.setDX(540);    cloud3.setDY(80);
    Scenery cloud4(imageStore.getBitMap("cloud") , SCREEN_W , 120 , -10 , 2);
    cloud4.setDX(290);    cloud4.setDY(120);
    Scenery cloud5(imageStore.getBitMap("cloud") , SCREEN_W , 160 , -3 , 0);
    cloud5.setDX(360);    cloud5.setDY(160);
    Scenery cloud6(imageStore.getBitMap("cloud") , SCREEN_W , 200 , -2 , 0);
    cloud6.setDX(430);    cloud6.setDY(200);
    Scenery cloud7(imageStore.getBitMap("cloud") , SCREEN_W , 240 , -8 , -2);
    cloud7.setDX(150);    cloud7.setDY(240);
    Scenery cloud8(imageStore.getBitMap("cloud") , SCREEN_W , 280 , -9 , 0);
    cloud8.setDX(220);    cloud8.setDY(280);
    Scenery cloud9(imageStore.getBitMap("cloud") , SCREEN_W , 380 , -5 , -1);
    cloud9.setDX(SCREEN_W);    cloud9.setDY(380);
    */

    /*
    Layer trans0(imageStore.getBitMap("terrain") , 8 , 4 , 32 , 32 , 15 , 20 , cutscene0 , 300);
    Layer trans1(imageStore.getBitMap("terrain") , 8 , 4 , 32 , 32 , 15 , 20 , cutscene1 , 300); 
    */

    /*
    Layer layer0(imageStore.getBitMap("terrain") , 8 , 4 , 32 , 32 , 50 , 50 , town0 , 2500);
    Layer layer1(imageStore.getBitMap("town") , 10 , 13 , 32 , 32 , 50 , 50 , town1 , 2500);
    Layer layer2(imageStore.getBitMap("town") , 10 , 13 , 32 , 32  , 50 , 50 , town2 , 2500);
    */

    //Layer shop0(imageStore.getBitMap("town") , 10 , 13 , 32 , 32 , 8 , 8 , theShop0 , 64);
    //Layer shop1(imageStore.getBitMap("town") , 10 , 13 , 32 , 32  , 8 , 8 , theShop1 , 64);

    //Layer battle0(imageStore.getBitMap("terrain") , 8 , 4 , 32 , 32 , 15 , 20 , battleScreen0 , 300);
    //Layer battle1(imageStore.getBitMap("terrain") , 8 , 4 , 32 , 32 , 15 , 20 , battleScreen1 , 300);

    /*
    vector<Layer*> layers;
    layers.push_back(&layer0);
    layers.push_back(&layer1);
    layers.push_back(&layer2);
    */
    /*
    AreaMap theShop;
    theShop.loadLayer(&shop0);
    theShop.loadLayer(&shop1);
    */

    /*
    AreaMap theMap;
    theMap.loadLayer(&layer0);
    theMap.loadLayer(&layer1);
    theMap.loadLayer(&layer2);
    */

    /*
    AreaMap theMap2;
    theMap2.loadLayer(&layer0);
    theMap2.loadLayer(&layer1);
    */

    //AreaMap battleMap;
    //battleMap.loadLayer(&battle0);
    //battleMap.loadLayer(&battle1);

    //AreaMap theBattleMap;
    //theBattleMap.loadLayer(&battle0);

    /*
    AreaMap cutScene;
    cutScene.loadLayer(&trans0);
    cutScene.loadLayer(&trans1);
    */

    /*
    theMap.loadExit(0 , 25 , &theMap2 , 48 , 25);
    theMap.loadExit(25 , 0 , &theMap2 , 25 , 48);
    theMap.loadExit(49 , 25 , &theMap2 , 2 , 25);
    theMap.loadExit(25 , 49 , &theMap2 , 25 , 2);
    theMap.loadExit(29 , 10 , &theShop , 4 , 5);
    theMap.loadExit(28 , 10 , &theShop , 4 , 5);
    */

    /*
    theMap2.loadExit(0 , 25 , &theMap , 48 , 25);
    theMap2.loadExit(25 , 0 , &theMap , 25, 48);
    theMap2.loadExit(49 , 25 , &theMap , 2 , 25);
    theMap2.loadExit(25 , 49 , &theMap , 25 , 2);
    */

    /*
    theMap2.loadExit(0 , 25 , &homeTown , 48 , 25);
    theMap2.loadExit(25 , 0 , &homeTown , 25, 48);
    theMap2.loadExit(49 , 25 , &homeTown , 2 , 25);
    theMap2.loadExit(25 , 49 , &homeTown , 25 , 2);
    */

    //theShop.loadExit(4 , 7 , &theMap , 28 , 12);
    //theShop.loadExit(4 , 7 , &homeTown , 28 , 12);

    //AreaMap *currMap = &theMap;
    //AreaMap *currMap = &homeTown;

    /*
    theMap.loadScenery(&cloud1);
    theMap.loadScenery(&cloud2);
    theMap.loadScenery(&cloud3);
    theMap.loadScenery(&cloud4);
    theMap.loadScenery(&cloud5);
    theMap.loadScenery(&cloud6);
    theMap.loadScenery(&cloud7);
    theMap.loadScenery(&cloud8);
    theMap.loadScenery(&cloud9);
    */

    //theMap.loadTangible(&theRock1);
    //theMap.loadTangible(&theRock2);

    homeTown.loadTangible(&theRock1);
    homeTown.loadTangible(&theRock2);

    //Create GameManager.
    GameManager gameManager = GameManager();
    gameManager.currMap = &homeTown;
    gameManager.player = playerEntity.getFirstPlayer();
    //gameManager.battleMap = &battleMap;
    gameManager.battleMap = &homeTownBattleScreen;
    //gameManager.cutSceneMap = &cutscene;
    gameManager.cutSceneMap = &battleTransitionScreen;
    //gameManager.loadPlayers(&thePlayers);
    gameManager.loadPlayers(playerEntity.getThePlayers());

    int cutsceneFrameCount = 0;  //For display.
    srand (time(NULL));  //Seed random

    FontStore fontStore;
    fontStore.loadAllDefaultFonts();

    BattleManager battleManager;

    DrawRepository drawRepository;
    drawRepository.loadGameManager(&gameManager);

    CharacterManipulationStore characterManipulationStore;
    characterManipulationStore.loadImageStore(&imageStore);
    characterManipulationStore.loadGameManager(&gameManager);
    characterManipulationStore.loadDrawRepository(&drawRepository);
    characterManipulationStore.loadFontStore(&fontStore);
    characterManipulationStore.loadBattleManager(&battleManager);
    characterManipulationStore.loadAllDefaultManipulations();

    battleManager.loadGameManager(&gameManager);
    battleManager.loadCharacterManipulationStore(&characterManipulationStore);

    battleManager.loadEnemyModel(imageStore.getBitMap("rat"));
    battleManager.loadEnemyModel(imageStore.getBitMap("wolf"));
    battleManager.loadEnemyModel(imageStore.getBitMap("soldier"));
    battleManager.loadDrawRepository(&drawRepository);
    battleManager.loadBackpack(playerEntity.getPlayerInventory());
    battleManager.loadFontStore(&fontStore);

    gameManager.loadDrawRepository(&drawRepository);

    //Cutscenes
    Intro *theIntro = new Intro(); 
    Instruct *theInstruct = new Instruct();

    drawRepository.loadCutscene(theIntro);   
    drawRepository.loadCutscene(theInstruct);

    //Initialize starting position.
    //LoadExitsForHomeTown::LoadExitsForHomeTown(&homeTown , &homeTownShop , &theMap2);
    LoadExitsForHomeTown::LoadExitsForHomeTown(&homeTown , &homeTownShop , &northernSnow);
    LoadExitsForHomeTownShop::LoadExitsForHomeTownShop(&homeTownShop , &homeTown);
    LoadExitsForNorthernSnow::LoadExitsForNorthernSnow(&northernSnow , &homeTown);
    Movement::setStart(*gameManager.player, homeTown , STARTCOL , STARTROW);

    al_start_timer(timer);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////Game Loop///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
    while(!gameManager.isEndOfGameLoop()){

      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);

        //Get keyboard input.
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN 
            || ev.type == ALLEGRO_EVENT_KEY_UP){

            theKey = getKeyboardInput(&ev , keys);
            gameManager.updateKey(theKey);
        }
        
        //Wait for timer.
        else if(ev.type == ALLEGRO_EVENT_TIMER){

            //Add to game timer.
            gameManager.increaseGameTimer();

//////////////////////////////////////////Cutscene/////////////////////////////
            
            if(!drawRepository.cutscenesEmpty()){
                drawRepository.playCutscenes();
            }

//////////////////////////////////////////Battle///////////////////////////////
            else if(gameManager.isBattle()){

                if(!battleManager.isEndOfBattle()){

                    Draw::drawArea(*gameManager.battleMap);
                    battleManager.updateAndDrawTurnTimers();
                    Draw::drawList(battleManager.getEnemiesList());
                    Draw::drawList(battleManager.getPlayersList());
                    Draw::drawMenus(battleManager.getMenuList());

                    //Updates and draws character hit points.
                    battleManager.drawFloatingTexts();

                    //Draw cursor.
                    drawRepository.drawTopCursor();

                    if(!battleManager.emptyEvents()){
                        battleManager.pauseBattle();
                        battleManager.playCurrEvent();
                        
                        if(battleManager.emptyEvents())
                            battleManager.unPauseBattle();
                    }            

                    //Play animations.
                    if(!drawRepository.animationsEmpty())
                        drawRepository.playAllAnimations();
                        
                    else battleManager.consumePlayerInput();
                }
            }

//////////////////////////////////////////Moving on Map////////////////////////
            else{

                //Check collisions.
                Collision::characterToAreaMap(*gameManager.player ,
                    gameManager.currMap);
            
                //Move the player on the map.
                Movement::moveMap(*gameManager.player , *gameManager.currMap ,
                    gameManager.getPressedKey(), keys);

                //Animate the player by increasing the framerate.
                gameManager.player->animate();
            
                //Animate the sceneries. 
                gameManager.currMap->animateSceneries();
            
                //Determine if there is a battle.
                battleManager.checkForBattle();

                //Draw map.
                Draw::drawArea(*gameManager.currMap , *gameManager.player);
                                     
                //Show variables.
#ifdef ttfaddon

                displayVariables(fontStore.getFont("default") ,
                    gameManager.getPressedKey() , gameManager.player ,
                    gameManager.currMap->getLayer(CENTERGROUND));
                al_draw_textf(fontStore.getFont("default"),
                    al_map_rgb(0, 0, 0), 500, 310, 0, 
                    "Cutscn count: %i" , cutsceneFrameCount);
#endif
        }

        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
        }

        //Close if X clicked.
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            gameManager.setEndOfGameLoopToEnd();
   }

   //Cleanup memory allocations.
   imageStore.destroyImages();
   al_destroy_display(display);
   al_destroy_timer(timer);
   al_destroy_event_queue(event_queue);
   
   }
   return 0;
}

//Initializes allegro, the mouse, and the keyboard.
int checkInit(){
    
    if(!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }
 
    if(!al_install_mouse()) {
        fprintf(stderr, "failed to initialize the mouse!\n");
        return -1;
    }

    if(!al_install_keyboard()) {
        fprintf(stderr, "failed to initialize the keyboard!\n");
        return -1;
    }

    return 0;
}

void displayVariables(ALLEGRO_FONT *theFont , int theKey , Character *thePlayer , Layer &layer){

    al_draw_textf(theFont, al_map_rgb(255, 255, 255), 500, 10, 0, "Key: %i" , theKey); 
    al_draw_textf(theFont, al_map_rgb(255, 255, 255), 500, 30, 0, "Left: %i" , thePlayer->getX());
    al_draw_textf(theFont, al_map_rgb(255, 255, 255), 500, 90, 0, "Up: %i" , thePlayer->getY());
    al_draw_textf(theFont, al_map_rgb(255, 255, 255), 500, 150, 0, "Right: %i" , 
        thePlayer->getX() + thePlayer->getW()); 
    al_draw_textf(theFont, al_map_rgb(255, 255, 255), 500, 210, 0, "Down: %i" , 
        thePlayer->getY() + thePlayer->getH()); 

    al_draw_textf(theFont, al_map_rgb(255, 255, 255), 500, 250, 0, "Row: %i" , 
        Collision::getRow(thePlayer->getUpperRightY() , layer)); 
    al_draw_textf(theFont, al_map_rgb(255, 255, 255), 500, 270, 0, "Col: %i" , 
        Collision::getCol(thePlayer->getUpperRightX() , layer)); 
    al_draw_textf(theFont, al_map_rgb(255, 255, 255), 500, 290, 0, "Layer Val: %i" ,
        Collision::getLayerVal(layer, Collision::getRow(thePlayer->getUpperRightY() , layer) , 
        Collision::getCol(thePlayer->getUpperRightX() , layer)));
}