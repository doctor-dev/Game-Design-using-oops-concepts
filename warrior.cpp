#include <iostream>
#include <string>
#include <iomanip>
#include "warrior.h"
#include "functions.h"

using namespace std;

Warrior::Warrior()
	:Player()
{
	strenght = 25;
	weaponTwo = Weapon(0,25);
}

Warrior::Warrior(string n, int l, int wepType, int wepLevel, int s)
	:Player(n, l, wepType, wepLevel)
{
	weaponTwo = Weapon(wepType, wepLevel);
	strenght = s;
}


// read function, reads in all data for a warrior object
void Warrior::read()
{
	int s, type, level;
	Player::read();
	cout << "Select a level for your strenght(0-200): " << endl;
	cin >> s;
	while (s < 0 || s > 200)
	{
		cout << "Invalid number, Try Again: " << endl;
		cin >> s;
	}
	strenght = s;
	
	cout << "Please select a weapon: " << endl
	<< "1 - Sword" << endl 
	<< "2 - Axe" << endl
	<< "3 - Bow" << endl
	<< "4 - Knife" << endl;
	cin >> type;
	while (type < 1 || type > 4)
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

//set strenght
void Warrior::setPower(int s)
{
	strenght = s;
}

//set weapon
void Warrior::setWeapon(int w)
{
	weaponTwo.setType(w);
}


//get functions

//get strenght
int Warrior::getPower() const
{
	return strenght;
}

//get weapon 
int Warrior::getWeapon() const
{
	return weaponTwo.getType();
}

//modify data
void Warrior::modify()
{
	int s; //randStrenght, 
    int playerLevel;
	Player::modify();
	
		//random numbers 
	//randStrenght = randomGenerator(-15, 15);
	
		//strenght level 
	//s = getPower();
	
	
		//adding random number to strenght level
	//s += randStrenght;
	
		//sets new strenght level
	//strenght = s;
	weaponTwo.modify();
	
		//if the strenght is > 200 add 40 to the player level
	s = getPower();
	playerLevel = getLevel();
	if (s > 200) 
	{
		setLevel(playerLevel += 40);
	}
	if (getLevel() <= 0 || getWeaponLevel() <= 0 || strenght <= 0)
	{
		setStatus(false);
	}
}	

    //add to strenght
void Warrior::operator += (const int num)
{
    int temp = getPower() + num;
    setPower(temp);
}

    //subtract form strenght
void Warrior::operator -= (const int num)
{
    int temp = getPower() - num;
    setPower(temp);
}

	//display function
void Warrior::display() const
{
	cout << left;
	cout << setw(20) << "Player Type:" << "Warrior" << endl;
	Player::display();
	cout << setw(20) << "Strength Level:" << strenght << endl;
	weaponTwo.display();
	cout << endl;
}

void Warrior::getin(){
	int level, strenght, wepLevel, wepType;
    string fName, lName, name;
    cout << "Please enter a first name for your Warrior: " << endl;
    cin >> fName;
    cout << "Please enter a last name for your Warrior: " << endl;
    cin >> lName;
    name = fName + " " + lName;
    this->setName(name);
    cout << "Please enter a level for your Warrior: " << endl;
    cin >> level;
    this->setLevel(level);
    cout << "Please enter a strenght level for your Warrior: " << endl;
    cin >> strenght;
    this->setPower(strenght);
	cout << "Please select a weapon: " << endl
	<< "1 - Sword" << endl 
	<< "2 - Axe" << endl
	<< "3 - Bow" << endl
	<< "4 - Knife" << endl;
	cin >> wepType;
	while (wepType < 1 || wepType > 4)
	{
		cout << "Invalid number, Try Again: " << endl;
		cin >> wepType;
	}
	this->setWeaponType(wepType-1);
    cout << "Please enter a weapon level: " << endl;
    cin >> wepLevel;
    this->setWeaponLevel(wepLevel);
	}

void Warrior::print(){
    string choice[7] = {"Sword", "Axe", "Bow", "Knife", 
		"Wand", "Staff", "Fire Stick"};
    
    cout << left;
    cout << setw(20) << "Player Type:" << "Warrior" << endl;
    cout << setw(20) << "Warrior Name:" << this->getName() << endl;
    cout << setw(20) << "Warrior Level:" << this->getLevel() << endl;
    cout << setw(20) << "Warrior Strength:" << this->getPower() << endl;
    cout << setw(20) << "Weapon Type: " << choice[this->getWeaponType()] << endl;
    cout << setw(20) << "Weapon Level: "  << this->getWeaponLevel() << endl;
    
	};


