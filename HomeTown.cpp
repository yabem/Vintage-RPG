#include "HomeTown.h"

//Constructor.
HomeTown::HomeTown(ImageStore *imageStore , DrawRepository *drawRepository ,
        GameManager *gameManager , BattleManager *battleManager , 
        FontStore *fontStore , int layoutSize) : 
            CustomAreaMap(imageStore , drawRepository , gameManager , 
            battleManager , fontStore , layoutSize){

                mapMusic = "Enchanted Valley";
}

//Destructor.
HomeTown::~HomeTown(){
}

//Loads the enemies and level ranges for the map.
void HomeTown::loadMapEnemies(){

    /*
    this->listOfEnemies.push_back(SOLDIER);
    this->listOfEnemies.push_back(NINJA_FOX);
    this->listOfEnemies.push_back(FANGED_FOX);
    this->listOfEnemies.push_back(SHEEP);

    this->loadEnemyLevelRange(3 , 5);

    */
}
//Loads all the cloud Scenery objects.
void HomeTown::loadTheSceneries(){

    Scenery *cloud1 = new Scenery(imageStore->getBitMap("cloud") , SCREEN_W , 0 , -2 , 0);
    cloud1->setDX(80);    cloud1->setDY(0);
    Scenery *cloud2 = new Scenery(imageStore->getBitMap("cloud") , SCREEN_W , 40 , -3 , 0);
    cloud2->setDX(500);    cloud2->setDY(40);
    Scenery *cloud3 = new Scenery(imageStore->getBitMap("cloud") , SCREEN_W , 80 , -3 , 0);
    cloud3->setDX(540);    cloud3->setDY(80);
    Scenery *cloud4 = new Scenery(imageStore->getBitMap("cloud") , SCREEN_W , 120 , -2 , 0);
    cloud4->setDX(290);   cloud4->setDY(120);
    Scenery *cloud5 = new Scenery(imageStore->getBitMap("cloud") , SCREEN_W , 160 , -2 , 0);
    cloud5->setDX(360);    cloud5->setDY(160);
    Scenery *cloud6 = new Scenery(imageStore->getBitMap("cloud") , SCREEN_W , 200 , -3 , 0);
    cloud6->setDX(430);    cloud6->setDY(200);
    Scenery *cloud7 = new Scenery(imageStore->getBitMap("cloud") , SCREEN_W , 240 , -3 , 0);
    cloud7->setDX(150);    cloud7->setDY(240);
    Scenery *cloud8 = new Scenery(imageStore->getBitMap("cloud") , SCREEN_W , 280 , -2 , 0);
    cloud8->setDX(220);    cloud8->setDY(280);
    Scenery *cloud9 = new Scenery(imageStore->getBitMap("cloud") , SCREEN_W , 380 , -3 , 0);
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
        Conversion::convertTilesToPixels(25) ,
        this->drawRepository ,
        this->gameManager , 
        "Mighty Rock: I'm a rock, are you really trying to talk to a rock?" ,
        this->fontStore->getFont("default"));
    talkingRock->createCharacter(32 , 32 , 60 , 1 , 4 , this);

    NPCWithDialogue *informativeShade = new NPCWithDialogue(
        imageStore->getBitMap("npcShade") ,
        Conversion::convertTilesToPixels(17) , 
        Conversion::convertTilesToPixels(27) ,
        this->drawRepository ,
        this->gameManager , 
        "Informative Shade: You can use I to access your inventory, L to review open quests, "
        "O to see completed quests, and U to view your party stats." ,
        this->fontStore->getFont("default"));
    informativeShade->createCharacter(32 , 32 , 90 , 2 , 4 , this);
    informativeShade->setCW(32);
    informativeShade->setCH(32);
    informativeShade->setCharacterFacing(DOWN);

    NPCWithDialogue *teacher = new NPCWithDialogue(
        imageStore->getBitMap("npcTalkingSheep") ,
        Conversion::convertTilesToPixels(28) , 
        Conversion::convertTilesToPixels(28) ,
        this->drawRepository ,
        this->gameManager , 
        "Teacher: Welcome to the town Hamletburgeville! It's safe to walk around here " 
        "but be careful going outside because there are tons of monsters. Lucky for you, "
        "you already have formidible weapons. Now you just need to be able to heal "
        "yourself. Search around the town. Talk to people. Open treasure chests. Search "
        "barrels. I'm sure you'll find a healing spell for everyone somewhere in town. Oh, "
        "word around the water cooler is that, a mage was trapped in a barrel somewhere to the "
        "eastern castle area. I bet if you find him he'd have something powerful for you!" ,
        this->fontStore->getFont("default"));
    teacher->createCharacter(32 , 32 , 15 , 2 , 4 , this);
    teacher->setCW(32);
    teacher->setCH(32);
    teacher->setCharacterFacing(DOWN);

    NPCWithDialogueAndGift *storeOwner = new NPCWithDialogueAndGift(
        imageStore->getBitMap("npcAngryCleric") ,
        Conversion::convertTilesToPixels(25) , 
        Conversion::convertTilesToPixels(25) ,
        this->drawRepository ,
        this->gameManager , 
        "Store Owner: Hey! Take this and help us figure out what happened. If you use this on"
        "a dead ally, you can bring them back to life. Try it out!" ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity());
    storeOwner->createCharacter(32 , 32 , 90 , 2 , 4 , this);
    storeOwner->setCW(32);
    storeOwner->setCH(32);
    storeOwner->setGift("lancer" , "Recover");
    storeOwner->setRewardNotification("Lancer received the Recover ability!");
    storeOwner->setMessageAfterGiftDelivery("Store Owner: Make sure to go around town and talk to everyone. They'll have some useful tips. " 
        "Remember, recover also resurrects dead allies.");
    storeOwner->setCharacterFacing(DOWN);

    NPCWithDialogueAndQuest *mysteriousManQuestGiver = new NPCWithDialogueAndQuest(
        imageStore->getBitMap("npcMysteriousMan") ,
        Conversion::convertTilesToPixels(3) , 
        Conversion::convertTilesToPixels(3) ,
        this->drawRepository ,
        this->gameManager ,
        this->fontStore->getFont("default") ,
        this->gameManager->getPlayerEntity()
        );
    mysteriousManQuestGiver->createCharacter(32 , 32 , 60 , 2 , 4 , this);
    mysteriousManQuestGiver->setCW(32);
    mysteriousManQuestGiver->setCH(32);
    mysteriousManQuestGiver->setCharacterFacing(DOWN);
    mysteriousManQuestGiver->setQuestExplanation(
        "Mysterious Man: Hey there! I'm running some trials and I am low " 
        "on some key materials. Can you please take this list, make like "
        "Fievel and go west to get everything and bring it back to me? "
        "I'll teach your mage a useful spell.");
    mysteriousManQuestGiver->setQuestReminder(
        "Mysterious Man: Did you acquire everything? ");
    mysteriousManQuestGiver->setQuestCompleteMessage(
        "Mysterious Man: As promised here's the spell.");
    mysteriousManQuestGiver->setRewardNotification(
        "Mage received the Heal ability!");
    mysteriousManQuestGiver->setGift("mage" , "Heal");
    mysteriousManQuestGiver->setQuestAfterCompleteMessage(
        "Mysterious Man: Try out the spell, I'm sure you'll enjoy it!"
        );
    GatherQuest *mysteriousManObjectives = new GatherQuest(
        gameManager->getPlayerEntity()->getPlayerInventory());
    mysteriousManObjectives->setQuestDisplayName("The Needs of a Tinkerer");
    mysteriousManObjectives->addObjective("Stick" , 2);
    mysteriousManObjectives->addObjective("Sand" , 1);
    mysteriousManObjectives->addObjective("Napalm" , 1);
    mysteriousManQuestGiver->loadQuest(mysteriousManObjectives);
    gameManager->getPlayerEntity()->addQuest("theNeedsOfATinkerer" , mysteriousManObjectives);

    NPCWithDialogue *witch = new NPCWithDialogue(
        imageStore->getBitMap("witch") ,
        Conversion::convertTilesToPixels(46) , 
        Conversion::convertTilesToPixels(4) ,        
        this->drawRepository ,
        this->gameManager , 
        "Witch: There are some extreme seasons in this country. Oh, by the way "
        "I hear there was a magical spotted mushroom in the north, be on the lookout for "
        "it in your journeys.",
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
        this->gameManager , "Old Man: This wind is really killing my hair. Anyway, legend has it that "
        "there's a talking red pepper somewhere in the southwestern part of the forest. "
        "I've never seen it but how great that would be if it existed!",
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
        "Clod: In battle, you won't have any MP. The skills and spells will have a "
        "recover time. Some skills will do less damage but let you recover faster. "
        "Others will do tons of damage but you'll need to wait a lot longer to use "
        "another ability. Before I forget, make sure you search the tombstones "
        "in the graveyard to the west. People were saying there was a ghost that was "
        "looking for help. Maybe you could help it out!",
        this->fontStore->getFont("default"));
    clod->createCharacter(32 , 32 , 60 , 2 , 4 , this);
    clod->setCW(32);
    clod->setCH(32);
    clod->setCharacterFacing(DOWN);

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
        "Strife: I'm making a delicious stew but I'm all out of eyeballs. "  
        "I need you to acquire some eyeballs from various animals. " 
        "Foxes and sheep to the east have the plumpest eyeballs! "
        "Can you do that for me? Of course you will! Thanks in advance!");
    strifeTheQuestGiver->setQuestReminder(
        "Strife: Have you gotten those eyes yet? Chop chop, I don't have much time!");
    strifeTheQuestGiver->setQuestCompleteMessage(
        "Strife: Wow, these eyes are so big and juicy, they'll be perfect! Here take this...");
    strifeTheQuestGiver->setRewardNotification(
        "Thief received the Knife Barrage ability!");
    strifeTheQuestGiver->setGift("thief" , "Knife Barrage");
    strifeTheQuestGiver->setQuestAfterCompleteMessage(
        "Strife: The soup turned out great. Thanks for the eyeballs."
        );
    strifeTheQuestGiver->setIdentifierName("strife");

    GatherQuest *strifeQuestObjectives = new GatherQuest(
        gameManager->getPlayerEntity()->getPlayerInventory());
    strifeQuestObjectives->setQuestDisplayName("I've Got My Eyes On You");
    strifeQuestObjectives->addObjective("Bloodshot Eye" , 2);
    strifeQuestObjectives->addObjective("Pussing Eye" , 2);
    strifeTheQuestGiver->loadQuest(strifeQuestObjectives);
    gameManager->getPlayerEntity()->addQuest("IveGotMyEyesOnYou" , strifeQuestObjectives);

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
        "perchance run across any in your southern travels? I'd be ever "
        "so grateful if you could gather this list of potions for me. I "
        "would most definitely repay you with something extraordinary!" );
    friendlyGentlemanQuestGiver->setQuestReminder(
        "Friendly Gentleman: How goes the potion hunt? ");
    friendlyGentlemanQuestGiver->setQuestCompleteMessage(
        "Friendly Gentleman: Well done kind sir, you have saved my slightly wrinkly overcooked bacon!");
    friendlyGentlemanQuestGiver->setRewardNotification(
        "Lancer received the Skewer ability!");
    friendlyGentlemanQuestGiver->setGift("lancer" , "Skewer");
    friendlyGentlemanQuestGiver->setQuestAfterCompleteMessage(
        "Friendly Gentleman: Whoop whoop, back in business!"
        );
    GatherQuest *potionObjectives = new GatherQuest(
        gameManager->getPlayerEntity()->getPlayerInventory());
    potionObjectives->setQuestDisplayName("Potions for a Gentleman");
    potionObjectives->addObjective("Red Potion" , 2);
    potionObjectives->addObjective("Green Potion" , 2);
    potionObjectives->addObjective("Blue Potion" , 2);
    friendlyGentlemanQuestGiver->loadQuest(potionObjectives);
    gameManager->getPlayerEntity()->addQuest("potionsForAGentleman" , potionObjectives);
    
    this->loadTangible(talkingRock);
    this->loadTangible(informativeShade);
    this->loadTangible(teacher);
    this->loadTangible(storeOwner);
    this->loadTangible(mysteriousManQuestGiver);
    this->loadTangible(witch);
    this->loadTangible(oldMan);
    this->loadTangible(clod);
    this->loadTangible(strifeTheQuestGiver);
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