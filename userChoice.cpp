
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
void UserChoice(int &userChoice) // IN  - User(s) desired menu choice.
{
	// VARIABLES
	bool invalid; // CALC - Main boolean for the function.
	int shift;	  // CALC - Number of spaces the error message will be
	              //        shifted.

	// MENU DO-WHILE LOOP - This loop is designed to OUTPUT the menu
	//                      choices for the user.
	do
	{
		// PROCESS
		invalid = false;

		// OUTPUT Menu
		cout << "\nStadium Finder\n";
		cout << "1 - Sort by Stadium Name\n";
		cout << "2 - Sort by Team Name\n";
		cout << "3 - Sort by Grass Type\n";
		cout << "4 - Sort by League Type\n";
		cout << "5 - Sort by Date Opened\n";
		cout << "6 - Access a Random Stadium\n";
		cout << "0 - EXIT\n";
		cout << "Enter a command (0 to exit): ";

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
			cout << "***** Please input a NUMBER between 0 and 6 "
				 <<	"*****\n\n";

			// PROCESS
			invalid = true;

		}// END OF IF STATEMENT

		// ELSE IF STATEMENT - This statement is designed to check
		//                     if the user INPUT is within the valid
		//                     range of the program. If not  will
		//                     OUTPUT error message.
		else if (userChoice < 0 || userChoice > 6)
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
			cout << "****\n";
			cout << "**** Please input a number between 0 "
				 <<	"and 6 ****\n\n";

			// PROCESS
			invalid = true;

		}// END OF ELSE IF STATEMENT

	}while (invalid); // END OF MENU DO-WHILE LOOP

}// END OF FUNCTION
