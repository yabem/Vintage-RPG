#include "InitEnemies.h"

//Initialize character based off of the level and type
//or enemy.
void InitEnemies::init(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

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
void InitEnemies::rat(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setBmap(enemies[enemyType]);

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = RAT_BASE_HP + (level * 5);
    int mp = RAT_BASE_MP + (level * 2);
    int atk = RAT_BASE_ATK + (level * 20);
    int def = RAT_BASE_DEF + (level * 2);
    float spd = RAT_BASE_SPEED - (level * 0.1);
    int rewardXP = RAT_BASE_REWARD_XP + (level * 5);
    int moneyReward = RAT_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = ratRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the rat's rewards.
std::vector<std::string> InitEnemies::ratRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 20)
        rewards.push_back("Potion");

    return rewards;
}

//Initialize to a wolf.
void InitEnemies::wolf(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setBmap(enemies[enemyType]);

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = WOLF_BASE_HP + (level * 7);
    int mp = WOLF_BASE_MP + (level * 4);
    int atk = WOLF_BASE_ATK + (level * 40);
    int def = WOLF_BASE_DEF + (level * 4);
    float spd = WOLF_BASE_SPEED - (level * 0.1);
    int rewardXP = WOLF_BASE_REWARD_XP + (level * 5);
    int moneyReward = WOLF_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = wolfRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the wolf's rewards.
std::vector<std::string> InitEnemies::wolfRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 30)
        rewards.push_back("Potion");

    if(randomNum < 10)
        rewards.push_back("Potion2");

    return rewards;
}

//Initialize to a soldier.
void InitEnemies::soldier(Character *character , int enemyType ,
    int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setBmap(enemies[enemyType]);

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = SOLDIER_BASE_HP + (level * 6);
    int mp = SOLDIER_BASE_MP + (level * 3);
    int atk = SOLDIER_BASE_ATK + (level * 30);
    int def = SOLDIER_BASE_DEF + (level * 3);
    float spd = SOLDIER_BASE_SPEED - (level * 0.1);
    int rewardXP = SOLDIER_BASE_REWARD_XP + (level * 5);
    int moneyReward = SOLDIER_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = soldierRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the soldier's rewards.
std::vector<std::string> InitEnemies::soldierRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 40)
        rewards.push_back("Potion");

    if(randomNum < 20)
        rewards.push_back("Potion2");

    if(randomNum < 10)
        rewards.push_back("Potion3");

    return rewards;
}


//Set the spacing so the enemies are drawn correctly on the screen.
void InitEnemies::initEnemiesSpacing(vector<Character*> theEnemies){

    int totalWidth = BATTLE_START_X_ENEMIES;
    int totalHeight = BATTLE_START_Y_ENEMIES;

    //Loop through all enemies to get the total height.
    for(vector<Character*>::iterator it = theEnemies.begin() ;
        it != theEnemies.end() ; it++){
        
        //Set x and y start locations.
        (*it)->setX(totalWidth);
        (*it)->setY(totalHeight);
        
        totalHeight += ((*it)->getH() + DEFAULT_BAR_HEIGHT);
    }
}