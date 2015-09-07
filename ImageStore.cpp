#include "ImageStore.h"

//Default constructor.
ImageStore::ImageStore(){

}

//Destructor.
//Make sure no duplicate destroys in main().
ImageStore::~ImageStore(){

    destroyImages();
}

//Destroys all the images.
//Pre:  None.
//Post: All the images in the container are destroyed and
//      the memory is reclaimed.
void ImageStore::destroyImages(){

    std::map<std::string , ALLEGRO_BITMAP*>::iterator iter = images.begin();

    while(iter != images.end()){

        al_destroy_bitmap(iter->second);
        iter->second = NULL;
        images.erase(iter);
        iter = images.begin();
    }
}

//Loads a single bitmap pointer to the bitmap map.
//Preconditions:    The bitmap pointer is not NULL.
//Postconditions:   The bitmap pointer is added to the
//                  end of the image vector.
void ImageStore::loadBitMap(std::string name , ALLEGRO_BITMAP *bmap){

    //Don't add anything if pointer is NULL.
    if(bmap == NULL || name == "")
        return;

    else images.insert(std::pair<std::string , ALLEGRO_BITMAP*>(name , bmap));
}

//Loads all of the default bitmaps.
//Precondition:     None.
//Postconditions:   Loads a BitMap into the images collection.
void ImageStore::loadAllDefaultImages(){

    //Loads all the key value pairs. The key is the string and the
    //value is the pointer to an ALLEGRO_BITMAP.

    //Characters
    loadBitMap("lancer" , al_load_bitmap("Images/lancer.png")); 
    loadBitMap("mage" , al_load_bitmap("Images/mage.png"));
    loadBitMap("warrior" , al_load_bitmap("Images/warrior.png"));
    loadBitMap("thief" , al_load_bitmap("Images/thief.png"));

    //Backgrounds
    loadBitMap("rock" , al_load_bitmap("Images/rock.png")); 
    loadBitMap("terrain" , al_load_bitmap("Images/terrain.png")); 
    loadBitMap("town" , al_load_bitmap("Images/town.png")); 
    loadBitMap("cloud" , al_load_bitmap("Images/clouds.png")); 
    loadBitMap("northernSnow" , al_load_bitmap("Images/northernSnow.png"));
    loadBitMap("terrainForNorthernSnow" , al_load_bitmap("Images/terrainForNorthernSnow.png"));
    loadBitMap("snowFall" , al_load_bitmap("Images/snowFall.png"));
    loadBitMap("snowFall2" , al_load_bitmap("Images/snowFall2.png"));
    loadBitMap("snowFall3" , al_load_bitmap("Images/snowFall3.png"));
    loadBitMap("desertRegion" , al_load_bitmap("Images/desertRegion.png"));
    loadBitMap("heatWave" , al_load_bitmap("Images/heatWave.png"));
    loadBitMap("southernForest" , al_load_bitmap("Images/southernForest.png"));
    loadBitMap("snowTerrain" , al_load_bitmap("Images/snowTerrain.png"));
    loadBitMap("easternCastle" , al_load_bitmap("Images/easternCastle.png"));
    loadBitMap("easternCastleTerrain" , al_load_bitmap("Images/easternCastleTerrain.png"));
    loadBitMap("darkness" , al_load_bitmap("Images/darkness.png"));
    loadBitMap("fog" , al_load_bitmap("Images/fog.png"));
    loadBitMap("fogInner" , al_load_bitmap("Images/fogInner.png"));
    loadBitMap("lightning" , al_load_bitmap("Images/lightning.png"));
    loadBitMap("whiteFlash" , al_load_bitmap("Images/whiteFlash.png"));
    loadBitMap("rain" , al_load_bitmap("Images/rain.png"));
    loadBitMap("moon" , al_load_bitmap("Images/moon.png"));
    loadBitMap("treasureBox1" , al_load_bitmap("Images/treasureBox1.png"));
    loadBitMap("treasureBox2" , al_load_bitmap("Images/treasureBox2.png"));
    loadBitMap("treasureBarrel" , al_load_bitmap("Images/treasureBarrel.png"));
    loadBitMap("forestBackground" , al_load_bitmap("Images/forestBackground.png"));
    loadBitMap("forestMidground" , al_load_bitmap("Images/forestMidground.png"));
    loadBitMap("forestForeground" , al_load_bitmap("Images/forestForeground.png"));
    loadBitMap("castle" , al_load_bitmap("Images/castle.png"));

    //NPCs
    loadBitMap("storeOwner" , al_load_bitmap("Images/storeOwner.png"));
    loadBitMap("npcMysteriousMan" , al_load_bitmap("Images/npcMysteriousMan.png"));
    loadBitMap("witch" , al_load_bitmap("Images/witch.png"));
    loadBitMap("strife" , al_load_bitmap("Images/strife.png"));
    loadBitMap("monk" , al_load_bitmap("Images/monk.png"));
    loadBitMap("clod" , al_load_bitmap("Images/clod.png"));
    loadBitMap("joanna" , al_load_bitmap("Images/joanna.png"));
    loadBitMap("introPlayer" , al_load_bitmap("Images/introPlayer.png"));
    loadBitMap("oldMan" , al_load_bitmap("Images/oldMan.png"));
    loadBitMap("friendlyGentleman" , al_load_bitmap("Images/friendlyGentleman.png"));
    loadBitMap("npcMysteriousMan" , al_load_bitmap("Images/npcMysteriousMan.png"));
    loadBitMap("npcHornedWarrior" , al_load_bitmap("Images/npcHornedWarrior.png"));
    loadBitMap("npcPurpleMonk" , al_load_bitmap("Images/npcPurpleMonk.png"));
    loadBitMap("npcRedVampire" , al_load_bitmap("Images/npcRedVampire.png"));
    loadBitMap("npcGreenCrownMage" , al_load_bitmap("Images/npcGreenCrownMage.png"));
    loadBitMap("npcEyepatchCat" , al_load_bitmap("Images/npcEyepatchCat.png"));
    loadBitMap("npcBlondeWarrior" , al_load_bitmap("Images/npcBlondeWarrior.png"));
    loadBitMap("npcPurpleFox" , al_load_bitmap("Images/npcPurpleFox.png"));
    loadBitMap("npcAgingArcher" , al_load_bitmap("Images/npcAgingArcher.png"));
    loadBitMap("npcTalkingSheep" , al_load_bitmap("Images/npcTalkingSheep.png"));
    loadBitMap("npcAngryCleric" , al_load_bitmap("Images/npcAngryCleric.png"));
    loadBitMap("npcOldScholar" , al_load_bitmap("Images/npcOldScholar.png"));
    loadBitMap("npcBlueDevil" , al_load_bitmap("Images/npcBlueDevil.png"));
    loadBitMap("npcBlueWarrior" , al_load_bitmap("Images/npcBlueWarrior.png"));
    loadBitMap("npcBlackMage" , al_load_bitmap("Images/npcBlackMage.png"));
    loadBitMap("npcRedQueen" , al_load_bitmap("Images/npcRedQueen.png"));
    loadBitMap("npcCloakedVoid" , al_load_bitmap("Images/npcCloakedVoid.png"));
    loadBitMap("npcShade" , al_load_bitmap("Images/npcShade.png"));
    loadBitMap("npcFirewall" , al_load_bitmap("Images/npcFirewall.png"));
    loadBitMap("npcFirewallBaby" , al_load_bitmap("Images/npcFirewallBaby.png"));
    loadBitMap("npcBlueStar" , al_load_bitmap("Images/npcBlueStar.png"));

    //Scenery
    loadBitMap("sceneryBarrel" , al_load_bitmap("Images/sceneryBarrel.png"));
    loadBitMap("sceneryGraveStone" , al_load_bitmap("Images/sceneryGraveStone.png"));
    loadBitMap("sceneryRedPeppers" , al_load_bitmap("Images/sceneryRedPeppers.png"));
    loadBitMap("scenerySpottedMushroom" , al_load_bitmap("Images/scenerySpottedMushroom.png"));

    //Attacks
    loadBitMap("swordAttack" , al_load_bitmap("Images/swordAttack.png"));

    //Thief Attacks
    loadBitMap("thiefAttackPart1" , al_load_bitmap("Images/thiefAttackPart1.png"));
    loadBitMap("thiefAttackPart2" , al_load_bitmap("Images/thiefAttackPart2.png"));
    loadBitMap("thiefPrepareStab" , al_load_bitmap("Images/thiefBackstab1.png"));
    loadBitMap("thiefPrepareStabWindUp" , al_load_bitmap("Images/thiefBackstab2.png"));
    loadBitMap("thiefStab" , al_load_bitmap("Images/thiefBackstab3.png"));
    loadBitMap("thiefKnifeBarrage1" , al_load_bitmap("Images/thiefKnifeBarrage1.png"));
    loadBitMap("thiefKnifeBarrage2" , al_load_bitmap("Images/thiefKnifeBarrage2.png"));
    loadBitMap("thiefKnifeBarrage3" , al_load_bitmap("Images/thiefKnifeBarrage3.png"));
    loadBitMap("thiefKnifeBarrage4" , al_load_bitmap("Images/thiefKnifeBarrage4.png"));
    loadBitMap("thiefKnifeBarrage5" , al_load_bitmap("Images/thiefKnifeBarrage5.png"));
    loadBitMap("thiefKnifeBarrage6" , al_load_bitmap("Images/thiefKnifeBarrage6.png"));
    loadBitMap("thiefKnifeBarrage7" , al_load_bitmap("Images/thiefKnifeBarrage7.png"));
    loadBitMap("thiefKnifeBarrage8" , al_load_bitmap("Images/thiefKnifeBarrage8.png"));
    loadBitMap("thiefMutilatingStrikes1" , al_load_bitmap("Images/thiefMutilatingStrikes1.png"));
    loadBitMap("thiefMutilatingStrikes2" , al_load_bitmap("Images/thiefMutilatingStrikes2.png"));
    loadBitMap("thiefMutilatingStrikes3" , al_load_bitmap("Images/thiefMutilatingStrikes3.png"));
    loadBitMap("thiefMutilatingStrikes4" , al_load_bitmap("Images/thiefMutilatingStrikes4.png"));
    loadBitMap("thiefMutilatingStrikes5" , al_load_bitmap("Images/thiefMutilatingStrikes5.png"));
    loadBitMap("thiefMutilatingStrikes6" , al_load_bitmap("Images/thiefMutilatingStrikes6.png"));
    loadBitMap("thiefMutilatingStrikes7" , al_load_bitmap("Images/thiefMutilatingStrikes7.png"));
    loadBitMap("thiefMutilatingStrikes8" , al_load_bitmap("Images/thiefMutilatingStrikes8.png"));
    loadBitMap("thiefMutilatingStrikes9" , al_load_bitmap("Images/thiefMutilatingStrikes9.png"));
    loadBitMap("thiefMutilatingStrikes10" , al_load_bitmap("Images/thiefMutilatingStrikes10.png"));
    loadBitMap("thiefMutilatingStrikes11" , al_load_bitmap("Images/thiefMutilatingStrikes11.png"));
    loadBitMap("thiefMutilatingStrikes12" , al_load_bitmap("Images/thiefMutilatingStrikes12.png"));
    loadBitMap("thiefMutilatingStrikes13" , al_load_bitmap("Images/thiefMutilatingStrikes13.png"));
    loadBitMap("thiefMutilatingStrikes14" , al_load_bitmap("Images/thiefMutilatingStrikes14.png"));
    loadBitMap("thiefMutilatingStrikes15" , al_load_bitmap("Images/thiefMutilatingStrikes15.png"));
    loadBitMap("thiefMutilatingStrikes16" , al_load_bitmap("Images/thiefMutilatingStrikes16.png"));
    loadBitMap("thiefMutilatingStrikes17" , al_load_bitmap("Images/thiefMutilatingStrikes17.png"));
    loadBitMap("thiefMutilatingStrikes18" , al_load_bitmap("Images/thiefMutilatingStrikes18.png"));
    loadBitMap("thiefMutilatingStrikes19" , al_load_bitmap("Images/thiefMutilatingStrikes19.png"));
    loadBitMap("thiefMutilatingStrikes20" , al_load_bitmap("Images/thiefMutilatingStrikes20.png"));

    //Mage attacks
    loadBitMap("mageAttackPart1" , al_load_bitmap("Images/mageAttackPart1.png"));
    loadBitMap("mageAttackPart2" , al_load_bitmap("Images/mageAttackPart2.png"));
    loadBitMap("magePrepareSpell" , al_load_bitmap("Images/magePrepareSpell.png"));
    loadBitMap("mageCastSpell" , al_load_bitmap("Images/mageCastSpell.png"));
    loadBitMap("fireball" , al_load_bitmap("Images/fireball.png"));
    loadBitMap("fire2" , al_load_bitmap("Images/fire2.png"));
    loadBitMap("fire3" , al_load_bitmap("Images/fire3.png"));
    loadBitMap("mageChainLightning1" , al_load_bitmap("Images/mageChainLightning1.png"));
    loadBitMap("mageChainLightning2" , al_load_bitmap("Images/mageChainLightning2.png"));
    loadBitMap("mageChainLightning3" , al_load_bitmap("Images/mageChainLightning3.png"));
    loadBitMap("mageChainLightning4" , al_load_bitmap("Images/mageChainLightning4.png"));
    loadBitMap("mageChainLightning5" , al_load_bitmap("Images/mageChainLightning5.png"));
    loadBitMap("mageChainLightning6" , al_load_bitmap("Images/mageChainLightning6.png"));
    loadBitMap("mageChainLightning7" , al_load_bitmap("Images/mageChainLightning7.png"));
    loadBitMap("mageChainLightning8" , al_load_bitmap("Images/mageChainLightning8.png"));
    loadBitMap("mageChainLightning9" , al_load_bitmap("Images/mageChainLightning9.png"));
    loadBitMap("mageChainLightning10" , al_load_bitmap("Images/mageChainLightning10.png"));
    loadBitMap("mageChainLightning11" , al_load_bitmap("Images/mageChainLightning11.png"));
    loadBitMap("mageChainLightning12" , al_load_bitmap("Images/mageChainLightning12.png"));
    loadBitMap("mageReignOfWinter1" , al_load_bitmap("Images/mageReignOfWinter1.png"));
    loadBitMap("mageReignOfWinter2" , al_load_bitmap("Images/mageReignOfWinter2.png"));
    loadBitMap("mageReignOfWinter3" , al_load_bitmap("Images/mageReignOfWinter3.png"));
    loadBitMap("mageReignOfWinter4" , al_load_bitmap("Images/mageReignOfWinter4.png"));
    loadBitMap("mageReignOfWinter5" , al_load_bitmap("Images/mageReignOfWinter5.png"));
    loadBitMap("mageReignOfWinter6" , al_load_bitmap("Images/mageReignOfWinter6.png"));
    loadBitMap("mageReignOfWinter7" , al_load_bitmap("Images/mageReignOfWinter7.png"));
    loadBitMap("mageReignOfWinter8" , al_load_bitmap("Images/mageReignOfWinter8.png"));
    loadBitMap("mageReignOfWinter9" , al_load_bitmap("Images/mageReignOfWinter9.png"));
    loadBitMap("mageReignOfWinter10" , al_load_bitmap("Images/mageReignOfWinter10.png"));
    loadBitMap("mageReignOfWinter11" , al_load_bitmap("Images/mageReignOfWinter11.png"));

    //Warrior attacks
    loadBitMap("warriorAttackPart1" , al_load_bitmap("Images/warriorAttackPart1.png"));
    loadBitMap("warriorAttackPart2" , al_load_bitmap("Images/warriorAttackPart2.png"));
    loadBitMap("warriorHeadbutt1" , al_load_bitmap("Images/warriorHeadbutt1.png"));
    loadBitMap("warriorHeadbutt2" , al_load_bitmap("Images/warriorHeadbutt2.png"));
    loadBitMap("warriorPrepareShieldBash" , al_load_bitmap("Images/warriorShieldBash1.png"));
    loadBitMap("warriorShieldBash" , al_load_bitmap("Images/warriorShieldBash2.png"));
    loadBitMap("warriorEarthShatter1" , al_load_bitmap("Images/warriorEarthShatter1.png"));
    loadBitMap("warriorEarthShatter2" , al_load_bitmap("Images/warriorEarthShatter2.png"));
    loadBitMap("warriorEarthShatter3" , al_load_bitmap("Images/warriorEarthShatter3.png"));
    loadBitMap("warriorEarthShatter4" , al_load_bitmap("Images/warriorEarthShatter4.png"));
    loadBitMap("warriorEarthShatter5" , al_load_bitmap("Images/warriorEarthShatter5.png"));
    loadBitMap("warriorEarthShatter6" , al_load_bitmap("Images/warriorEarthShatter6.png"));
    loadBitMap("warriorEarthShatter7" , al_load_bitmap("Images/warriorEarthShatter7.png"));
    loadBitMap("warriorEarthShatter8" , al_load_bitmap("Images/warriorEarthShatter8.png"));
    loadBitMap("warriorEarthShatter9" , al_load_bitmap("Images/warriorEarthShatter9.png"));

    //Lancer attacks
    loadBitMap("lancerAttackPart1" , al_load_bitmap("Images/lancerAttack1.png"));
    loadBitMap("lancerAttackPart2" , al_load_bitmap("Images/lancerAttack2.png"));
    loadBitMap("skewerPart1" , al_load_bitmap("Images/lancerSkewer1.png"));
    loadBitMap("skewerPart2" , al_load_bitmap("Images/lancerSkewer2.png"));
    loadBitMap("skewerPart3" , al_load_bitmap("Images/lancerSkewer3.png"));
    loadBitMap("playerKneel" , al_load_bitmap("Images/lancerJump1.png"));
    loadBitMap("playerJump" , al_load_bitmap("Images/lancerJump2.png"));
    loadBitMap("playerLanceDive" , al_load_bitmap("Images/lancerJump3.png"));
    loadBitMap("furyOfTheFang1" , al_load_bitmap("Images/lancerFuryOfTheFang1.png"));
    loadBitMap("furyOfTheFang2" , al_load_bitmap("Images/lancerFuryOfTheFang2.png"));
    loadBitMap("furyOfTheFang3" , al_load_bitmap("Images/lancerFuryOfTheFang3.png"));
    loadBitMap("furyOfTheFang4" , al_load_bitmap("Images/lancerFuryOfTheFang4.png"));
    loadBitMap("furyOfTheFang5" , al_load_bitmap("Images/lancerFuryOfTheFang5.png"));
    loadBitMap("furyOfTheFang6" , al_load_bitmap("Images/lancerFuryOfTheFang6.png"));
    loadBitMap("furyOfTheFang7" , al_load_bitmap("Images/lancerFuryOfTheFang7.png"));
    loadBitMap("furyOfTheFang8" , al_load_bitmap("Images/lancerFuryOfTheFang8.png"));
    loadBitMap("furyOfTheFang9" , al_load_bitmap("Images/lancerFuryOfTheFang9.png"));
    loadBitMap("furyOfTheFang10" , al_load_bitmap("Images/lancerFuryOfTheFang10.png"));

    //Healing
    loadBitMap("potionSparkleFirst" , al_load_bitmap("Images/potionSparkleFirst.png"));
    loadBitMap("potionSparkleSecond" , al_load_bitmap("Images/potionSparkleSecond.png"));
    loadBitMap("potionSparkleThird" , al_load_bitmap("Images/potionSparkleThird.png"));
    loadBitMap("potionSparkleFourth" , al_load_bitmap("Images/potionSparkleFourth.png"));

    //Enemies
    loadBitMap("Rat" , al_load_bitmap("Images/rat.png")); 
    loadBitMap("Wolf" , al_load_bitmap("Images/wolf.png")); 
    loadBitMap("Soldier" , al_load_bitmap("Images/soldier.png")); 
    loadBitMap("Ice Bull" , al_load_bitmap("Images/iceBull.png"));
    loadBitMap("Blob King" , al_load_bitmap("Images/blobKing.png"));
    loadBitMap("Guardian" , al_load_bitmap("Images/guardian.png"));
    loadBitMap("Demon" , al_load_bitmap("Images/demon.png"));
    loadBitMap("Carrot Rat" , al_load_bitmap("Images/carrotRat.png"));
    loadBitMap("Walrus" , al_load_bitmap("Images/walrus.png"));
    loadBitMap("Goo Cube" , al_load_bitmap("Images/gooCube.png"));
    loadBitMap("Ice Cube" , al_load_bitmap("Images/iceCube.png"));
    loadBitMap("Fire Cube" , al_load_bitmap("Images/fireCube.png"));
    loadBitMap("Shield Skeleton" , al_load_bitmap("Images/shieldSkeleton.png"));
    loadBitMap("Wererat" , al_load_bitmap("Images/wererat.png"));
    loadBitMap("Cactus" , al_load_bitmap("Images/cactus.png"));
    loadBitMap("Oldman Axe" , al_load_bitmap("Images/oldmanAxe.png"));
    loadBitMap("Mushroom Man" , al_load_bitmap("Images/mushroomMan.png"));
    loadBitMap("Zombie" , al_load_bitmap("Images/zombie.png"));
    loadBitMap("Baby Blob" , al_load_bitmap("Images/babyBlob.png"));
    loadBitMap("Sheep" , al_load_bitmap("Images/sheep.png"));
    loadBitMap("Kungfoo Dog" , al_load_bitmap("Images/kungfooDog.png"));
    loadBitMap("Fanged Fox" , al_load_bitmap("Images/fangedFox.png"));
    loadBitMap("Ninja Fox" , al_load_bitmap("Images/ninjaFox.png"));
    loadBitMap("Red Reaper" , al_load_bitmap("Images/redReaper.png"));
    loadBitMap("Spider" , al_load_bitmap("Images/spider.png"));
    loadBitMap("Spider Egg" , al_load_bitmap("Images/spiderEgg.png"));
    loadBitMap("Spider Web" , al_load_bitmap("Images/spiderWeb.png"));
    loadBitMap("Tentacle Mage" , al_load_bitmap("Images/tentacleMage.png"));
    loadBitMap("Echidna" , al_load_bitmap("Images/echidna.png"));
    loadBitMap("Umgar The World Destroyer" , al_load_bitmap("Images/umgarTheWorldDestroyer.png"));

    loadBitMap("default" , al_load_bitmap("Images/default.png"));

    std::map<std::string , ALLEGRO_BITMAP*>::iterator iter = images.begin();
    
    //Set the ignore color for all images.
    while(iter != images.end()){
        al_convert_mask_to_alpha(iter->second , al_map_rgb(255,0,255)); 
        iter++;
    }
}

//Retrieves a pointer to the Bitmap.
//Preconditions:    The name is a valid entry in the images map.
//Postconditions:   Returns a pointer the the value that matches the key.
//                  If the name is blank, returns NULL.
ALLEGRO_BITMAP* ImageStore::getBitMap(std::string bitMapName){

    if(bitMapName == "")
        return NULL;

    //Create iterator for testing if the element exists.
    std::map<std::string , ALLEGRO_BITMAP*>::iterator iter = images.begin();

    iter = images.find(bitMapName);

    if(iter == images.end()){

        //Element not found, return default image.
        return getBitMap("default");    
    }

    else return iter->second;
}