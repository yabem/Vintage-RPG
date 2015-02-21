#include "InitEnemies.h"

//Initialize character based off of the level and type
//or enemy.
void InitEnemies::init(Character *character , int enemyType , int level , vector<ALLEGRO_BITMAP*> enemies){

    switch(enemyType){
        case RAT:
            rat(character , enemyType , level , enemies);
            break;

        case WOLF:
            wolf(character , enemyType , level , enemies);

        case SOLDIER:
            soldier(character , enemyType , level , enemies);

        default:
            return;
    }
}

//Initialize to a rat.
void InitEnemies::rat(Character *character , int enemyType , int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setBmap(enemies[enemyType]);

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = RATBASEHP + (level * 5);
    int mp = RATBASEMP + (level * 2);
    int atk = RATBASEATK + (level * 2);
    int def = RATBASEDEF + (level * 2);

    CharStats *charStats = new CharStats(level , hp , mp , atk , def, 0 , 0 , 0);

    character->setStats(charStats);
}

//Initialize to a wolf.
void InitEnemies::wolf(Character *character , int enemyType , int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setBmap(enemies[enemyType]);

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = WOLFBASEHP + (level * 7);
    int mp = WOLFBASEMP + (level * 4);
    int atk = WOLFBASEATK + (level * 4);
    int def = WOLFBASEDEF + (level * 4);

    CharStats *charStats = new CharStats(level , hp , mp , atk , def, 0 , 0 , 0);

    character->setStats(charStats);
}

//Initialize to a wolf.
void InitEnemies::soldier(Character *character , int enemyType ,
    int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setBmap(enemies[enemyType]);

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = SOLDIERBASEHP + (level * 6);
    int mp = SOLDIERBASEMP + (level * 3);
    int atk = SOLDIERBASEATK + (level * 3);
    int def = SOLDIERBASEDEF + (level * 3);

    CharStats *charStats = new CharStats(level , hp , mp , atk , def, 0 , 0 , 0);

    character->setStats(charStats);
}

//Set the spacing so the enemies are drawn correctly on the screen.
void InitEnemies::initEnemiesSpacing(vector<Character*> theEnemies){

    int totalWidth = BATTLESTARTX;
    int totalHeight = BATTLESTARTY;

    //Loop through all enemies to get the total height.
    for(vector<Character*>::iterator it = theEnemies.begin() ;
        it != theEnemies.end() ; it++){
        
        //Set x and y start locations.
        (*it)->setX(totalWidth);
        (*it)->setY(totalHeight);
        
        totalHeight += (*it)->getH();
    }
}