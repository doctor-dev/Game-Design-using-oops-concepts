#define WARRIOR_H


#include "player.h"

// Wizard class
class Warrior : public Player 
{
	
	public :
	
	//default constructor
	Warrior();
	
	//construstor with paramaters
	Warrior(string n, int l, int wepType, int wepLevel, int s);
	
	virtual void read();
	
	// set functions
	//set strenght
	virtual void setPower(int s);
	
	//set weapon
	void setWeapon(int w);
	
	//get functions
	
	//get magic
	virtual int getPower() const;
	
	//get weapon 
	int getWeapon() const;
	
	// modify data
	virtual void modify();
    
    //overloaded opperators
    
    //add to strenght
    void operator += (const int num);
    
    //subtract from strenght
    void operator -= (const int num);
    
	
	// display the player/wizard/weapon data
	virtual void display() const;	

	virtual void print() override;

	virtual void getin() override;
	
	private : 
	
	int strenght;
	Weapon weaponTwo;
	
};




















