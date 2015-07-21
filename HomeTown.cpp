#include "HomeTown.h"

//Constructor.
HomeTown::HomeTown(ImageStore *imageStore , DrawRepository *drawRepository ,
        GameManager *gameManager , BattleManager *battleManager , 
        FontStore *fontStore , int layoutSize) : 
            CustomAreaMap(imageStore , drawRepository , gameManager , 
            battleManager , fontStore , layoutSize){
}

//Destructor.
HomeTown::~HomeTown(){
}

//Loads all the cloud Scenery objects.
void HomeTown::loadTheSceneries(){

    Scenery *cloud1 = new Scenery(imageStore->getBitMap("cloud") , SCREEN_W , 0 , -4 , 1);
    cloud1->setDX(80);    cloud1->setDY(0);
    Scenery *cloud2 = new Scenery(imageStore->getBitMap("cloud") , SCREEN_W , 40 , -8 , 0);
    cloud2->setDX(500);    cloud2->setDY(40);
    Scenery *cloud3 = new Scenery(imageStore->getBitMap("cloud") , SCREEN_W , 80 , -6 , 0);
    cloud3->setDX(540);    cloud3->setDY(80);
    Scenery *cloud4 = new Scenery(imageStore->getBitMap("cloud") , SCREEN_W , 120 , -10 , 2);
    cloud4->setDX(290);   cloud4->setDY(120);
    Scenery *cloud5 = new Scenery(imageStore->getBitMap("cloud") , SCREEN_W , 160 , -3 , 0);
    cloud5->setDX(360);    cloud5->setDY(160);
    Scenery *cloud6 = new Scenery(imageStore->getBitMap("cloud") , SCREEN_W , 200 , -2 , 0);
    cloud6->setDX(430);    cloud6->setDY(200);
    Scenery *cloud7 = new Scenery(imageStore->getBitMap("cloud") , SCREEN_W , 240 , -8 , -2);
    cloud7->setDX(150);    cloud7->setDY(240);
    Scenery *cloud8 = new Scenery(imageStore->getBitMap("cloud") , SCREEN_W , 280 , -9 , 0);
    cloud8->setDX(220);    cloud8->setDY(280);
    Scenery *cloud9 = new Scenery(imageStore->getBitMap("cloud") , SCREEN_W , 380 , -5 , -1);
    cloud9->setDX(SCREEN_W);    cloud9->setDY(380);

    this->loadScenery(cloud1);
    this->loadScenery(cloud2);
    this->loadScenery(cloud3);
    this->loadScenery(cloud4);
    this->loadScenery(cloud5);
    this->loadScenery(cloud6);
    this->loadScenery(cloud7);
    this->loadScenery(cloud8);
    this->loadScenery(cloud9);
}

void HomeTown::loadTheTangibles(){

    NPCWithDialogue *talkingRock = new NPCWithDialogue(
        imageStore->getBitMap("rock") ,
        Conversion::convertTilesToPixels(26) , 
        Conversion::convertTilesToPixels(26) ,
        this->drawRepository ,
        this->gameManager , 
        "Mighty Rock: I'm a rock, are you really trying to talk to a rock?" ,
        this->fontStore->getFont("default"));
    talkingRock->createCharacter(32 , 32 , 60 , 1 , 4 , this);

    NPCWithDialogue *teacher = new NPCWithDialogue(
        imageStore->getBitMap("playerLookalike") ,
        Conversion::convertTilesToPixels(28) , 
        Conversion::convertTilesToPixels(28) ,
        this->drawRepository ,
        this->gameManager , 
        "Teacher: Welcome to the town Stiltaviksenburgville! It's safe to walk around here " 
        "but be careful going outside because there are tons of monsters. Lucky for you, you already "
        "have formidible weapons. Now you just need to be able to heal yourself. Search around the town. "
        "Talk to people. Open treasure chests. Search barrels. I'm sure you'll find a healing spell for "
        "everyone somewhere in town." ,
        this->fontStore->getFont("default"));
    teacher->createCharacter(32 , 32 , 90 , 2 , 4 , this);
    teacher->setCW(32);
    teacher->setCH(32);
    teacher->setCharacterFacing(DOWN);

    NPCWithDialogueAndGift *storeOwner = new NPCWithDialogueAndGift(
        imageStore->getBitMap("playerLookalike") ,
        Conversion::convertTilesToPixels(25) , 
        Conversion::convertTilesToPixels(25) ,
        this->drawRepository ,
        this->gameManager , 
        "Store Owner: Hey! You look a lot like me! Take this and help us figure out what happened." ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity());
    storeOwner->createCharacter(32 , 32 , 90 , 2 , 4 , this);
    storeOwner->setCW(32);
    storeOwner->setCH(32);
    storeOwner->setGift("player" , "Jump");
    storeOwner->setRewardNotification("Player received the Jump ability!");
    storeOwner->setMessageAfterGiftDelivery(" Make sure to go around town and talk to everyone. They'll have some useful tips." 
        "Well...most of them will.");
    storeOwner->setCharacterFacing(DOWN);

    NPCWithDialogueAndGift *mysteriousMan = new NPCWithDialogueAndGift(
        imageStore->getBitMap("mysteriousMan") ,
        Conversion::convertTilesToPixels(3) , 
        Conversion::convertTilesToPixels(3) ,        
        this->drawRepository ,
        this->gameManager , 
        "Mysterious Man: I bet your mage could use this handy spell." ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity());
    mysteriousMan->createCharacter(32 , 32 , 60 , 2 , 4 , this);
    mysteriousMan->setCW(32);
    mysteriousMan->setCH(32);
    mysteriousMan->setGift("mage" , "Fireball");
    mysteriousMan->setRewardNotification("mage received the Fireball spell!");
    mysteriousMan->setMessageAfterGiftDelivery("Try out the spell, I'm sure you'll enjoy it. Hadouken!");
    mysteriousMan->setCharacterFacing(DOWN);

    NPCWithDialogue *witch = new NPCWithDialogue(
        imageStore->getBitMap("witch") ,
        Conversion::convertTilesToPixels(46) , 
        Conversion::convertTilesToPixels(4) ,        
        this->drawRepository ,
        this->gameManager , 
        "Witch: There are some extreme seasons in this country." ,
        this->fontStore->getFont("default"));
    witch->createCharacter(32 , 32 , 60 , 2 , 4 , this);
    witch->setCW(32);
    witch->setCH(32);
    witch->setCharacterFacing(DOWN);

    NPCWithDialogue *oldMan = new NPCWithDialogue(
        imageStore->getBitMap("oldMan") ,
        Conversion::convertTilesToPixels(33) , 
        Conversion::convertTilesToPixels(36) ,        
        this->drawRepository ,
        this->gameManager , "Old Man: This wind is really killing my hair..." ,
        this->fontStore->getFont("default"));
    oldMan->createCharacter(32 , 32 , 60 , 2 , 4 , this);
    oldMan->setCW(32);
    oldMan->setCH(32);
    oldMan->setCharacterFacing(DOWN);

    NPCWithDialogue *clod = new NPCWithDialogue(
        imageStore->getBitMap("clod") ,
        Conversion::convertTilesToPixels(8) , 
        Conversion::convertTilesToPixels(19) ,        
        this->drawRepository ,
        this->gameManager , 
        "Clod: In battle, you won't have any MP. The skills and spells will have a recover "
        "time. Some skills will do less damage but let you recover faster. Others will do tons "
        "of damage but you'll need to wait a lot longer to use another ability.",
        this->fontStore->getFont("default"));
    clod->createCharacter(32 , 32 , 60 , 2 , 4 , this);
    clod->setCW(32);
    clod->setCH(32);
    clod->setCharacterFacing(DOWN);

    NPCWithDialogue *joanna = new NPCWithDialogue(
        imageStore->getBitMap("joanna") ,
        Conversion::convertTilesToPixels(6) , 
        Conversion::convertTilesToPixels(19) ,        
        this->drawRepository ,
        this->gameManager , 
        "Joanna: Dickle punch with lightning! Oh yeah, where's the music? What's a going on?" ,
        this->fontStore->getFont("default"));
    joanna->createCharacter(32 , 32 , 60 , 2 , 4 , this);
    joanna->setCW(32);
    joanna->setCH(32);
    joanna->setCharacterFacing(DOWN);

    ItemLocationWithGift *treasureBoxWithRecoverForPlayer = new ItemLocationWithGift(
        imageStore->getBitMap("treasureBox1") ,
        Conversion::convertTilesToPixels(18) , 
        Conversion::convertTilesToPixels(18) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity()
        );
    treasureBoxWithRecoverForPlayer->setRewardNotification(
        "Player learned the Recover ability!");
    treasureBoxWithRecoverForPlayer->setGift(
        "player" , "Recover");
    treasureBoxWithRecoverForPlayer->setMessageAfterGiftDelivery(
        "Nothing out of the ordinary.");

    ItemLocationWithGift *treasureBoxWithRecoverForMage = new ItemLocationWithGift(
        imageStore->getBitMap("treasureBox2") ,
        Conversion::convertTilesToPixels(19) , 
        Conversion::convertTilesToPixels(18) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity()
        );
    treasureBoxWithRecoverForMage->setRewardNotification(
        "Mage learned the Recover ability!");
    treasureBoxWithRecoverForMage->setGift(
        "mage" , "Recover");
    treasureBoxWithRecoverForMage->setMessageAfterGiftDelivery(
        "The box is empty.");

    ItemLocationWithGift *treasureBarrelWithRecoverForThief = new ItemLocationWithGift(
        imageStore->getBitMap("treasureBarrel") ,
        Conversion::convertTilesToPixels(12) , 
        Conversion::convertTilesToPixels(10) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity()
        );
    treasureBarrelWithRecoverForThief->setRewardNotification(
        "Thief learned the Recover ability!");
    treasureBarrelWithRecoverForThief->setGift(
        "thief" , "Recover");
    treasureBarrelWithRecoverForThief->setMessageAfterGiftDelivery(
        "Nothing worth noting.");

    ItemLocationWithGift *treasureBarrelWithRecoverForWarrior = new ItemLocationWithGift(
        imageStore->getBitMap("treasureBarrel") ,
        Conversion::convertTilesToPixels(33) , 
        Conversion::convertTilesToPixels(37) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity()
        );
    treasureBarrelWithRecoverForWarrior->setRewardNotification(
        "Warrior learned the Recover ability!");
    treasureBarrelWithRecoverForWarrior->setGift(
        "warrior" , "Recover");
    treasureBarrelWithRecoverForWarrior->setMessageAfterGiftDelivery(
        "The barrel is empty.");

    NPCWithDialogueAndQuest *strifeTheQuestGiver = new NPCWithDialogueAndQuest(
        imageStore->getBitMap("strife") ,
        Conversion::convertTilesToPixels(17) , 
        Conversion::convertTilesToPixels(17) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity()
        );
    strifeTheQuestGiver->createCharacter(32 , 32 , 60 , 2 , 4 , this);
    strifeTheQuestGiver->setCW(32);
    strifeTheQuestGiver->setCH(32);
    strifeTheQuestGiver->setCharacterFacing(DOWN);
    strifeTheQuestGiver->setQuestExplanation(
        "Strife: I'm making a delicious stew but I'm all out of rat eyeballs."  
        "I need you to kill 3 rats so I can get the last 6 eyes that " 
        "the recipe requires. Can you do that for me? Of course you will! " 
        "Thanks in advance!");
    strifeTheQuestGiver->setQuestReminder(
        "Strife: Have you killed those 3 rats yet? Chop chop, I don't have much time!");
    strifeTheQuestGiver->setQuestCompleteMessage(
        "Strife:Wow, these eyes are so big and juicy, they'll be perfect! Here take this...");
    strifeTheQuestGiver->setRewardNotification(
        "Strife: Player received the Jump ability!");
    strifeTheQuestGiver->setGift("player" , "Jump");
    strifeTheQuestGiver->setQuestAfterCompleteMessage(
        "Strife: The soup turned out great. Thanks for the eye balls."
        );

    KillQuest *kill3Rats = new KillQuest();
    kill3Rats->setQuestDisplayName("Three Semi-Blind Mice");
    kill3Rats->addObjective("rat" , 3);
    kill3Rats->addObjective("wolf" , 8);
    kill3Rats->addObjective("soldier" , 6);
    kill3Rats->setMustBeActiveForPlayerToUpdate();
    strifeTheQuestGiver->loadQuest(kill3Rats);
    gameManager->getPlayerEntity()->addQuest("ratQuest" , kill3Rats);

    NPCWithDialogueAndQuest *skugsTheQuestGiver = new NPCWithDialogueAndQuest(
        imageStore->getBitMap("monk") ,
        Conversion::convertTilesToPixels(9) , 
        Conversion::convertTilesToPixels(40) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity()
        );
    skugsTheQuestGiver->createCharacter(32 , 32 , 60 , 2 , 4 , this);
    skugsTheQuestGiver->setCW(32);
    skugsTheQuestGiver->setCH(32);
    skugsTheQuestGiver->setCharacterFacing(DOWN);
    skugsTheQuestGiver->setQuestExplanation(
        "Skugs: I was out training in the dessert... no the desert... and "  
        "I ran into a demon near the graves and I ran away because it was " 
        "too strong. Please go kill it so I can continue my training and " 
        "get me a neon orange belt.");
    skugsTheQuestGiver->setQuestReminder(
        "Skugs: Any luck killing the demon in the desert? ");
    skugsTheQuestGiver->setQuestCompleteMessage(
        "Skugs: I really didn't think you could do it to be honest. I'm impressed. Take "
        "this as a token of my gratitude.");
    skugsTheQuestGiver->setRewardNotification(
        "Skugs: Player received the Triple Thrust ability!");
    skugsTheQuestGiver->setGift("player" , "Triple Thrust");
    skugsTheQuestGiver->setQuestAfterCompleteMessage(
        "Skugs: You're my hero, peculiar person that doesn't say anything."
        );
    KillQuest *killDesertDemon= new KillQuest();
    killDesertDemon->setQuestDisplayName("A Demon in the Desert");
    killDesertDemon->addObjective("demon" , 1);
    skugsTheQuestGiver->loadQuest(killDesertDemon);
    gameManager->getPlayerEntity()->addQuest("demonQuest" , killDesertDemon);

    NPCWithDialogueAndQuest *friendlyGentlemanQuestGiver = new NPCWithDialogueAndQuest(
        imageStore->getBitMap("friendlyGentleman") ,
        Conversion::convertTilesToPixels(10) , 
        Conversion::convertTilesToPixels(40) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity()
        );
    friendlyGentlemanQuestGiver->createCharacter(32 , 32 , 60 , 2 , 4 , this);
    friendlyGentlemanQuestGiver->setCW(32);
    friendlyGentlemanQuestGiver->setCH(32);
    friendlyGentlemanQuestGiver->setCharacterFacing(DOWN);
    friendlyGentlemanQuestGiver->setQuestExplanation(
        "Friendly Gentleman: Why hullo there friend. You look like a strapping young lad. "  
        "I run a potion exchange and I'm short some potions. Have you "
        "perchance run across any? I'd be every so graetful if you could "
        "get me 10 potions and 5 hi-potions. I would most definitely "
        "repay you with something extraordinary!" );
    friendlyGentlemanQuestGiver->setQuestReminder(
        "Friendly Gentleman: How goes the potion hunt? ");
    friendlyGentlemanQuestGiver->setQuestCompleteMessage(
        "Friendly Gentleman: Well done kind sir, you have saved my slightly wrinkly overcooked bacon!");
    friendlyGentlemanQuestGiver->setRewardNotification(
        "Friendly Gentleman: Thief received the Backstab ability!");
    friendlyGentlemanQuestGiver->setGift("thief" , "Backstab");
    friendlyGentlemanQuestGiver->setQuestAfterCompleteMessage(
        "Friendly Gentleman: Whoop whoop, back in business!"
        );
    GatherQuest *get10Potions5Hipotions = new GatherQuest(
        gameManager->getPlayerEntity()->getPlayerInventory());
    get10Potions5Hipotions->setQuestDisplayName("Potions for a Gentleman");
    get10Potions5Hipotions->addObjective("Potion" , 2);
    get10Potions5Hipotions->addObjective("hi-potion" , 5);
    friendlyGentlemanQuestGiver->loadQuest(get10Potions5Hipotions);
    gameManager->getPlayerEntity()->addQuest("potionQuest" , get10Potions5Hipotions);
    
    this->loadTangible(talkingRock);
    this->loadTangible(teacher);
    this->loadTangible(storeOwner);
    this->loadTangible(mysteriousMan);
    this->loadTangible(witch);
    this->loadTangible(oldMan);
    this->loadTangible(clod);
    this->loadTangible(joanna);
    this->loadTangible(treasureBoxWithRecoverForPlayer);
    this->loadTangible(treasureBoxWithRecoverForMage);
    this->loadTangible(treasureBarrelWithRecoverForThief);
    this->loadTangible(treasureBarrelWithRecoverForWarrior);
    this->loadTangible(strifeTheQuestGiver);
    this->loadTangible(skugsTheQuestGiver);
    this->loadTangible(friendlyGentlemanQuestGiver);
}

//Loads all the layers to the areaMap.
void HomeTown::loadLayers(){

    Layer *backgroundLayer = new Layer(imageStore->getBitMap("terrain") ,
        50 , 50 , this->backgroundLayerLayout , 2500);
    Layer *collisionLayer = new Layer(imageStore->getBitMap("town") ,
        50 , 50 , this->collisionLayerLayout , 2500);
    Layer *canGoBehindLayer = new Layer(imageStore->getBitMap("town") ,
        50 , 50 , this->canGoBehindLayerLayout , 2500);
   
    this->loadLayer(backgroundLayer);
    this->loadLayer(collisionLayer);
    this->loadLayer(canGoBehindLayer);
}

void HomeTown::loadBackgroundLayerMapConfiguration(){

    int backgroundLayerLayout[] = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,
        1,1,2,1,1,1,1,1,3,1,1,1,1,1,2,1,1,1,1,4,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,3,5,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,
        1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,3,3,3,3,3,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,7,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,
        1,1,3,3,3,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,3,3,3,3,3,1,1,1,1,1,1,4,4,1,4,4,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,1,1,1,1,1,6,1,1,1,1,
        1,1,3,3,3,5,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        7,4,1,1,1,1,1,1,1,1,1,1,1,1,1,6,1,1,6,4,7,1,1,1,1,
        1,1,6,3,3,3,3,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,4,1,1,1,
        1,1,1,1,1,8,1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,4,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,
        4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,1,1,1,1,
        4,1,1,1,1,1,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,10,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,1,1,
        1,1,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,8,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,7,1,1,1,7,1,1,1,1,1,1,9,7,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,10,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,2,1,4,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,7,1,1,1,1,1,1,1,
        1,1,1,2,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,1,1,1,1,1,1,1,
        1,1,8,1,1,1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,4,1,1,
        1,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,10,1,1,7,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,8,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,
        1,1,1,1,7,1,1,7,1,1,2,1,1,1,8,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,10,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,10,1,1,7,1,
        10,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,10,10,1,1,1,1,1,1,1,
        1,1,1,1,1,11,11,1,1,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,8,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1,3,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,3,10,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,7,1,1,1,1,1,1,1,1,1,1,8,1,1,1,1,1,6,1,1,
        1,4,1,1,11,1,1,1,1,1,1,1,11,1,1,1,4,1,1,7,1,1,1,1,1,
        4,1,1,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,10,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,11,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,10,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,3,3,3,1,1,5,5,1,1,1,1,1,1,1,1,
        1,4,1,1,1,1,1,1,1,1,1,1,1,4,1,1,1,10,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,10,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,4,1,1,1,1,1,1,7,1,1,1,1,6,1,1,10,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,10,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
    }; 

    this->backgroundLayerLayout = new int[this->layoutSize];
    for(int i = 0 ; i < this->layoutSize ; i++)    
        this->backgroundLayerLayout[i] = backgroundLayerLayout[i];
}

void HomeTown::loadCollisionLayerMapConfiguration(){

    int collisionLayerLayout[] ={
       1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1,
       1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,15,16, 0, 0, 1, 1,
       1, 1, 0, 0,15,16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0,10,11,11,11,11,12, 0, 0, 0,13, 6, 6, 6, 6,14,20, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0,10,11,11,11,11,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       21,22,23,23,23,23,24, 0, 0, 0,13, 6, 6, 6, 6,14,25, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0,22,23,23,23,23,24, 0, 0,26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       20,27,28,28,28,28,29, 0, 0, 0,31,28,28,28,28,32, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0,27,28,28,28,28,29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       20,27,35,28,28,35,29, 0, 0, 0,27,35,28,28,35,29, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0,21,27,35,28,28,35,29, 0, 0, 0,37,38, 0, 0, 0, 0, 0, 0, 0, 0,
        0,27,28, 0, 0,28,29, 0, 0, 0,27,28, 0, 0,28,29, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0,21,27,28,28,28,28,29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0,40,41, 0, 0,41,43, 0, 0, 0,40,41, 0, 0,41,43,20, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0,20,40,41,41,41,41,43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0,50, 0, 0,50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0,27,35,29, 0,27,35,29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,60,
        0, 0, 0, 0, 0, 0, 0, 0,21,27,35,29,27,35,29,27,35,29,27,35,29, 0, 0, 1, 1,
       1, 1, 0, 0,61,40,41,43,62,40,41,43,61, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,21,40,41,43,40,41,43,40,41,43,40,41,43, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,20, 0, 0, 0, 0, 0, 0, 0,20, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1,65,66,66,67,66,66,66,66,66,67,66,66,65,66,66,67, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,67,66,66,66,66,66,67,66,66,65,66,66,67,66,66,66, 1, 1,
       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,70,71,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       1, 1,66,66,66,67,66,66,65,66,66,67,66,66,66,66,66,67, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,67,66,66,66,66,66,67,66,66,66,66,66,67,66,66,65, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0,74, 0, 0, 0,75,76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,77, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0,61,67, 0, 0, 0, 0, 0, 0, 0, 0,67,61, 0, 0, 0,95,96, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,51,52,52,52,52,52,52,52,53, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,101,102,102,102,102,102,102,102,103, 0, 0, 0, 0,
        0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0,104,105,106, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,107,35,108,35,108,35,108,35,109, 0, 0, 0, 0,
        0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0,111,112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,40,41,41,41,41,41,41,41,43, 0, 0, 0, 0, 0, 1,
        1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0,61,67, 0, 0, 0, 0, 0, 0, 0, 0,67,61, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0,60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,107,35,35,109, 0, 0, 1,
        1,
       1, 1, 0, 0, 0, 0, 0, 0,33,34,119, 0, 0, 0, 0, 0, 0, 0, 0,120,121, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,15,16, 0, 0, 0, 0, 0, 0, 0,107, 0, 0,109, 0, 0,
        1, 1,
       1, 1, 0, 0, 0, 0, 0,119,122,123,124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,40, 0, 0,43, 0, 0,
        1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
       1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };

    this->collisionLayerLayout = new int[this->layoutSize];
    for(int i = 0 ; i < this->layoutSize ; i++)    
        this->collisionLayerLayout[i] = collisionLayerLayout[i];
}

void HomeTown::loadCanGoBehindLayerMapConfiguration(){

    int canGoBehindLayerLayout[] ={
       1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1,
       1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 2, 3, 3, 3, 3, 4, 0, 0, 0, 5, 6, 6, 6, 6, 7, 0, 0, 0, 8, 9, 0, 0, 1, 1,
       1, 1, 0, 0, 8, 9, 2, 3, 3, 3, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0,10,11,11,11,11,12, 0, 0, 0,13, 6, 6, 6, 6,14, 0, 0, 0,15,16, 0, 0, 1, 1,
       1, 1, 0, 0,15,16,10,11,11,11,11,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0,10,11,11,11,11,12, 0, 0, 0,13, 6, 6, 6, 6,14, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0,10,11,11,11,11,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0,10,11,11,11,11,12,17,18,19,13, 6, 6, 6, 6,14,20, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0,10,11,11,11,11,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       21,22,23,23,23,23,24, 0, 0, 0,13, 6, 6, 6, 6,14,25, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0,22,23,23,23,23,24,17,19,26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       20,27,28,28,28,28,29,30, 0, 0,31,28,28,28,28,32,30, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0,27,28,28,28,28,29, 0, 0, 0,33,34, 0, 0, 0, 0, 0, 0, 0, 0,
       20,27,35,28,28,35,29,36, 0, 0,27,35,28,28,35,29,36, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0,21,27,35,28,28,35,29, 0, 0, 0,37,38, 0, 0, 0, 0, 0, 0, 0, 0,
        0,27,28,39,39,28,29, 0, 0, 0,27,28,39,39,28,29, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0,21,27,28,28,28,28,29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0,40,41,0,0,41,43, 0, 0, 0,40,41,0,0,41,43,20, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0,20,40,41,41,41,41,43,44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0,46, 0, 0,46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0,47,48,49, 0,47,48,49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0,50, 0, 0,50, 0, 0, 0,47,48,49,47,48,49,47,48,49,47,48,49, 0, 0, 1, 1,
       1, 1, 0, 0, 0,51,52,53, 0,51,52,53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,51,52,53,51,52,53,51,52,53,51,52,53, 0, 0, 1, 1,
       1, 1, 0, 0, 0,54,55,56,57,54,55,56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,54,55,56,54,55,56,54,55,56,54,55,56, 0, 0, 1, 1,
       1, 1, 0, 0,58,27,35,29,59,27,35,29,58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,60,
        0, 0, 0, 0, 0, 0, 0, 0,21,27,35,29,27,35,29,27,35,29,27,35,29, 0, 0, 1, 1,
       1, 1, 0, 0,61,40,41,43,62,40,41,43,61, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,21,40,41,43,40,41,43,40,41,43,40,41,43, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,20, 0, 0, 0, 0, 0, 0, 0,20, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0,63, 0, 0, 0, 0, 0,63, 0, 0, 0, 0, 0,63, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,63, 0, 0, 0, 0, 0,63, 0, 0, 0, 0, 0,63, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0,64, 0, 0, 0, 0, 0,64, 0, 0, 0, 0, 0,64, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,64, 0, 0, 0, 0, 0,64, 0, 0, 0, 0, 0,64, 0, 0, 0, 1, 1,
       1, 1,65,66,66,67,66,66,66,66,66,67,66,66,65,66,66,67, 0, 0, 0, 0, 0,68,69,
        0, 0, 0, 0, 0, 0, 0,67,66,66,66,66,66,67,66,66,65,66,66,67,66,66,66, 1, 1,
       0, 0, 0, 0, 0,63, 0, 0, 0, 0, 0,63, 0, 0, 0, 0, 0,63, 0, 0, 0, 0, 0,70,71,
        0, 0, 0, 0, 0, 0, 0,63, 0, 0, 0, 0, 0,63, 0, 0, 0, 0, 0,63, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0,64, 0, 0, 0, 0, 0,64, 0, 0, 0, 0, 0,64, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,64, 0, 0, 0, 0, 0,64, 0, 0, 0, 0, 0,64, 0, 0, 0, 0, 0,
       1, 1,66,66,66,67,66,66,65,66,66,67,66,66,66,66,66,67, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,67,66,66,66,66,66,67,66,66,66,66,66,67,66,66,65, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0,44, 0, 0, 0,72,73, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0,74, 0, 0, 0,75,76, 0, 0, 0,44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,77, 0, 0, 0,78,79, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,47,48,48,48,48,48,48,48,49, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0,63, 0, 0, 0, 0, 0, 0, 0, 0,63, 0, 0, 0, 0,80,81, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,82,83,83,83,83,83,83,83,84, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0,58,64, 0, 0,85,86,87,88, 0, 0,64,58, 0, 0, 0,89,90, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,82,83,83,83,83,83,83,83,84, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0,61,67, 0, 0,91,92,93,94, 0, 0,67,61, 0, 0, 0,95,96, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,51,52,52,52,52,52,52,52,53, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0,97,98,99,100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,101,102,102,102,102,102,102,102,103, 0, 0, 0,
        0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0,104,105,106, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,107,35,108,35,108,35,108,35,109, 0,110, 0, 0,
        0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0,111,112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,40,41,41,41,41,41,41,41,43, 0,113, 0, 0, 0,
        1, 1,
       1, 1, 0, 0, 0,63, 0, 0, 0, 0, 0, 0, 0, 0,63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 6, 6, 7, 0, 0, 1, 1,
       1, 1, 0, 0,58,64, 0, 0, 0, 0, 0, 0, 0, 0,64,58, 0, 0, 0,114,115, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,13, 6, 6,14, 0, 0, 1,
        1,
       1, 1, 0, 0,61,67, 0, 0, 0, 0, 0, 0, 0, 0,67,61, 0, 0, 0,31,32, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,116,102,102,117, 0, 0,
        1, 1,
       1, 1, 0, 0,60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,54,56, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 8, 9, 0, 0, 0, 0, 0, 0, 0,107,35,35,109,118, 0, 1,
        1,
       1, 1, 0, 0, 0, 0, 0, 0,33,34,119, 0, 0, 0, 0, 0, 0, 0, 0,120,121, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,15,16, 0, 0, 0, 0, 0, 0, 0,107,39,39,109, 0, 0,
        1, 1,
       1, 1, 0, 0, 0, 0, 0,119,122,123,124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,40,0,0,43, 0, 0,
        1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
       1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
       1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };

    this->canGoBehindLayerLayout = new int[this->layoutSize];

    for(int i = 0 ; i < this->layoutSize ; i++)    
        this->canGoBehindLayerLayout[i] = canGoBehindLayerLayout[i];
}