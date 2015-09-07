#include "Backpack.h"

//Constructor.
Backpack::Backpack(FontStore *fontStore){

    moneyBalance = 0;
    inventoryDisplay = NULL;
    this->fontStore = fontStore;
}

//Destructor.
Backpack::~Backpack(){

    removeAllContents();
}

int Backpack::getMoney(){

    return moneyBalance;
}

void Backpack::addMoney(int amountToAdd){

    moneyBalance += amountToAdd;
}

//Adds the item to the backpack.
//Pre:  The I_InventoryItem is valid.
//Post: If the I_InventoryItem does not exists, it is added.
//      If the I_InventoryItem already exists, the quantity is
//      added to the existing I_InventoryItem.
void Backpack::addItem(I_InventoryItem *i_InventoryItem){
    
    //Find the Reward if it exists.
    std::map<std::string , I_InventoryItem*>::iterator contentsIter =
        contents.find(i_InventoryItem->getName());
        
    //Reward does not exist in the summary so add it.
    if(contentsIter == contents.end()){

        contents.insert(std::pair<std::string , I_InventoryItem*>(
            i_InventoryItem->getName() , i_InventoryItem));

        insertItemIntoSortedContents(i_InventoryItem);
    }
        
    //Reward already exists so add the quantity.
    else {
        (*contentsIter).second->addToAmount(i_InventoryItem->getAmount());
        delete i_InventoryItem;
    }
}

//Adds the I_Inventory item into the sortedContents list in the appropriate position
//based on the item name.
//Pre:  The item does not exist in the list.
//Post: The item is added to the list where 
void Backpack::insertItemIntoSortedContents(I_InventoryItem *i_InventoryItem){

    std::vector<I_InventoryItem*>::iterator sortedContentsIter =
        sortedContents.begin();

    //List is empty, insert the item.
    if(sortedContentsIter == sortedContents.end()){

        sortedContents.push_back(i_InventoryItem);
        return;
    }

    while(sortedContentsIter != sortedContents.end()){

        //Insertitem is less than, so insert into position.
        if(i_InventoryItem->getName().compare((*sortedContentsIter)->getName()) < 0){

            sortedContents.insert(sortedContentsIter , i_InventoryItem);
            return;
        }

        else sortedContentsIter++;
    }

    //Insert into the end of the list if everything is smaller than the
    //item to insert.
    sortedContents.push_back(i_InventoryItem);
}

//Retrieves the amount of the specified item that is currently in the player's
//backpack.
//Pre:  The I_InventoryItem is valid.
//Post: If the I_InventoryItem exists the amount for that item is returned.
//      Otherwise returns 0.
int Backpack::getAmountInInventory(std::string itemName){

    //Find the item if it exists.
    std::map<std::string , I_InventoryItem*>::iterator contentsIter =
        contents.find(itemName);

    //Item does not exist, return 0.
    if(contentsIter == contents.end()){
        
        return 0;
    }

    else return contentsIter->second->getAmount();
}

//Checks the player's inventory to see if the item exists.
//Pre:  The itemName is not NULL.
//Post: Checks the inventory map to see if the item exists. Returns
//      true if the item exists otherwise returns false.
bool Backpack::itemExistsInInventory(std::string itemName){

    //Find the item if it exists.
    std::map<std::string , I_InventoryItem*>::iterator contentsIter =
        contents.find(itemName);

    //Item does not exist in the summary so add it.
    if(contentsIter == contents.end()){
        
        return false;
    }

    //Item exists.
    else return true;
}

//Removes the quantity from the item.
//Pre:  The itemName exists.
//Post: The quantity adjusted is added to the quantity. If the new quantity is over
//      the capacity, the quantity is set to the capacity and returns true.
//      If the adjusted quantity is less than 0, the amount is not removed and returns false.
//      If the adjusted quantity is > 0 and < capacity, returns true. If the item
//      does not exist, returns false.
bool Backpack::adjustItemQuantity(std::string itemName , int quantityToAdjust){

    //Find the itemName if it exists.
    std::map<std::string , I_InventoryItem*>::iterator contentsIter =
        contents.find(itemName);
        
    //Item does not exist.
    if(contentsIter == contents.end()){
        return false;
    }
        
    //Reward already exists so add the quantity.
    else {

        return (*contentsIter).second->addToAmount(quantityToAdjust);
    }
}

//Removes all the contents of the backpack.
//Pre:  None.
//Post: Cycles through each item in the backpack and deletes contents.
void Backpack::removeAllContents(){

    //Find the item if it exists.
    std::map<std::string , I_InventoryItem*>::iterator contentsIter;

    for(contentsIter = contents.begin() ;
        contentsIter != contents.end() ;
        contentsIter++){

            delete contentsIter->second;
            contentsIter->second = NULL;
    }
}

//Recreates the inventory display from the items in inventory.
//Pre:  None.
//Post: Permanently updates the inventoryDisplay.
void Backpack::updateInventoryDisplay(){

    //Delete existing display.
    delete inventoryDisplay;

    std::string currentInventory = 
        "---------------------------Inventory----------------------------,";

    currentInventory += "Gold: ";
    currentInventory += Conversion::convertIntToString(getMoney());
    currentInventory += ",";

    //Find the item if it exists.
    std::vector<I_InventoryItem*>::iterator contentsIter;

    for(contentsIter = sortedContents.begin() ;
        contentsIter != sortedContents.end() ;
        contentsIter++){

            currentInventory += (*contentsIter)->getName();
            currentInventory += " x";
            currentInventory += Conversion::convertIntToString(
                (*contentsIter)->getAmount());

            //Check if there's another element.
            if(contentsIter + 1 != sortedContents.end()){
                currentInventory += ",";
            }
    }

    currentInventory += ";";

    InfoTable *inventoryDisplay = new InfoTable(currentInventory ,
        fontStore->getFont("default"));
    inventoryDisplay->formatText();
    this->inventoryDisplay = inventoryDisplay;
    centerInventoryDisplayToScreen();
}

//Moves the inventoryDisplay to the middle of the screen.
//Pre:  None.
//Post: Gets the difference in width between the inventoryDisplay and the screen 
//      width. Divides that by two, then adds it to the start position of
//      the inventoryDisplay.
void Backpack::centerInventoryDisplayToScreen(){

    int totalWidthOfInfoTable = 
        inventoryDisplay->getDX() - inventoryDisplay->getSX();
    int amountToAddToInfoTableToCenter = 
        (SCREEN_W - totalWidthOfInfoTable) / 2;

    inventoryDisplay->setSX(amountToAddToInfoTableToCenter);
    inventoryDisplay->calculateMenuEndCoordinates();
    inventoryDisplay->calculateSelectorCoords();
}

//Displays the player's inventory.
//Pre:  The Backpack is valid.
//Post: Displays all the items with current inventory and max capacity.
void Backpack::displayInventory(){

    inventoryDisplay->draw();
}