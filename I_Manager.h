#pragma once

#include <stdio.h>
class CharacterList;
class Menu;
class CharacterManipulationStore;
class DrawRepository;
class I_Event;
class Character;
class I_Reward;
class Backpack;
class I_List;

class I_Manager{

private:

public:

    virtual ~I_Manager();

    //Used to switch variables in GameManager.
    virtual void switchVariablesToMap();

    //Used to save variables in GameManager.
    virtual void saveAreaMapVariables();
    
    //Used to pause the battle in TurnTimerList.
    virtual void pauseBattle();     

    //Used to unpause the battle in TurnTimerList.
    virtual void unPauseBattle();   

    //Used to determine battle state in TurnTimerList.
    virtual bool battlePaused();

    //Used to get list.
    virtual CharacterList* getList() = 0;

    //Used in TurnTimerList to move the Character to the correct position.
    virtual void setCurrPlayer(int position);

    //Used in TurnTimerList to move the Character to the correct position.
    virtual void setCurrEnemy(int position);

    //Used to generate players in BattleManager.
    virtual void generatePlayers(CharacterList *characterList , 
        int maxNumberPlayers);

    //Used to load a Menu in TurnTimerList.
    virtual void loadMenu(Menu *menu);

    //Used to load an I_Event for the TurnTimerList.
    virtual void loadEvent(I_Event *i_Event);

    //Used for the AI.
    virtual CharacterManipulationStore* getCharManipStore();

    //Used for AI.
    virtual DrawRepository* getDrawRepository();

    //Returns the enemies list.
    virtual CharacterList* getEnemiesList();

    //Returns the players list.
    virtual I_List* getPlayersList();

    //Used for PlayerEvent.
    virtual bool emptyMenus();

    //Gets the currently selected enemy.
    virtual Character* getCurrEnemy();

    //Returns the pressedKey
    virtual int getPressedKey() const;

    //Sets the pressed key to unused.
    virtual void setPressedKeyToInactive();

    //Sets the gameloop to end.
    virtual void setEndOfGameLoopToEnd();

    //Used for enemyTurn.
    virtual void deleteCurrEnemy();

    //Loads a Reward to the TreasureBox.
    virtual void loadReward(I_Reward *i_Reward);

    //Load backpack.
    virtual void loadBackpack(Backpack *backpack);

    //Get backpack.
    virtual Backpack* getBackpack();
};