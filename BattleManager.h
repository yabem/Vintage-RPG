//Stores all the information about the battle including players,
//enemies, and variables.

#pragma once
#include "Cursor.h"
#include "Character.h"

class BattleManager{

private:
    
    enum turnTypes{NONE , PLAYER , ENEMY};
    int currentTarget;   //The enemies' or players' turn.
    Cursor *battleCursor;
    
public:
    
    //Default constructor.
    BattleManager();

    //Destructor.
    ~BattleManager();

    //Switches the turnToAct to the specified type.
    void changeTarget(int currentTarget);

    //Loads a cursor.
    void loadCursor(Cursor *cursor);

    //Draws cursor.
    void drawCursor() const;

    //Adjust cursor to target.
    void moveCursorToTarget(Character *character);

    //Changes currentTarget to enemies.
    void targetEnemies();

    //Changes currentTarget to Players.
    void targetPlayers();

    //Return current target.
    int getCurrentTarget();

    //Determines if the current target is the enemies.
    bool targettingEnemies();
};