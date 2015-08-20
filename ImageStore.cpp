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
    loadBitMap("lancer" , al_load_bitmap("lancer.png")); 
    loadBitMap("mage" , al_load_bitmap("mage.png"));
    loadBitMap("warrior" , al_load_bitmap("warrior.png"));
    loadBitMap("thief" , al_load_bitmap("thief.png"));

    //Backgrounds
    loadBitMap("rock" , al_load_bitmap("rock.png")); 
    loadBitMap("terrain" , al_load_bitmap("terrain.png")); 
    loadBitMap("town" , al_load_bitmap("town.png")); 
    loadBitMap("cloud" , al_load_bitmap("clouds.png")); 
    loadBitMap("northernSnow" , al_load_bitmap("northernSnow.png"));
    loadBitMap("terrainForNorthernSnow" , al_load_bitmap("terrainForNorthernSnow.png"));
    loadBitMap("snowFall" , al_load_bitmap("snowFall.png"));
    loadBitMap("snowFall2" , al_load_bitmap("snowFall2.png"));
    loadBitMap("snowFall3" , al_load_bitmap("snowFall3.png"));
    loadBitMap("desertRegion" , al_load_bitmap("desertRegion.png"));
    loadBitMap("heatWave" , al_load_bitmap("heatWave.png"));
    loadBitMap("southernForest" , al_load_bitmap("southernForest.png"));
    loadBitMap("snowTerrain" , al_load_bitmap("snowTerrain.png"));
    loadBitMap("easternCastle" , al_load_bitmap("easternCastle.png"));
    loadBitMap("easternCastleTerrain" , al_load_bitmap("easternCastleTerrain.png"));
    loadBitMap("darkness" , al_load_bitmap("darkness.png"));
    loadBitMap("fog" , al_load_bitmap("fog.png"));
    loadBitMap("fogInner" , al_load_bitmap("fogInner.png"));
    loadBitMap("lightning" , al_load_bitmap("lightning.png"));
    loadBitMap("whiteFlash" , al_load_bitmap("whiteFlash.png"));
    loadBitMap("rain" , al_load_bitmap("rain.png"));
    loadBitMap("moon" , al_load_bitmap("moon.png"));
    loadBitMap("treasureBox1" , al_load_bitmap("treasureBox1.png"));
    loadBitMap("treasureBox2" , al_load_bitmap("treasureBox2.png"));
    loadBitMap("treasureBarrel" , al_load_bitmap("treasureBarrel.png"));
    loadBitMap("forestBackground" , al_load_bitmap("forestBackground.png"));
    loadBitMap("forestMidground" , al_load_bitmap("forestMidground.png"));
    loadBitMap("forestForeground" , al_load_bitmap("forestForeground.png"));
    loadBitMap("castle" , al_load_bitmap("castle.png"));

    //NPCs
    loadBitMap("storeOwner" , al_load_bitmap("storeOwner.png"));
    loadBitMap("npcMysteriousMan" , al_load_bitmap("npcMysteriousMan.png"));
    loadBitMap("witch" , al_load_bitmap("witch.png"));
    loadBitMap("strife" , al_load_bitmap("strife.png"));
    loadBitMap("monk" , al_load_bitmap("monk.png"));
    loadBitMap("clod" , al_load_bitmap("clod.png"));
    loadBitMap("joanna" , al_load_bitmap("joanna.png"));
    loadBitMap("introPlayer" , al_load_bitmap("introPlayer.png"));
    loadBitMap("oldMan" , al_load_bitmap("oldMan.png"));
    loadBitMap("friendlyGentleman" , al_load_bitmap("friendlyGentleman.png"));
    loadBitMap("npcMysteriousMan" , al_load_bitmap("npcMysteriousMan.png"));
    loadBitMap("npcHornedWarrior" , al_load_bitmap("npcHornedWarrior.png"));
    loadBitMap("npcPurpleMonk" , al_load_bitmap("npcPurpleMonk.png"));
    loadBitMap("npcRedVampire" , al_load_bitmap("npcRedVampire.png"));
    loadBitMap("npcGreenCrownMage" , al_load_bitmap("npcGreenCrownMage.png"));
    loadBitMap("npcEyepatchCat" , al_load_bitmap("npcEyepatchCat.png"));
    loadBitMap("npcBlondeWarrior" , al_load_bitmap("npcBlondeWarrior.png"));
    loadBitMap("npcPurpleFox" , al_load_bitmap("npcPurpleFox.png"));
    loadBitMap("npcAgingArcher" , al_load_bitmap("npcAgingArcher.png"));
    loadBitMap("npcTalkingSheep" , al_load_bitmap("npcTalkingSheep.png"));
    loadBitMap("npcAngryCleric" , al_load_bitmap("npcAngryCleric.png"));
    loadBitMap("npcOldScholar" , al_load_bitmap("npcOldScholar.png"));
    loadBitMap("npcBlueDevil" , al_load_bitmap("npcBlueDevil.png"));
    loadBitMap("npcBlueWarrior" , al_load_bitmap("npcBlueWarrior.png"));
    loadBitMap("npcBlackMage" , al_load_bitmap("npcBlackMage.png"));
    loadBitMap("npcRedQueen" , al_load_bitmap("npcRedQueen.png"));
    loadBitMap("npcCloakedVoid" , al_load_bitmap("npcCloakedVoid.png"));
    loadBitMap("npcShade" , al_load_bitmap("npcShade.png"));

    //Scenery
    loadBitMap("sceneryBarrel" , al_load_bitmap("sceneryBarrel.png"));
    loadBitMap("sceneryGraveStone" , al_load_bitmap("sceneryGraveStone.png"));
    loadBitMap("sceneryRedPeppers" , al_load_bitmap("sceneryRedPeppers.png"));
    loadBitMap("scenerySpottedMushroom" , al_load_bitmap("scenerySpottedMushroom.png"));

    //Attacks
    loadBitMap("swordAttack" , al_load_bitmap("swordAttack.png"));

    //Thief Attacks
    loadBitMap("thiefAttackPart1" , al_load_bitmap("thiefAttackPart1.png"));
    loadBitMap("thiefAttackPart2" , al_load_bitmap("thiefAttackPart2.png"));
    loadBitMap("thiefPrepareStab" , al_load_bitmap("thiefBackstab1.png"));
    loadBitMap("thiefPrepareStabWindUp" , al_load_bitmap("thiefBackstab2.png"));
    loadBitMap("thiefStab" , al_load_bitmap("thiefBackstab3.png"));
    loadBitMap("thiefKnifeBarrage1" , al_load_bitmap("thiefKnifeBarrage1.png"));
    loadBitMap("thiefKnifeBarrage2" , al_load_bitmap("thiefKnifeBarrage2.png"));
    loadBitMap("thiefKnifeBarrage3" , al_load_bitmap("thiefKnifeBarrage3.png"));
    loadBitMap("thiefKnifeBarrage4" , al_load_bitmap("thiefKnifeBarrage4.png"));
    loadBitMap("thiefKnifeBarrage5" , al_load_bitmap("thiefKnifeBarrage5.png"));
    loadBitMap("thiefKnifeBarrage6" , al_load_bitmap("thiefKnifeBarrage6.png"));
    loadBitMap("thiefKnifeBarrage7" , al_load_bitmap("thiefKnifeBarrage7.png"));
    loadBitMap("thiefKnifeBarrage8" , al_load_bitmap("thiefKnifeBarrage8.png"));
    loadBitMap("thiefMutilatingStrikes1" , al_load_bitmap("thiefMutilatingStrikes1.png"));
    loadBitMap("thiefMutilatingStrikes2" , al_load_bitmap("thiefMutilatingStrikes2.png"));
    loadBitMap("thiefMutilatingStrikes3" , al_load_bitmap("thiefMutilatingStrikes3.png"));
    loadBitMap("thiefMutilatingStrikes4" , al_load_bitmap("thiefMutilatingStrikes4.png"));
    loadBitMap("thiefMutilatingStrikes5" , al_load_bitmap("thiefMutilatingStrikes5.png"));
    loadBitMap("thiefMutilatingStrikes6" , al_load_bitmap("thiefMutilatingStrikes6.png"));
    loadBitMap("thiefMutilatingStrikes7" , al_load_bitmap("thiefMutilatingStrikes7.png"));
    loadBitMap("thiefMutilatingStrikes8" , al_load_bitmap("thiefMutilatingStrikes8.png"));
    loadBitMap("thiefMutilatingStrikes9" , al_load_bitmap("thiefMutilatingStrikes9.png"));
    loadBitMap("thiefMutilatingStrikes10" , al_load_bitmap("thiefMutilatingStrikes10.png"));
    loadBitMap("thiefMutilatingStrikes11" , al_load_bitmap("thiefMutilatingStrikes11.png"));
    loadBitMap("thiefMutilatingStrikes12" , al_load_bitmap("thiefMutilatingStrikes12.png"));
    loadBitMap("thiefMutilatingStrikes13" , al_load_bitmap("thiefMutilatingStrikes13.png"));
    loadBitMap("thiefMutilatingStrikes14" , al_load_bitmap("thiefMutilatingStrikes14.png"));
    loadBitMap("thiefMutilatingStrikes15" , al_load_bitmap("thiefMutilatingStrikes15.png"));
    loadBitMap("thiefMutilatingStrikes16" , al_load_bitmap("thiefMutilatingStrikes16.png"));
    loadBitMap("thiefMutilatingStrikes17" , al_load_bitmap("thiefMutilatingStrikes17.png"));
    loadBitMap("thiefMutilatingStrikes18" , al_load_bitmap("thiefMutilatingStrikes18.png"));
    loadBitMap("thiefMutilatingStrikes19" , al_load_bitmap("thiefMutilatingStrikes19.png"));
    loadBitMap("thiefMutilatingStrikes20" , al_load_bitmap("thiefMutilatingStrikes20.png"));

    //Mage attacks
    loadBitMap("mageAttackPart1" , al_load_bitmap("mageAttackPart1.png"));
    loadBitMap("mageAttackPart2" , al_load_bitmap("mageAttackPart2.png"));
    loadBitMap("magePrepareSpell" , al_load_bitmap("magePrepareSpell.png"));
    loadBitMap("mageCastSpell" , al_load_bitmap("mageCastSpell.png"));
    loadBitMap("fireball" , al_load_bitmap("fireball.png"));
    loadBitMap("fire2" , al_load_bitmap("fire2.png"));
    loadBitMap("fire3" , al_load_bitmap("fire3.png"));
    loadBitMap("mageChainLightning1" , al_load_bitmap("mageChainLightning1.png"));
    loadBitMap("mageChainLightning2" , al_load_bitmap("mageChainLightning2.png"));
    loadBitMap("mageChainLightning3" , al_load_bitmap("mageChainLightning3.png"));
    loadBitMap("mageChainLightning4" , al_load_bitmap("mageChainLightning4.png"));
    loadBitMap("mageChainLightning5" , al_load_bitmap("mageChainLightning5.png"));
    loadBitMap("mageChainLightning6" , al_load_bitmap("mageChainLightning6.png"));
    loadBitMap("mageChainLightning7" , al_load_bitmap("mageChainLightning7.png"));
    loadBitMap("mageChainLightning8" , al_load_bitmap("mageChainLightning8.png"));
    loadBitMap("mageChainLightning9" , al_load_bitmap("mageChainLightning9.png"));
    loadBitMap("mageChainLightning10" , al_load_bitmap("mageChainLightning10.png"));
    loadBitMap("mageChainLightning11" , al_load_bitmap("mageChainLightning11.png"));
    loadBitMap("mageChainLightning12" , al_load_bitmap("mageChainLightning12.png"));
    loadBitMap("mageReignOfWinter1" , al_load_bitmap("mageReignOfWinter1.png"));
    loadBitMap("mageReignOfWinter2" , al_load_bitmap("mageReignOfWinter2.png"));
    loadBitMap("mageReignOfWinter3" , al_load_bitmap("mageReignOfWinter3.png"));
    loadBitMap("mageReignOfWinter4" , al_load_bitmap("mageReignOfWinter4.png"));
    loadBitMap("mageReignOfWinter5" , al_load_bitmap("mageReignOfWinter5.png"));
    loadBitMap("mageReignOfWinter6" , al_load_bitmap("mageReignOfWinter6.png"));
    loadBitMap("mageReignOfWinter7" , al_load_bitmap("mageReignOfWinter7.png"));
    loadBitMap("mageReignOfWinter8" , al_load_bitmap("mageReignOfWinter8.png"));
    loadBitMap("mageReignOfWinter9" , al_load_bitmap("mageReignOfWinter9.png"));
    loadBitMap("mageReignOfWinter10" , al_load_bitmap("mageReignOfWinter10.png"));
    loadBitMap("mageReignOfWinter11" , al_load_bitmap("mageReignOfWinter11.png"));

    //Warrior attacks
    loadBitMap("warriorAttackPart1" , al_load_bitmap("warriorAttackPart1.png"));
    loadBitMap("warriorAttackPart2" , al_load_bitmap("warriorAttackPart2.png"));
    loadBitMap("warriorHeadbutt1" , al_load_bitmap("warriorHeadbutt1.png"));
    loadBitMap("warriorHeadbutt2" , al_load_bitmap("warriorHeadbutt2.png"));
    loadBitMap("warriorPrepareShieldBash" , al_load_bitmap("warriorShieldBash1.png"));
    loadBitMap("warriorShieldBash" , al_load_bitmap("warriorShieldBash2.png"));
    loadBitMap("warriorEarthShatter1" , al_load_bitmap("warriorEarthShatter1.png"));
    loadBitMap("warriorEarthShatter2" , al_load_bitmap("warriorEarthShatter2.png"));
    loadBitMap("warriorEarthShatter3" , al_load_bitmap("warriorEarthShatter3.png"));
    loadBitMap("warriorEarthShatter4" , al_load_bitmap("warriorEarthShatter4.png"));
    loadBitMap("warriorEarthShatter5" , al_load_bitmap("warriorEarthShatter5.png"));
    loadBitMap("warriorEarthShatter6" , al_load_bitmap("warriorEarthShatter6.png"));
    loadBitMap("warriorEarthShatter7" , al_load_bitmap("warriorEarthShatter7.png"));
    loadBitMap("warriorEarthShatter8" , al_load_bitmap("warriorEarthShatter8.png"));
    loadBitMap("warriorEarthShatter9" , al_load_bitmap("warriorEarthShatter9.png"));

    //Lancer attacks
    loadBitMap("lancerAttackPart1" , al_load_bitmap("lancerAttack1.png"));
    loadBitMap("lancerAttackPart2" , al_load_bitmap("lancerAttack2.png"));
    loadBitMap("skewerPart1" , al_load_bitmap("lancerSkewer1.png"));
    loadBitMap("skewerPart2" , al_load_bitmap("lancerSkewer2.png"));
    loadBitMap("skewerPart3" , al_load_bitmap("lancerSkewer3.png"));
    loadBitMap("playerKneel" , al_load_bitmap("lancerJump1.png"));
    loadBitMap("playerJump" , al_load_bitmap("lancerJump2.png"));
    loadBitMap("playerLanceDive" , al_load_bitmap("lancerJump3.png"));
    loadBitMap("furyOfTheFang1" , al_load_bitmap("lancerFuryOfTheFang1.png"));
    loadBitMap("furyOfTheFang2" , al_load_bitmap("lancerFuryOfTheFang2.png"));
    loadBitMap("furyOfTheFang3" , al_load_bitmap("lancerFuryOfTheFang3.png"));
    loadBitMap("furyOfTheFang4" , al_load_bitmap("lancerFuryOfTheFang4.png"));
    loadBitMap("furyOfTheFang5" , al_load_bitmap("lancerFuryOfTheFang5.png"));
    loadBitMap("furyOfTheFang6" , al_load_bitmap("lancerFuryOfTheFang6.png"));
    loadBitMap("furyOfTheFang7" , al_load_bitmap("lancerFuryOfTheFang7.png"));
    loadBitMap("furyOfTheFang8" , al_load_bitmap("lancerFuryOfTheFang8.png"));
    loadBitMap("furyOfTheFang9" , al_load_bitmap("lancerFuryOfTheFang9.png"));
    loadBitMap("furyOfTheFang10" , al_load_bitmap("lancerFuryOfTheFang10.png"));

    //Healing
    loadBitMap("potionSparkleFirst" , al_load_bitmap("potionSparkleFirst.png"));
    loadBitMap("potionSparkleSecond" , al_load_bitmap("potionSparkleSecond.png"));
    loadBitMap("potionSparkleThird" , al_load_bitmap("potionSparkleThird.png"));
    loadBitMap("potionSparkleFourth" , al_load_bitmap("potionSparkleFourth.png"));

    //Enemies
    loadBitMap("rat" , al_load_bitmap("rat.png")); 
    loadBitMap("wolf" , al_load_bitmap("wolf.png")); 
    loadBitMap("soldier" , al_load_bitmap("soldier.png")); 
    loadBitMap("iceBull" , al_load_bitmap("iceBull.png"));
    loadBitMap("blobKing" , al_load_bitmap("blobKing.png"));
    loadBitMap("guardian" , al_load_bitmap("guardian.png"));
    loadBitMap("demon" , al_load_bitmap("demon.png"));
    loadBitMap("carrotRat" , al_load_bitmap("carrotRat.png"));
    loadBitMap("walrus" , al_load_bitmap("walrus.png"));
    loadBitMap("gooCube" , al_load_bitmap("gooCube.png"));
    loadBitMap("iceCube" , al_load_bitmap("iceCube.png"));
    loadBitMap("fireCube" , al_load_bitmap("fireCube.png"));
    loadBitMap("shieldSkeleton" , al_load_bitmap("shieldSkeleton.png"));
    loadBitMap("wererat" , al_load_bitmap("wererat.png"));
    loadBitMap("cactus" , al_load_bitmap("cactus.png"));
    loadBitMap("oldmanAxe" , al_load_bitmap("oldmanAxe.png"));
    loadBitMap("mushroomMan" , al_load_bitmap("mushroomMan.png"));
    loadBitMap("zombie" , al_load_bitmap("zombie.png"));
    loadBitMap("babyBlob" , al_load_bitmap("babyBlob.png"));
    loadBitMap("sheep" , al_load_bitmap("sheep.png"));
    loadBitMap("kungfooDog" , al_load_bitmap("kungfooDog.png"));
    loadBitMap("fangedFox" , al_load_bitmap("fangedFox.png"));
    loadBitMap("ninjaFox" , al_load_bitmap("ninjaFox.png"));
    loadBitMap("redReaper" , al_load_bitmap("redReaper.png"));
    loadBitMap("spider" , al_load_bitmap("spider.png"));
    loadBitMap("spiderEgg" , al_load_bitmap("spiderEgg.png"));
    loadBitMap("spiderWeb" , al_load_bitmap("spiderWeb.png"));
    loadBitMap("tentacleMage" , al_load_bitmap("tentacleMage.png"));
    loadBitMap("echidna" , al_load_bitmap("echidna.png"));
    loadBitMap("umgarTheWorldDestroyer" , al_load_bitmap("umgarTheWorldDestroyer.png"));

    loadBitMap("default" , al_load_bitmap("default.png"));

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