#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "wizard.h"
#include "functions.h" 

using namespace std;

	//constructor without parameters
Wizard::Wizard()
	:Player()
{
	magic = 25;
	weaponTwo = Weapon(4,25);
}

	//constructor with parameters
Wizard::Wizard(string n, int l, int wepType, int wepLevel, int m)
	:Player(n, l, wepType, wepLevel)
{
	weaponTwo = Weapon(wepType, wepLevel);
	magic = m;
}

	//prompts user and reads in all data for wizard
void Wizard::read()
{
	int m, type, level;
	Player::read();
	cout << "Select a level for your magic(0-200): " << endl;
	cin >> m;
	while (m < 0 || m > 200)
	{
		cout << "Invalid number, Try Again: " << endl;
		cin >> m;
	}
	magic = m;
	
	cout << "Please select a weapon: " << endl
	<< "5 - Wand" << endl 
	<< "6 - Staff" << endl
	<< "7 - Fire Stick" << endl;
	cin >> type;
	while (type < 5 || type > 7)
	{
		cout << "Invalid number, Try Again: " << endl;
		cin >> type;
	}
	weaponTwo.setType(--type);
	
	cout << "Please enter a level for your weapon(0-200): " << endl;
	cin >> level;
	while (level < 0 || level > 200)
	{
		cout << "Invalid number, Try Again: " << endl;
		cin >> level;
	}
	weaponTwo.setLevel(level);
}

	//set magic
void Wizard::setPower(int m)
{
	magic = m;
}

	//set weapon
void Wizard::setWeapon(int w)
{
	weaponTwo.setType(w);
}

//get functions

	//get magic
int Wizard::getPower() const
{
	return magic;
}

	//get weapon 
int Wizard::getWeapon() const
{
	return weaponTwo.getType();
}

    //add to magic
void Wizard::operator += (const int num)
{
    int temp = getPower() + num;
    setPower(temp);
}

    //subtract form magic
void Wizard::operator -= (const int num)
{
    int temp = getPower() - num;
    setPower(temp);
}


	//modify data
void Wizard::modify()
{
    int m, playerLevel;
	
	//randomly modify the weapon level
	weaponTwo.modify();
	
	//if the magic is > 200, then add 40 to the player level
	m = getPower();
	playerLevel = getLevel();
	if (m > 200) 
	{
		setLevel(playerLevel += 40);
	}
	if (getLevel() <= 0 || getWeaponLevel() <= 0 || magic <= 0)
	{
		setStatus(false);
	}
	
}	

	//displays all data for wizard
void Wizard::display() const
{
	cout << left;
	cout << setw(20) << "Player Type:" << "Wizard" << endl;
	Player::display();
	cout << setw(20) << "Magic Level: " << magic << endl;
	weaponTwo.display();
	cout << endl;
}

void Wizard::print(){
    string choice[7] = {"Sword", "Axe", "Bow", "Knife", 
		"Wand", "Staff", "Fire Stick"};
    
    cout << left;
    cout << setw(20) << "Player Type:" << "Wizard" << endl;
    cout << setw(20) << "Wizard Name:" << this->getName() << endl;
    cout << setw(20) << "Wizard Level:" << this->getLevel() << endl;
    cout << setw(20) << "Wizard Magic:" << this->getPower() << endl;
    cout << setw(20) << "Weapon Type: " << choice[this->getWeaponType()] << endl;
    cout << setw(20) << "Weapon Level: "  << this->getWeaponLevel() << endl;
    
    
}

void Wizard::getin(){

    int level, magic, wepLevel, wepType;
    string fName, lName, name;
    cout << "Please enter a first name for your Wizard: " << endl;
    cin >> fName;
    cout << "Please enter a last name for your Wizard: " << endl;
    cin >> lName;
    name = fName + " " + lName;
    this->setName(name);
    cout << "Please enter a level for your Wizard: " << endl;
    cin >> level;
    this->setLevel(level);
    cout << "Please enter a magic level for your Wizard: " << endl;
    cin >> magic;
    this->setPower(magic);
    cout << "Please select a weapon: " << endl
	<< "5 - Wand" << endl 
	<< "6 - Staff" << endl
	<< "7 - Fire Stick" << endl;
	cin >> wepType;
	while (wepType < 5 || wepType > 7)
	{
		cout << "Invalid number, Try Again: " << endl;
		cin >> wepType;
	}
	this->setWeaponType(wepType-1);
    cout << "Please enter a weapon level: " << endl;
    cin >> wepLevel;
    this->setWeaponLevel(wepLevel);
    
}

