//The BattleCreator class is responsible for initializing
//and running battles.
#pragma once
#include <vector>
#include <allegro5\allegro.h>
//#include <allegro5/allegro_native_dialog.h>
//#include <allegro5/allegro_primitives.h>
//#include <allegro5/allegro_ttf.h>
//#include <allegro5/allegro_font.h>
//#include <allegro5/allegro_image.h>
class Character;

class BattleCreator{

public:

    void loadEnemyModel(ALLEGRO_BITMAP *model);  //Loads all the input model.

private:

    vector<Character*> enemies; //Vector for enemies during battle.
    

}