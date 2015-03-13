//Interface that all Events derive from. Events are loaded into lists
//and executed in FIFO order.

#pragma once

class I_Event{

private:

public:

    //Constructor.
    I_Event();

    //Destructor.
    virtual ~I_Event();

    //Used to execute all events.
    virtual bool execute() = 0;
};