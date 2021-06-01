#ifndef WIZZARD_H
#define WIZZARD_H


#include "player.h"

// Wizard class
class Wizard : public Player 
{

public :
	
	//default constructor
	Wizard();
	
	//constructor with parameters
	Wizard(string n, int l, int wepType, int wepLevel, int m);
	
	// read in all data
	virtual void read();
	
	// modify data
	virtual void modify();
	
	// set functions
	
	//get magic
	virtual void setPower(int m);
	
	//set weapon
	void setWeapon(int w);
	
	//get functions
	
	//get magic
	virtual int getPower() const;
	
	//get weapon 
	int getWeapon() const;
    
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
	
	int magic;
	Weapon weaponTwo;
	
};




#endif


