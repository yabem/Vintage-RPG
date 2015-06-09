//The Character class has all the information for a character such as
//the bitmap and the draw location. It also stores an animation feature
//and the location to draw the character to the buffer. Default destructor,
//copy constructor, and assignment operator.

#include "Character.h"

Character::Character(){

    this->image = NULL;
    this->x = 0;
    this->y = 0;
    this->facing = UP;
    this->crFrame = 0;
    this->sequence = 0;
    this->framesPerSequence = 1;
    this->numSequence = 1;
    this->w = 0;
    this->h = 0;
    this->moveRate = 0;
    playable = false;
   
    //Initialize collisions to false.
    for(int i = 0 ; i < DIRECTIONS ; i++)
        collCheck[i] = false;

    //Set upper left.
    this->upperLeftX = x; this->upperLeftY = y;  
    
    //Set lower left.
    this->lowerLeftX = x; this->lowerLeftY = y + h;  
    
    //Set lower right.
    this->lowerRightX = x + w; this->lowerRightY = y + h; 
    
    //Set upper right.
    this->upperRightX = x + w; this->upperRightY = y; 

    abilities = "";
    menu = NULL;
    this->identifierName = "";
}

//Constructor.
Character::Character(ALLEGRO_BITMAP *image , int w , int h , 
    int framesPerSequence , int numSequence , int moveRate){

    this->image = image;
    this->x = x;
    this->y = y;
    this->facing = UP;
    this->crFrame = 0;
    this->sequence = 0;
    this->framesPerSequence = framesPerSequence;
    this->numSequence = numSequence;
    this->w = w;
    this->h = h;
    this->moveRate = moveRate;
    
    //Initialize collisions to false.
    for(int i = 0 ; i < DIRECTIONS ; i++)
        collCheck[i] = false;

    //Set upper left.
    this->upperLeftX = x; this->upperLeftY = y;  
    
    //Set lower left.
    this->lowerLeftX = x; this->lowerLeftY = y + h;  
    
    //Set lower right.
    this->lowerRightX = x + w; this->lowerRightY = y + h; 
    
    //Set upper right.
    this->upperRightX = x + w; this->upperRightY = y; 
}


//Destructor.
Character::~Character(){

}

//Return x value. 
int Character::getX() const{

    return x;
}

//Return Y value. 
int Character::getY() const{

    return y;
}

//Return width value. 
int Character::getW() const{

    return w;
}

//Return height value. 
int Character::getH() const{

    return h;
}
   
//Return upper right x value.
int Character::getUpperRightX() const{
    
    return upperRightX;
}

//Return upper right y value.
int Character::getUpperRightY() const{

    return upperRightY;
}

//Return upper left x value.
int Character::getUpperLeftX() const{

    return upperLeftX;
}

//Return upper left y value.
int Character::getUpperLeftY() const{

    return upperLeftY;
}

//Return lower right x value.
int Character::getLowerRightX() const{

    return lowerRightX;
}

//Return lower right y value.
int Character::getLowerRightY() const{

    return lowerRightY;
}

//Return lower left x value.
int Character::getLowerLeftX() const{

    return lowerLeftX;
}

//Return lower left y value.
int Character::getLowerLeftY() const{

    return lowerLeftY;
}

//Returns if the player is playable.
//Pre:  None.
//Post: Returns the value of isPlayable.
bool Character::isPlayable() const{

    return playable;
}

//Return facing direction.
int Character::getFacing() const{

    return facing;
}

//Return the collision value for the direction.
bool Character::getCollision(int index){

    if(index < 0 || index >= maxDirections)
        return false;

    else return collCheck[index];
}

//Return a pointer to the character stats.
Stats* Character::getStats(){

    return stats;
}

//Deletes the character's stats.
void Character::deleteStats(){

    if(stats != NULL)
        delete stats;
}

//Returns the current HP.
int Character::getCurrHP(){

    return stats->getCurrHP();
}

//Returns the total HP.
int Character::getTtlHP(){

    return stats->getTtlHP();
}

//Returns the attack stat for the character.
int Character::getAttack() const{

    return stats->getTtlAtk();
}

//Returns the defense stat for the character.
int Character::getDefense() const{

    return stats->getTtlDef();
}

//Adds the value to the Character's remaining hitpoints.
//Pre:  The Stat's pointer points to a valid Stats object.
//Post: The Character's Stat's object is permanently changed to
//      by adding the amount. If the Character has no more hitpoints
//      remaining the Character is now dead.
void Character::addToRemainingHP(int amount){

    if(isDead())
        return;

    else stats->addToCurrHP(amount);
}

//Adds to the Character's total XP.
void Character::addToTotalXP(int amount){

    stats->addToTtlXP(amount);
}

//Sets the pointer to the image.
//Pre:  The image must be in the .png format.
//Post: The image pointer is permanently updated.
void Character::setImage(ALLEGRO_BITMAP *image){

    this->image = image;
}

//Set x to input.
void Character::setX(int x){

    this->x = x;
}

//Set y to input.
void Character::setY(int y){

    this->y = y;
}

//Set w to input.
void Character::setW(int w){

    this->w = w;
}

//Set h to input.
void Character::setH(int h){

    this->h = h;
}

//Add value to all x coordinates
void Character::addToAllCornerX(int add){

    upperRightX += add;  
    upperLeftX += add;
    lowerLeftX += add;
    lowerRightX += add;
}

//Add value to all y coordinates
void Character::addToAllCornerY(int add){

    upperRightY += add;  
    upperLeftY += add;
    lowerLeftY += add;
    lowerRightY += add;
}

//Set facing direction.
bool Character::setFacing(int direction){

    //Check for bad input.
    if(direction < 0)// || direction >= DIRECTIONS)
        return false;

    else{
        facing = direction;
        return true;
    }
}

//Set collision index to true.
bool Character::setColl(int index){

    //Check for out of bounds.
    if(index < 0 || index >= DIRECTIONS)
        return false;

    //Change index to true.
    else{
        collCheck[index] = true;
        return true;
    }
}

//Set stats pointer to input.
void Character::setStats(Stats *stats){

    this->stats = stats;
}

//Resets the sequence.
//Pre:  None.
//Post: Makes the sequence 0.
void Character::resetSequence(){

    sequence = 0;
}

//Sets the IdentifierName.
//Pre:  None.
//Post: Permanently sets the identifierName.
void Character::setIdentifierName(std::string identifierName){

    this->identifierName = identifierName;
}

//Returns the identifierName.
//Pre:  None.
//Post: Returns the identifierName.
std::string Character::getIdentifierName(){

    return this->identifierName;
}

//Reset all collisions to false.
void Character::resetColl(){

    //Reset everything to false.
    for(int i = 0 ; i < DIRECTIONS ; i++)
        collCheck[i] = false;

}

//Recalculate corners based off of x and y values.
void Character::refreshCorners(){

    this->upperLeftX = x; 
    this->upperLeftY = y;

    this->lowerLeftX = x; 
    this->lowerLeftY = y + h; 

    this->lowerRightX = x + w; 
    this->lowerRightY = y + h; 

    this->upperRightX = x + w;
    this->upperRightY = y;
}

//Draw to buffer.
void Character::draw() const{
    
    al_draw_bitmap_region(image , 
    w * facing * 2 + (w * sequence) , 0 , //X and y draw from on bitmap.
    w , h ,                               //X and y draw to on bitmap.
    x , y , 0);                           //X and y draw to on buffer.
}

//Increase frame count.
void Character::animate(){

    //Add frame.
    crFrame++;

    //Player animation.
    if(crFrame >= framesPerSequence){

        //Adjust sequence.
        if(++sequence >= numSequence)
            sequence = 0;
      
        //Reset current frame.
        crFrame= 0;
    }
}

//Move character based off of keys.
int Character::move(bool *keys , int keyPressed){

    int result = -1;

    //Determine which key is pressed.
    switch(keyPressed){

	    case SPACE:
		    break;
	    case RIGHT:
            facing = RIGHT;
		    break;
	    case LEFT:
            facing = LEFT;
		    break;
	    case UP:
            facing = UP;
		    break;
	    case DOWN:
            facing = DOWN;
		    break;
    }

    //Calculate new position if the player is not at the right edge
    //of the screen and there is no collision.
    if(!collCheck[RIGHT] && x + w < SCREEN_W && keys[RIGHT]){
        x += keys[RIGHT] * moveRate;
        result = RIGHT;
    }    
        
    //Calculate new position if the player is not at the left edge
    //of the screen and there is no collision.
    if(!collCheck[LEFT] && x > 0 && keys[LEFT]){
        x -= keys[LEFT] * moveRate;
        result = LEFT;
    }
    
    //Calculate new position if the player is not at the upper edge
    //of the screen and there is no collision.
    if(!collCheck[UP] && y > 0 && keys[UP]){
        y -= keys[UP] * moveRate;
        result = UP;
    }
    
    //Calculate new position if the player is not at the bottom edge
    //of the screen and there is no collision.
    if(!collCheck[DOWN] && y + h < SCREEN_H && keys[DOWN]){
        y += keys[DOWN] * moveRate;
        result = DOWN;
    }

    resetColl(); //Reset collision.

    return result;  //return the key that was pressed.
}

//Returns the dead status of the Character.
bool Character::isDead(){

    return getStats()->isDead();
}

//Makes the Character Playable.
//Pre:  None.
//Post: Makes the isPlayable bool true.
void Character::makePlayable(){

    playable = true;
}

//Makes the Character dead.
//Pre:  The Stats sheet is initialized.
//Post: Makes the Character dead by changing the
//      dead status to true.
void Character::makeDead(){

    facing = DEAD;
    stats->makeDead();
}

//Makes the Character alive.
//Pre:  The Stats sheet is initialized.
//Post: Makes the Character alive by changing the dead
//      status to false.
void Character::makeAlive(){

    stats->makeAlive();
}

//Executes a random attack.
//Pre:  None.
//Post: Pulls a random attack and executes it.
void Character::executeRandomAttack(){


}

//Loads the Menu choices.
//Pre:  The string is formatted correctly.
//Post: 
void Character::loadAbilities(std::string abilities){

    this->abilities = abilities;
}

//Loads an ability,
//Pre:  The string is a valid ability.
//Post: Permanently adds the ability to abilities.
void Character::addAbility(std::string ability){

    int i = 0;
    std::string tempStr = "";

    while(this->abilities[i] != ';'){

        tempStr += abilities[i];
        i++;
    }

    this->abilities = tempStr + ("," + ability + ";");
}

//Retrieves the menuChoices.
//Pre:  None.
//Post: Returns the 
std::string Character::getAbilities(){

    return abilities;
}

//Retrieves the Menu.
//Pre: None.
//Post: Returns a pointer to the Menu.
Menu* Character::getMenu(){

    return menu;
}

//Retrieves the XP reward for killing the Character.
//Pre:  None.
//Post: Returns the XP reward from the Stats object.
int Character::getXPReward(){

    return stats->getXPRewardForSlaying();
}

//Retrieves the money reward for killing the Character.
//Pre:  None.
//Post: Returns the money reward from the Stats object.
int Character::getMoneyReward(){

    return stats->getMoneyRewardForSlaying();
}