#include "ImageStore.h"

//Default constructor.
ImageStore::ImageStore(){

}

//Destructor.
//Make sure no duplicate destroys in main().
ImageStore::~ImageStore(){

    std::map<std::string , ALLEGRO_BITMAP*>::iterator iter = images.begin();

    while(iter != images.end()){

        al_destroy_bitmap(iter->second);
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
    loadBitMap("swordAttack" , al_load_bitmap("swordAttack.png"));
    loadBitMap("soldier" , al_load_bitmap("soldier.png")); 
    loadBitMap("player" , al_load_bitmap("player.png")); 
    loadBitMap("rock" , al_load_bitmap("rock.png")); 
    loadBitMap("terrain" , al_load_bitmap("terrain.png")); 
    loadBitMap("town" , al_load_bitmap("town.png")); 
    loadBitMap("rat" , al_load_bitmap("rat.png")); 
    loadBitMap("wolf" , al_load_bitmap("wolf.png")); 
    loadBitMap("cloud" , al_load_bitmap("clouds.png")); 
    loadBitMap("fire1" , al_load_bitmap("fire1.png"));
    loadBitMap("fire2" , al_load_bitmap("fire2.png"));
    loadBitMap("fire3" , al_load_bitmap("fire3.png"));
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