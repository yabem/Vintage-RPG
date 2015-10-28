#include "SouthernForest.h"

//Constructor.
SouthernForest::SouthernForest(ImageStore *imageStore ,  DrawRepository *drawRepository ,
        GameManager *gameManager , BattleManager *battleManager , FontStore *fontStore ,
        int layoutSize) : CustomAreaMap(imageStore , drawRepository , gameManager , 
        battleManager , fontStore , layoutSize){

            mapMusic = "Arcadia";
}

//Destructor.
SouthernForest::~SouthernForest(){
}

//Loads the enemies and level ranges for the map.
void SouthernForest::loadMapEnemies(){

    //Easy
    this->listOfEnemies.push_back(WERERAT);
    this->listOfEnemies.push_back(BABY_BLOB);

    //Medium
    this->listOfEnemies.push_back(GOO_CUBE);
    this->listOfEnemies.push_back(MUSHROOM_MAN);

    //Hard
    this->listOfEnemies.push_back(WOLF);

    this->loadEnemyLevelRange(1 , 3);
}

//Loads all the cloud Scenery objects.
void SouthernForest::loadTheSceneries(){

    FilterImage *fog = new FilterImage(imageStore->getBitMap("fog") , 0 , 0 , 0 , 0);
    PulsingImage *fogInner = new PulsingImage(imageStore->getBitMap("fogInner") , 0 , 0 , 0 , 0);

    fogInner->setMinTransparency(.35);
    fogInner->setMaxTransparency(.65);
    fogInner->setTransparencyIncrementer(.0025);

    this->loadScenery(fog);
    this->loadScenery(fogInner);
}

//Load the interactive models.
void SouthernForest::loadTheTangibles(){

    //Blob King quest.
    std::string identifierName = "Blob King"; //Used when deleting the Tangible once the fight is over.

    NPCWithDialogueThenBattle *blobKing = new NPCWithDialogueThenBattle(imageStore->getBitMap("Blob King") ,
        Conversion::convertTilesToPixels(25) , 
        Conversion::convertTilesToPixels(39) ,        
        this->drawRepository ,
        this->gameManager , "Shmodor... shMOdor... SHMODOR!" ,
        this->battleManager ,
        this->fontStore->getFont("default") ,
        identifierName); 

    blobKing->createCharacter(160 , 80 , 60 , 1 , 4 , this);
    blobKing->setIdentifierName(identifierName);
    blobKing->setMusic("Split In Synapse");

    std::vector<int> enemies;
    enemies.push_back(WERERAT);
    enemies.push_back(BLOB_KING);
    enemies.push_back(WERERAT);

    std::vector<int> enemyLevels;
    enemyLevels.push_back(3);
    enemyLevels.push_back(3);
    enemyLevels.push_back(3);

    blobKing->loadEnemies(enemies , enemyLevels);

    //Horned Warrior quest.
    NPCWithDialogueAndQuest *forester = new NPCWithDialogueAndQuest(
        imageStore->getBitMap("npcHornedWarrior") ,
        Conversion::convertTilesToPixels(22) , 
        Conversion::convertTilesToPixels(3) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity()
        );
    forester->createCharacter(32 , 32 , 60 , 2 , 4 , this);
    forester->setCW(32);
    forester->setCH(32);
    forester->setCharacterFacing(DOWN);
    forester->setQuestExplanation(
        "Forester: I've been collecting wood in this forest for years. "  
        "Recently there's been an influx of evil creatures. Please, " 
        "help me clear the forest so I can get wood... Why are you " 
        "looking at me like I said something suggestive?");
    forester->setQuestReminder(
        "Forester: I'm still encounter evil every day, please hurry!");
    forester->setQuestCompleteMessage(
        "Forester: Great, you did it! Take this as a token of my appreciation.");
    forester->setRewardNotification(
        "Mage learned the Fireball ability!");
    forester->setGift("mage" , "Fireball");
    forester->setQuestAfterCompleteMessage(
        "Forester: The forest is much safer now, thanks!"
        );

    KillQuest *killTask = new KillQuest();
    killTask->setQuestDisplayName("Help Clear the Forest");
    killTask->addObjective("Wererat" , 2);
    killTask->addObjective("Wolf" , 2);
    killTask->addObjective("Mushroom Man" , 2);
    killTask->setMustBeActiveForPlayerToUpdate();
    forester->loadQuest(killTask);
    gameManager->getPlayerEntity()->addQuest("clearTheForest" , killTask);

    //Barrold quest
    NPCWithDialogueAndQuest *barroldTheQuestGiver = new NPCWithDialogueAndQuest(
        imageStore->getBitMap("npcPurpleMonk") ,
        Conversion::convertTilesToPixels(45) , 
        Conversion::convertTilesToPixels(23) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity()
        );
    barroldTheQuestGiver->createCharacter(32 , 32 , 60 , 2 , 4 , this);
    barroldTheQuestGiver->setCW(32);
    barroldTheQuestGiver->setCH(32);
    barroldTheQuestGiver->setCharacterFacing(DOWN);
    barroldTheQuestGiver->setQuestExplanation(
        "Barrold: There's a huge blob down south. Help kill it because "  
        "it's killing everything in the forest! The good creatures, the bad "
        "creatures, and even the ugly creatures!");
    barroldTheQuestGiver->setQuestReminder(
        "Barrold: Ahhhh! Hurry!!!");
    barroldTheQuestGiver->setQuestCompleteMessage(
        "Barrold: I could have done it myself, but here's a reward.");
    barroldTheQuestGiver->setRewardNotification(
        "Thief learned the Backstab ability!");
    barroldTheQuestGiver->setGift("thief" , "Backstab");
    barroldTheQuestGiver->setQuestAfterCompleteMessage(
        "Barrold: Well, back to standing here alone in the forest."
        );
    KillQuest *killBlobKing = new KillQuest();
    killBlobKing->setQuestDisplayName("One Eyed Monster");
    killBlobKing->addObjective("Blob King" , 1);
    barroldTheQuestGiver->loadQuest(killBlobKing);
    gameManager->getPlayerEntity()->addQuest("blobKingQuest" , killBlobKing);

    //Red pepper quest
    NPCWithDialogueAndQuest *spicyRedPeppers = new NPCWithDialogueAndQuest(
        imageStore->getBitMap("sceneryRedPeppers") ,
        Conversion::convertTilesToPixels(6) , 
        Conversion::convertTilesToPixels(41) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity()
        );
    spicyRedPeppers->createCharacter(32 , 32 , 1 , 1 , 1 , this);
    spicyRedPeppers->setCW(32);
    spicyRedPeppers->setCH(32);
    spicyRedPeppers->setCharacterFacing(UP);
    spicyRedPeppers->setQuestExplanation(
        "Doctor Peppers: Whaddup. I'm the team doctor and official mascot for the Red "  
        "Pepper Lancers Polearm Spinning group. I'm so close to finishing an all natural, "
        "gluten free, soy, vegan, egg free, nut free, soy based, energy drink. I'm missing "
        "one ingredient. If you get it for me, I'll show you the Red Pepper Lancers' newest "
        "dance moves.");
    spicyRedPeppers->setQuestReminder(
        "Doctor Peppers: Chika chika meow meow.");
    spicyRedPeppers->setQuestCompleteMessage(
        "Doctor Peppers: Wooooooooot! You did it! Here you go. Now your Lancer can cut loose "
        "red pepper style.");
    spicyRedPeppers->setRewardNotification(
        "Lancer learned Fury of the Fang!");
    spicyRedPeppers->setGift("lancer" , "Fury of the Fang");
    spicyRedPeppers->setQuestAfterCompleteMessage(
        "Doctor Peppers: How are the dance moves? Great, I'm sure!"
        );

    GatherQuest *peppersQuestObjectives = new GatherQuest(
        gameManager->getPlayerEntity()->getPlayerInventory());
    peppersQuestObjectives->setQuestDisplayName("Doctor Peppers' Crew");
    peppersQuestObjectives->addObjective("Old Man Spices" , 1);
    spicyRedPeppers->loadQuest(peppersQuestObjectives);
    gameManager->getPlayerEntity()->addQuest("doctorPeppersCrew" , peppersQuestObjectives);

    this->loadTangible(spicyRedPeppers);

    this->loadTangible(barroldTheQuestGiver);
    this->loadTangible(blobKing);
    this->loadTangible(forester);
}

//Loads all the layers to the areaMap.
void SouthernForest::loadLayers(){

    Layer *backgroundLayer = new Layer(imageStore->getBitMap("snowTerrain") ,
        50 , 50 , this->backgroundLayerLayout , 2500);
    Layer *collisionLayer = new Layer(imageStore->getBitMap("southernForest") ,
        50 , 50 , this->collisionLayerLayout , 2500);
    Layer *canGoBehindLayer = new Layer(imageStore->getBitMap("southernForest") ,
        50 , 50 , this->canGoBehindLayerLayout , 2500);
   
    this->loadLayer(backgroundLayer);
    this->loadLayer(collisionLayer);
    this->loadLayer(canGoBehindLayer);
}

void SouthernForest::loadBackgroundLayerMapConfiguration(){

    int backgroundLayerLayout[] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 2, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1,
        1, 1, 2, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1,
        1, 1, 3, 5, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1,
        1, 1, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 3, 3, 3, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 4, 4, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 4, 4, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 3, 3, 3, 5, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 5, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 6, 3, 3, 3, 3, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 6, 3, 3, 3, 3, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 4, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 4, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1,
        1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 2, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1,
        1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 3, 5, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
        1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3,
        5, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1,
        1, 1, 3, 3, 3, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3,
        3, 3, 3, 3, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 4, 4, 1, 4, 4, 1, 1, 1, 1, 1, 1, 3,
        3, 3, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7, 1, 1,
        1, 1, 3, 3, 3, 5, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3,
        3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 4, 4, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 6, 3, 3, 3, 3, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3,
        3, 3, 5, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7, 4, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 4, 1, 1, 6,
        3, 3, 3, 3, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 4, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 4, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    }; 

    this->backgroundLayerLayout = new int[this->layoutSize];
    for(int i = 0 ; i < this->layoutSize ; i++)    
        this->backgroundLayerLayout[i] = backgroundLayerLayout[i];
}

void SouthernForest::loadCollisionLayerMapConfiguration(){

    int collisionLayerLayout[] ={
        99,100,101,99,100,101,99,100,101,99,100,101,99,100,101, 0, 0, 0, 0, 0,99,
        100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,
        99,100,101,99,100,101,99,100,101,
        102,103,104,102,103,104,102,103,104,102,103,104,102,103,104, 0, 0, 0, 0, 0,
        102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,
        103,104,102,103,104,102,103,104,102,103,104,
        105,106,107,105,106,107,105,106,107,105,106,107,105,106,107, 0, 0, 0, 0, 0,
        105,106,107,105,106,107,105,106,107,105,106,107,105,106,107,105,106,107,105,
        106,107,105,106,107,105,106,107,105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,
        101,
        102,103,104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,102,
        103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,108,109, 0, 0, 0, 0, 0,108,109,
        105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,105,106,107, 0, 0, 0, 0, 0, 0,108,109,110,111,112,31,
        34,99,100,101,
        102,103,104, 0, 0, 0, 0, 0,105,106,107,113,114,115, 0, 0, 0, 0, 0,105,106,
        107, 0, 0, 0,105,106,107, 0, 0, 0,99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0,116,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,99,100,101,
        105,106,107,99,100,101,105,106,107,102,103,104, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0,105,106,107,
        99,100,101, 0, 0,105,106,107, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,102,103,104,
        99,100,101,102,103,104,99,100,101,105,106,107, 0, 0, 0, 0, 0, 0, 0,108,109,
        108,109, 0, 0,99,100,101,
        102,103,104, 0, 0, 0, 0, 0,105,106,107,105,106,107, 0, 0,102,103,104,105,
        106,107,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,108,109,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,99,100,101,
        105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0, 0, 0,
        0, 0, 0, 0, 0,105,106,107,
        99,100,101, 0, 0,105,106,107, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,102,103,104,
        99,100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0, 0, 0,
        0, 0, 0, 0, 0,99,100,101,
        102,103,104, 0, 0, 0, 0, 0,105,106,107,105,106,107, 0, 0,102,103,104,105,
        106,107,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101, 0, 0,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,99,100,101,
        105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0, 0, 0,
        102,103,104, 0, 0,105,106,107,
        99,100,101, 0, 0,105,106,107, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,102,103,104,
        99,100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0, 0, 0,
        105,106,107, 0, 0,99,100,101,
        102,103,104, 0, 0, 0, 0, 0,113,114,115,105,106,107, 0, 0,102,103,104,102,
        103,104,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101, 0, 0,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,105,106,107,
        105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0, 0, 0,
        102,103,104, 0, 0,105,106,107,
        99,100,101, 0, 0,105,106,107, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,99,100,101,
        99,100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0, 0, 0,
        105,106,107, 0, 0,99,100,101,
        102,103,104, 0, 0, 0, 0, 0,105,106,107,113,114,115, 0, 0,102,103,104,102,
        103,104,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101, 0, 0,102,103,104,
        105,106,107, 0, 0,117,118,118,118,118,118,118,118,119, 0, 0,105,106,107,105,
        106,107,105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0,
        0, 0,102,103,104, 0, 0,105,106,107,
        99,100,101, 0, 0,120,121,121,121,121,121,121,121,122, 0, 0,99,100,101,99,
        100,101,99,100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0,
        0, 0,105,106,107, 0, 0,99,100,101,
        102,103,104, 0, 0,123,124,124,124,124,124,124,124,125, 0, 0,102,103,104,102,
        103,104,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101, 0, 0,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,105,106,107,
        105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0, 0, 0,
        102,103,104, 0, 0,105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,99,100,101,99,
        100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0, 0, 0,105,
        106,107, 0, 0,99,100,101,
        102,103,104, 0, 0,105,106,107,105,106,107,105,106,107, 0, 0,102,103,104,102,
        103,104,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101, 0, 0,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,105,106,107,
        105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0, 0, 0,
        102,103,104,108,109,105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,99,
        100,101,102,103,104, 0, 0, 0,105,106,107, 0, 0,102,103,104, 0, 0, 0,105,106,
        107,126,127,99,100,101,
        102,103,104, 0, 0,105,106,107,105,106,107,105,106,107, 0, 0, 0, 0, 0,102,
        103,104,102,103,104,105,106,107, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,105,106,
        107, 0,128,128,129,130,102,103,104,
        105,106,107, 0, 0,117,118,118,118,118,118,118,118,118,118,118,118,118,119,
        105,106,107,105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0,128,128,108,109,105,106,107,
        99,100,101, 0, 0,120,121,121,121,121,121,121,121,121,121,121,121,121,122,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0,99,100,101,99,100,101,
        102,103,104, 0, 0,123,124,124,124,124,124,124,124,124,124,124,124,124,125,
        102,103,104, 0, 0, 0, 0, 0, 0, 0,108,109, 0, 0,108,109, 0, 0,108,109, 0, 0,
        108,109, 0,102,103,104,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,
        105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,
        99,100,101,
        102,103,104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,102,103,104,
        105,106,107, 0, 0, 0, 0,108,109, 0, 0,108,109, 0, 0,108,109, 0, 0,108,109,
        0,102,103,104,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,
        105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,
        99,100,101,
        102,103,104, 0, 0, 0, 0, 0, 0,117,118,118,118,118,118,118,119, 0, 0,102,103,
        104,105,106,107, 0, 0, 0, 0,108,109, 0, 0,108,109, 0, 0,108,109, 0, 0,108,
        109, 0,102,103,104,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0,120,121,121,121,121,121,121,122, 0, 0,105,106,
        107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,
        106,107,105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0,123,124,124,124,124,124,124,125, 0, 0,99,100,
        101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,
        100,101,99,100,101,
        102,103,104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,102,103,104,105,
        106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,102,103,
        104,102,103,104,
        105,106,107,110,111,112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,131, 0, 0, 0, 0,105,106,
        107,105,106,107,
        99,100,101,117,118,119,34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107, 0, 0, 0,132,128, 0, 0, 0,99,
        100,101,99,100,101,
        102,103,104,120,121,122,35,32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,34,128,128,110,111,112,
        102,103,104,102,103,104,
        105,106,107,123,124,125,35,34,35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,
        133,35,133, 0, 0, 0, 0, 0,105,106,107, 0, 0, 0, 0, 0,128,128,128,134,135,
        136,105,106,107,105,106,107,
        99,100,101,117,118,119,117,118,119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,
        99,100,101,105,106,107, 0, 0,99,100,101,105,106,107, 0, 0,128,128,128,137,
        138,139,99,100,101,99,100,101,
        102,103,104,120,121,122,120,121,122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,102,103,
        104,102,103,104,35,35,35,35,35,102,103,104,140,141,51, 0, 0,128,128,128,142,
        143,144,102,103,104,102,103,104,
        105,106,107,123,124,125,123,124,125,110,111,112,110,111,112,110,111,112, 0,
        105,106,107,105,106,107,35,35,35,35,35,105,106,107,140,145,53, 0, 0,128,128,
        128,110,111,112,105,106,107,105,106,107,
        99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,
        101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,
        100,101,99,100,101,99,100,101,99,100,
        102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,
        103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,103,
        104,102,103,104,102,103,104,102,103,104,102,103
    };

    this->collisionLayerLayout = new int[this->layoutSize];
    for(int i = 0 ; i < this->layoutSize ; i++)    
        this->collisionLayerLayout[i] = collisionLayerLayout[i];
}

void SouthernForest::loadCanGoBehindLayerMapConfiguration(){

    int canGoBehindLayerLayout[] ={
        99,100,101,99,100,101,99,100,101,99,100,101,99,100,101, 0, 0, 0, 0, 0,99,
        100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,
        99,100,101,99,100,101,99,100,101,
        102,103,104,102,103,104,102,103,104,102,103,104,102,103,104, 0, 0, 0, 0, 0,
        102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,
        103,104,102,103,104,102,103,104,102,103,104,
        105,106,107,105,106,107,105,106,107,105,106,107,105,106,107, 0, 0, 0, 0, 0,
        105,106,107,105,106,107,105,106,107,105,106,107,105,106,107,105,106,107,105,
        106,107,105,106,107,105,106,107,105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,126,127, 0, 0,134,135,136,126,127,
        99,100,101,
        102,103,104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,99,100,101, 0, 0, 0, 0,129,130,126,127,137,138,139,129,
        130,102,103,104,
        105,106,107, 0, 0, 0, 0, 0,99,100,101,146,147,148, 0, 0, 0, 0, 0,99,100,101,
        0, 0, 0,99,100,101, 0, 0, 0,102,103,104, 0, 0, 0, 0,108,109,129,130,142,
        143,144,108,109,105,106,107,
        99,100,101, 0, 0, 0, 0, 0,102,103,104,149,150,151, 0, 0,99,100,101,102,103,
        104,99,100,101,102,103,104,99,100,101,105,106,107, 0, 0, 0, 0, 0, 0,108,109,
        110,111,112,31,34,99,100,101,
        102,103,104, 0, 0,99,100,101,105,106,107,113,114,115, 0, 0,102,103,104,105,
        106,107,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0, 0, 0, 0, 0,
        0,126,127,126,127, 0,116,102,103,104,
        105,106,107, 0, 0,102,103,104,99,100,101,99,100,101, 0, 0,105,106,107,99,
        100,101,105,106,107,99,100,101,105,106,107,102,103,104, 0, 0, 0, 0, 0, 0,
        0,129,130,129,130,126,127,105,106,107,
        99,100,101, 0, 0,105,106,107,102,103,104,102,103,104, 0, 0,99,100,101,102,
        103,104,99,100,101,102,103,104,99,100,101,105,106,107, 0, 0, 0, 0, 0, 0, 0,
        108,109,108,109,129,130,99,100,101,
        102,103,104, 0, 0,99,100,101,105,106,107,105,106,107, 0, 0,102,103,104,105,
        106,107,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,108,109,102,103,104,
        105,106,107, 0, 0,102,103,104,99,100,101,99,100,101, 0, 0,105,106,107,99,
        100,101,105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0,
        0, 0, 0, 0, 0, 0, 0,105,106,107,
        99,100,101, 0, 0,105,106,107,102,103,104,102,103,104, 0, 0,99,100,101,102,
        103,104,99,100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0,
        0, 0, 0, 0, 0, 0, 0,99,100,101,
        102,103,104, 0, 0,99,100,101,105,106,107,105,106,107, 0, 0,102,103,104,105,
        106,107,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101, 0, 0,102,103,104,
        105,106,107, 0, 0,102,103,104,146,147,148,99,100,101, 0, 0,105,106,107,99,
        100,101,105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0,
        0, 0,102,103,104, 0, 0,105,106,107,
        99,100,101, 0, 0,105,106,107,149,150,151,102,103,104, 0, 0,99,100,101,102,
        103,104,99,100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0,
        0, 0,105,106,107, 0, 0,99,100,101,
        102,103,104, 0, 0,99,100,101,113,114,115,105,106,107, 0, 0,102,103,104,102,
        103,104,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101, 0, 0,102,103,104,
        105,106,107, 0, 0,102,103,104,99,100,101,146,147,148, 0, 0,105,106,107,105,
        106,107,105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0,
        0, 0,102,103,104, 0, 0,105,106,107,
        99,100,101, 0, 0,105,106,107,102,103,104,149,150,151, 0, 0,99,100,101,99,
        100,101,99,100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0,
        0, 0,105,106,107, 0, 0,99,100,101,
        102,103,104, 0, 0, 0, 0, 0,105,106,107,113,114,115, 0, 0,102,103,104,102,
        103,104,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101, 0, 0,102,103,104,
        105,106,107, 0, 0,117,118,118,118,118,118,118,118,119, 0, 0,105,106,107,105,
        106,107,105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0,
        0, 0,102,103,104, 0, 0,105,106,107,
        99,100,101, 0, 0,120,121,121,121,121,121,121,121,122, 0, 0,99,100,101,99,
        100,101,99,100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0,
        0, 0,105,106,107, 0, 0,99,100,101,
        102,103,104, 0, 0,123,124,124,124,124,124,124,124,125, 0, 0,102,103,104,102,
        103,104,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101, 0, 0,102,103,104,
        105,106,107, 0, 0,99,100,101,99,100,101,99,100,101, 0, 0,105,106,107,105,
        106,107,105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101, 0,
        0, 0,102,103,104, 0, 0,105,106,107,
        99,100,101, 0, 0,102,103,104,102,103,104,102,103,104, 0, 0,99,100,101,99,
        100,101,99,100,101,102,103,104,99,100,101,105,106,107, 0, 0,102,103,104, 0,
        0, 0,105,106,107,126,127,99,100,101,
        102,103,104, 0, 0,105,106,107,105,106,107,105,106,107, 0, 0,102,103,104,102,
        103,104,102,103,104,105,106,107,102,103,104,99,100,101, 0, 0,105,106,107,
        0, 0, 0,99,100,101,129,130,102,103,104,
        105,106,107, 0, 0,99,100,101,99,100,101,99,100,101, 0, 0,105,106,107,105,
        106,107,105,106,107,99,100,101,105,106,107,102,103,104, 0, 0,99,100,101,99,
        100,101,102,103,104,108,109,105,106,107,
        99,100,101, 0, 0,102,103,104,102,103,104,102,103,104, 0, 0, 0, 0, 0,99,100,
        101,99,100,101,102,103,104, 0, 0, 0,105,106,107, 0, 0,102,103,104,102,103,
        104,105,106,107,126,127,99,100,101,
        102,103,104, 0, 0,105,106,107,105,106,107,105,106,107, 0, 0, 0, 0, 0,102,
        103,104,102,103,104,105,106,107, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,105,106,
        107, 0,128,128,129,130,102,103,104,
        105,106,107, 0, 0,117,118,118,118,118,118,118,118,118,118,118,118,118,119,
        105,106,107,105,106,107, 0, 0, 0, 0,126,127, 0, 0,126,127, 0, 0,126,127, 0,
        0,126,127,128,128,108,109,105,106,107,
        99,100,101, 0, 0,120,121,121,121,121,121,121,121,121,121,121,121,121,122,
        99,100,101, 0, 0, 0, 0, 0, 0, 0,129,130, 0, 0,129,130, 0, 0,129,130, 0, 0,
        129,130, 0,99,100,101,99,100,101,
        102,103,104, 0, 0,123,124,124,124,124,124,124,124,124,124,124,124,124,125,
        102,103,104, 0, 0, 0, 0, 0, 0, 0,108,109, 0, 0,108,109, 0, 0,108,109, 0, 0,
        108,109, 0,102,103,104,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,105,106,107,
        99,100,101, 0, 0, 0, 0,126,127, 0, 0,126,127, 0, 0,126,127, 0, 0,126,127,
        0,105,106,107,105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,102,103,104,99,100,101,
        102,103,104, 0, 0, 0, 0,129,130, 0, 0,129,130, 0, 0,129,130, 0, 0,129,130,
        0,99,100,101,99,100,101,
        102,103,104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,102,103,104,
        105,106,107, 0, 0, 0, 0,108,109, 0, 0,108,109, 0, 0,108,109, 0, 0,108,109,
        0,102,103,104,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,99,
        100,101, 0, 0, 0, 0,126,127, 0, 0,126,127, 0, 0,126,127, 0, 0,126,127, 0,
        105,106,107,105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,102,
        103,104, 0, 0, 0, 0,129,130, 0, 0,129,130, 0, 0,129,130, 0, 0,129,130, 0,
        99,100,101,99,100,101,
        102,103,104, 0, 0, 0, 0, 0, 0,117,118,118,118,118,118,118,119, 0, 0,102,103,
        104,105,106,107, 0, 0, 0, 0,108,109, 0, 0,108,109, 0, 0,108,109, 0, 0,108,
        109, 0,102,103,104,102,103,104,
        105,106,107,134,135,136, 0, 0, 0,120,121,121,121,121,121,121,122, 0, 0,105,
        106,107,99,100,101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0,105,106,107,105,106,107,
        99,100,101,137,138,139, 0, 0, 0,123,124,124,124,124,124,124,125, 0, 0,99,
        100,101,102,103,104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0,99,100,101,99,100,101,
        102,103,104,142,143,144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,102,103,104,
        105,106,107, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101, 0, 0, 0, 0, 0,134,135,136,
        102,103,104,102,103,104,
        105,106,107,110,111,112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,105,106,107,
        99,100,101, 0, 0, 0, 0, 0, 0, 0, 0,102,103,104, 0, 0, 0,131, 0,137,138,139,
        105,106,107,105,106,107,
        99,100,101,117,118,119,34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,99,100,101,
        102,103,104, 0, 0, 0, 0, 0,99,100,101,105,106,107, 0, 0, 0,132,128,142,143,
        144,99,100,101,99,100,101,
        102,103,104,120,121,122,35,32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,102,103,104,
        105,106,107,99,100,101, 0, 0,102,103,104,99,100,101, 0, 0,34,128,128,110,
        111,112,102,103,104,102,103,104,
        105,106,107,123,124,125,35,34,35,134,135,136,134,135,136,134,135,136, 0,105,
        106,107,133,35,133,102,103,104, 0, 0,105,106,107,102,103,104, 0, 0,128,128,
        128,134,135,136,105,106,107,105,106,107,
        99,100,101,117,118,119,117,118,119,137,138,139,137,138,139,137,138,139, 0,
        99,100,101,99,100,101,105,106,107, 0, 0,99,100,101,105,106,107, 0, 0,128,
        128,128,137,138,139,99,100,101,99,100,101,
        102,103,104,120,121,122,120,121,122,142,143,144,142,143,144,142,143,144, 0,
        102,103,104,102,103,104,35,35,35,35,35,102,103,104,140,141,51, 0, 0,128,128,
        128,142,143,144,102,103,104,102,103,104,
        105,106,107,123,124,125,123,124,125,110,111,112,110,111,112,110,111,112, 0,
        105,106,107,105,106,107,35,35,35,35,35,105,106,107,140,145,53, 0, 0,128,128,
        128,110,111,112,105,106,107,105,106,107,
        99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,
        101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,100,101,99,
        100,101,99,100,101,99,100,101,99,100,
        102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,
        103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,103,104,102,103,
        104,102,103,104,102,103,104,102,103,104,102,103
    };

    this->canGoBehindLayerLayout = new int[this->layoutSize];

    for(int i = 0 ; i < this->layoutSize ; i++)    
        this->canGoBehindLayerLayout[i] = canGoBehindLayerLayout[i];
}