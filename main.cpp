#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
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
#include "HomeTownArmory.h"
#include "HomeTownBar.h"
#include "LoadExitsForHomeTownShop.h"
#include "LoadExitsForHomeTownArmory.h"
#include "LoadExitsForHomeTownBar.h"
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
#include "InsideCastle.h"
#include "InsideCastleBattle.h"
#include "LoadExitsForCastle.h"
#include "NorthernSnowBattle.h"
#include "StatsByLevelStore.h"
#include "MusicBox.h"
#include "ProcessPlayerInput.h"
#include "GameInitialization.h"
#include "EndGameWithCredits.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//To do:
//Give clues about secret quests.


//Tiles taken from http://opengameart.org/content/tiled-terrains
//Tile editor http://tilestudio.sourceforge.net/
//More tiles taken from http://opengameart.org/content/lpc-tile-atlas
//Images taken from http://rpg.hamsterrepublic.com/ohrrpgce/Free_Sprites
//Fireblast taken from http://opengameart.org/content/fire-blast
//Lightning http://opengameart.org/content/painterly-spell-icons-part-2
//Music http://incompetech.com/music/royalty-free/index.html?collection=045&Search=Search
//Music Metaphysik http://incompetech.com/music/royalty-free/index.html?collection=035&Search=Search
//Music Split Synapse, Mistake the Gateway, Alchemists Tower http://incompetech.com/music/royalty-free/index.html?collection=033&page=1

//#define DISPLAY_COORDINATES
//#define Q_FOR_BATTLE

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
 
    //Load addons
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_audio();
    al_init_acodec_addon();

    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 / FPS);

    MusicBox musicBox;
    musicBox.loadAllSongs();
    musicBox.playSong("Moonlight Hall");

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

    HomeTownArmory homeTownArmory(&imageStore , &drawRepository , &gameManager , 
        &battleManager , &fontStore , BATTLE_MAP_SIZE);
    homeTownArmory.loadDefaults();

    HomeTownBar homeTownBar(&imageStore , &drawRepository , &gameManager , 
        &battleManager , &fontStore , BATTLE_MAP_SIZE);
    homeTownBar.loadDefaults();

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

    InsideCastle insideCastle(&imageStore , &drawRepository , &gameManager , 
        &battleManager , &fontStore , 1600);
    insideCastle.loadDefaults();

    InsideCastleBattle insideCastleBattle(&imageStore , BATTLE_MAP_SIZE);
        insideCastleBattle.loadDefaults();
    
    //Set battlemaps.
    homeTown.setBattleMap(&easternCastleBattle);
    northernSnow.setBattleMap(&northernSnowBattle);
    westernDesert.setBattleMap(&westernDesertBattle);
    southernForest.setBattleMap(&southernForestBattle);
    easternCastle.setBattleMap(&easternCastleBattle);
    insideCastle.setBattleMap(&insideCastleBattle);

    gameManager.currMap = &homeTown;
    gameManager.player = playerEntity.getFirstPlayer();
    gameManager.battleMap = &easternCastleBattle;
    gameManager.cutSceneMap = &battleTransitionScreen;
    gameManager.loadPlayers(playerEntity.getThePlayers());
    gameManager.loadMusicBox(&musicBox);

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

    GameInitialization::loadAllEnemyModels(&battleManager , &imageStore);

    battleManager.loadDrawRepository(&drawRepository);
    battleManager.loadBackpack(playerEntity.getPlayerInventory());
    battleManager.loadFontStore(&fontStore);

    gameManager.loadDrawRepository(&drawRepository);

    //Cutscenes
    GameInitialization::loadIntro(&gameManager , &drawRepository , &fontStore , &imageStore);

    //Load all the map exits
    LoadExitsForHomeTown::LoadExitsForHomeTown(&homeTown , &homeTownShop , &homeTownArmory , &homeTownBar ,
        &northernSnow , &westernDesert , &easternCastle , &southernForest);
    LoadExitsForHomeTownShop::LoadExitsForHomeTownShop(&homeTownShop , &homeTown);
    LoadExitsForHomeTownArmory::LoadExitsForHomeTownArmory(&homeTownArmory , &homeTown);
    LoadExitsForHomeTownBar::LoadExitsForHomeTownBar(&homeTownBar , &homeTown);
    LoadExitsForNorthernSnow::LoadExitsForNorthernSnow(&northernSnow , &homeTown);
    LoadExitsForWesternDesert::LoadExitsForWesternDesert(&westernDesert , &homeTown);
    LoadExitsForSouthernForest::LoadExitsForSouthernForest(&southernForest , &homeTown);
    LoadExitsForEasternCastle::LoadExitsForEasternCastle(&easternCastle , &homeTown , &insideCastle);
    LoadExitsForCastle::LoadExitsForCastle(&insideCastle , &easternCastle);
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
            
                ProcessPlayerInput::processPlayerInput(&gameManager , 
                    &playerEntity , &drawRepository);

                //Move the player on the map.
                Movement::moveMap(*gameManager.player , *gameManager.currMap ,
                    gameManager.getPressedKey(), keys , &battleManager);

                //Animate the player by increasing the framerate.
                gameManager.player->animate();
            
                //Animate the sceneries. 
                gameManager.currMap->animateSceneries();

#ifdef Q_FOR_BATTLE
                //Force a battle for testing.
                if(gameManager.getPressedKey() == Q){
                    battleManager.initializeBattle();
                }
#endif
                //Draw map.
                Draw::drawArea(*gameManager.currMap , *gameManager.player);
 
                //Show variables.
                
#ifdef DISPLAY_COORDINATES
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