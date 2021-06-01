#include "weapons.h"
#include "functions.h"
#include "player.h"
#include "wizard.h"
#include "warrior.h"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>


using namespace std; 


int main ()
{
    srand (int(time (0)));	// seed random number
    
	
	int playerNum, max, playerWithMax,choice; // playerType;
	vector <Player*> players;
	
	
    // displays description of game
	description();
	
    //prompts the user for how many players they would like
	playerNum = howMany();
	if (playerNum == 0)			// if they respond 0 - game over
	{
		return 0;
	}
	
    //loop that gets info for the objects in the loop
	for (int i = 0; i < playerNum; i++)
	{	
		cout << "Enter 1 to select warrior and any other number for wizard" <<endl;
		cin >> choice;
		if(choice == 1){
            Warrior* myWarrior = new Warrior();
            myWarrior->getin();
            players.push_back(myWarrior);
		}
		else{
			Wizard* myWarrior = new Wizard();
            myWarrior->getin();
            players.push_back(myWarrior);
		}		
	}
	
	cout << endl << endl;		//makes ui look better
	
    //loop that runs 25 times and modifies wizard/warrior data
	for (int i = 0; i < 25; i++)
	{
		//checks to see if the players status is true, then modifies
		for (int j = 0; j < players.size(); j++)
		{
			if ((*players[j]).getStatus() == true)
			{
                int rand = randomGenerator(0, 15);
                if (rand % 2 == 0)
                    (*players[j]) += rand;
                else
                    (*players[j]) -= rand;

               // players[j]->modify();
			}
		}
        
        // sees if the player level or the weapon level is less then 0
        //if so it chnages the player status to 0
		for (int i = 0; i < players.size(); i++)
		{	
			int p, w;
			p = (*players[i]).getLevel();
			//w = players[i]->getWeaponLevel();
            
			if (p < 0 || w < 0)
			{
				(*players[i]).setStatus(false);
			}
		}
        
        //if a player has more then 200 points player wins/game over
		for (int i = 0; i < players.size(); i++)
		{
			if ((*players[i]).getStatus() == true) 
			{
				int n;
				n = (*players[i]).getLevel();
                if (n > 200)
                {
                    cout << "The Winner is: " << endl << endl;
					
                    cout << players[i];
                    playerWithMax = i;
                    for (int i = 0; i < players.size(); i++)
                    {
                        if (i != playerWithMax)	//displays losers
                        {
                            cout << "Losers: " << endl << endl;
							cout << players[i];
                        }
                    }
                }
			}
		}
	}
    //set the max and the player with the max to 0
    max = (*players[0]).getLevel();
    playerWithMax = 0;
	
    // finds out which player has the highest score
	for (int i = 0; i < players.size(); i++)
    {
        if ((*players[i]).getLevel() > max)
        {
            max = (*players[i]).getLevel();
            playerWithMax = i;
        }	
        
    }
    
    // displays the player with the highest score
	cout << left;
	cout << setw(20) << "The Winner is:" << endl;
	players[playerWithMax]->print();
	
    //displays the losers
	if (playerNum >= 1)
	{
		cout << "Losers:" << endl << endl;
		for (int i = 0; i < players.size(); i++)
		{
			if (i != playerWithMax)
			{
				players[i]->print();
			}
		}
	}
	
	
    // End of program statements
	cout << "Please press enter once or twice to continue...";
	cin.ignore().get();    			// hold console window open
	return EXIT_SUCCESS;           	// successful termination
    
}
//  end main() *****************************************************************


//  Function Implementations ***************************************************

