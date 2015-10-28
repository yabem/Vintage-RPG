#include "InsideCastle.h"

//Constructor.
InsideCastle::InsideCastle(ImageStore *imageStore ,  DrawRepository *drawRepository ,
        GameManager *gameManager , BattleManager *battleManager , FontStore *fontStore ,
        int layoutSize) : CustomAreaMap(imageStore , drawRepository , gameManager , 
        battleManager , fontStore , layoutSize){

            mapMusic = "Mistake The Getaway";
}

//Destructor.
InsideCastle::~InsideCastle(){
}

//Loads the enemies and level ranges for the map.
void InsideCastle::loadMapEnemies(){

    //Easy
    this->listOfEnemies.push_back(SPIDER);
    this->listOfEnemies.push_back(SPIDER_EGG);

    //Medium
    this->listOfEnemies.push_back(SPIDER_WEB);
    this->listOfEnemies.push_back(ECHIDNA);

    //Hard
    this->listOfEnemies.push_back(TENTACLE_MAGE);

    this->loadEnemyLevelRange(9 , 11);
}

//Load the interactive models.
void InsideCastle::loadTheTangibles(){

    //Magical barrier
    std::string npcName = "fireWall";
    NPCWithQuestAndRemoval *magicalBarrier = new NPCWithQuestAndRemoval(
        imageStore->getBitMap("npcFirewall") ,
        Conversion::convertTilesToPixels(16) , 
        Conversion::convertTilesToPixels(5) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity(),
        npcName
        );
    magicalBarrier->createCharacter(304 , 190 , 60 , 2 , 4 , this);
    magicalBarrier->setIdentifierName(npcName);
    magicalBarrier->setCW(304);
    magicalBarrier->setCH(190);
    magicalBarrier->setCharacterFacing(UP);
    magicalBarrier->setQuestExplanation(
        "Magical Barrier: I am a magic firewall. I've been summoned from " 
        "my home by that huge guy right there. I'd gladly leave but I can't "
        "go back to my kids empty handed. They'll be super dissapointed. Get "
        "me a Dog Collar, a Crown, a Dark Jewel, and a fancy "
        "pair of Bull Horns and I'll gladly let you pass.");
    magicalBarrier->setQuestReminder(
        "Magical Barrier: She gives me money, when I'm in neeeeeeeeeeeed.... ");
    magicalBarrier->setQuestCompleteMessage(
        "Magical Barrier: Wow, the kids are going to LOVE this swag. Thanks dude!");
    magicalBarrier->setRewardNotification(
        "The barrier magically dissipates and the path forward is revealed!");

    GatherQuest *magicalBarrierObjectives = new GatherQuest(
        gameManager->getPlayerEntity()->getPlayerInventory());
    magicalBarrierObjectives->setQuestDisplayName("So this a Firewall?");
    magicalBarrierObjectives->addObjective("Dog Collar" , 1);
    magicalBarrierObjectives->addObjective("Crown" , 1);
    magicalBarrierObjectives->addObjective("Dark Jewel" , 1);
    magicalBarrierObjectives->addObjective("Bull Horns" , 1);
    magicalBarrier->loadQuest(magicalBarrierObjectives);
    gameManager->getPlayerEntity()->addQuest("soThisIsAFirewall?" , magicalBarrierObjectives);

    //Umgar quest.
    std::string identifierName = "Umgar The World Destroyer"; //Used when deleting the Tangible once the fight is over.

    NPCWithDialogueThenBattle *umgarTheWorldDestroyer = 
        new NPCWithDialogueThenBattle(imageStore->getBitMap("Umgar The World Destroyer") ,
        Conversion::convertTilesToPixels(17) , 
        Conversion::convertTilesToPixels(5) ,        
        this->drawRepository ,
        this->gameManager , "Umgar the World Destroyer: I foresaw this day was nigh and now "
        "you have come. I have been watching, waiting, and preparing to devour this world. "
        "I will end you, your village, and this entire world. Your meaningless existance is over. " 
        "I will grant you grant you a swift death before I plunge this world into the Permanent "
        "Void! Gahfaaafafafafafaaaa!" ,
        this->battleManager ,
        this->fontStore->getFont("default") ,
        identifierName); 

    umgarTheWorldDestroyer->createCharacter(240 , 160 , 60 , 1 , 4 , this);
    umgarTheWorldDestroyer->setIdentifierName(identifierName);
    umgarTheWorldDestroyer->setMusic("Alchemists Tower");

    std::vector<int> enemies;
    enemies.push_back(SPIDER);
    enemies.push_back(UMGAR_THE_WORLD_DESTROYER);
    enemies.push_back(SPIDER);

    std::vector<int> enemyLevels;
    enemyLevels.push_back(11);
    enemyLevels.push_back(11);
    enemyLevels.push_back(11);

    umgarTheWorldDestroyer->loadEnemies(enemies , enemyLevels);

    //KMAK the All-Powerful quest.
    NPCWithDialogueAndQuestWithItemReward *kMak = new NPCWithDialogueAndQuestWithItemReward(
        imageStore->getBitMap("npcBlackMage") ,
        Conversion::convertTilesToPixels(38) , 
        Conversion::convertTilesToPixels(31) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity()
        );
    kMak->createCharacter(32 , 32 , 60 , 2 , 4 , this);
    kMak->setCW(32);
    kMak->setCH(32);
    kMak->setCharacterFacing(DOWN);
    kMak->setQuestExplanation(
        "KMAK the All-Powerful: Well hello! I'm KMAK the All-Powerful! I'm also really "
        "REALLY, lazy and really, REALLY afraid of spiders! Can you please kill 5 spiders, "
        "3 spider eggs and 2 spiderwebs for me?");
    kMak->setQuestReminder(
        "KMAK the All-Powerful: Seriously... we're timing you on this you know...");
    kMak->setQuestCompleteMessage(
        "KMAK the All-Powerful: Way to go! Those eggs really put up a fight!");
    kMak->setRewardNotification(
        "You received a Spider-Slaying Stinger of Sensational Spider-Slaying!");
    kMak->setItemReward("Spider-Slaying Stinger of Sensational Spider-Slaying");
    kMak->setQuestAfterCompleteMessage(
        "KMAK the All-Powerful: Spiders... if they could talk I wonder what they would say... probably "
        "'please don’t kill me.' Oh well."
        );
    kMak->setAmountGained(1);

    KillQuest *killTask = new KillQuest();
    killTask->setQuestDisplayName("Spider Slaying 101");
    killTask->addObjective("Spider" , 2);
    killTask->addObjective("Spider Egg" , 2);
    killTask->addObjective("Spider Web" , 2);
    killTask->setMustBeActiveForPlayerToUpdate();
    kMak->loadQuest(killTask);
    gameManager->getPlayerEntity()->addQuest("spiderSlaying101" , killTask);

    NPCWithDialogue *queen = new NPCWithDialogue(
            imageStore->getBitMap("npcRedQueen") ,
            Conversion::convertTilesToPixels(19) , 
            Conversion::convertTilesToPixels(7) ,
            this->drawRepository ,
            this->gameManager , 
            "Queen of Stiltaviksenburgville: Thank you for saving the world. My reign can now continue "
            "and I will do everything in my power to fix the scourge that Umgar has left behind. "
            "Umgar has been a lingering presence for centuries and my family has battled him "
            "for a millenia. You have defeated him but he will appear again. For now we are safe "
            "and we can thank you for that. Please speak with my aid. She has a special message "
            "for you. Thank you again braver band of non-speaking warriors!" ,
            this->fontStore->getFont("default"));
        queen->createCharacter(32 , 32 , 90 , 2 , 4 , this);
        queen->setCW(32);
        queen->setCH(32);
        queen->setCharacterFacing(DOWN);

    NPCWithDialogue *gameEndingInformer = new NPCWithDialogue(
            imageStore->getBitMap("npcCloakedVoid") ,
            Conversion::convertTilesToPixels(20) , 
            Conversion::convertTilesToPixels(7) ,
            this->drawRepository ,
            this->gameManager , 
            "Game Creator: You did it! You completed the game. Thanks for playing. I hope you " 
            "enjoyed it. Feel free to continue to explore the world and finish any remaining quests. "
            "I guess you can call that a New Game+ but without the New Game..."
            "or the +... To end the game and see the final cutscene, go talk to that blue star." ,
            this->fontStore->getFont("default"));
        gameEndingInformer->createCharacter(32 , 32 , 90 , 2 , 4 , this);
        gameEndingInformer->setCW(32);
        gameEndingInformer->setCH(32);
        gameEndingInformer->setCharacterFacing(DOWN);

    NPCWithDialogue *escapedPrisoner = new NPCWithDialogue(
            imageStore->getBitMap("npcBlueWarrior") ,
            Conversion::convertTilesToPixels(6) , 
            Conversion::convertTilesToPixels(30) ,
            this->drawRepository ,
            this->gameManager , 
            "Escaped Prisoner: I don't remember what happened. I was farming in the south "
            "when all of a sudden the sky turned black. I saw a bright light and then my memory "
            "went blank. Then I woke up here. I'm going to escape quietly.",
            this->fontStore->getFont("default"));
        escapedPrisoner->createCharacter(32 , 32 , 90 , 2 , 4 , this);
        escapedPrisoner->setCW(32);
        escapedPrisoner->setCH(32);
        escapedPrisoner->setCharacterFacing(DOWN);

    NPCWithDialogueThenCutscene *endGameBlueStar = new NPCWithDialogueThenCutscene(
        imageStore->getBitMap("npcBlueStar") ,
        Conversion::convertTilesToPixels(9) , 
        Conversion::convertTilesToPixels(7) ,
        this->drawRepository ,
        this->gameManager , 
        "You jump into the portal and on to your next adventure!" ,
        this->fontStore->getFont("default"));
    endGameBlueStar->createCharacter(32 , 32 , 90 , 2 , 4 , this);
    endGameBlueStar->setCW(32);
    endGameBlueStar->setCH(32);
    endGameBlueStar->setCharacterFacing(0);

    //Baby Magical barrier
    std::string anotherNPCName = "fireWallBaby";
    NPCWithQuestAndRemoval *babyMagicalBarrier = new NPCWithQuestAndRemoval(
        imageStore->getBitMap("npcFirewallBaby") ,
        Conversion::convertTilesToPixels(9) , 
        Conversion::convertTilesToPixels(7) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity(),
        anotherNPCName
        );
    babyMagicalBarrier->createCharacter(64 , 64 , 60 , 2 , 4 , this);
    babyMagicalBarrier->setIdentifierName(anotherNPCName);
    babyMagicalBarrier->setCW(64);
    babyMagicalBarrier->setCH(64);
    babyMagicalBarrier->setCharacterFacing(UP);
    babyMagicalBarrier->setQuestExplanation(
        "Baby Magical Barrier: You will need proof that you saved the world " 
        "to pass this point.");
    babyMagicalBarrier->setQuestReminder(
        "Baby Magical Barrier: Yup, I'm still waiting. ");
    babyMagicalBarrier->setQuestCompleteMessage(
        "Baby Magical Barrier: Well, that will do it. Enter at your own risk!");
    babyMagicalBarrier->setRewardNotification(
        "The barrier magically dissipates the portal is revealed!");

    GatherQuest *babyMagicalBarrierObjectives = new GatherQuest(
        gameManager->getPlayerEntity()->getPlayerInventory());
    babyMagicalBarrierObjectives->setQuestDisplayName("Maybe We Do Need Those Stinkin' Badges");
    babyMagicalBarrierObjectives->addObjective("Badge of I Saved the World" , 1);
    babyMagicalBarrier->loadQuest(babyMagicalBarrierObjectives);
    gameManager->getPlayerEntity()->addQuest("maybeWeDoNeedThoseStinkin'Badges" , babyMagicalBarrierObjectives);

    this->loadTangible(magicalBarrier);  
    this->loadTangible(queen);
    this->loadTangible(gameEndingInformer);
    this->loadTangible(escapedPrisoner);
    this->loadTangible(kMak);
    this->loadTangible(umgarTheWorldDestroyer);
    this->loadTangible(endGameBlueStar); 
    this->loadTangible(babyMagicalBarrier);
}

//Loads all the layers to the areaMap.
void InsideCastle::loadLayers(){

    Layer *backgroundLayer = new Layer(imageStore->getBitMap("castle") ,
        40 , 40 , this->backgroundLayerLayout , 1600);
    Layer *collisionLayer = new Layer(imageStore->getBitMap("castle") ,
        40 , 40 , this->collisionLayerLayout , 1600);
    Layer *canGoBehindLayer = new Layer(imageStore->getBitMap("castle") ,
        40 , 40 , this->canGoBehindLayerLayout , 1600);
   
    this->loadLayer(backgroundLayer);
    this->loadLayer(collisionLayer);
    this->loadLayer(canGoBehindLayer);
}

void InsideCastle::loadBackgroundLayerMapConfiguration(){

    int backgroundLayerLayout[] = {
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,157,
        157,157
    }; 

    this->backgroundLayerLayout = new int[this->layoutSize];
    for(int i = 0 ; i < this->layoutSize ; i++)    
        this->backgroundLayerLayout[i] = backgroundLayerLayout[i];
}

void InsideCastle::loadCollisionLayerMapConfiguration(){

    int collisionLayerLayout[] ={
        115,116,116,116,116,116,116,116,117,117,117,117,117,117,117,117,117,117,
        117,117,117,117,117,117,117,117,117,117,117,117,117,117,118,116,116,116,116,
        116,116,119,
        115,116,116,116,116,116,116,116,117,117,117,117,117,117,117,117,117,117,117,
        117,117,117,117,117,117,117,117,117,117,117,117,117,118,116,116,116,116,116,
        116,119,
        115,116,116,116,116,116,116,116,120,120,120,120,120,120,120,120,120,120,120,
        120,120,120,120,120,120,120,120,120,120,120,120,120,118,116,116,116,116,116,
        116,119,
        115,116,116,116,116,116,116,116, 8, 8, 8,121,122,121,121,122,121,121, 0, 0,
        0, 0,122,121,122,121,122,122,121, 0,123,123,118,116,116,116,116,116,116,
        119,
        115,116,116,116,116,116,116,116,15,15,15, 0,122,121,121,121,122, 0,124,125,
        125,124, 0,121,121,121,121,121,19,20,126,126,118,116,116,116,116,116,116,
        119,
        115,116,116,116,116,116,116,116, 5, 6, 7, 8, 0,122,121,121,121, 0,127,125,
        125,127, 0,122,121,121,121, 0,25,26,128,128,118,116,116,116,116,116,116,119,
        115,116,116,116,116,116,116,116,13,14,14,15, 0,122,121,122,122, 0,129,130,
        131,129, 0,122,121,122,121, 0, 0, 0,132,133,118,116,116,116,116,116,116,119,
        115,116,116,116,116,116,116,116, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,134,118,116,116,116,116,116,116,119,
        115,116,116,116,116,116,116,116,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 6, 7,135,118,116,116,116,116,116,116,119,
        115,116,116,116,116,116,116,116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,14,14, 0,118,116,116,116,116,116,116,119,
        115,137,138,138,138,138,139,137, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,139,137,138,138,138,138,139,119,
        115,115,63,64,65,66,119,115, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,119,115,63,64,65,66,119,119,
        115,115,70,142,142,72,119,115, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,119,115,70,142,142,72,119,119,
        115,115,143,142,142,142,119,115,141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,141,119,115,143,142,142,142,119,119,
        115,144, 0, 0, 0, 0,145,144,146,141, 0, 0,141, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,141, 0, 0,141,146,145,144, 0, 0, 0, 0,145,119,
        115, 0, 0, 0, 0, 0, 0, 0, 0,146, 0, 0,146,76,77,76,77, 0, 0, 0, 0, 0, 0,76,
        77,76,77,146, 0, 0,146, 0, 0, 0, 0, 0, 0,19,20,119,
        115, 6, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,25,26,119,
        115,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,119,
        115,147,147,147,147,147,147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,147,147,147,147,147,147,119,
        115,116,116,116,116,116,116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,118,116,116,116,116,116,119,
        115,116,116,116,116,116,116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,118,116,116,116,116,116,119,
        115,116,116,116,116,116,116,141, 0, 0,141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,141, 0, 0,141,118,116,116,116,116,116,119,
        115,116,116,116,116,116,116,146, 0, 0,146,76,77, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,76,77,146, 0, 0,146,118,116,116,116,116,116,119,
        115,116,116,116,116,116,116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,118,116,116,116,116,116,119,
        115,116,116,116,116,116,116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,118,116,116,116,116,116,119,
        115,138,138,138,138,138,139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,138,138,138,138,138,139,119,
        115,115,148,148,148,148,119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,115,148,148,148,148,119,119,
        115,115,148,148,148,148,119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,115,148,148,148,148,119,119,
        115,144,149,149,149,149,145,141, 0, 0,141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,141, 0, 0,141,144,149,149,149,149,145,119,
        115,150,151, 0, 6, 7, 0,146,76,77,146,76,77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0,76,77,146,76,77,146, 0, 0, 0, 5, 6, 7,119,
        115,152,153, 0,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,13,14,14,119,
        115,152,153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,119,
        115,154,155, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,119,
        115,150,151, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,119,
        115,152,153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,119,
        115,152,153, 0, 0, 0, 0,141, 0, 0,141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,141, 0, 0,141, 0, 0, 0, 0,150,151,119,
        115,152,153, 0, 0,76,77,146,76,77,146,76,77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0,76,77,146,76,77,146,76,77, 0, 0,152,153,119,
        115,152,153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,152,153,119,
        115,154,155, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,154,155,119,
        156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,144, 0, 0, 0,
        0, 0, 0, 0,145,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,
        156
    };

    this->collisionLayerLayout = new int[this->layoutSize];
    for(int i = 0 ; i < this->layoutSize ; i++)    
        this->collisionLayerLayout[i] = collisionLayerLayout[i];
}

void InsideCastle::loadCanGoBehindLayerMapConfiguration(){

    int canGoBehindLayerLayout[] ={
        115,116,116,116,116,116,116,116,117,117,117,117,117,117,117,117,117,117,
        117,117,117,117,117,117,117,117,117,117,117,117,117,117,118,116,116,116,116,
        116,116,119,
        115,116,116,116,116,116,116,116,117,117,117,117,117,117,117,117,117,117,117,
        117,117,117,117,117,117,117,117,117,117,117,117,117,118,116,116,116,116,116,
        116,119,
        115,116,116,116,116,116,116,116,120,120,120,120,120,120,120,120,120,120,120,
        120,120,120,120,120,120,120,120,120,120,120,120,120,118,116,116,116,116,116,
        116,119,
        115,116,116,116,116,116,116,116, 8, 8, 8,121,122,121,121,122,121,121, 0, 0,
        0, 0,122,121,122,121,122,122,121, 0,123,123,118,116,116,116,116,116,116,
        119,
        115,116,116,116,116,116,116,116,15,15,15, 0,122,121,121,121,122, 0,124,125,
        125,124, 0,121,121,121,121,121,19,20,126,126,118,116,116,116,116,116,116,
        119,
        115,116,116,116,116,116,116,116, 5, 6, 7, 8, 0,122,121,121,121, 0,127,125,
        125,127, 0,122,121,121,121, 0,25,26,128,128,118,116,116,116,116,116,116,119,
        115,116,116,116,116,116,116,116,13,14,14,15, 0,122,121,122,122, 0,129,130,
        131,129, 0,122,121,122,121, 0, 0, 0,132,133,118,116,116,116,116,116,116,119,
        115,116,116,116,116,116,116,116, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,134,118,116,116,116,116,116,116,119,
        115,116,116,116,116,116,116,116,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 6, 7,135,118,116,116,116,116,116,116,119,
        115,116,116,116,116,116,116,116,136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,14,14,136,118,116,116,116,116,116,116,119,
        115,137,138,138,138,138,139,137,140,136, 0, 0,136, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,136, 0, 0,136,140,139,137,138,138,138,138,139,119,
        115,115,63,64,65,66,119,115,141,140, 0, 0,140, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,140, 0, 0,140,141,119,115,63,64,65,66,119,119,
        115,115,70,142,142,72,119,115,141,141, 0, 0,141, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,141, 0, 0,141,141,119,115,70,142,142,72,119,119,
        115,115,143,142,142,142,119,115,141,141, 0, 0,141,111,112,111,112, 0, 0, 0,
        0, 0, 0,111,112,111,112,141, 0, 0,141,141,119,115,143,142,142,142,119,119,
        115,144, 0, 0, 0, 0,145,144,146,141, 0, 0,141,113,114,113,114, 0, 0, 0, 0,
        0, 0,113,114,113,114,141, 0, 0,141,146,145,144, 0, 0, 0, 0,145,119,
        115, 0, 0, 0, 0, 0, 0, 0, 0,146, 0, 0,146,76,77,76,77, 0, 0, 0, 0, 0, 0,76,
        77,76,77,146, 0, 0,146, 0, 0, 0, 0, 0, 0,19,20,119,
        115, 6, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,25,26,119,
        115,14,14, 0, 0, 0, 0,136, 0, 0,136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,136, 0, 0,136, 0, 0, 0, 0, 0, 0,119,
        115,147,147,147,147,147,147,140, 0, 0,140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,140, 0, 0,140,147,147,147,147,147,147,119,
        115,116,116,116,116,116,116,141, 0, 0,141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,141, 0, 0,141,118,116,116,116,116,116,119,
        115,116,116,116,116,116,116,141, 0, 0,141,111,112, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,111,112,141, 0, 0,141,118,116,116,116,116,116,119,
        115,116,116,116,116,116,116,141, 0, 0,141,113,114, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,113,114,141, 0, 0,141,118,116,116,116,116,116,119,
        115,116,116,116,116,116,116,146, 0, 0,146,76,77, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,76,77,146, 0, 0,146,118,116,116,116,116,116,119,
        115,116,116,116,116,116,116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,118,116,116,116,116,116,119,
        115,116,116,116,116,116,116,136, 0, 0,136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,136, 0, 0,136,118,116,116,116,116,116,119,
        115,138,138,138,138,138,139,140, 0, 0,140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,140, 0, 0,140,138,138,138,138,138,139,119,
        115,115,148,148,148,148,119,141, 0, 0,141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,141, 0, 0,141,115,148,148,148,148,119,119,
        115,115,148,148,148,148,119,141,111,112,141,111,112, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,111,112,141,111,112,141,115,148,148,148,148,119,119,
        115,144,149,149,149,149,145,141,113,114,141,113,114, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,113,114,141,113,114,141,144,149,149,149,149,145,119,
        115,150,151, 0, 6, 7, 0,146,76,77,146,76,77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0,76,77,146,76,77,146, 0, 0, 0, 5, 6, 7,119,
        115,152,153, 0,14,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,13,14,14,119,
        115,152,153, 0, 0, 0, 0,136, 0, 0,136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,136, 0, 0,136, 0, 0, 0, 0, 0, 0,119,
        115,154,155, 0, 0, 0, 0,140, 0, 0,140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,140, 0, 0,140, 0, 0, 0, 0, 0, 0,119,
        115,150,151, 0, 0, 0, 0,141, 0, 0,141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,141, 0, 0,141, 0, 0, 0, 0, 0, 0,119,
        115,152,153, 0, 0,111,112,141,111,112,141,111,112, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,111,112,141,111,112,141,111,112, 0, 0, 0, 0,119,
        115,152,153, 0, 0,113,114,141,113,114,141,113,114, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,113,114,141,113,114,141,113,114, 0, 0,150,151,119,
        115,152,153, 0, 0,76,77,146,76,77,146,76,77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0,76,77,146,76,77,146,76,77, 0, 0,152,153,119,
        115,152,153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,152,153,119,
        115,154,155, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,154,155,119,
        156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,144, 0, 0, 0,
        0, 0, 0, 0,145,156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,
        156
    };

    this->canGoBehindLayerLayout = new int[this->layoutSize];

    for(int i = 0 ; i < this->layoutSize ; i++)    
        this->canGoBehindLayerLayout[i] = canGoBehindLayerLayout[i];
}