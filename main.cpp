#include "headerfile.h"
#include "stadium.h"

//right-click the project and go to "Properties"
//C/C++ Build -> Settings -> Tool Settings -> GCC C++ Compiler -> Miscellaneous -> Other Flags. Put -std=c++0x at the end
int main()
{
	int userChoice;			// IN           - User(s) menu selection
	int mainChoice;			// IN			- User(s) main menu selection
	menu userSelection; 	//                INPUT (ENUM TYPE).
	mainMenu mainSelection; //				  INPUT (ENUM TYPE).

	srand(time(0));
	//Creates a vector containing the stadium class
	vector<stadium> S;
	//Reads input into the vector
	readInput(S);

	// FUNCTION mainChoice - This function is designed to DISPLAY
	//                           the main menu to the user(s).
		UserChoice(mainChoice, 3, 6);

		// PROCESS
		mainSelection = mainMenu(mainChoice);

		// WHILE LOOP - MAIN BODY LOOP
		while (mainChoice != EXITMAIN)
		{
			// SWITCH STATEMENT -
			switch(mainSelection)
			{
				// CASE EXIT - Exit Case.
				case EXITMAIN:
						  	  break;// END OF CASE EXIT

				// CASE STADIUMNAME
				case STADIUMFINDER:
					// FUNCTION UserMenuChoice - This function is designed to DISPLAY
					//                           the menu to the user(s).
					UserChoice(userChoice, 0, 6);

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
								OutputMLG(S, 4);
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
						UserChoice(userChoice, 0, 6);

						// PROCESS
						userSelection = menu(userChoice);

					}
				//SORT function to sort the vector by stadium
								break; // END OF CASE STADIUMNAME

				// CASE TRIPPLANNER
				case TRIPPLANNER:
					// FUNCTION - TripPlanner - Method that helps the user plan their
					//							travels, destination by destination
					tripPlanner(S);
					//SORT function to sort the vector by teamName
								break; // END OF CASE TEAMNAME

				// CASE SOUVENIRSHOP
				case SOUVENIRSHOP:
					cout << "\nTO BE INCLUDED LATER!\n";
					//SORT function to sort the vector by stadium
								break; // END OF CASE GRASSTOP

				// CASE DISTANCE MEASURE
				case DISTANCEMEASURE:
					StoryTen();
								break; // END OF CASE LEAGUETYPE

				// CASE LEAGUEVISIT
				case LEAGUEVISIT:
					cout << "\nTO BE INCLUDED LATER!\n";
								break; // END OF CASE LEAGUETYPE

				// CASE ADMINLOGIN
				case ADMINLOGIN:
					cout << "\nTO BE INCLUDED LATER!\n";
								break; // END OF CASE LEAGUETYPE

				// CASE DEFAULT - Default case.
				default:
							break; // END OF CASE DEFAULT
			}// END OF SWITCH STATEMENT

			// FUNCTION mainChoice - This function is designed to DISPLAY
			//                           the main menu to the user(s).
			UserChoice(mainChoice, 3, 6);

			// PROCESS
			mainSelection = mainMenu(mainChoice);

		}
//
//	OutputMLG(S);
//	cout << S.size();
	return 0;
}
