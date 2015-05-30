#include <iostream>
#include <vector>

using namespace std;

#include "utils.h"
#include "Player.h"

/*************************************************************************

TEST CASES

1.							OUTPUT: MENU
		INPUT: 2			OUTPUT: Please enter a name for the new player:
		INPUT: Andy			OUTPUT: Andy was successfully added!
									MENU
		INPUT: 2			OUTPUT: Please enter a name for the new player:
		INPUT: Haylee		OUTPUT: Haylee was successfully added!
									MENU
		INPUT: 3			OUTPUT: Which player would you like to add to the queue?
		INPUT: Andy			OUTPUT: Andy was successfully added to the queue!
									MENU
		INPUT: 3			OUTPUT: Which player would you like to add to the queue?
		INPUT: Haylee		OUTPUT: Haylee was successfully added to the queue!
									MENU
		INPUT: 3			OUTPUT: Which player would you like to add to the queue?
		INPUT: Andy			OUTPUT: Andy was successfully added to the queue!
									MENU
		INPUT: 3			OUTPUT: Which player would you like to add to the queue?
		INPUT: Haylee		OUTPUT: Haylee was successfully added to the queue!
									MENU
		INPUT: 3			OUTPUT: Which player would you like to add to the queue?
		INPUT: Andy			OUTPUT: Andy was successfully added to the queue!
									MENU
		INPUT: 3			OUTPUT: Which player would you like to add to the queue?
		INPUT: Haylee		OUTPUT: Haylee was successfully added to the queue!
									MENU
		INPUT: 5			OUTPUT: Fight...Draw
									MENU
		INPUT: 5			OUTPUT: Fight...Draw
									MENU
		INPUT: 5			OUTPUT: Fight...Andy Wins!
									MENU
		INPUT: 1			OUTPUT: NAME: Andy
									WINS: 1
									LOSSES: 0
									DRAWS: 2
									WIN PCT: 0.33

									NAME: Haylee
									WINS: 0
									LOSSES: 1
									DRAWS: 2
									WIN PCT: 0
		INPUT: 6			OUTPUT: Exit

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

2.							OUTPUT: MENU
		INPUT: 2			OUTPUT: Please enter a name for the new player:
		INPUT: The Hammer	OUTPUT: The Hammer was successfully added!
									MENU
		INPUT: 2			OUTPUT: Please enter a name for the new player:
		INPUT: The Hammer	OUTPUT: A player by that name already exists
		INPUT: 3			OUTPUT: Which player would you like to add to the queue?
		INPUT: The Hammer	OUTPUT: The Hammer was successfully added to the queue!
									MENU
		INPUT: 3			OUTPUT: Which player would you like to add to the queue?
		INPUT: The Hammer	OUTPUT: The Hammer was successfully added to the queue!
									MENU
		INPUT: 4			OUTPUT: The following players are in the queue:
										The Hammer
										The Hammer
		INPUT: 6			OUTPUT: Exit

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

3.							OUTPUT: MENU
		INPUT: 3			OUTPUT: Which player would you like to add to the queue?
		INPUT: Andy			OUTPUT: We couldn't find any players by that name.
		INPUT: 6			OUTPUT: Exit


**************************************************************************/


// TODO
// Check over requirements one more time

int main() {
	// Set up vectors. One for players, one for the game queue.
	vector<Player*> players;
	vector<Player*> queue;

	int menu_choice;

	do {
		// Get the user's menu choice
		menu_choice = menu();

		// 1 - Show Players - This will show all of the players in the game 
		// (this is everyone in the vector of pointers to all players).  
		// This should show their names, their wins, losses, and draws, and 
		// their winning record as a percentage.
		if (menu_choice == 1) {
			showPlayers(players);
		} 

		// 2 - Add Player - This will prompt the user for the name of a new player, 
		// then create a Player* for that player and add it to the vector of all players. 
		// Each name may occur only once.  Names with multiple words (separated by spaces) 
		// must be allowed. You must report whether the player has been added or if the name already exists.
		else if (menu_choice == 2) {
			string name = "";
			cout << endl << "Please enter a name for the new player: ";
			cin.sync();
			getline(cin, name);
			addPlayer(players, name);
		}


		// 3 - Add To Line-up - This will prompt the user for a name.  
		// You must verify that this Player is pointed to in the vector that points to all players.  
		// If so, you will add a * (pointer) to the same Player in the vector of players waiting to compete.
		else if (menu_choice == 3) {
			string name;
			cout << endl << "Which player would you like to add to the queue? ";
			cin.sync();
			getline(cin, name);
			addToQueue(players, queue, name);
		}


		// 4 - Show Line-up - This will show all of the players waiting to compete
		else if (menu_choice == 4) {
			cout << endl << "The following players are in the queue:" << endl;
			for (int i = 0; i < queue.size(); i++) {
				cout << "  " << queue[i]->get_name() << endl;
			}
		}


		// 5 - Fight - This will take the first two players pointed to in the vector of players 
		// waiting to compete (the two that have been waiting the longest) and will have them compete. 
		// Fighting instructions are found below in Part 4. 
		// (This section does not need to be implemented until part 4.)
		else if (menu_choice == 5) {
			fight(queue);
		}
	} while (menu_choice != 6); // 6 - Quit


	cout << "\nThanks for playing!\n\n";
	system("pause()");
	return 0;
}