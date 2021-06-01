#include <iostream>
#include <string>
#include <iomanip>
#include "weapons.h"
#include "player.h"

using namespace std;

// default constructor
Player::Player()
{
	weaponOne = Weapon();
	setName ("");
	setLevel(25);
	setWeaponType(1);
	setWeaponLevel(20);
	setStatus(true);	
		
}

// constructor with parameters
Player::Player(string n, int l, int wepType, int wepLevel)
{
	weaponOne = Weapon(wepType, wepLevel);
	setName (n);
	setLevel(l);
	setWeaponType(wepType);
	setWeaponLevel(wepLevel);
	setStatus(true);
}

//  Class member function implementations **************************************
//

//read in all data for player
void Player::read()
{
	string fName, lName, fullName;
	// prompt user for first namea and last name of their player
	cout << "Please enter a first name: " << endl;
	cin >> fName;
	
	// prompt the user for a last name for their player
	cout << "Please enter a last name: " << endl;
	cin >> lName;
	name = fName + " " + lName;
	
	//gets and validates player level
	cout << "Please enter a level for your player(0-200): " << endl;
	cin >> level;
	while (level < 0 || level > 200)
	{
		cout << "Invalid number, Try Again: " << endl;
		cin >> level;
	}
}


	//sets player name
void Player::setName(string n)
{
	name = n;
}

	// sets player level
void Player::setLevel(int l)
{
	level = l;
}

	//sets player weapon type
void Player::setWeaponType(int type)
{
	weaponOne.setType(type);
}

	//sets player weaon level
void Player::setWeaponLevel(int l)
{
	weaponOne.setLevel(l);
}

	// set player status
void Player::setStatus(bool s)
{
	status = s;
}

//GET METHODS#################################################

	// get player name
string Player::getName() const
{
	return name;
}

	//get player level
int Player::getLevel() const
{
	return level;
}

	//get player status
bool Player::getStatus() const
{
	return status;
}

	//get weapon type
int Player::getWeaponType() const
{
	return weaponOne.getType();
}

	//get weapon level
 int Player::getWeaponLevel() const
{
	return weaponOne.getLevel();
}


	//modify player
void Player::modify() 
{
	int randPlayer, playerLevel;
	
	//random numbers 
	randPlayer = randomGenerator(-15, 15);
	
	//player level 
	playerLevel = getLevel();

	
	//adding random number
	playerLevel += randPlayer;
	
	//sets new level
	level = playerLevel;
	weaponOne.modify();
}

	//display
void Player::display() const
{
	cout << left;
	cout << setw(20) << "Player Name:" << name << endl;
	cout << setw(20) << "Player Level:" << level << endl;
	
}









