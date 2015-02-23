//An interface that holds a list of objects.

#pragma once

class IList{

private:

public:

    IList();
    virtual ~IList();
    virtual bool deleteSelection(int position);
    virtual void deleteList();
};