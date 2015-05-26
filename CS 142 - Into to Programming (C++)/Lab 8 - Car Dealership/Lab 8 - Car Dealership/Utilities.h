#include <string>

using namespace std;

const int NOTFOUND = -1;

//---------------------------------------------------------------------------------------
/*
* get_valid_int
* 
* Gets a valid integer from the user between bounds
*
* Parameter: lower_bound
*		Lower bound for acceptable input
*
* Parameter: upper_bound
*		Upper bound for acceptable input
*
* Parameter: error_message
*		Error message to be displayed if user input is invalid
*
*/
int get_valid_int(int lower_bound, int upper_bound, string error_message);
//---------------------------------------------------------------------------------------
/*
* menu
*
* Shows the menu and asks for a menu choice
*
*/
int menu();
//---------------------------------------------------------------------------------------
