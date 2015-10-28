#include "NorthernSnow.h"

//Constructor.
NorthernSnow::NorthernSnow(ImageStore *imageStore ,  DrawRepository *drawRepository ,
        GameManager *gameManager , BattleManager *battleManager , FontStore *fontStore ,
        int layoutSize) : CustomAreaMap(imageStore , drawRepository , gameManager , 
        battleManager , fontStore , layoutSize){

            mapMusic = "Dreamy Flashback";
}

//Destructor.
NorthernSnow::~NorthernSnow(){
}

//Loads the enemies and level ranges for the map.
void NorthernSnow::loadMapEnemies(){

    //Easy
    this->listOfEnemies.push_back(ICE_CUBE);
    this->listOfEnemies.push_back(WALRUS);
    
    //Medium
    this->listOfEnemies.push_back(CARROT_RAT);
    this->listOfEnemies.push_back(OLDMAN_AXE);
    
    //Hard
    this->listOfEnemies.push_back(RED_REAPER);

    this->loadEnemyLevelRange(5 , 7);
}

//Loads all the cloud Scenery objects.
void NorthernSnow::loadTheSceneries(){

    FallingImage *fallingSnow1 = new FallingImage
        (imageStore->getBitMap("snowFall") , 0 , -(SCREEN_H / 2) , 0 , 2);
    FallingImage *fallingSnow2 = new FallingImage
        (imageStore->getBitMap("snowFall2") , 0 , -(SCREEN_H / 2) , 0 , .7);
    FallingImage *fallingSnow3 = new FallingImage
        (imageStore->getBitMap("snowFall3") , 0 , -(SCREEN_H / 2) , 0 , .3);

    fallingSnow1->setDY(-240);
    fallingSnow2->setDY(-200);
    fallingSnow3->setDY(-160);

    this->loadScenery(fallingSnow3);
    this->loadScenery(fallingSnow2);
    this->loadScenery(fallingSnow1);
}

//Load the interactive models.
void NorthernSnow::loadTheTangibles(){

    //Ice Bull quest.
    std::string identifierName = "Ice Bull"; //Used when deleting the Tangible once the fight is over.

    NPCWithDialogueThenBattle *iceBull = new NPCWithDialogueThenBattle(imageStore->getBitMap("Ice Bull") ,
        Conversion::convertTilesToPixels(20) , 
        Conversion::convertTilesToPixels(20) ,        
        this->drawRepository ,
        this->gameManager , "Do you dare challenge the great Bull of the North?" ,
        this->battleManager ,
        this->fontStore->getFont("default") ,
        identifierName); 

    iceBull->createCharacter(130 , 78 , 60 , 1 , 4 , this);
    iceBull->setIdentifierName(identifierName);
    iceBull->setMusic("Split In Synapse");

    std::vector<int> enemies;
    enemies.push_back(CARROT_RAT);
    enemies.push_back(ICE_BULL);
    enemies.push_back(CARROT_RAT);

    std::vector<int> enemyLevels;
    enemyLevels.push_back(7);
    enemyLevels.push_back(7);
    enemyLevels.push_back(7);

    iceBull->loadEnemies(enemies , enemyLevels);

    //Red Vampire quest.
    NPCWithDialogueAndQuest *wanderer = new NPCWithDialogueAndQuest(
        imageStore->getBitMap("npcRedVampire") ,
        Conversion::convertTilesToPixels(39) , 
        Conversion::convertTilesToPixels(43) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity()
        );
    wanderer->createCharacter(32 , 32 , 60 , 2 , 4 , this);
    wanderer->setCW(32);
    wanderer->setCH(32);
    wanderer->setCharacterFacing(DOWN);
    wanderer->setQuestExplanation(
        "Wanderer: I'm visiting from a far off land. This place is so "  
        "dangerous. Please clear a way for me so I can get back home! ");
    wanderer->setQuestReminder(
        "Wanderer: I wander how long it's going to take you. A pun indeed.");
    wanderer->setQuestCompleteMessage(
        "Wanderer: I can make my way home now, thank you stranger.");
    wanderer->setRewardNotification(
        "Warrior received the Bandage ability!");
    wanderer->setGift("warrior" , "Bandage");
    wanderer->setQuestAfterCompleteMessage(
        "Wanderer: I can't wait to get home!"
        );

    KillQuest *killTask = new KillQuest();
    killTask->setQuestDisplayName("Cleanse the North");
    killTask->addObjective("Walrus" , 2);
    killTask->addObjective("Ice Cube" , 2);
    killTask->addObjective("Carrot Rat" , 1);
    killTask->setMustBeActiveForPlayerToUpdate();
    wanderer->loadQuest(killTask);
    gameManager->getPlayerEntity()->addQuest("cleanseTheNorth" , killTask);

    //Jon Winter quest
    NPCWithDialogueAndQuest *jonWinter = new NPCWithDialogueAndQuest(
        imageStore->getBitMap("npcBlondeWarrior") ,
        Conversion::convertTilesToPixels(42) , 
        Conversion::convertTilesToPixels(27) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity()
        );
    jonWinter->createCharacter(32 , 32 , 60 , 2 , 4 , this);
    jonWinter->setCW(32);
    jonWinter->setCH(32);
    jonWinter->setCharacterFacing(DOWN);
    jonWinter->setQuestExplanation(
        "Jon Winter: There's a huge bull to the west. I would help you take "
        "on the bull but I was recently betrayed and wounded by my brothers. " 
        "Please slay the beast whilst I recover.");
    jonWinter->setQuestReminder(
        "Jon Winter: How fares the hunt? ");
    jonWinter->setQuestCompleteMessage(
        "Jon Winter: You've exceeded my expectations. I owe you much gratitude. "
        "Here, take this as a reward.");
    jonWinter->setRewardNotification(
        "Mage learned the Chain Lightning ability!");
    jonWinter->setGift("mage" , "Chain Lightning");
    jonWinter->setQuestAfterCompleteMessage(
        "Jon Winter: Well done. May the Many bless you."
        );
    KillQuest *killIceBull= new KillQuest();
    killIceBull->setQuestDisplayName("The Bully of the North");
    killIceBull->addObjective("Ice Bull" , 1);
    jonWinter->loadQuest(killIceBull);
    gameManager->getPlayerEntity()->addQuest("iceBullQuest" , killIceBull);

    //Mushroom quest
    NPCWithDialogueAndQuest *magicMushroom = new NPCWithDialogueAndQuest(
        imageStore->getBitMap("scenerySpottedMushroom") ,
        Conversion::convertTilesToPixels(9) , 
        Conversion::convertTilesToPixels(31) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity()
        );
    magicMushroom->createCharacter(32 , 32 , 1 , 1 , 1 , this);
    magicMushroom->setCW(32);
    magicMushroom->setCH(32);
    magicMushroom->setCharacterFacing(UP);
    magicMushroom->setQuestExplanation(
        "Magic Mushroom: Hey... hey hey hey hey HEEEEEY! "  
        "Blob eyes blob eyes blob eyes blob eyes blob eyes blob eyes blob eyes.");
    magicMushroom->setQuestReminder(
        "Magic Mushroom: OooOOOOoooOOooOoOoOoooo blob eyes.");
    magicMushroom->setQuestCompleteMessage(
        "Mr. Mushboom: I can see and think again. Thank you. I was once a powerful "
        "giant until I started eating mushrooms. I guess one of them had a curse and turned "
        "me into a mushroom. I'm still a mushroom but at least I can think again. Take this "
        "ability, your warrior will find it very useful.");
    magicMushroom->setRewardNotification(
        "Warrior learned Earth Shatter!");
    magicMushroom->setGift("warrior" , "Earth Shatter");
    magicMushroom->setQuestAfterCompleteMessage(
        "Mr. Mushboom: What to do, what to do..."
        );

    GatherQuest *mushboomQuestObjectives = new GatherQuest(
        gameManager->getPlayerEntity()->getPlayerInventory());
    mushboomQuestObjectives->setQuestDisplayName("You Are What You Eat");
    mushboomQuestObjectives->addObjective("Blob Eye" , 1);
    magicMushroom->loadQuest(mushboomQuestObjectives);
    gameManager->getPlayerEntity()->addQuest("youAreWhatYouEat" , mushboomQuestObjectives);

    this->loadTangible(magicMushroom);
    this->loadTangible(jonWinter);
    this->loadTangible(wanderer);
    this->loadTangible(iceBull);
}

//Loads all the layers to the areaMap.
void NorthernSnow::loadLayers(){

    Layer *backgroundLayer = new Layer(imageStore->getBitMap("terrainForNorthernSnow") ,
        50 , 50 , this->backgroundLayerLayout , 2500);
    
    Layer *collisionLayer = new Layer(imageStore->getBitMap("northernSnow") ,
        50 , 50 , this->collisionLayerLayout , 2500);
    
    this->loadLayer(backgroundLayer);
    this->loadLayer(collisionLayer);
}

void NorthernSnow::loadBackgroundLayerMapConfiguration(){

    int backgroundLayerLayout[] = {
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,13,
        13,
        12,15,12,12,12,12,12,12,12,12,12,12,13,13,13,13,13,13,13,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,13,13,13,13,13,13,13,13,13,13,13,
        12,15,12,12,12,12,12,12,12,12,12,12,13,13,13,13,13,13,13,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,13,13,
        12,15,12,12,12,12,12,12,12,12,12,12,13,13,13,13,13,13,13,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,13,13,
        12,15,12,12,12,12,12,12,12,12,12,12,13,13,13,13,13,13,13,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,13,13,
        12,15,12,12,12,12,12,12,13,13,13,13,13,13,13,13,13,13,13,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,13,13,
        12,15,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,15,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,15,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,15,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,15,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,15,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,15,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,15,12,12,12,12,12,12,12,15,15,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,15,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,15,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,15,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,15,13,
        12,15,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,15,13,
        12,15,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,15,13,
        12,15,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,15,13,
        12,15,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,15,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,15,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,15,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,15,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,15,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,15,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,15,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,15,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,15,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,15,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,15,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,15,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,15,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,13,13,13,13,13,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,13,13,13,13,13,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,13,13,13,13,13,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,12,12,12,12,15,15,12,12,12,12,12,12,12,12,12,12,12,12,13,13,13,13,13,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,12,12,12,12,15,15,12,12,12,12,12,12,12,12,12,12,12,12,13,13,13,13,13,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,15,15,13,13,
        12,12,12,12,12,12,12,12,12,12,13,13,13,13,13,13,13,13,12,12,13,13,13,13,13,
        13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
        12,12,12,12,12,12,12,12,12,12,13,13,13,13,13,13,13,13,12,12,13,13,13,13,13,
        13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
        12,12,12,12,12,12,12,12,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
        13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,12,13,13,
        12,12,12,12,12,12,12,12,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
        13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
        12,12,12,12,12,12,12,12,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
        13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
        12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,13,13
    };

    this->backgroundLayerLayout = new int[this->layoutSize];

    for(int i = 0 ; i < this->layoutSize ; i++)    
        this->backgroundLayerLayout[i] = backgroundLayerLayout[i];
}

void NorthernSnow::loadCollisionLayerMapConfiguration(){

    int collisionLayerLayout[] ={
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 0, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
        1, 1, 2, 3, 0, 0, 6, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 9, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,10, 0,11,12,13,12, 0, 0, 1, 1,
        1, 1, 6, 7, 2, 3,14,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,16,16,16,16,16,16,
        16,16,16,16,16,16,16,16,16,16,16,16,17,17,16,10, 0,11,12,13,12, 0, 0, 1, 1,
        1, 1,14,15, 6, 7,18,19, 0,20,21,22,23, 0, 5, 0, 0, 8,16, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,16,10, 0,11,12,13,12, 0, 0, 1, 1,
        1, 1,18,19,14,15,24,25, 0,20,21,22,23, 0, 8, 9, 9, 9,16,10, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0,11,12,13,12, 0, 0, 1, 1,
        1, 1,24,25,18,19, 0, 0, 0,20,21,22,23, 0, 8,16,16,16,16,10, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0,11,12,13,12, 0, 0, 1, 1,
        1, 1, 0, 0,24,25, 0, 0, 0,20,21,22,23, 0, 8,16,16,16,16,10, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0,11,12,13,12, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 0, 0, 0,20,21,22,23, 0, 8,16, 9, 9, 9,10, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0,11,12,13,12, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 0, 0, 0,20,21,22,23, 0, 8,16,10, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 0, 0, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 0, 0, 0, 0, 1, 1,
        1, 1, 0, 0, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,16,10, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16, 9, 9, 9, 9, 9,10, 0, 0, 1, 1,
        1, 1, 0, 0, 8,16,16,16,16,16,16,16,16,16,16,16,10, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,16,16,16,16,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 8,16,16,16, 9, 9, 9, 9, 9, 9, 9, 9,10, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 9, 9, 9, 9, 9,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 8,16,16,16,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 8,16,16,16,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 8,16,16,16,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 8, 9, 9,16,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 8,16,16,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 8,16,17,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 8,16,17, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,10, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 8,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 9, 9, 9,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,16,10, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,16,16,16,10, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0,
        8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,10, 0, 0, 0, 8,26, 9, 9, 9,10, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0,
        8,16,16,16,16,16,16,16,16,16,16,10, 0, 0, 0, 8,16,10, 0, 0, 0, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0,
        8,16, 9, 9, 9, 9, 9, 9, 9, 9,16,10, 0, 0, 0, 8,16,10, 0, 0, 0, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,27,28,29, 0, 0, 0, 0, 0, 8,16,10, 0, 0,
        8,16,10, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 8,16,10, 0, 0,23, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,30,31,32, 0, 0, 0, 0, 0, 8,16, 9, 9, 9,
        9,16,10, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 8,16,10, 0, 0, 0, 0,33, 1, 1,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,34,35,36, 0, 0, 0, 0, 0, 8,16,16,16,16,
        16,16,10, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 8,16,10, 0, 0, 0,20,37, 1, 1,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 9, 9, 9, 9,
        9, 9,10, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 8,16,10, 0, 0, 0,20,37, 1, 1,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 8,16,10, 0,20, 0,37,37, 1, 1,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 8,16,10, 0, 0, 0, 0, 4, 1, 1,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,38,39,40,41, 0, 0, 0, 0, 0, 0,42, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 8,16,10, 0, 0, 0, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,43,44,45,46, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 8,16,10, 0, 0, 0, 8,16,10, 0, 0, 0, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 8, 9, 9, 9,17,10, 0, 0, 0, 8,17,10, 0, 0, 0, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0,33,33, 8,47,47,47,47,10, 0, 0, 0, 8,47,10, 0, 0,33, 0, 0, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,48,48, 0, 0, 0,48,48, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,48,48, 0, 0, 0,48,48, 1, 1, 1, 1, 1, 1, 1, 1
    };

    this->collisionLayerLayout = new int[this->layoutSize];
    for(int i = 0 ; i < this->layoutSize ; i++)    
        this->collisionLayerLayout[i] = collisionLayerLayout[i];
}