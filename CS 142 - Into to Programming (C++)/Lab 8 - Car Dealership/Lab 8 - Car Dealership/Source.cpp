#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Car.h"
#include "Dealership.h"
#include "Utilities.h"

/******************************************************************************************************************

TEST CASES

*******************************************************************************************************************
1:							OUTPUT: MENU
		INPUT: 2			OUTPUT: The current balance is $10000.00
									MENU
		INPUT: 3			OUTPUT: Enter the new car's details:
									Name:
		INPUT: Porsche		OUTPUT:	Color:
		INPUT: Red			OUTPUT: Price:
		INPUT: 20000		OUTPUT:	You don't have enough money to buy that car :(
									MENU
		INPUT: 3			OUTPUT: Enter the new car's details:
									Name:
		INPUT: Jetta		OUTPUT: Color: 
		INPUT: White		OUTPUT: Price:
		INPUT: 5000			OUTPUT: Jetta has been added to the inventory!
									MENU
		INPUT: 2			OUTPUT: The current balance is $5000.00
		INPUT: 1			OUTPUT: Current Inventory:
									Name: Jetta
									Color: White
									Price: $5000
									MENU
		INPUT: 4			OUTPUT: Enter the name of the car you want to sell:
		INPUT: Jetter		OUTPUT: We couldn't find a car by that name in the inventory
									MENU
		INPUT: 4			OUTPUT: Enter the name of the car you want to sell:
		INPUT: Jetta		OUTPUT: Car sold!
									MENU
		INPUT: 1			OUTPUT: Current Inventory:
									MENU
		INPUT: 2			OUTPUT: The current balance is $10000.00
		INPUT: 8			OUTPUT: Thank You!
									EXIT

*******************************************************************************************************************

2:							OUTPUT: MENU
		INPUT: 6			OUTPUT: Enter the name of the file to load:
		INPUT: cars1.txt	OUTPUT: Successfully loaded cars1.txt
									MENU
		INPUT: 2			OUTPUT: The current balance is $10529.23
									MENU
		INPUT: 1			OUTPUT: Current Inventory:
									Name: Jalopy
									Color: Blue
									Price: $3402.99
									...
									...
									MENU
		INPUT: 5			OUTPUT: Which car do you want to paint?
		INPUT: Jalopy		OUTPUT: What color do you want to paint it?
		INPUT: Red			OUTPUT: You painted your Jalopy Red.
		INPUT: 1			OUTPUT: Current Inventory:
									Name: Jalopy
									Color: Red
									Price: 3302.99
									...
									...
									MENU
		INPUT: 8			OUTPUT: Thank You!
									Exit

*******************************************************************************************************************

3:							OUTPUT: MENU
		INPUT: 3			OUTPUT: Enter the new car's details:
									Name:
		INPUT: Corvette		OUTPUT: Color:
		INPUT: Yellow		OUTPUT: Price:
		INPUT: 8995.92		OUTPUT: Corvette has been added to the inventory!
									MENU
		INPUT: 2			OUTPUT: The current balance is $1004.08
		INPUT: 7			OUTPUT: Enter a name for the new file: 
		INPUT: test.txt		OUTPUT: test.txt successfully saved!
									MENU
		FILE CONTENTS:
			1004.08
			Corvette Yellow 8995.92

		INPUT: 8			OUTPUT: Thank You!
									Exit

******************************************************************************************************************/

int main() {
	// Create a new dealership object. This object stores the inventory and balance as well as 
	// providing functions for buying, selling, loading, etc.
	Dealership dealership = Dealership();

	int menu_choice;

	do {
		// Get menu choice
		menu_choice = menu();

		// The follow variables are needed inside the switch. Since there are only 4, I chose to keep 
		// the switch statement as is since has some performance advantages and, in my opinion, looks cleaner. 
		// Had there been more variables, I would have switched to if-else statements to allow for initialization
		// of variables inside flow statements.
		string name, color, filename;
		double price;

		// Call functions based on user input
		switch (menu_choice)
		{
			
		// SHOW CURRENT INVENTORY
		case 1:
			dealership.print_inventory();
			break;

		// SHOW CURRENT BALANCE
		case 2:
			dealership.print_balance();
			break;

		// BUY A CAR
		case 3:
			cout << "Enter the new car's details:" << endl
				<< "  Name: ";
			cin.sync();
			getline(cin, name);
			cout << "  Color: ";

			getline(cin, color);
			cout << "  Price: ";
			cin >> price;
			dealership.buy_car(name, color, price);
			break;

		// SELL A CAR
		case 4:
			cout << endl << "Enter the name of the car you want to sell: ";
			cin.sync();
			getline(cin, name);
			dealership.sell_car(name);
			break;
		
		// PAINT A CAR
		case 5:
			cout << endl << "Which car do you want to paint?" << endl;
			cin.sync();
			getline(cin, name);
			dealership.paint_car(name);
			break;
		
		// LOAD FILE
		case 6:
			cout << endl << "Enter the name of the file to load: ";
			cin.sync();
			getline(cin, filename);
			dealership.load_file(filename);
			break;
		
		// SAVE FILE
		case 7:
			cout << endl << "Enter a name for the new file: ";
			cin.sync();
			getline(cin, filename);
			dealership.save_file(filename);
			break;

		// 8 exits the program
		}

	} while (menu_choice != 8);

	cout << "\nThank You!\n";

	system("pause");

	return 0;
}