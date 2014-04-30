#include "headerfile.h"
#include "stadium.h"

//right-click the project and go to "Properties"
//C/C++ Build -> Settings -> Tool Settings -> GCC C++ Compiler -> Miscellaneous -> Other Flags. Put -std=c++0x at the end
int main()
{
	int userChoice;
	menu  userSelection; 		// IN           - User(s) menu selection
								//                INPUT (ENUM TYPE).

	srand(time(0));
	//Creates a vector containing the stadium class
	vector<stadium> S;
	//Reads input into the vector
	readInput(S);

	// FUNCTION UserMenuChoice - This function is designed to DISPLAY
	//                           the menu to the user(s).
	UserChoice(userChoice);

	// PROCESS
	userSelection = menu(userChoice);

	// WHILE LOOP - MAIN BODY LOOP
	while (userChoice != EXIT)
	{
		// SWITCH STATEMENT -
		switch(userSelection)
		{
			// CASE EXIT - Exit Case.
			case EXIT:
					  	  break;// END OF CASE EXIT

			// CASE STADIUMNAME
			case STADIUMNAME:
			//SORT function to sort the vector by stadium
				OutputMLG(S, 0);
							break; // END OF CASE STADIUMNAME


			// CASE TEAMNAME
			case TEAMNAME:
				//SORT function to sort the vector by teamName
				OutputMLG(S, 1);
							break; // END OF CASE TEAMNAME

			// CASE GRASSTOP
			case GRASSTOP:
				//SORT function to sort the vector by stadium
				OutputMLG(S, 2);
							break; // END OF CASE GRASSTOP

			// CASE LEAGUETYPE
			case LEAGUETYPE:

							break; // END OF CASE LEAGUETYPE

			// CASE LEAGUETYPE
			case DATEOFCREATION:
				OutputMLG(S, 3);
							break; // END OF CASE LEAGUETYPE


			// CASE RANDOMSTADIUM
			case RANDOMSTADIUM:
							randomStadium(S);
							break; // END OF CASE RANDOMSTADIUM

			// CASE DEFAULT - Default case.
			default:
						break; // END OF CASE DEFAULT
		}// END OF SWITCH STATEMENT

		// FUNCTION UserChoice - This function is designed to display
		//                       and grab the menu choice from the user(s).
		UserChoice(userChoice);

		// PROCESS
		userSelection = menu(userChoice);

	}


//
//	OutputMLG(S);
//	cout << S.size();
	return 0;
}
