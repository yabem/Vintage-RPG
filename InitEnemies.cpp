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
            break;

        case SOLDIER:
            soldier(character , enemyType , level , enemies);
            break;

        case ICE_BULL:
            iceBull(character , enemyType , level , enemies);
            break;

        case BLOB_KING:
            blobKing(character , enemyType , level , enemies);
            break;

        case GUARDIAN:
            guardian(character , enemyType , level , enemies);
            break;

        case DEMON:
            demon(character , enemyType , level , enemies);
            break;

        case CARROT_RAT:
            carrotRat(character , enemyType , level , enemies);
            break;

        case WALRUS:
            walrus(character , enemyType , level , enemies);
            break;

        case GOO_CUBE:
            gooCube(character , enemyType , level , enemies);
            break;

        case ICE_CUBE:
            iceCube(character , enemyType , level , enemies);
            break;

        case FIRE_CUBE:
            fireCube(character , enemyType , level , enemies);
            break;

        case SHIELD_SKELETON:
            shieldSkeleton(character , enemyType , level , enemies);
            break;

        case WERERAT:
            wererat(character , enemyType , level , enemies);
            break;

        case CACTUS:
            cactus(character , enemyType , level , enemies);
            break;

        case OLDMAN_AXE:
            oldmanAxe(character , enemyType , level , enemies);
            break;

        case MUSHROOM_MAN:
            mushroomMan(character , enemyType , level , enemies);
            break;

        case ZOMBIE:
            zombie(character , enemyType , level , enemies);
            break;

        case BABY_BLOB:
            babyBlob(character , enemyType , level , enemies);
            break;

        case SHEEP:
            sheep(character , enemyType , level , enemies);
            break;

        case KUNGFOO_DOG:
            kungfooDog(character , enemyType , level , enemies);
            break;

        case FANGED_FOX:
            fangedFox(character , enemyType , level , enemies);
            break;

        case NINJA_FOX:
            ninjaFox(character , enemyType , level , enemies);
            break;

        case RED_REAPER:
            redReaper(character , enemyType , level , enemies);
            break;

        default:
            return;
    }
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

//Initialize to a rat.
void InitEnemies::rat(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("rat");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = RAT_BASE_HP + (level * 5);
    int mp = RAT_BASE_MP + (level * 2);
    int atk = RAT_BASE_ATK + (level * 5);
    int def = RAT_BASE_DEF + (level * 1);
    float spd = RAT_BASE_SPEED - (level * 0.1);
    int rewardXP = RAT_BASE_REWARD_XP + (level * 5);
    int moneyReward = RAT_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = ratRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the rat's rewards.
std::vector<std::string> InitEnemies::ratRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 30)
        rewards.push_back("Stick");

    if(randomNum < 10)
        rewards.push_back("Rock");

    return rewards;
}

//Initialize to a wolf.
void InitEnemies::wolf(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("wolf");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = WOLF_BASE_HP + (level * 7);
    int mp = WOLF_BASE_MP + (level * 4);
    int atk = WOLF_BASE_ATK + (level * 7);
    int def = WOLF_BASE_DEF + (level * 1);
    float spd = WOLF_BASE_SPEED - (level * 0.1);
    int rewardXP = WOLF_BASE_REWARD_XP + (level * 5);
    int moneyReward = WOLF_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = wolfRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the wolf's rewards.
std::vector<std::string> InitEnemies::wolfRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 30)
        rewards.push_back("Red Potion");

    if(randomNum < 10)
        rewards.push_back("Green Potion");

    return rewards;
}

//Initialize to a soldier.
void InitEnemies::soldier(Character *character , int enemyType ,
    int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("soldier");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = SOLDIER_BASE_HP + (level * 6);
    int mp = SOLDIER_BASE_MP + (level * 3);
    int atk = SOLDIER_BASE_ATK + (level * 9);
    int def = SOLDIER_BASE_DEF + (level * 2);
    float spd = SOLDIER_BASE_SPEED - (level * 0.1);
    int rewardXP = SOLDIER_BASE_REWARD_XP + (level * 5);
    int moneyReward = SOLDIER_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = soldierRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the soldier's rewards.
std::vector<std::string> InitEnemies::soldierRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 15)
        rewards.push_back("Red Potion");

    if(randomNum < 15)
        rewards.push_back("Green Potion");

    if(randomNum < 15)
        rewards.push_back("Blue Potion");

    return rewards;
}

//Initialize to an ice bull.
void InitEnemies::iceBull(Character *character , int enemyType ,
    int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("iceBull");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = ICE_BULL_BASE_HP + (level * 6);
    int mp = ICE_BULL_BASE_MP + (level * 3);
    int atk = ICE_BULL_BASE_ATK + (level * 10);
    int def = ICE_BULL_BASE_DEF + (level * 2);
    float spd = ICE_BULL_BASE_SPEED - (level * 0.1);
    int rewardXP = ICE_BULL_BASE_REWARD_XP + (level * 5);
    int moneyReward = ICE_BULL_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = iceBullRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the iceBull's rewards.
std::vector<std::string> InitEnemies::iceBullRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 100)
        rewards.push_back("Ice Bull Horns");

    return rewards;
}

//Initialize to a blobKing.
void InitEnemies::blobKing(Character *character , int enemyType ,
    int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("blobKing");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = BLOB_KING_BASE_HP + (level * 6);
    int mp = BLOB_KING_BASE_MP + (level * 3);
    int atk = BLOB_KING_BASE_ATK + (level * 15);
    int def = BLOB_KING_BASE_DEF + (level * 2);
    float spd = BLOB_KING_BASE_SPEED - (level * 0.1);
    int rewardXP = BLOB_KING_BASE_REWARD_XP + (level * 5);
    int moneyReward = BLOB_KING_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = blobKingRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the blobKing's rewards.
std::vector<std::string> InitEnemies::blobKingRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 100)
        rewards.push_back("Blob King Crown");

    return rewards;
}

//Initialize to a guardian.
void InitEnemies::guardian(Character *character , int enemyType ,
    int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("guardian");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = GUARDIAN_BASE_HP + (level * 6);
    int mp = GUARDIAN_BASE_MP + (level * 3);
    int atk = GUARDIAN_BASE_ATK + (level * 14);
    int def = GUARDIAN_BASE_DEF + (level * 2);
    float spd = GUARDIAN_BASE_SPEED - (level * 0.1);
    int rewardXP = GUARDIAN_BASE_REWARD_XP + (level * 5);
    int moneyReward = GUARDIAN_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = guardianRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the guardian's rewards.
std::vector<std::string> InitEnemies::guardianRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 100)
        rewards.push_back("Guardian Collar");

    return rewards;
}

//Initialize to a demon.
void InitEnemies::demon(Character *character , int enemyType ,
    int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("demon");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = DEMON_BASE_HP + (level * 6);
    int mp = DEMON_BASE_MP + (level * 3);
    int atk = DEMON_BASE_ATK + (level * 14);
    int def = DEMON_BASE_DEF + (level * 2);
    float spd = DEMON_BASE_SPEED - (level * 0.1);
    int rewardXP = DEMON_BASE_REWARD_XP + (level * 5);
    int moneyReward = DEMON_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = demonRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the demon's rewards.
std::vector<std::string> InitEnemies::demonRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 100)
        rewards.push_back("Demon Jewel");

    return rewards;
}

//Initialize to a carrotRat.
void InitEnemies::carrotRat(Character *character , int enemyType ,
    int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("carrotRat");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = CARROT_RAT_BASE_HP + (level * 6);
    int mp = CARROT_RAT_BASE_MP + (level * 3);
    int atk = CARROT_RAT_BASE_ATK + (level * 14);
    int def = CARROT_RAT_BASE_DEF + (level * 2);
    float spd = CARROT_RAT_BASE_SPEED - (level * 0.1);
    int rewardXP = CARROT_RAT_BASE_REWARD_XP + (level * 5);
    int moneyReward = CARROT_RAT_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = carrotRatRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the carrotRat's rewards.
std::vector<std::string> InitEnemies::carrotRatRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 5)
        rewards.push_back("Carrot");

    return rewards;
}

//Initialize to a walrus.
void InitEnemies::walrus(Character *character , int enemyType ,
    int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("walrus");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = WALRUS_BASE_HP + (level * 6);
    int mp = WALRUS_BASE_MP + (level * 3);
    int atk = WALRUS_BASE_ATK + (level * 14);
    int def = WALRUS_BASE_DEF + (level * 2);
    float spd = WALRUS_BASE_SPEED - (level * 0.1);
    int rewardXP = WALRUS_BASE_REWARD_XP + (level * 5);
    int moneyReward = WALRUS_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = walrusRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the walrus's rewards.
std::vector<std::string> InitEnemies::walrusRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 5)
        rewards.push_back("Whiskers");

    return rewards;
}

//Initialize to a gooCube.
void InitEnemies::gooCube(Character *character , int enemyType ,
    int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("gooCube");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = GOO_CUBE_BASE_HP + (level * 6);
    int mp = GOO_CUBE_BASE_MP + (level * 3);
    int atk = GOO_CUBE_BASE_ATK + (level * 14);
    int def = GOO_CUBE_BASE_DEF + (level * 2);
    float spd = GOO_CUBE_BASE_SPEED - (level * 0.1);
    int rewardXP = GOO_CUBE_BASE_REWARD_XP + (level * 5);
    int moneyReward = GOO_CUBE_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = gooCubeRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the gooCube's rewards.
std::vector<std::string> InitEnemies::gooCubeRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 30)
        rewards.push_back("Small Goo");

    if(randomNum < 20)
        rewards.push_back("Medium Goo");

    if(randomNum < 10)
        rewards.push_back("Large Goo");

    return rewards;
}

//Initialize to a iceCube.
void InitEnemies::iceCube(Character *character , int enemyType ,
    int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("iceCube");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = ICE_CUBE_BASE_HP + (level * 6);
    int mp = ICE_CUBE_BASE_MP + (level * 3);
    int atk = ICE_CUBE_BASE_ATK + (level * 14);
    int def = ICE_CUBE_BASE_DEF + (level * 2);
    float spd = ICE_CUBE_BASE_SPEED - (level * 0.1);
    int rewardXP = ICE_CUBE_BASE_REWARD_XP + (level * 5);
    int moneyReward = ICE_CUBE_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = iceCubeRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the iceCube's rewards.
std::vector<std::string> InitEnemies::iceCubeRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 30)
        rewards.push_back("Small Goo");

    if(randomNum < 20)
        rewards.push_back("Medium Goo");

    if(randomNum < 10)
        rewards.push_back("Large Goo");

    return rewards;
}

//Initialize to a fireCube.
void InitEnemies::fireCube(Character *character , int enemyType ,
    int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("fireCube");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = FIRE_CUBE_BASE_HP + (level * 6);
    int mp = FIRE_CUBE_BASE_MP + (level * 3);
    int atk = FIRE_CUBE_BASE_ATK + (level * 14);
    int def = FIRE_CUBE_BASE_DEF + (level * 2);
    float spd = FIRE_CUBE_BASE_SPEED - (level * 0.1);
    int rewardXP = FIRE_CUBE_BASE_REWARD_XP + (level * 5);
    int moneyReward = FIRE_CUBE_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = fireCubeRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the fireCube's rewards.
std::vector<std::string> InitEnemies::fireCubeRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 30)
        rewards.push_back("Small Goo");

    if(randomNum < 20)
        rewards.push_back("Medium Goo");

    if(randomNum < 10)
        rewards.push_back("Large Goo");

    return rewards;
}

//Initialize to a shieldSkeleton.
void InitEnemies::shieldSkeleton(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("shieldSkeleton");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = SHIELD_SKELETON_BASE_HP + (level * 5);
    int mp = SHIELD_SKELETON_BASE_MP + (level * 2);
    int atk = SHIELD_SKELETON_BASE_ATK + (level * 5);
    int def = SHIELD_SKELETON_BASE_DEF + (level * 1);
    float spd = SHIELD_SKELETON_BASE_SPEED - (level * 0.1);
    int rewardXP = SHIELD_SKELETON_BASE_REWARD_XP + (level * 5);
    int moneyReward = SHIELD_SKELETON_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = shieldSkeletonRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the shieldSkeleton's rewards.
std::vector<std::string> InitEnemies::shieldSkeletonRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 20)
        rewards.push_back("Rock");

    if(randomNum < 20)
        rewards.push_back("Sand");

    return rewards;
}

//Initialize to a wererat.
void InitEnemies::wererat(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("wererat");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = WERERAT_BASE_HP + (level * 5);
    int mp = WERERAT_BASE_MP + (level * 2);
    int atk = WERERAT_BASE_ATK + (level * 5);
    int def = WERERAT_BASE_DEF + (level * 1);
    float spd = WERERAT_BASE_SPEED - (level * 0.1);
    int rewardXP = WERERAT_BASE_REWARD_XP + (level * 5);
    int moneyReward = WERERAT_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = wereratRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the wererat's rewards.
std::vector<std::string> InitEnemies::wereratRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 30)
        rewards.push_back("Green Potion");

    if(randomNum < 10)
        rewards.push_back("Blue Potion");

    return rewards;
}

//Initialize to a cactus.
void InitEnemies::cactus(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("cactus");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = CACTUS_BASE_HP + (level * 5);
    int mp = CACTUS_BASE_MP + (level * 2);
    int atk = CACTUS_BASE_ATK + (level * 5);
    int def = CACTUS_BASE_DEF + (level * 1);
    float spd = CACTUS_BASE_SPEED - (level * 0.1);
    int rewardXP = CACTUS_BASE_REWARD_XP + (level * 5);
    int moneyReward = CACTUS_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = cactusRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the cactus's rewards.
std::vector<std::string> InitEnemies::cactusRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 20)
        rewards.push_back("Napalm");

    if(randomNum < 20)
        rewards.push_back("Sand");

    return rewards;
}

//Initialize to a oldmanAxe.
void InitEnemies::oldmanAxe(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("oldmanAxe");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = OLDMAN_AXE_BASE_HP + (level * 5);
    int mp = OLDMAN_AXE_BASE_MP + (level * 2);
    int atk = OLDMAN_AXE_BASE_ATK + (level * 5);
    int def = OLDMAN_AXE_BASE_DEF + (level * 1);
    float spd = OLDMAN_AXE_BASE_SPEED - (level * 0.1);
    int rewardXP = OLDMAN_AXE_BASE_REWARD_XP + (level * 5);
    int moneyReward = OLDMAN_AXE_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = oldmanAxeRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the oldmanAxe's rewards.
std::vector<std::string> InitEnemies::oldmanAxeRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 5)
        rewards.push_back("Old Man Spices");

    return rewards;
}

//Initialize to a mushroomMan.
void InitEnemies::mushroomMan(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("mushroomMan");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = MUSHROOM_MAN_BASE_HP + (level * 5);
    int mp = MUSHROOM_MAN_BASE_MP + (level * 2);
    int atk = MUSHROOM_MAN_BASE_ATK + (level * 5);
    int def = MUSHROOM_MAN_BASE_DEF + (level * 1);
    float spd = MUSHROOM_MAN_BASE_SPEED - (level * 0.1);
    int rewardXP = MUSHROOM_MAN_BASE_REWARD_XP + (level * 5);
    int moneyReward = MUSHROOM_MAN_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = mushroomManRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the mushroomMan's rewards.
std::vector<std::string> InitEnemies::mushroomManRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 30)
        rewards.push_back("Blue Potion");

    if(randomNum < 10)
        rewards.push_back("Red Potion");

    return rewards;
}

//Initialize to a zombie.
void InitEnemies::zombie(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("zombie");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = ZOMBIE_BASE_HP + (level * 5);
    int mp = ZOMBIE_BASE_MP + (level * 2);
    int atk = ZOMBIE_BASE_ATK + (level * 5);
    int def = ZOMBIE_BASE_DEF + (level * 1);
    float spd = ZOMBIE_BASE_SPEED - (level * 0.1);
    int rewardXP = ZOMBIE_BASE_REWARD_XP + (level * 5);
    int moneyReward = ZOMBIE_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = zombieRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the zombie's rewards.
std::vector<std::string> InitEnemies::zombieRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 20)
        rewards.push_back("Napalm");

    if(randomNum < 20)
        rewards.push_back("Sand");

    return rewards;
}

//Initialize to a babyBlob.
void InitEnemies::babyBlob(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("babyBlob");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = BABY_BLOB_BASE_HP + (level * 5);
    int mp = BABY_BLOB_BASE_MP + (level * 2);
    int atk = BABY_BLOB_BASE_ATK + (level * 5);
    int def = BABY_BLOB_BASE_DEF + (level * 1);
    float spd = BABY_BLOB_BASE_SPEED - (level * 0.1);
    int rewardXP = BABY_BLOB_BASE_REWARD_XP + (level * 5);
    int moneyReward = BABY_BLOB_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = babyBlobRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the babyBlob's rewards.
std::vector<std::string> InitEnemies::babyBlobRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 5)
        rewards.push_back("Blob Eye");

    return rewards;
}

//Initialize to a sheep.
void InitEnemies::sheep(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("sheep");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = SHEEP_BASE_HP + (level * 5);
    int mp = SHEEP_BASE_MP + (level * 2);
    int atk = SHEEP_BASE_ATK + (level * 5);
    int def = SHEEP_BASE_DEF + (level * 1);
    float spd = SHEEP_BASE_SPEED - (level * 0.1);
    int rewardXP = SHEEP_BASE_REWARD_XP + (level * 5);
    int moneyReward = SHEEP_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = sheepRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the sheep's rewards.
std::vector<std::string> InitEnemies::sheepRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 30)
        rewards.push_back("Tiny Eye");

    if(randomNum < 10)
        rewards.push_back("Bloodshot Eye");

    if(randomNum < 10)
        rewards.push_back("Pussing Eye");

    return rewards;
}

//Initialize to a kungfooDog.
void InitEnemies::kungfooDog(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("kungfooDog");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = KUNGFOO_DOG_BASE_HP + (level * 5);
    int mp = KUNGFOO_DOG_BASE_MP + (level * 2);
    int atk = KUNGFOO_DOG_BASE_ATK + (level * 5);
    int def = KUNGFOO_DOG_BASE_DEF + (level * 1);
    float spd = KUNGFOO_DOG_BASE_SPEED - (level * 0.1);
    int rewardXP = KUNGFOO_DOG_BASE_REWARD_XP + (level * 5);
    int moneyReward = KUNGFOO_DOG_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = kungfooDogRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the kungfooDog's rewards.
std::vector<std::string> InitEnemies::kungfooDogRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 5)
        rewards.push_back("Kungfoo Belt");

    return rewards;
}

//Initialize to a fangedFox.
void InitEnemies::fangedFox(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("fangedFox");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = FANGED_FOX_BASE_HP + (level * 5);
    int mp = FANGED_FOX_BASE_MP + (level * 2);
    int atk = FANGED_FOX_BASE_ATK + (level * 5);
    int def = FANGED_FOX_BASE_DEF + (level * 1);
    float spd = FANGED_FOX_BASE_SPEED - (level * 0.1);
    int rewardXP = FANGED_FOX_BASE_REWARD_XP + (level * 5);
    int moneyReward = FANGED_FOX_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = fangedFoxRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the fangedFox's rewards.
std::vector<std::string> InitEnemies::fangedFoxRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 30)
        rewards.push_back("Tiny Eye");

    if(randomNum < 15)
        rewards.push_back("Pussing Eye");

    return rewards;
}

//Initialize to a ninjaFox.
void InitEnemies::ninjaFox(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("ninjaFox");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = NINJA_FOX_BASE_HP + (level * 5);
    int mp = NINJA_FOX_BASE_MP + (level * 2);
    int atk = NINJA_FOX_BASE_ATK + (level * 5);
    int def = NINJA_FOX_BASE_DEF + (level * 1);
    float spd = NINJA_FOX_BASE_SPEED - (level * 0.1);
    int rewardXP = NINJA_FOX_BASE_REWARD_XP + (level * 5);
    int moneyReward = NINJA_FOX_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = ninjaFoxRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the ninjaFox's rewards.
std::vector<std::string> InitEnemies::ninjaFoxRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 30)
        rewards.push_back("Tiny Eye");

    if(randomNum < 15)
        rewards.push_back("Bloodshot Eye");

    return rewards;
}

//Initialize to a redReaper.
void InitEnemies::redReaper(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("redReaper");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = RED_REAPER_BASE_HP + (level * 5);
    int mp = RED_REAPER_BASE_MP + (level * 2);
    int atk = RED_REAPER_BASE_ATK + (level * 5);
    int def = RED_REAPER_BASE_DEF + (level * 1);
    float spd = RED_REAPER_BASE_SPEED - (level * 0.1);
    int rewardXP = RED_REAPER_BASE_REWARD_XP + (level * 5);
    int moneyReward = RED_REAPER_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = redReaperRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the redReaper's rewards.
std::vector<std::string> InitEnemies::redReaperRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 5)
        rewards.push_back("Scythe");

    return rewards;
}