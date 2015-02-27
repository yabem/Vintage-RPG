#include "Character.h"
#include "CharStats.h"

namespace InitEnemies{

    
    //Initialize character based off of the level and type or enemy.
    void init(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);

    //Create the enemy.
    void rat(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void wolf(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);
    void soldier(Character *character , int enemyType , int level , 
        vector<ALLEGRO_BITMAP*> enemies);

    //Set the spacing so the enemies are drawn correctly on the screen.
    void initEnemiesSpacing(vector<Character*> theEnemies);
    
};