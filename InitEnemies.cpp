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

        case SPIDER:
            spider(character , enemyType , level , enemies);
            break;

        case SPIDER_EGG:
            spiderEgg(character , enemyType , level , enemies);
            break;

        case SPIDER_WEB:
            spiderWeb(character , enemyType , level , enemies);
            break;

        case TENTACLE_MAGE:
            spiderWeb(character , enemyType , level , enemies);
            break;

        case ECHIDNA:
            spiderWeb(character , enemyType , level , enemies);
            break;

        case UMGAR_THE_WORLD_DESTROYER:
            umgarTheWorldDestroyer(character , enemyType , level , enemies);
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
    character->setIdentifierName("Rat");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = RAT_BASE_HP + (level * HP_MOD_FOR_EASY_ENEMIES);
    int mp = RAT_BASE_MP + (level * 2);
    int atk = RAT_BASE_ATK + (level * ATK_MOD_FOR_EASY_ENEMIES);
    int def = RAT_BASE_DEF + (level * DEF_MOD_FOR_EASY_ENEMIES);
    float spd = RAT_BASE_SPEED - (level * SPD_MOD_FOR_EASY_ENEMIES);
    int rewardXP = RAT_BASE_REWARD_XP;
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
    character->setIdentifierName("Wolf");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = WOLF_BASE_HP + (level * HP_MOD_FOR_HARD_ENEMIES);
    int mp = WOLF_BASE_MP + (level * 4);
    int atk = WOLF_BASE_ATK + (level * ATK_MOD_FOR_HARD_ENEMIES);
    int def = WOLF_BASE_DEF + (level * DEF_MOD_FOR_HARD_ENEMIES);
    float spd = WOLF_BASE_SPEED - (level * SPD_MOD_FOR_HARD_ENEMIES);
    int rewardXP = WOLF_BASE_REWARD_XP;
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
    character->setIdentifierName("Soldier");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = SOLDIER_BASE_HP + (level * HP_MOD_FOR_EASY_ENEMIES);
    int mp = SOLDIER_BASE_MP + (level * 3);
    int atk = SOLDIER_BASE_ATK + (level * ATK_MOD_FOR_EASY_ENEMIES);
    int def = SOLDIER_BASE_DEF + (level * DEF_MOD_FOR_EASY_ENEMIES);
    float spd = SOLDIER_BASE_SPEED - (level * SPD_MOD_FOR_EASY_ENEMIES);
    int rewardXP = SOLDIER_BASE_REWARD_XP;
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

    if(randomNum < 20)
        rewards.push_back("Red Potion");

    if(randomNum < 20)
        rewards.push_back("Green Potion");

    if(randomNum < 20)
        rewards.push_back("Blue Potion");

    return rewards;
}

//Initialize to an ice bull.
void InitEnemies::iceBull(Character *character , int enemyType ,
    int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("Ice Bull");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = ICE_BULL_BASE_HP + (level * HP_MOD_FOR_HARD_ENEMIES);
    int mp = ICE_BULL_BASE_MP + (level * 3);
    int atk = ICE_BULL_BASE_ATK + (level * ATK_MOD_FOR_HARD_ENEMIES);
    int def = ICE_BULL_BASE_DEF + (level * DEF_MOD_FOR_HARD_ENEMIES);
    float spd = ICE_BULL_BASE_SPEED - (level * SPD_MOD_FOR_HARD_ENEMIES);
    int rewardXP = ICE_BULL_BASE_REWARD_XP;
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
        rewards.push_back("Bull Horns");

    return rewards;
}

//Initialize to a blobKing.
void InitEnemies::blobKing(Character *character , int enemyType ,
    int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("Blob King");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = BLOB_KING_BASE_HP + (level * HP_MOD_FOR_HARD_ENEMIES);
    int mp = BLOB_KING_BASE_MP + (level * 3);
    int atk = BLOB_KING_BASE_ATK + (level * ATK_MOD_FOR_HARD_ENEMIES);
    int def = BLOB_KING_BASE_DEF + (level * DEF_MOD_FOR_HARD_ENEMIES);
    float spd = BLOB_KING_BASE_SPEED - (level * SPD_MOD_FOR_HARD_ENEMIES);
    int rewardXP = BLOB_KING_BASE_REWARD_XP;
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
        rewards.push_back("Crown");

    return rewards;
}

//Initialize to a guardian.
void InitEnemies::guardian(Character *character , int enemyType ,
    int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("Guardian");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = GUARDIAN_BASE_HP + (level * HP_MOD_FOR_HARD_ENEMIES);
    int mp = GUARDIAN_BASE_MP + (level * 3);
    int atk = GUARDIAN_BASE_ATK + (level * ATK_MOD_FOR_HARD_ENEMIES);
    int def = GUARDIAN_BASE_DEF + (level * DEF_MOD_FOR_HARD_ENEMIES);
    float spd = GUARDIAN_BASE_SPEED - (level * SPD_MOD_FOR_HARD_ENEMIES);
    int rewardXP = GUARDIAN_BASE_REWARD_XP;
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
        rewards.push_back("Dog Collar");

    return rewards;
}

//Initialize to a demon.
void InitEnemies::demon(Character *character , int enemyType ,
    int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("Demon");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = DEMON_BASE_HP + (level * HP_MOD_FOR_HARD_ENEMIES);
    int mp = DEMON_BASE_MP + (level * 3);
    int atk = DEMON_BASE_ATK + (level * ATK_MOD_FOR_HARD_ENEMIES);
    int def = DEMON_BASE_DEF + (level * DEF_MOD_FOR_HARD_ENEMIES);
    float spd = DEMON_BASE_SPEED - (level * SPD_MOD_FOR_HARD_ENEMIES);
    int rewardXP = DEMON_BASE_REWARD_XP;
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
        rewards.push_back("Dark Jewel");

    return rewards;
}

//Initialize to a carrotRat.
void InitEnemies::carrotRat(Character *character , int enemyType ,
    int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("Carrot Rat");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = CARROT_RAT_BASE_HP + (level * HP_MOD_FOR_MEDIUM_ENEMIES);
    int mp = CARROT_RAT_BASE_MP + (level * 3);
    int atk = CARROT_RAT_BASE_ATK + (level * ATK_MOD_FOR_MEDIUM_ENEMIES);
    int def = CARROT_RAT_BASE_DEF + (level * DEF_MOD_FOR_MEDIUM_ENEMIES);
    float spd = CARROT_RAT_BASE_SPEED - (level * SPD_MOD_FOR_MEDIUM_ENEMIES);
    int rewardXP = CARROT_RAT_BASE_REWARD_XP;
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

    if(randomNum < 10)
        rewards.push_back("Carrot");

    return rewards;
}

//Initialize to a walrus.
void InitEnemies::walrus(Character *character , int enemyType ,
    int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("Walrus");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = WALRUS_BASE_HP + (level * HP_MOD_FOR_EASY_ENEMIES);
    int mp = WALRUS_BASE_MP + (level * 3);
    int atk = WALRUS_BASE_ATK + (level * ATK_MOD_FOR_EASY_ENEMIES);
    int def = WALRUS_BASE_DEF + (level * DEF_MOD_FOR_EASY_ENEMIES);
    float spd = WALRUS_BASE_SPEED - (level * SPD_MOD_FOR_EASY_ENEMIES);
    int rewardXP = WALRUS_BASE_REWARD_XP;
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

    if(randomNum < 10)
        rewards.push_back("Whiskers");

    return rewards;
}

//Initialize to a gooCube.
void InitEnemies::gooCube(Character *character , int enemyType ,
    int level , vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("Goo Cube");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = GOO_CUBE_BASE_HP + (level * HP_MOD_FOR_MEDIUM_ENEMIES);
    int mp = GOO_CUBE_BASE_MP + (level * 3);
    int atk = GOO_CUBE_BASE_ATK + (level * ATK_MOD_FOR_MEDIUM_ENEMIES);
    int def = GOO_CUBE_BASE_DEF + (level * DEF_MOD_FOR_MEDIUM_ENEMIES);
    float spd = GOO_CUBE_BASE_SPEED - (level * SPD_MOD_FOR_MEDIUM_ENEMIES);
    int rewardXP = GOO_CUBE_BASE_REWARD_XP;
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
    character->setIdentifierName("Ice Cube");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = ICE_CUBE_BASE_HP + (level * HP_MOD_FOR_EASY_ENEMIES);
    int mp = ICE_CUBE_BASE_MP + (level * 3);
    int atk = ICE_CUBE_BASE_ATK + (level * ATK_MOD_FOR_EASY_ENEMIES);
    int def = ICE_CUBE_BASE_DEF + (level * DEF_MOD_FOR_EASY_ENEMIES);
    float spd = ICE_CUBE_BASE_SPEED - (level * SPD_MOD_FOR_EASY_ENEMIES);
    int rewardXP = ICE_CUBE_BASE_REWARD_XP;
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
    character->setIdentifierName("Fire Cube");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = FIRE_CUBE_BASE_HP + (level * HP_MOD_FOR_MEDIUM_ENEMIES);
    int mp = FIRE_CUBE_BASE_MP + (level * 3);
    int atk = FIRE_CUBE_BASE_ATK + (level * ATK_MOD_FOR_MEDIUM_ENEMIES);
    int def = FIRE_CUBE_BASE_DEF + (level * DEF_MOD_FOR_MEDIUM_ENEMIES);
    float spd = FIRE_CUBE_BASE_SPEED - (level * SPD_MOD_FOR_MEDIUM_ENEMIES);
    int rewardXP = FIRE_CUBE_BASE_REWARD_XP;
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
    character->setIdentifierName("Shield Skeleton");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = SHIELD_SKELETON_BASE_HP + (level * HP_MOD_FOR_HARD_ENEMIES);
    int mp = SHIELD_SKELETON_BASE_MP + (level * 2);
    int atk = SHIELD_SKELETON_BASE_ATK + (level * ATK_MOD_FOR_HARD_ENEMIES);
    int def = SHIELD_SKELETON_BASE_DEF + (level * DEF_MOD_FOR_HARD_ENEMIES);
    float spd = SHIELD_SKELETON_BASE_SPEED - (level * SPD_MOD_FOR_HARD_ENEMIES);
    int rewardXP = SHIELD_SKELETON_BASE_REWARD_XP;
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
    character->setIdentifierName("Wererat");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = WERERAT_BASE_HP + (level * HP_MOD_FOR_EASY_ENEMIES);
    int mp = WERERAT_BASE_MP + (level * 2);
    int atk = WERERAT_BASE_ATK + (level * ATK_MOD_FOR_EASY_ENEMIES);
    int def = WERERAT_BASE_DEF + (level * DEF_MOD_FOR_EASY_ENEMIES);
    float spd = WERERAT_BASE_SPEED - (level * 0.1);
    int rewardXP = WERERAT_BASE_REWARD_XP + (level * SPD_MOD_FOR_EASY_ENEMIES);
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
    character->setIdentifierName("Cactus");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = CACTUS_BASE_HP + (level * HP_MOD_FOR_EASY_ENEMIES);
    int mp = CACTUS_BASE_MP + (level * 2);
    int atk = CACTUS_BASE_ATK + (level * ATK_MOD_FOR_EASY_ENEMIES);
    int def = CACTUS_BASE_DEF + (level * DEF_MOD_FOR_EASY_ENEMIES);
    float spd = CACTUS_BASE_SPEED - (level * SPD_MOD_FOR_EASY_ENEMIES);
    int rewardXP = CACTUS_BASE_REWARD_XP;
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
    character->setIdentifierName("Oldman Axe");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = OLDMAN_AXE_BASE_HP + (level * HP_MOD_FOR_MEDIUM_ENEMIES);
    int mp = OLDMAN_AXE_BASE_MP + (level * 2);
    int atk = OLDMAN_AXE_BASE_ATK + (level * ATK_MOD_FOR_MEDIUM_ENEMIES);
    int def = OLDMAN_AXE_BASE_DEF + (level * DEF_MOD_FOR_MEDIUM_ENEMIES);
    float spd = OLDMAN_AXE_BASE_SPEED - (level * SPD_MOD_FOR_MEDIUM_ENEMIES);
    int rewardXP = OLDMAN_AXE_BASE_REWARD_XP;
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

    if(randomNum < 10)
        rewards.push_back("Old Man Spices");

    return rewards;
}

//Initialize to a mushroomMan.
void InitEnemies::mushroomMan(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("Mushroom Man");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = MUSHROOM_MAN_BASE_HP + (level * HP_MOD_FOR_MEDIUM_ENEMIES);
    int mp = MUSHROOM_MAN_BASE_MP + (level * 2);
    int atk = MUSHROOM_MAN_BASE_ATK + (level * ATK_MOD_FOR_MEDIUM_ENEMIES);
    int def = MUSHROOM_MAN_BASE_DEF + (level * DEF_MOD_FOR_MEDIUM_ENEMIES);
    float spd = MUSHROOM_MAN_BASE_SPEED - (level * SPD_MOD_FOR_MEDIUM_ENEMIES);
    int rewardXP = MUSHROOM_MAN_BASE_REWARD_XP;
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
    character->setIdentifierName("Zombie");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = ZOMBIE_BASE_HP + (level * HP_MOD_FOR_MEDIUM_ENEMIES);
    int mp = ZOMBIE_BASE_MP + (level * 2);
    int atk = ZOMBIE_BASE_ATK + (level * ATK_MOD_FOR_MEDIUM_ENEMIES);
    int def = ZOMBIE_BASE_DEF + (level * DEF_MOD_FOR_MEDIUM_ENEMIES);
    float spd = ZOMBIE_BASE_SPEED - (level * SPD_MOD_FOR_MEDIUM_ENEMIES);
    int rewardXP = ZOMBIE_BASE_REWARD_XP;
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
    character->setIdentifierName("Baby Blob");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = BABY_BLOB_BASE_HP + (level * HP_MOD_FOR_EASY_ENEMIES);
    int mp = BABY_BLOB_BASE_MP + (level * 2);
    int atk = BABY_BLOB_BASE_ATK + (level * ATK_MOD_FOR_EASY_ENEMIES);
    int def = BABY_BLOB_BASE_DEF + (level * DEF_MOD_FOR_EASY_ENEMIES);
    float spd = BABY_BLOB_BASE_SPEED - (level * SPD_MOD_FOR_EASY_ENEMIES);
    int rewardXP = BABY_BLOB_BASE_REWARD_XP;
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

    if(randomNum < 10)
        rewards.push_back("Blob Eye");

    return rewards;
}

//Initialize to a sheep.
void InitEnemies::sheep(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("Sheep");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = SHEEP_BASE_HP + (level * HP_MOD_FOR_HARD_ENEMIES);
    int mp = SHEEP_BASE_MP + (level * 2);
    int atk = SHEEP_BASE_ATK + (level * ATK_MOD_FOR_HARD_ENEMIES);
    int def = SHEEP_BASE_DEF + (level * DEF_MOD_FOR_HARD_ENEMIES);
    float spd = SHEEP_BASE_SPEED - (level * SPD_MOD_FOR_HARD_ENEMIES);
    int rewardXP = SHEEP_BASE_REWARD_XP;
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
    character->setIdentifierName("Kungfoo Dog");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = KUNGFOO_DOG_BASE_HP + (level * HP_MOD_FOR_EASY_ENEMIES);
    int mp = KUNGFOO_DOG_BASE_MP + (level * 2);
    int atk = KUNGFOO_DOG_BASE_ATK + (level * ATK_MOD_FOR_EASY_ENEMIES);
    int def = KUNGFOO_DOG_BASE_DEF + (level * DEF_MOD_FOR_EASY_ENEMIES);
    float spd = KUNGFOO_DOG_BASE_SPEED - (level * SPD_MOD_FOR_EASY_ENEMIES);
    int rewardXP = KUNGFOO_DOG_BASE_REWARD_XP;
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

    if(randomNum < 10)
        rewards.push_back("Kungfoo Belt");

    return rewards;
}

//Initialize to a fangedFox.
void InitEnemies::fangedFox(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("Fanged Fox");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = FANGED_FOX_BASE_HP + (level * HP_MOD_FOR_MEDIUM_ENEMIES);
    int mp = FANGED_FOX_BASE_MP + (level * 2);
    int atk = FANGED_FOX_BASE_ATK + (level * ATK_MOD_FOR_MEDIUM_ENEMIES);
    int def = FANGED_FOX_BASE_DEF + (level * DEF_MOD_FOR_MEDIUM_ENEMIES);
    float spd = FANGED_FOX_BASE_SPEED - (level * SPD_MOD_FOR_MEDIUM_ENEMIES);
    int rewardXP = FANGED_FOX_BASE_REWARD_XP;
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
    character->setIdentifierName("Ninja Fox");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = NINJA_FOX_BASE_HP + (level * HP_MOD_FOR_MEDIUM_ENEMIES);
    int mp = NINJA_FOX_BASE_MP + (level * 2);
    int atk = NINJA_FOX_BASE_ATK + (level * ATK_MOD_FOR_MEDIUM_ENEMIES);
    int def = NINJA_FOX_BASE_DEF + (level * DEF_MOD_FOR_MEDIUM_ENEMIES);
    float spd = NINJA_FOX_BASE_SPEED - (level * SPD_MOD_FOR_MEDIUM_ENEMIES);
    int rewardXP = NINJA_FOX_BASE_REWARD_XP;
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
    character->setIdentifierName("Red Reaper");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = RED_REAPER_BASE_HP + (level * HP_MOD_FOR_HARD_ENEMIES);
    int mp = RED_REAPER_BASE_MP + (level * 2);
    int atk = RED_REAPER_BASE_ATK + (level * ATK_MOD_FOR_HARD_ENEMIES);
    int def = RED_REAPER_BASE_DEF + (level * DEF_MOD_FOR_HARD_ENEMIES);
    float spd = RED_REAPER_BASE_SPEED - (level * SPD_MOD_FOR_HARD_ENEMIES);
    int rewardXP = RED_REAPER_BASE_REWARD_XP;
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

    if(randomNum < 10)
        rewards.push_back("Scythe");

    return rewards;
}

//Initialize to a spider.
void InitEnemies::spider(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("Spider");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = SPIDER_BASE_HP + (level * HP_MOD_FOR_EASY_ENEMIES);
    int mp = SPIDER_BASE_MP + (level * 2);
    int atk = SPIDER_BASE_ATK + (level * ATK_MOD_FOR_EASY_ENEMIES);
    int def = SPIDER_BASE_DEF + (level * DEF_MOD_FOR_EASY_ENEMIES);
    float spd = SPIDER_BASE_SPEED - (level * SPD_MOD_FOR_EASY_ENEMIES);
    int rewardXP = SPIDER_BASE_REWARD_XP;
    int moneyReward = SPIDER_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = spiderRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the spider's rewards.
std::vector<std::string> InitEnemies::spiderRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 10)
        rewards.push_back("Spider Leg");

    return rewards;
}

//Initialize to a spiderEgg.
void InitEnemies::spiderEgg(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("Spider Egg");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = SPIDER_EGG_BASE_HP + (level * HP_MOD_FOR_EASY_ENEMIES);
    int mp = SPIDER_EGG_BASE_MP + (level * 2);
    int atk = SPIDER_EGG_BASE_ATK + (level * ATK_MOD_FOR_EASY_ENEMIES);
    int def = SPIDER_EGG_BASE_DEF + (level * DEF_MOD_FOR_EASY_ENEMIES);
    float spd = SPIDER_EGG_BASE_SPEED - (level * SPD_MOD_FOR_EASY_ENEMIES);
    int rewardXP = SPIDER_EGG_BASE_REWARD_XP;
    int moneyReward = SPIDER_EGG_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = spiderEggRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the spiderEgg's rewards.
std::vector<std::string> InitEnemies::spiderEggRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 10)
        rewards.push_back("Spider Egg Spindle");

    return rewards;
}

//Initialize to a spiderWeb.
void InitEnemies::spiderWeb(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("Spider Web");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = SPIDER_WEB_BASE_HP + (level * HP_MOD_FOR_MEDIUM_ENEMIES);
    int mp = SPIDER_WEB_BASE_MP + (level * 2);
    int atk = SPIDER_WEB_BASE_ATK + (level * ATK_MOD_FOR_MEDIUM_ENEMIES);
    int def = SPIDER_WEB_BASE_DEF + (level * DEF_MOD_FOR_MEDIUM_ENEMIES);
    float spd = SPIDER_WEB_BASE_SPEED - (level * SPD_MOD_FOR_MEDIUM_ENEMIES);
    int rewardXP = SPIDER_WEB_BASE_REWARD_XP;
    int moneyReward = SPIDER_WEB_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = spiderWebRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the spiderWeb's rewards.
std::vector<std::string> InitEnemies::spiderWebRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 10)
        rewards.push_back("Spider Web Bits");

    return rewards;
}

//Initialize to a tentacleMage.
void InitEnemies::tentacleMage(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("Tentacle Mage");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = TENTACLE_MAGE_BASE_HP + (level * HP_MOD_FOR_HARD_ENEMIES);
    int mp = TENTACLE_MAGE_BASE_MP + (level * 2);
    int atk = TENTACLE_MAGE_BASE_ATK + (level * ATK_MOD_FOR_HARD_ENEMIES);
    int def = TENTACLE_MAGE_BASE_DEF + (level * DEF_MOD_FOR_HARD_ENEMIES);
    float spd = TENTACLE_MAGE_BASE_SPEED - (level * SPD_MOD_FOR_HARD_ENEMIES);
    int rewardXP = TENTACLE_MAGE_BASE_REWARD_XP;
    int moneyReward = TENTACLE_MAGE_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = tentacleMageRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the tentacleMage's rewards.
std::vector<std::string> InitEnemies::tentacleMageRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 10)
        rewards.push_back("Mages Warped Staff");

    return rewards;
}

//Initialize to a echidna.
void InitEnemies::echidna(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("Echidna");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = ECHIDNA_BASE_HP + (level * HP_MOD_FOR_MEDIUM_ENEMIES);
    int mp = ECHIDNA_BASE_MP + (level * 2);
    int atk = ECHIDNA_BASE_ATK + (level * ATK_MOD_FOR_MEDIUM_ENEMIES);
    int def = ECHIDNA_BASE_DEF + (level * DEF_MOD_FOR_MEDIUM_ENEMIES);
    float spd = ECHIDNA_BASE_SPEED - (level * SPD_MOD_FOR_MEDIUM_ENEMIES);
    int rewardXP = ECHIDNA_BASE_REWARD_XP;
    int moneyReward = ECHIDNA_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = echidnaRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the echidna's rewards.
std::vector<std::string> InitEnemies::echidnaRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 10)
        rewards.push_back("Echidna Tail");

    return rewards;
}

//Initialize to a umgarTheWorldDestroyer.
void InitEnemies::umgarTheWorldDestroyer(Character *character , int enemyType , int level ,
    vector<ALLEGRO_BITMAP*> enemies){

    character->setImage(enemies[enemyType]);
    character->setIdentifierName("Umgar The World Destroyer");

    //Base stats times level.
    character->setW(al_get_bitmap_width(enemies[enemyType]));
    character->setH(al_get_bitmap_height(enemies[enemyType])); 
    
    //Calculate stat values based off of level.
    int hp = UMGAR_THE_WORLD_DESTROYER_BASE_HP + (level * HP_MOD_FOR_HARD_ENEMIES);
    int mp = UMGAR_THE_WORLD_DESTROYER_BASE_MP + (level * 2);
    int atk = UMGAR_THE_WORLD_DESTROYER_BASE_ATK + (level * ATK_MOD_FOR_HARD_ENEMIES);
    int def = UMGAR_THE_WORLD_DESTROYER_BASE_DEF + (level * DEF_MOD_FOR_HARD_ENEMIES);
    float spd = UMGAR_THE_WORLD_DESTROYER_BASE_SPEED - (level * SPD_MOD_FOR_HARD_ENEMIES);
    int rewardXP = UMGAR_THE_WORLD_DESTROYER_BASE_REWARD_XP;
    int moneyReward = UMGAR_THE_WORLD_DESTROYER_BASE_MONEY_REWARD;
    std::vector<std::string> itemRewards = umgarTheWorldDestroyerRewards();

    CharStats *charStats = new CharStats(level , hp , mp , atk , 0 , def,
        0 , 0 , 0 , spd , rewardXP , moneyReward , itemRewards);

    character->setStats(charStats);
}

//Gets the umgarTheWorldDestroyer's rewards.
std::vector<std::string> InitEnemies::umgarTheWorldDestroyerRewards(){

    std::vector<std::string> rewards;
    int randomNum = rand() % 100;

    if(randomNum < 100)
        rewards.push_back("Badge of I Saved the World");

    return rewards;
}