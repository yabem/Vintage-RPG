#pragma once
class CharacterList;

class I_Manager{

private:

public:

    virtual ~I_Manager();
    virtual void switchVariablesToMap();
    virtual void saveAreaMapVariables();
    virtual CharacterList* getList() = 0;

    virtual void generatePlayers(CharacterList *characterList , 
        int maxNumberPlayers);
};