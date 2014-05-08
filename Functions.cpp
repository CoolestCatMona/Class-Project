#include "headerfile.h"
#include "stadium.h"



//FUNCTION - reads input from designated input file and stores it
//in a vector of classes
void readInput(std::vector<stadium> &Stadiums)
{
	ifstream file;				//IN - Input File
	file.open("IFile.txt");		//CALC - Opens input file
	string string;				//CALC - String
	bool surface;				//CALC - bool holding surface type
	int integer;				//CALC - Integer holding day
	int integerTwo;				//CALC - Integer holding month
	int integerThree;			//CALC - Integer holding year
	int i = 0;					//CALC - integer for looping
	//loops until all input has been read from input file
	while (file)
	{
		stadium T;
		Stadiums.push_back(T);
		//Sets LEAGUE
		getline(file, string);
		Stadiums.at(i).setLeague(string);
		//Sets STADIUM
		getline(file, string);
		Stadiums.at(i).setStadium(string);
		//Sets TEAM
		getline(file, string);
		Stadiums.at(i).setTeam(string);
		//Sets CITY
		getline(file, string);
		Stadiums.at(i).setCity(string);
		//Sets STATE
		getline(file, string);
		Stadiums.at(i).setState(string);
		//Sets DAY
		file >> integer;
		Stadiums.at(i).setDay(integer);
		//Moves to a new line
		file.ignore(1000, '\n');
		//Sets MONTH
		file >> integerTwo;
		Stadiums.at(i).setMonth(integerTwo);
		//Moves to a new line
		file.ignore(1000, '\n');
		//Sets YEAR
		file >> integerThree;
		Stadiums.at(i).setYear(integerThree);
		//Moves to a new line
		file.ignore(1000, '\n');
		//Sets SURFACE
		file >> surface;
		Stadiums.at(i).setSurface(surface);
		//Moves to a new line
		file.ignore(1000, '\n');
		file.ignore(1000, '\n');
		//Increases i
		i++;
	}
	//Closes file when finished
	file.close();
}
//FUNCTION - Accesses and outputs a random stadium and info
void randomStadium(std::vector<stadium> Stadiums)
{
	int random;							//CALC - Random integer
	stadium s;							//CALC - Stadium
	random = rand() % Stadiums.size() + 0;
										//CALC - Generates a random number
										//between 0 and the size of vector

	//FIND function to find a stadium at an integer
	s = find(random, Stadiums);

	//Outputs information about the stadium
	cout << "\nFinding a Random Stadium...\n\n";
	cout << s.getStadium() << " of " << s.getCity() << ", "
		 << s.getState() << ", is the home of the " << s.getTeam() << ".\n"
		 << "The " << s.getTeam() << " are a";
	//Handles grammar
	if(s.getLeague() == AMERICAN)
	{
		cout << "n " << s.getLeague() << " League team.\n";
	}
	else
	{
		cout << ' ' << s.getLeague() << " League team.\n";
	}
	cout << s.getStadium() << " was opened on " << s.getDay() << '/'
		 << s.getMonth() << '/' << s.getYear() << " and has a";
	if(s.getSurface())
	{
		cout << " Grass Surface.\n";
	}
	else
	{
		cout << " Astro-Turf Surface.\n";
	}

}
//FUNCTION - Finds an specific stadium at a certain point
stadium find(int i, std::vector<stadium> Stadiums)
{
	return Stadiums.at(i);
}
//FUNCTION - Sort the stadium vector by Stadium name
bool byStadium(const stadium& lhs,const stadium& rhs)
{
	string a;
	string b;
	a = lhs.getStadium();
	b = rhs.getStadium();

	return a < b;
}

////FUNCTION - Sort the stadium vector by grass top
//bool byGrass(const stadium& lhs,const stadium& rhs)
//{
//	bool a;
//	bool b;
//	a = lhs.getSurface();
//	b = rhs.getSurface();
//
//	return a < b;
//}

//FUNCTION - Sort the stadium vector by Team Name
bool byTeamName(const stadium &lhs, const stadium &rhs)
{
	string a;
	string b;
	a = lhs.getTeam();
	b = rhs.getTeam();

	return a < b;
}

//FUNCTION - Sort the stadium vector by grass top
bool byDate(const stadium& lhs,const stadium& rhs)
{
	int a;
	int b;
	a = lhs.getYear();
	b = rhs.getYear();

	// COMPARING MONTH
	if(a==b)
	{
		int c;
		int d;
		c = lhs.getMonth();
		d = rhs.getMonth();

		// COMPARING DAY
		if(c==d)
		{
			int e;
			int f;
			e = lhs.getDay();
			f = rhs.getDay();

			return e < f;
		}
		else
		{
			return c < d;
		}
	}
	else
	{
		return a < b;
	}

}


//FUNCTION - Outputs a list of all major league stadiums sorted by input
void OutputMLG(std::vector<stadium> Stadiums, int sortType)
{
	int i;						//CALC - int for looping
	int j = 1;					//CALC - index starting at 1
	int size = Stadiums.size();	//CALC - int holding size of vector
	int fieldMenu;				// CALC - User Choice for field menu
	int leagueMenu;				// CALC - User Choice for league menu
	field userChoice;			// CALC - Enum selection for field menu
	league userLeagueChoice;	// CALC - Enum selection for league menu

	cout << endl;

	//Outputs all MAJOR LEAGUE Stadiums by chosen sort method

	// SORT BY STADIUM NAME
	if(sortType == 0)
	{
		//Tells user that the program is outputting stadiums
		cout << "Outputting a list of ALL Major League Stadiums...\n\n";
		//SORT function to sort the vector by stadium
		sort(Stadiums.begin(), Stadiums.end(), byStadium);
		for(i = 0; i < size; i++)
		{
				//Outputs Header for Table IF Stadiums were found
				if(j == 1)
				{
					cout << "# | Stadium Name\n";
					cout << setfill('-') << "--|" << setw(12) << '-' << endl;
				}
				if(j<10)
				{
					cout << j << " |";
				}
				else
				{
					cout << j << '|';
				}
				cout << Stadiums.at(i).getStadium() << endl;
				j++;
		}
	}
	// SORT BY TEAM NAME
	else if(sortType == 1)
	{
		//Tells user that the program is outputting stadiums
		cout << "Outputting a list of ALL Major League Teams...\n\n";
		//SORT function to sort the vector by stadium
		sort(Stadiums.begin(), Stadiums.end(), byTeamName);
		for(i = 0; i < size; i++)
		{
				//Outputs Header for Table IF Stadiums were found
				if(j == 1)
				{
					cout << "# |          Team Name          |      Stadium Name\n";
					cout << setfill('-') << "--|" << setw(56) << '-' << endl;
				}
				if(j<10)
				{
					cout << j << " |";
				}
				else
				{
					cout << j << '|';
				}
				cout << right << setfill(' ') << setw(29) << Stadiums.at(i).getTeam() << "|" << setw(5) << "("  << Stadiums.at(i).getStadium() << ")" << endl;
				j++;
		}

		cout << left;
	}
	// SORT BY SURFACE TYPE
	else if(sortType == 2)
	{

		// FUNCTION UserMenuChoice - This function is designed to DISPLAY
		//                           the menu to the user(s).
		UserChoice(fieldMenu, 1, 2);

		// PROCCESS
		userChoice = field(fieldMenu);

		//SORT function to sort the vector by stadium
		sort(Stadiums.begin(), Stadiums.end(), byStadium);

		// WHILE LOOP - MAIN BODY LOOP
			while (userChoice != EXIT)
			{

				cout << "\nOutputting a list of ALL Major League Stadiums by sorted by Surface Type...\n";

				// SWITCH STATEMENT -
				switch(userChoice)
				{
					// CASE EXIT - Exit Case.
					case EXITFIELD:
							  	  break;// END OF CASE EXIT

					// CASE STADIUMNAME
					case GRASS:
						for(i = 0; i < size; i++)
						{
								//Outputs Header for Table IF Stadiums were found
								if(Stadiums.at(i).getSurface() && j == 1)
								{
									cout << "\n# | Stadiums with Grass Surfaces\n";
									cout << setfill('-') << "--|" << setw(12) << '-' << endl;
								}
								if(Stadiums.at(i).getSurface() && j<10)
								{
									cout << j << " |";
									cout << Stadiums.at(i).getStadium();
									cout << endl;
									j++;
								}
								else if(Stadiums.at(i).getSurface())
								{
									cout << j << '|';
									cout << Stadiums.at(i).getStadium();
									cout << endl;
									j++;
								}
						}
						// REINITALIZE
						j = 1;
									break; // END OF CASE STADIUMNAME

					// CASE TEAMNAME
					case ASTROTURF:
						for(i = 0; i < size; i++)
						{
								//Outputs Header for Table IF Stadiums were found
								if(!Stadiums.at(i).getSurface() && j == 1)
								{
									cout << "\n# | Stadiums with Astroturf Surfaces\n";
									cout << setfill('-') << "--|" << setw(12) << '-' << endl;
								}
								if(!Stadiums.at(i).getSurface() && j<10)
								{
									cout << j << " |";
									cout << Stadiums.at(i).getStadium();
									cout << endl;
									j++;
								}
								else if(!Stadiums.at(i).getSurface())
								{
									cout << j << '|';
									cout << Stadiums.at(i).getStadium();
									cout << endl;
									j++;
								}
						}
						// REINITALIZE
						j = 1;

									break; // END OF CASE TEAMNAME

					// CASE DEFAULT - Default case.
					default:
								break; // END OF CASE DEFAULT
				}// END OF SWITCH STATEMENT

				// FUNCTION UserChoice - This function is designed to display
				//                       and grab the menu choice from the user(s).
				UserChoice(fieldMenu, 1, 2);

				// PROCESS
				userChoice = field(fieldMenu);

			}

	}

	// SORT BY DATE OPENED
	else if(sortType == 3)
	{
		//Tells user that the program is outputting stadiums
		cout << "Outputting a list of ALL Major League Stadiums by sorted by Date Opened...\n\n";
		//SORT function to sort the vector by date
		sort(Stadiums.begin(), Stadiums.end(), byDate);
		for(i = 0; i < size; i++)
		{
				//Outputs Header for Table IF Stadiums were found
				if(j == 1)
				{
					cout << "# |             Team Name       |      Date Opened\n";
					cout << setfill('-') << "--|" << setw(56) << '-' << endl;
				}
				if(j<10)
				{
					cout << j << " |";
				}
				else
				{
					cout << j << '|';
				}
				// OUTPUTTING DATE
				cout << right << setfill(' ') << setw(29) << Stadiums.at(i).getStadium() << "|" << setw(5) << "(" << Stadiums.at(i).getMonth() << "/";
				cout << Stadiums.at(i).getDay() << "/" << Stadiums.at(i).getYear() <<  ")" << endl;
				j++;
		}
		cout << left;
	}

	// SORT BY LEAGUE TYPE
	else if(sortType == 4)
	{

		// FUNCTION UserMenuChoice - This function is designed to DISPLAY
		//                           the menu to the user(s).
		UserChoice(leagueMenu, 2, 2);

		// PROCCESS
		userLeagueChoice = league(leagueMenu);

		cout << "\nOutputting a list of ALL Major League Stadiums by sorted by League...\n";
		//SORT function to sort the vector by stadium
		sort(Stadiums.begin(), Stadiums.end(), byStadium);

		// WHILE LOOP - MAIN BODY LOOP
			while (userLeagueChoice != EXIT)
			{
				// SWITCH STATEMENT -
				switch(userLeagueChoice)
				{
					// CASE EXIT - Exit Case.
					case EXITFIELD:
							  	  break;// END OF CASE EXIT

					// CASE STADIUMNAME
					case NATIONALLEAGUE:
						for(i = 0; i < size; i++)
						{
								//Outputs Header for Table IF Stadiums were found
								if(Stadiums.at(i).getLeague() == NATIONAL && j == 1)
								{
									cout << "\n# | National League Stadiums\n";
									cout << setfill('-') << "--|" << setw(12) << '-' << endl;
								}
								if(Stadiums.at(i).getLeague() == NATIONAL && j<10)
								{
									cout << j << " |";
									cout << Stadiums.at(i).getStadium();
									cout << endl;
									j++;
								}
								else if(Stadiums.at(i).getLeague() == NATIONAL)
								{
									cout << j << '|';
									cout << Stadiums.at(i).getStadium();
									cout << endl;
									j++;
								}
						}
							// REINITALIZE
							j = 1;
									break; // END OF CASE NATIONALLEAGUE

					// CASE TEAMNAME
					case AMERICANLEAGUE:
						for(i = 0; i < size; i++)
						{
								//Outputs Header for Table IF Stadiums were found
								if(Stadiums.at(i).getLeague() == AMERICAN && j == 1)
								{
									cout << "\n# | American League Stadiums\n";
									cout << setfill('-') << "--|" << setw(12) << '-' << endl;
								}
								if(Stadiums.at(i).getLeague() == AMERICAN && j<10)
								{
									cout << j << " |";
									cout << Stadiums.at(i).getStadium();
									cout << endl;
									j++;
								}
								else if(Stadiums.at(i).getLeague() == AMERICAN)
								{
									cout << j << '|';
									cout << Stadiums.at(i).getStadium();
									cout << endl;
									j++;
								}
						}
							// REINITALIZE
							j = 1;
									break; // END OF CASE NATIONALLEAGUE
									break; // END OF CASE AMERICANLEAGUE

					// CASE DEFAULT - Default case.
					default:
								break; // END OF CASE DEFAULT
				}// END OF SWITCH STATEMENT

				// FUNCTION UserChoice - This function is designed to display
				//                       and grab the menu choice from the user(s).
				UserChoice(leagueMenu, 2, 2);

				// PROCESS
				userLeagueChoice = league(leagueMenu);

			}

	}

	//Outputs a new line and resets setfill before next section of output
	cout << endl << setfill(' ');
}
