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
#include "AreaMap.h"
#include "Collision.h"
#include "Movement.h"
#include "Draw.h"
#include <time.h>
#include <stdlib.h>
#include "Cutscene.h"
#include "GameManager.h"
#include "ImageStore.h"
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
#include "EasternCastleBattle.h"
#include "NorthernSnow.h"
#include "LoadExitsForNorthernSnow.h"
#include "BattleTransitionScreen.h"
#include "WesternDesert.h"
#include "LoadExitsForWesternDesert.h"
#include "SouthernForest.h"
#include "LoadExitsForSouthernForest.h"
#include "EasternCastle.h"
#include "LoadExitsForEasternCastle.h"
#include "SouthernForestBattle.h"
#include "WesternDesertBattle.h"
#include "NorthernSnowBattle.h"
#include "ShowActiveQuestLog.h"
#include "ShowCompletedQuestLog.h"
#include "ShowInventory.h"
#include "ShowPartyStatus.h"
#include "StatsByLevelStore.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//To do:
//Make controls a class
//Make tangible collision better so you can't go through objects.
//change MP to mag, put scaling on healing/recovery with mag

//Tiles taken from http://opengameart.org/content/tiled-terrains
//More tiles taken from http://opengameart.org/content/lpc-tile-atlas
//Images taken from http://rpg.hamsterrepublic.com/ohrrpgce/Free_Sprites
//Fireblast taken from http://opengameart.org/content/fire-blast
//Lightning http://opengameart.org/content/painterly-spell-icons-part-2
#define ttfaddon

int checkInit();
void displayVariables(ALLEGRO_FONT *theFont ,
    ALLEGRO_FONT *theShadowFont , int theKey ,
    Character *thePlayer , Layer &layer);

int main(int argc, char **argv){
    {
    //Memory leak checks.
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG | _CRTDBG_MODE_WNDW);
    
   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;
    
   //List of all the keys.
   bool keys[11] = {false , false , false , false , false , false ,
       false, false , false , false , false};

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

    //Creates the StatsByLevelStore.
    StatsByLevelStore statsByLevelStore;
    statsByLevelStore.loadAllCharacterStats();

    FontStore fontStore;
    fontStore.loadAllDefaultFonts();
    fontStore.loadAllDefaultColors();

    ALLEGRO_COLOR *testColor = fontStore.getColor("default");

    DrawRepository drawRepository;
    GameManager gameManager = GameManager();
    BattleManager battleManager;

    //Loads the information for the player.
    PlayerEntity playerEntity(&imageStore , &fontStore , &statsByLevelStore);
    playerEntity.createBackpack();
    playerEntity.createQuestLog();
    playerEntity.loadDefaultPlayers();
    gameManager.setPlayerEntity(&playerEntity);
    gameManager.setStatsByLevelStore(&statsByLevelStore);

    HomeTown homeTown(&imageStore , &drawRepository , &gameManager , 
        &battleManager , &fontStore , AREA_MAP_SIZE);
    homeTown.loadDefaults();

    HomeTownShop homeTownShop(&imageStore , &drawRepository , &gameManager , 
        &battleManager , &fontStore , BATTLE_MAP_SIZE);
    homeTownShop.loadDefaults();

    EasternCastleBattle easternCastleBattle(&imageStore , BATTLE_MAP_SIZE);
    easternCastleBattle.loadDefaults();
    
    NorthernSnow northernSnow(&imageStore , &drawRepository , &gameManager , 
        &battleManager , &fontStore , AREA_MAP_SIZE);
    northernSnow.loadDefaults();

    NorthernSnowBattle northernSnowBattle(&imageStore , BATTLE_MAP_SIZE);
    northernSnowBattle.loadDefaults();

    BattleTransitionScreen battleTransitionScreen(&imageStore);
    battleTransitionScreen.loadDefaults();

    WesternDesert westernDesert(&imageStore , &drawRepository , &gameManager , 
        &battleManager , &fontStore , AREA_MAP_SIZE);
    westernDesert.loadDefaults();

    WesternDesertBattle westernDesertBattle(&imageStore , BATTLE_MAP_SIZE);
    westernDesertBattle.loadDefaults();

    SouthernForest southernForest(&imageStore , &drawRepository , &gameManager , 
        &battleManager , &fontStore , AREA_MAP_SIZE);
    southernForest.loadDefaults();

    SouthernForestBattle southernForestBattle(&imageStore , BATTLE_MAP_SIZE);
    southernForestBattle.loadDefaults();

    EasternCastle easternCastle(&imageStore , &drawRepository , &gameManager , 
        &battleManager , &fontStore , AREA_MAP_SIZE);
    easternCastle.loadDefaults();

    //Set battlemaps.
    homeTown.setBattleMap(&easternCastleBattle);
    northernSnow.setBattleMap(&northernSnowBattle);
    westernDesert.setBattleMap(&westernDesertBattle);
    southernForest.setBattleMap(&southernForestBattle);
    easternCastle.setBattleMap(&easternCastleBattle);

    gameManager.currMap = &homeTown;
    gameManager.player = playerEntity.getFirstPlayer();
    gameManager.battleMap = &easternCastleBattle;
    gameManager.cutSceneMap = &battleTransitionScreen;
    gameManager.loadPlayers(playerEntity.getThePlayers());

    int cutsceneFrameCount = 0;  //For display.
    srand (time(NULL));  //Seed random

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
    battleManager.loadEnemyModel(imageStore.getBitMap("iceBull"));
    battleManager.loadEnemyModel(imageStore.getBitMap("blobKing"));
    battleManager.loadEnemyModel(imageStore.getBitMap("guardian"));
    battleManager.loadEnemyModel(imageStore.getBitMap("demon"));
    battleManager.loadEnemyModel(imageStore.getBitMap("carrotRat"));
    battleManager.loadEnemyModel(imageStore.getBitMap("walrus"));
    battleManager.loadEnemyModel(imageStore.getBitMap("gooCube"));
    battleManager.loadEnemyModel(imageStore.getBitMap("iceCube"));
    battleManager.loadEnemyModel(imageStore.getBitMap("fireCube"));
    battleManager.loadEnemyModel(imageStore.getBitMap("shieldSkeleton"));
    battleManager.loadEnemyModel(imageStore.getBitMap("wererat"));
    battleManager.loadEnemyModel(imageStore.getBitMap("cactus"));
    battleManager.loadEnemyModel(imageStore.getBitMap("oldmanAxe"));
    battleManager.loadEnemyModel(imageStore.getBitMap("mushroomMan"));
    battleManager.loadEnemyModel(imageStore.getBitMap("zombie"));
    battleManager.loadEnemyModel(imageStore.getBitMap("babyBlob"));
    battleManager.loadEnemyModel(imageStore.getBitMap("sheep"));
    battleManager.loadEnemyModel(imageStore.getBitMap("kungfooDog"));
    battleManager.loadEnemyModel(imageStore.getBitMap("fangedFox"));
    battleManager.loadEnemyModel(imageStore.getBitMap("ninjaFox"));
    battleManager.loadEnemyModel(imageStore.getBitMap("redReaper"));
    battleManager.loadDrawRepository(&drawRepository);
    battleManager.loadBackpack(playerEntity.getPlayerInventory());
    battleManager.loadFontStore(&fontStore);

    gameManager.loadDrawRepository(&drawRepository);

    //Cutscenes
    Intro *theIntro = new Intro(fontStore.getFont("default") , &imageStore); 
    theIntro->loadBackground();
    Instruct *theInstruct = new Instruct(fontStore.getFont("default"));

    drawRepository.loadCutscene(theIntro);   
    drawRepository.loadCutscene(theInstruct);

    //Initialize starting position.
    LoadExitsForHomeTown::LoadExitsForHomeTown(&homeTown , &homeTownShop , &northernSnow ,
        &westernDesert , &easternCastle , &southernForest);
    LoadExitsForHomeTownShop::LoadExitsForHomeTownShop(&homeTownShop , &homeTown);
    LoadExitsForNorthernSnow::LoadExitsForNorthernSnow(&northernSnow , &homeTown);
    LoadExitsForWesternDesert::LoadExitsForWesternDesert(&westernDesert , &homeTown);
    LoadExitsForSouthernForest::LoadExitsForSouthernForest(&southernForest , &homeTown);
    LoadExitsForEasternCastle::LoadExitsForEasternCastle(&easternCastle , &homeTown);
    Movement::setStartCoords(*gameManager.player, homeTown , 
        Conversion::convertTilesToPixels(STARTCOL) , 
        Conversion::convertTilesToPixels(STARTROW));

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

                    if(!battleManager.isEventsEmpty()){

                        battleManager.pauseBattle();
                        battleManager.playCurrEvent();
                    }     

                    //Increase battle time.
                    if(!battleManager.battlePaused()){

                        battleManager.incrementBattleTime();
                        battleManager.recalculateFillRatesOnTimers();
                        battleManager.updateAugments();
                    }

                    //Unpause the battle if the event is done.
                    if(battleManager.isEventsEmpty()){
                            
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
                    gameManager.currMap , &gameManager);
            
                //Display active quest log.
                if(gameManager.getPressedKey() == L){
                    ShowActiveQuestLog *showActiveQuestLog = new 
                        ShowActiveQuestLog(&gameManager , &playerEntity);
                    drawRepository.loadCutscene(showActiveQuestLog);
                    gameManager.resetPressedKey();
                }

                //Display completed quest log.
                if(gameManager.getPressedKey() == O){
                    ShowCompletedQuestLog *showCompletedQuestLog = new 
                        ShowCompletedQuestLog(&gameManager , &playerEntity);
                    drawRepository.loadCutscene(showCompletedQuestLog);
                    gameManager.resetPressedKey();
                }

                //Display player inventory.
                if(gameManager.getPressedKey() == I){
                    ShowInventory *showInvenory= new 
                        ShowInventory(&gameManager , &playerEntity);
                    drawRepository.loadCutscene(showInvenory);
                    gameManager.resetPressedKey();
                }

                //Display party statuses.
                if(gameManager.getPressedKey() == U){
                    ShowPartyStatus *showPartyStatus= new 
                        ShowPartyStatus(&gameManager , &playerEntity);
                    drawRepository.loadCutscene(showPartyStatus);
                    gameManager.resetPressedKey();
                }

                //Move the player on the map.
                Movement::moveMap(*gameManager.player , *gameManager.currMap ,
                    gameManager.getPressedKey(), keys , &battleManager);

                //Animate the player by increasing the framerate.
                gameManager.player->animate();
            
                //Animate the sceneries. 
                gameManager.currMap->animateSceneries();

                //Force a battle for testing.
                if(gameManager.getPressedKey() == Q){
                    battleManager.initializeBattle();
                }

                //Draw map.
                Draw::drawArea(*gameManager.currMap , *gameManager.player);
 
                //Show variables.
                
#ifdef ttfaddon
                displayVariables(fontStore.getFont("default") ,
                    fontStore.getFont("shadowFont"),
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

void displayVariables(ALLEGRO_FONT *theFont , ALLEGRO_FONT *theShadowFont , 
    int theKey , Character *thePlayer , Layer &layer){

    al_draw_textf(theFont, al_map_rgb(0, 0, 0), 499, 10, 0, "KEY: %i" , theKey); 
    al_draw_textf(theFont, al_map_rgb(0, 0, 0), 501, 10, 0, "KEY: %i" , theKey); 
    al_draw_textf(theFont, al_map_rgb(0, 0, 0), 500, 9, 0, "KEY: %i" , theKey); 
    al_draw_textf(theFont, al_map_rgb(0, 0, 0), 500, 11, 0, "KEY: %i" , theKey); 
    al_draw_textf(theFont, al_map_rgb(255, 255, 255), 500, 10, 0, "KEY: %i" , theKey); 

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