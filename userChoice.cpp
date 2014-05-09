#include "headerfile.h"

/*************************************************************************
* FUNCTION UserChoice
*-------------------------------------------------------------------------
* 	This function is designed to display and grab the menu choice from
* 	the user(s).
*-------------------------------------------------------------------------
* 	PRE-CONDITIONS
*
* 	    userChoice : Has to be pre-initialized in main.cpp
*
* 	POST-CONDITIONS
*
*		Necessary data is OUTPUT to console and returned to main.cpp.
*************************************************************************/
void UserChoice(int &userChoice, int menuType, int maxChoice) // IN  - User(s) desired menu choice.
{
	// VARIABLES
	bool invalid;		// CALC - Main boolean for the function.
	int shift;	  		// CALC - Number of spaces the error message will be
						//        shifted.
	string stadiumMenu; // OUT  - Menu being output to the user
	string grassSub;	// OUT  - Grass Type Submenu
	string leagueSub;   // OUT  - League Type Submenu
	string mainMenu;	// OUT  - Main Menu of the Program

	// INITIALIZE
	stadiumMenu = { "\nStadium Finder\n"
				"1 - Sort by Stadium Name\n"
				"2 - Sort by Team Name\n"
				"3 - Sort by Playing Surface\n"
				"4 - Sort by League Type\n"
				"5 - Sort by Date Opened\n"
				"6 - Access a Random Stadium\n"
				"0 - BACK\n"
				"Enter a command (0 to Return to Previous Menu): "};

	grassSub = { "\nSort by Playing Surface\n"
				"1 - View Stadiums with Grass Surface\n"
				"2 - View Stadiums with Astroturf Surface\n"
				"0 - BACK\n"
				"Enter a command (0 to Return to Previous Menu): "};

	leagueSub = { "\nSort by League Type\n"
				"1 - View National League Stadiums\n"
				"2 - View American League Stadiums\n"
				"0 - BACK\n"
				"Enter a command (0 to Return to Previous Menu): "};

	mainMenu = { "\nMain Menu\n"
				"1 - Stadium Finder\n"
				"2 - Trip Planner\n"
				"3 - Souvenir Shop\n"
				"4 - Distance Measure\n"
				"5 - Visit a League\n"
				"6 - Admin Login\n"
				"0 - EXIT\n"
				"Enter a command (0 to exit): "};

	// MENU DO-WHILE LOOP - This loop is designed to OUTPUT the menu
	//                      choices for the user.
	do
	{
		// PROCESS
		invalid = false;

		if(menuType == 0)
		{
			// OUTPUT Menu
			cout << stadiumMenu;
		}
		else if(menuType == 1)
		{
			cout << grassSub;
		}
		else if(menuType == 2)
		{
			cout << leagueSub;
		}
		else if(menuType == 3)
		{
			cout << mainMenu;
		}

		// IF STATEMENT - This statement is designed to check the
		//                user INPUT is a character and OUTPUT an
		//                error code.
		if (!(cin >> userChoice))
		{
			// Clears the INPUT buffer.
			cin.clear();
			// Checks the max string size.
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << endl;

				cout << "\n***** Please input a NUMBER between 0 and ";
				cout << maxChoice;
				cout <<	"*****\n\n";



			// PROCESS
			invalid = true;

		}// END OF IF STATEMENT

		// ELSE IF STATEMENT - This statement is designed to check
		//                     if the user INPUT is within the valid
		//                     range of the program. If not  will
		//                     OUTPUT error message.
		else if (userChoice < 0 || userChoice > maxChoice)
		{
			// MOD - Determines the correct spacing for user INPUT.
			shift = Spacing(userChoice);
			cout << left;
			cout << "\n**** The number ";

			// IF STATEMENT - This selection statement is designed to
			//                OUTPUT the correct spacing depending
			//                on user INPUT.
			if(userChoice < 0)
			{
				// MOD
				cout << setw(shift + 2);
				cout << userChoice << " is an invalid entry";
				cout << right;
				cout << setw(12 - (shift +2));
			}
			else
			{
				// MOD
				cout << setw(shift + 1);
				cout << userChoice << " is an invalid entry";
				cout << right;
				cout << setw(12 - (shift +1));
			}

			// OUTPUT
			cout << "\n***** Please input a NUMBER between 0 and ";
			cout << maxChoice;
			cout <<	"*****\n\n";

			// PROCESS
			invalid = true;

		}// END OF ELSE IF STATEMENT

	}while (invalid); // END OF MENU DO-WHILE LOOP

}// END OF FUNCTION
