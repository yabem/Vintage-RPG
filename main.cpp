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
#include "Animation.h"
#include "MovingImage.h"
#include "MovingText.h"
#include "Stats.h"
#include "CharStats.h"
#include "CharFactory.h"
#include "InitEnemies.h"
#include "Cutscene.h"
#include "GameManager.h"
#include "Menu.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

class BattleTrans;
//To do:
//Make controls a class
//Get rid of setStart() dupe function and create a colToX() and rowToY() functions
//Get rid of #includes
//Make battle sequence.
//Make tangible collision better so you can't go through objects.

//Tiles taken from http://opengameart.org/content/tiled-terrains

#define ttfaddon

int checkInit();
void displayVariables(ALLEGRO_FONT *theFont , int theKey , Character *thePlayer , Layer &layer);
//void increaseGameTimer(int &timer);

int main(int argc, char **argv){

    //Memory leak checks.
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG | _CRTDBG_MODE_WNDW);
    
   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;

   //List of all the keys.
   bool keys[6] = {false , false , false , false , false , false};
   bool done = false;

   int theKey = -1;
   int playWidth = 32;     //Player width
   
   int playerStartX = SCREEN_W / 2;
   int playerStartY = 0;
   int screenStartX = 800 - (SCREEN_W / 2) ;
   int screenStartY = 0;

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

#ifdef ttfaddon
   ALLEGRO_FONT *font18 = al_load_font("arial.ttf" , 18 , 0);
#endif   

   al_register_event_source(event_queue, al_get_display_event_source(display));
   al_register_event_source(event_queue, al_get_keyboard_event_source());
   al_register_event_source(event_queue, al_get_timer_event_source(timer));

   //Load the bitmaps.
   ALLEGRO_BITMAP *player = al_load_bitmap("player.png");
   ALLEGRO_BITMAP *rock = al_load_bitmap("rock.png");
   ALLEGRO_BITMAP *cloud = al_load_bitmap("clouds.png");
   ALLEGRO_BITMAP *terrain = al_load_bitmap("terrain.png");
   ALLEGRO_BITMAP *town = al_load_bitmap("town.png");
   ALLEGRO_BITMAP *rat = al_load_bitmap("rat.png");
   ALLEGRO_BITMAP *wolf = al_load_bitmap("wolf.png");
   ALLEGRO_BITMAP *soldier = al_load_bitmap("soldier.png");
   ALLEGRO_BITMAP *attack = al_load_bitmap("swordAttack.png");

   //Set background color to transparent.
   al_convert_mask_to_alpha(terrain , al_map_rgb(255,0,255)); 
   al_convert_mask_to_alpha(town , al_map_rgb(255,4,255)); 
   al_convert_mask_to_alpha(player , al_map_rgb(255,0,255)); 
   al_convert_mask_to_alpha(rock , al_map_rgb(255,0,255)); 
   al_convert_mask_to_alpha(cloud , al_map_rgb(255,0,255)); 
   al_convert_mask_to_alpha(rat , al_map_rgb(255,0,255)); 
   al_convert_mask_to_alpha(wolf , al_map_rgb(255,0,255));
   al_convert_mask_to_alpha(soldier , al_map_rgb(255,0,255));
   al_convert_mask_to_alpha(attack , al_map_rgb(255,0,255)); 

   //Create the enemy vector and add all the bitmaps.
   vector<ALLEGRO_BITMAP*> enemyModels;
   enemyModels.push_back(rat);
   enemyModels.push_back(wolf);
   enemyModels.push_back(soldier);

   //Characters
   Character thePlayer(player , playWidth , playWidth , 30 , 2 , rate);

   //Character stats
   CharStats playerStats(1 ,25 , 10 , 10 , 10 , 1 , 100 , 10);
   thePlayer.setStats(&playerStats);

   //Animations queue
   queue<Animation*> animations;

   //Moving Images
   MovingImage weaponAttack(attack , 34 , 34 , 30);

   //Moving Texts
#ifdef ttfaddon
   MovingText damage(font18 , 10 , 10 , 8 , false);
   MovingText damageStay(font18 , 10 , 10 , 16 , false);
#endif

   //Character vectors
   vector<Character*> players;
   vector<Character*> enemies;

   players.push_back(&thePlayer);

   Tangible theRock1(rock , 60 , 60 , 32 , 32 , 60 , 60 , 32 , 32);
   Tangible theRock2(rock , 888 , 888 , 32 , 32 , 888 , 888 , 32 , 32);

   Scenery cloud1(cloud , SCREEN_W , 0 , 100 , 100 , -4 , 1);
   Scenery cloud2(cloud , SCREEN_W , 40 , 100 , 100 , -8 , 0);
   Scenery cloud3(cloud , SCREEN_W , 80 , 100 , 100 , -6 , 0);
   Scenery cloud4(cloud , SCREEN_W , 120 , 100 , 100 , -10 , 2);
   Scenery cloud5(cloud , SCREEN_W , 160 , 100 , 100 , -3 , 0);
   Scenery cloud6(cloud , SCREEN_W , 200 , 100 , 100 , -2 , 0);
   Scenery cloud7(cloud , SCREEN_W , 240 , 100 , 100 , -8 , -2);
   Scenery cloud8(cloud , SCREEN_W , 280 , 100 , 100 , -9 , 0);
   Scenery cloud9(cloud , SCREEN_W , 380 , 100 , 100 , -5 , -1);

   Layer trans0(terrain , 8 , 4 , 32 , 32 , 15 , 20 , cutscene0 , 300);
   Layer trans1(terrain , 8 , 4 , 32 , 32 , 15 , 20 , cutscene1 , 300); 

   Layer layer0(terrain , 8 , 4 , 32 , 32 , 50 , 50 , town0 , 2500);
   Layer layer1(town , 10 , 13 , 32 , 32 , 50 , 50 , town1 , 2500);
   Layer layer2(town , 10 , 13 , 32 , 32  , 50 , 50 , town2 , 2500);

   Layer shop0(town , 10 , 13 , 32 , 32 , 8 , 8 , theShop0 , 64);
   Layer shop1(town , 10 , 13 , 32 , 32  , 8 , 8 , theShop1 , 64);

   Layer battle0(terrain , 8 , 4 , 32 , 32 , 15 , 20 , battleScreen0 , 300);
   Layer battle1(terrain , 8 , 4 , 32 , 32 , 15 , 20 , battleScreen1 , 300);

   vector<Layer*> layers;
   layers.push_back(&layer0);
   layers.push_back(&layer1);
   layers.push_back(&layer2);

   AreaMap theShop;
   theShop.loadLayer(&shop0);
   theShop.loadLayer(&shop1);

   AreaMap theMap;
   theMap.loadLayer(&layer0);
   theMap.loadLayer(&layer1);
   theMap.loadLayer(&layer2);

   AreaMap theMap2;
   theMap2.loadLayer(&layer0);
   theMap2.loadLayer(&layer1);

   AreaMap battleMap;
   battleMap.loadLayer(&battle0);
   battleMap.loadLayer(&battle1);

   //Trying map
   Map theBattleMap;
   theBattleMap.loadLayer(&battle0);

   AreaMap cutScene;
   cutScene.loadLayer(&trans0);
   cutScene.loadLayer(&trans1);

   theMap.loadExit(0 , 25 , &theMap2 , 48 , 25);
   theMap.loadExit(25 , 0 , &theMap2 , 25 , 48);
   theMap.loadExit(49 , 25 , &theMap2 , 2 , 25);
   theMap.loadExit(25 , 49 , &theMap2 , 25 , 2);
   theMap.loadExit(29 , 10 , &theShop , 4 , 5);
   theMap.loadExit(28 , 10 , &theShop , 4 , 5);
   
   theMap2.loadExit(0 , 25 , &theMap , 48 , 25);
   theMap2.loadExit(25 , 0 , &theMap , 25, 48);
   theMap2.loadExit(49 , 25 , &theMap , 2 , 25);
   theMap2.loadExit(25 , 49 , &theMap , 25 , 2);

   theShop.loadExit(4 , 7 , &theMap , 28 , 12);

   AreaMap *currMap = &theMap;

   theMap.loadScenery(&cloud1);
   theMap.loadScenery(&cloud2);
   theMap.loadScenery(&cloud3);
   theMap.loadScenery(&cloud4);
   theMap.loadScenery(&cloud5);
   theMap.loadScenery(&cloud6);
   theMap.loadScenery(&cloud7);
   theMap.loadScenery(&cloud8);
   theMap.loadScenery(&cloud9);

   theMap.loadTangible(&theRock1);
   theMap.loadTangible(&theRock2);


   //Create GameManager.
   GameManager gameManager = GameManager();
   gameManager.currMap = &theMap;
   gameManager.player = &thePlayer;
   gameManager.battleMap = &battleMap; 
   gameManager.cutSceneMap = &cutScene;

   gameManager.loadEnemyModel(rat);
   gameManager.loadEnemyModel(wolf);
   gameManager.loadEnemyModel(soldier);

   //Cutscenes
   Intro *theIntro = new Intro(); 
   Instruct *theInstruct = new Instruct();

   gameManager.loadCutscene(theIntro);   
   gameManager.loadCutscene(theInstruct);

   bool test = false;   //Used to set start location.
   bool battle = false;
   bool firstTime = true;

   int cutSwitch = 1;  //Switches between map and white background
   bool intro = true;   //start screen

   bool startingInstructions = true;
   int selectEnemy = 1 , enemyChoice = 0;
   int gameTimer = 0;
   int brow = 0 , bcol = 0 , theX = 0 , theY = 0;
   int theFacing = 0;
   int cutsceneFrameCount = 0 , miniCount = 0;
   int r = 0 , g = 0 , b = 0 , fade = 8;
   int menuChoice = 0;
   AreaMap* prevMap;
   srand (time(NULL));  //Seed random
   al_start_timer(timer);
   int numEnemies = 0;
   CharFactory charFactory;

   TextBox textBox("You awaken in a strange town that you have never seen before. "
       "You don't know where you are and why you are there. "
       "Your first task is to find some clues and figure out what happened. " 
       "Go forth and start your quest.");
    TextBox victoryBox("You have slain all the enemies! "
    "You gained 10xp and 50gold.");
    
    Menu menu("Attack,Magic|Fire|Fire1,Fire2,Fire3;Ice,Chain Lightning;Item|Potion,Antidote,Herb;Run;");
    menu.formatText();
    gameManager.loadMenu(&menu);
    
   //Initialize starting position.
   Movement::setStart(*gameManager.player, theMap , STARTCOL , STARTROW);
   
   ////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////////////////Game Loop////////////////////////////////////////////
   ////////////////////////////////////////////////////////////////////////////////////////
   while(!done){

      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);

        //Get keyboard input.
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN || ev.type == ALLEGRO_EVENT_KEY_UP){
            theKey = getKeyboardInput(&ev , keys);
            gameManager.updateKey(theKey);
        }
        
        //Wait for timer.
        else if(ev.type == ALLEGRO_EVENT_TIMER){

            //Add to game timer.
            gameManager.increaseGameTimer();

            //////////////////////////////////////////Cutscene//////////////////////////////////////////////
            
            if(!gameManager.cutscenes.empty()){
                gameManager.playCutscenes();
                
                gameManager.drawMenus();
                /*
                menu.draw();
                menu.moveSelection(gameManager.pressedKey);
                gameManager.resetPressedKey();
                */
                
                //menu.getSelection();
                //menu.destroyMenu();
            }

            //////////////////////////////////////////Battle////////////////////////////////////////////////
            else if(gameManager.isBattle()){

                //Save variables for end of battle.
                if(gameManager.firstTime){

                    gameManager.saveAreaMapVariables();
                    gameManager.initializeBattle();
                }

                //Check for end of battle.
                else if(keys[Q] == TRUE || gameManager.enemies.size() == 0){
                    
                    //Create victory cutscene.
                    gameManager.generateVictoryCutScene();

                    //Draw final battle frame.
                    Draw::drawArea(*gameManager.currMap , *gameManager.player);

                    //Switch to map variables.
                    gameManager.switchVariablesToMap();
                }
                
                //The battle continues.
                else{
                    
                    //Draw map.
                    Draw::drawBattle(theBattleMap , players , gameManager.enemies);

                    al_draw_filled_rectangle(gameManager.player->getX() - 100 , gameManager.player->getY() , gameManager.player->getX() - 20 , gameManager.player->getY() + 100 , al_map_rgb(0 , 0 , 255));
                    al_draw_rectangle(gameManager.player->getX() - 100 , gameManager.player->getY() , gameManager.player->getX() - 20 , gameManager.player->getY() + 100 , al_map_rgb(255 , 255 , 255) , 2 );
#ifdef ttfaddon                    
                    al_draw_textf(font18, al_map_rgb(150, 150, 150), gameManager.player->getX() - 95 , gameManager.player->getY() + 5, 0, "Attack");
                    al_draw_textf(font18, al_map_rgb(150, 150, 150), gameManager.player->getX() - 95 , gameManager.player->getY() + 25, 0, "Magic");
                    al_draw_textf(font18, al_map_rgb(150, 150, 150), gameManager.player->getX() - 95 , gameManager.player->getY() + 45, 0, "Item");
                    al_draw_textf(font18, al_map_rgb(150, 150, 150), gameManager.player->getX() - 95 , gameManager.player->getY() + 65, 0, "Run");
#endif

                    //Play all animations.
                    if(animations.size() != 0){

                        //Pop off the animaton once it's done.
                        if(animations.front()->play())
                            animations.pop();
                         
                        //Move cursor back once animations are done.
                        if(animations.size() == 0){

                            //Check if enemy is dead.
                            if((*gameManager.enemyIter)->getStats()->getCurrHP() <= 0){
                                delete (*gameManager.enemyIter)->getStats();
                                delete (*gameManager.enemyIter);
                                gameManager.enemies.erase(gameManager.enemyIter);
                            }
                            
                            gameManager.resetEnemyIter();
                            enemyChoice = 0;
                            selectEnemy = 1;
                        }
                    }

                    else{
                        switch(theKey){

                            case UP:
                                if(selectEnemy == 1 && menuChoice > 0)
                                    menuChoice -= 20;

                                if(selectEnemy == -1 && enemyChoice > 0){
                                    enemyChoice--;
                                    gameManager.enemyIter--;
                                }

                                keys[theKey] = false;
                                theKey = NOKEY;
                                break;

                            case DOWN:
                                if(selectEnemy == 1 && menuChoice < 60)
                                    menuChoice += 20;

                                if(selectEnemy == -1 && enemyChoice < gameManager.enemies.size() - 1){
                                    enemyChoice++;
                                    gameManager.enemyIter++;
                                }
                                keys[theKey] = false;
                                theKey = NOKEY;
                                break;

                            case SPACE:

                                if(selectEnemy == -1){

                                    weaponAttack.initialize(SCREEN_W , 0 , (*gameManager.enemyIter)->getX() , (*gameManager.enemyIter)->getY());
#ifdef ttfaddon
                                    damage.initialize("10" , (*gameManager.enemyIter)->getX() , (*gameManager.enemyIter)->getY() , (*gameManager.enemyIter)->getX() , (*gameManager.enemyIter)->getY() - 50);
                                    damageStay.initialize("10" , (*gameManager.enemyIter)->getX() , (*gameManager.enemyIter)->getY() , (*gameManager.enemyIter)->getX() , (*gameManager.enemyIter)->getY());
#endif
                                    (*gameManager.enemyIter)->getStats()->addToCurrHP(-10);
                                    
                                    animations.push(&weaponAttack);
#ifdef ttfaddon
                                    animations.push(&damage);
                                    animations.push(&damageStay);
#endif
                                }

                                else selectEnemy *= -1;

                                keys[theKey] = false;
                                theKey = NOKEY;
                                break;
                        }
                    }

                    if(selectEnemy == -1){

                        int sPtX = gameManager.enemies[enemyChoice]->getX() + gameManager.enemies[enemyChoice]->getW();
                        int sPtY = gameManager.enemies[enemyChoice]->getY() + gameManager.enemies[enemyChoice]->getH() / 2;

                       al_draw_filled_triangle(
                           sPtX + SELWID, sPtY - SELHGT ,       //Upper point
                           sPtX , sPtY,                         //Middle point
                           sPtX + SELWID , sPtY + SELHGT ,      //Lower point
                           al_map_rgb(150, 150, 150));
                       
                       al_draw_triangle(
                           sPtX + SELWID, sPtY - SELHGT ,       //Upper point
                           sPtX , sPtY,                         //Middle point
                           sPtX + SELWID , sPtY + SELHGT ,      //Lower point
                           al_map_rgb(255, 255, 255) , 2);
                    }

                    else{
                        al_draw_filled_triangle(gameManager.player->getX() - 120 , gameManager.player->getY() + menuChoice , gameManager.player->getX() - 100 , gameManager.player->getY() + 15 + menuChoice , gameManager.player->getX() - 120 , gameManager.player->getY() + 30 + menuChoice , al_map_rgb(150, 150, 150));
                        al_draw_triangle(gameManager.player->getX() - 120 , gameManager.player->getY() + menuChoice , gameManager.player->getX() - 100 , gameManager.player->getY() + 15 + menuChoice , gameManager.player->getX() - 120 , gameManager.player->getY() + 30 + menuChoice , al_map_rgb(255, 255, 255) , 2);
                    }
                }
            }

        //////////////////////////////////////////Moving on Map////////////////////////////////////////////////
            else{
                //Check collisions.
                Collision::characterToAreaMap(*gameManager.player , gameManager.currMap);
            
                //Move the player on the map.
                Movement::moveMap(*gameManager.player , *gameManager.currMap , theKey , keys);
            
                //Animate the player by increasing the framerate.
                gameManager.player->animate();
            
                //Animate the sceneries. 
                gameManager.currMap->animateSceneries();
            
                //Determine if there is a battle.
                gameManager.checkForBattle();

                //Draw map.
                Draw::drawArea(*gameManager.currMap , *gameManager.player);

                
     
                //Show variables.
#ifdef ttfaddon
                displayVariables(font18 , theKey , gameManager.player , gameManager.currMap->getLayer(CENTERGROUND));
                al_draw_textf(font18, al_map_rgb(0, 0, 0), 500, 310, 0, "Cutscn count: %i" , cutsceneFrameCount);
#endif
        }

        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
        }

        //Close if X clicked.
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            done = true;
   }

   //Cleanup memory allocations.
   al_destroy_display(display);
   al_destroy_timer(timer);
   al_destroy_event_queue(event_queue);
   al_destroy_bitmap(player);
   al_destroy_bitmap(terrain);
   al_destroy_bitmap(town);
   al_destroy_bitmap(rock);
   al_destroy_bitmap(cloud);
   al_destroy_bitmap(rat);
   al_destroy_bitmap(wolf);
   al_destroy_bitmap(soldier);
   al_destroy_bitmap(attack);

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


/*
void increaseGameTimer(int &gameTimer){

    //Increase ingame timer.
    gameTimer++;

    //Reset in game timer once it hits 2000.
    if(gameTimer == 2000)
        gameTimer = 0;
}
*/