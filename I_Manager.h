#pragma once
class CharacterList;
class Menu;

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

    //Used to generate players in BattleManager.
    virtual void generatePlayers(CharacterList *characterList , 
        int maxNumberPlayers);

    //Used to load a Menu in TurnTimerList.
    virtual void loadMenu(Menu *menu);
};