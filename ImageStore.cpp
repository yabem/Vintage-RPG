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
    loadBitMap("player" , al_load_bitmap("player.png")); 
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

    //NPCs
    loadBitMap("storeOwner" , al_load_bitmap("storeOwner.png"));
    loadBitMap("mysteriousMan" , al_load_bitmap("mysteriousMan.png"));
    loadBitMap("witch" , al_load_bitmap("witch.png"));
    loadBitMap("strife" , al_load_bitmap("strife.png"));
    loadBitMap("monk" , al_load_bitmap("monk.png"));
    loadBitMap("clod" , al_load_bitmap("clod.png"));
    loadBitMap("joanna" , al_load_bitmap("joanna.png"));
    loadBitMap("introPlayer" , al_load_bitmap("introPlayer.png"));
    loadBitMap("playerLookalike" , al_load_bitmap("playerLookalike.png"));
    loadBitMap("oldMan" , al_load_bitmap("oldMan.png"));
    loadBitMap("friendlyGentleman" , al_load_bitmap("friendlyGentleman.png"));

    //Attacks
    loadBitMap("swordAttack" , al_load_bitmap("swordAttack.png"));
    loadBitMap("fireball" , al_load_bitmap("fireball.png"));
    loadBitMap("fire2" , al_load_bitmap("fire2.png"));
    loadBitMap("fire3" , al_load_bitmap("fire3.png"));
    loadBitMap("playerKneel" , al_load_bitmap("playerKneel.png"));
    loadBitMap("playerJump" , al_load_bitmap("playerJump.png"));
    loadBitMap("playerLanceDive" , al_load_bitmap("playerLanceDive.png"));
    loadBitMap("magePrepareSpell" , al_load_bitmap("magePrepareSpell.png"));
    loadBitMap("mageCastSpell" , al_load_bitmap("mageCastSpell.png"));
    loadBitMap("thiefPrepareStab" , al_load_bitmap("thiefPrepareStab.png"));
    loadBitMap("thiefPrepareStabWindUp" , al_load_bitmap("thiefPrepareStabWindUp.png"));
    loadBitMap("thiefStab" , al_load_bitmap("thiefStab.png"));
    loadBitMap("warriorPrepareShieldBash" , al_load_bitmap("warriorPrepareShieldBash.png"));
    loadBitMap("warriorShieldBash" , al_load_bitmap("warriorShieldBash.png"));
    loadBitMap("lancerAttackPart1" , al_load_bitmap("lancerAttackPart1.png"));
    loadBitMap("lancerAttackPart2" , al_load_bitmap("lancerAttackPart2.png"));
    loadBitMap("mageAttackPart1" , al_load_bitmap("mageAttackPart1.png"));
    loadBitMap("mageAttackPart2" , al_load_bitmap("mageAttackPart2.png"));
    loadBitMap("thiefAttackPart1" , al_load_bitmap("thiefAttackPart1.png"));
    loadBitMap("thiefAttackPart2" , al_load_bitmap("thiefAttackPart2.png"));
    loadBitMap("warriorAttackPart1" , al_load_bitmap("warriorAttackPart1.png"));
    loadBitMap("warriorAttackPart2" , al_load_bitmap("warriorAttackPart2.png"));
    loadBitMap("skewerPart1" , al_load_bitmap("skewerPart1.png"));
    loadBitMap("skewerPart2" , al_load_bitmap("skewerPart2.png"));
    loadBitMap("skewerPart3" , al_load_bitmap("skewerPart3.png"));
    loadBitMap("furyOfTheFang1" , al_load_bitmap("furyOfTheFang1.png"));
    loadBitMap("furyOfTheFang2" , al_load_bitmap("furyOfTheFang2.png"));
    loadBitMap("furyOfTheFang3" , al_load_bitmap("furyOfTheFang3.png"));
    loadBitMap("furyOfTheFang4" , al_load_bitmap("furyOfTheFang4.png"));
    loadBitMap("furyOfTheFang5" , al_load_bitmap("furyOfTheFang5.png"));
    loadBitMap("furyOfTheFang6" , al_load_bitmap("furyOfTheFang6.png"));
    loadBitMap("furyOfTheFang7" , al_load_bitmap("furyOfTheFang7.png"));
    loadBitMap("furyOfTheFang8" , al_load_bitmap("furyOfTheFang8.png"));
    loadBitMap("furyOfTheFang9" , al_load_bitmap("furyOfTheFang9.png"));
    loadBitMap("furyOfTheFang10" , al_load_bitmap("furyOfTheFang10.png"));

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