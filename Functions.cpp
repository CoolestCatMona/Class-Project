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
		//Sets CONNECTIONS
		getline(file, string);
		Stadiums.at(i).setConnect(string);
		//Sets CONNECTION DISTANCES
		getline(file, string);
		Stadiums.at(i).setConnectD(string);
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
void Dijkstra(vertex_t source,
                          const adjacency_list_t &adjacency_list,
                          std::vector<weight_t> &min_distance,
                          std::vector<vertex_t> &previous)
{
    int n = adjacency_list.size();
    min_distance.clear();
    min_distance.resize(n, max_weight);
    min_distance[source] = 0;
    previous.clear();
    previous.resize(n, -1);
    std::set<std::pair<weight_t, vertex_t> > vertex_queue;
    vertex_queue.insert(std::make_pair(min_distance[source], source));

    while (!vertex_queue.empty())
    {
        weight_t dist = vertex_queue.begin()->first;
        vertex_t u = vertex_queue.begin()->second;
        vertex_queue.erase(vertex_queue.begin());

        // Visit each edge exiting u
	const std::vector<neighbor> &neighbors = adjacency_list[u];
        for (std::vector<neighbor>::const_iterator neighbor_iter
        		= neighbors.begin();
             neighbor_iter != neighbors.end();
             neighbor_iter++)
        {
            vertex_t v = neighbor_iter->target;
            weight_t weight = neighbor_iter->weight;
            weight_t distance_through_u = dist + weight;
	    if (distance_through_u < min_distance[v]) {
	        vertex_queue.erase(std::make_pair(min_distance[v], v));

	        min_distance[v] = distance_through_u;
	        previous[v] = u;
	        vertex_queue.insert(std::make_pair(min_distance[v], v));

	    }

        }
    }
}
std::list<vertex_t> Shortest(
    vertex_t vertex, const std::vector<vertex_t> &previous)
{
    std::list<vertex_t> path;
    for ( ; vertex != -1; vertex = previous[vertex])
        path.push_front(vertex);
    return path;
}
void StoryTen()
{
	//Creates graph containing map properties
    adjacency_list_t adjacency_list(30);
    //String containing ballpark names
    string ballparks[30] = {"AT&T Park","Oco Coliseum","SafeCo Field",
    						"Dodger Stadium","Angels Stadium of Anaheim",
    						"Chase Field", "Petco Park", "Coors Field",
    						"Target Field","Globe Life Park in Arlington",
    						"Minute Maid Park","Kauffman Stadium",
    						"Miller Park","Wrigley Field",
    						"US Cellular Park","Busch Stadium",
    						"Rogers Center","Progressive Field",
    						"Great America Ballpark","Turner Field",
    						"Tropicana Field","Tropicana Field",
    						"Marlins Park","PNC Park","Fenway Park",
    						"Citizens Bank Park","Yankee Stadium",
    						"Citi Field","Oriole Park at Camden Yards",
    						"Nationals Park"};
    int i;								//Integer for looping
    int FirstPick;						//Menu option picked by user
    int SecondPick;						//Second option by user
    bool invalid = true;				//Valid menu choice
    int j;								//Integer for looping
    adjacency_list[ATT].push_back(neighbor(SAFECO, 680));
    adjacency_list[ATT].push_back(neighbor(DODGERS, 340));
    adjacency_list[ATT].push_back(neighbor(ANGELS, 340));
    adjacency_list[ATT].push_back(neighbor(CHASE, 650));
    adjacency_list[ATT].push_back(neighbor(OCO, 38));

    adjacency_list[OCO].push_back(neighbor(SAFECO, 680));
    adjacency_list[OCO].push_back(neighbor(DODGERS, 340));
    adjacency_list[OCO].push_back(neighbor(ANGELS, 340));
    adjacency_list[OCO].push_back(neighbor(CHASE, 650));
    adjacency_list[OCO].push_back(neighbor(ATT, 38));

    adjacency_list[SAFECO].push_back(neighbor(ATT, 680));
    adjacency_list[SAFECO].push_back(neighbor(OCO, 680));
    adjacency_list[SAFECO].push_back(neighbor(TARGET, 1390));
    adjacency_list[SAFECO].push_back(neighbor(ROGERS, 2070));

    adjacency_list[DODGERS].push_back(neighbor(TARGET, 1500));
    adjacency_list[DODGERS].push_back(neighbor(ATT, 340));
    adjacency_list[DODGERS].push_back(neighbor(OCO, 340));
    adjacency_list[DODGERS].push_back(neighbor(PETCO, 110));
    adjacency_list[DODGERS].push_back(neighbor(ANGELS, 30));

    adjacency_list[ANGELS].push_back(neighbor(TARGET, 1500));
    adjacency_list[ANGELS].push_back(neighbor(ATT, 340));
    adjacency_list[ANGELS].push_back(neighbor(OCO, 340));
    adjacency_list[ANGELS].push_back(neighbor(PETCO, 110));
    adjacency_list[ANGELS].push_back(neighbor(DODGERS, 30));

    adjacency_list[CHASE].push_back(neighbor(ATT, 650));
    adjacency_list[CHASE].push_back(neighbor(OCO, 650));
    adjacency_list[CHASE].push_back(neighbor(PETCO, 300));
    adjacency_list[CHASE].push_back(neighbor(COORS, 830));
    adjacency_list[CHASE].push_back(neighbor(RANGERS, 870));
    adjacency_list[CHASE].push_back(neighbor(MM, 1115));

    adjacency_list[PETCO].push_back(neighbor(DODGERS, 110));
    adjacency_list[PETCO].push_back(neighbor(ANGELS, 110));
    adjacency_list[PETCO].push_back(neighbor(COORS, 830));
    adjacency_list[PETCO].push_back(neighbor(CHASE, 300));

    adjacency_list[COORS].push_back(neighbor(ROYALS, 560));
    adjacency_list[COORS].push_back(neighbor(RANGERS, 650));
    adjacency_list[COORS].push_back(neighbor(CHASE, 580));
    adjacency_list[COORS].push_back(neighbor(PETCO, 830));

    adjacency_list[TARGET].push_back(neighbor(SAFECO, 1390));
    adjacency_list[TARGET].push_back(neighbor(MILLER, 300));
    adjacency_list[TARGET].push_back(neighbor(BUSCH, 465));
    adjacency_list[TARGET].push_back(neighbor(ANGELS, 1500));
    adjacency_list[TARGET].push_back(neighbor(DODGERS, 1500));

    adjacency_list[RANGERS].push_back(neighbor(MM, 230));
    adjacency_list[RANGERS].push_back(neighbor(CHASE, 870));
    adjacency_list[RANGERS].push_back(neighbor(COORS, 650));
    adjacency_list[RANGERS].push_back(neighbor(ROYALS, 460));
    adjacency_list[RANGERS].push_back(neighbor(TURNER, 740));

    adjacency_list[MM].push_back(neighbor(CHASE, 1115));
    adjacency_list[MM].push_back(neighbor(RANGERS, 230));
    adjacency_list[MM].push_back(neighbor(BUSCH, 680));
    adjacency_list[MM].push_back(neighbor(TROPICANA, 790));
    adjacency_list[MM].push_back(neighbor(MARLINS, 965));

    adjacency_list[ROYALS].push_back(neighbor(COORS, 560));
    adjacency_list[ROYALS].push_back(neighbor(RANGERS, 460));
    adjacency_list[ROYALS].push_back(neighbor(BUSCH, 235));
    adjacency_list[ROYALS].push_back(neighbor(WRIGLEY, 560));
    adjacency_list[ROYALS].push_back(neighbor(CELLULAR, 560));

    adjacency_list[MILLER].push_back(neighbor(WRIGLEY, 80));
    adjacency_list[MILLER].push_back(neighbor(CELLULAR, 80));
    adjacency_list[MILLER].push_back(neighbor(TARGET, 300));
    adjacency_list[MILLER].push_back(neighbor(ROGERS, 430));

    adjacency_list[WRIGLEY].push_back(neighbor(MILLER, 80));
    adjacency_list[WRIGLEY].push_back(neighbor(COMERCIA, 240));
    adjacency_list[WRIGLEY].push_back(neighbor(ROYALS, 415));
    adjacency_list[WRIGLEY].push_back(neighbor(CELLULAR, 9));

    adjacency_list[CELLULAR].push_back(neighbor(MILLER, 80));
    adjacency_list[CELLULAR].push_back(neighbor(COMERCIA, 240));
    adjacency_list[CELLULAR].push_back(neighbor(ROYALS, 415));
    adjacency_list[CELLULAR].push_back(neighbor(WRIGLEY, 9));

    adjacency_list[BUSCH].push_back(neighbor(TARGET, 465));
    adjacency_list[BUSCH].push_back(neighbor(ROYALS, 235));
    adjacency_list[BUSCH].push_back(neighbor(MM, 680));
    adjacency_list[BUSCH].push_back(neighbor(GAP, 310));

    adjacency_list[ROGERS].push_back(neighbor(SAFECO, 2070));
    adjacency_list[ROGERS].push_back(neighbor(MILLER, 430));
    adjacency_list[ROGERS].push_back(neighbor(COMERCIA, 210));
    adjacency_list[ROGERS].push_back(neighbor(PNC, 115));
    adjacency_list[ROGERS].push_back(neighbor(FENWAY, 430));

    adjacency_list[COMERCIA].push_back(neighbor(ROGERS, 210));
    adjacency_list[COMERCIA].push_back(neighbor(PROGRESSIVE, 90));
    adjacency_list[COMERCIA].push_back(neighbor(WRIGLEY, 240));
    adjacency_list[COMERCIA].push_back(neighbor(CELLULAR, 240));

    adjacency_list[PROGRESSIVE].push_back(neighbor(COMERCIA, 90));
    adjacency_list[PROGRESSIVE].push_back(neighbor(PNC, 115));
    adjacency_list[PROGRESSIVE].push_back(neighbor(GAP, 225));

    adjacency_list[GAP].push_back(neighbor(BUSCH, 310));
    adjacency_list[GAP].push_back(neighbor(CELLULAR, 250));
    adjacency_list[GAP].push_back(neighbor(PROGRESSIVE, 225));
    adjacency_list[GAP].push_back(neighbor(PNC, 260));
    adjacency_list[GAP].push_back(neighbor(TURNER, 375));
    adjacency_list[GAP].push_back(neighbor(TROPICANA, 790));

    adjacency_list[TURNER].push_back(neighbor(MARLINS, 600));
    adjacency_list[TURNER].push_back(neighbor(RANGERS, 740));
    adjacency_list[TURNER].push_back(neighbor(GAP, 375));
    adjacency_list[TURNER].push_back(neighbor(CAMDEN, 560));
    adjacency_list[TURNER].push_back(neighbor(NATIONALS, 560));

    adjacency_list[TROPICANA].push_back(neighbor(MM, 790));
    adjacency_list[TROPICANA].push_back(neighbor(MARLINS, 210));
    adjacency_list[TROPICANA].push_back(neighbor(GAP, 790));

    adjacency_list[MARLINS].push_back(neighbor(TURNER, 600));
    adjacency_list[MARLINS].push_back(neighbor(MM, 965));
    adjacency_list[MARLINS].push_back(neighbor(TROPICANA, 210));
    adjacency_list[MARLINS].push_back(neighbor(FENWAY, 1255));
    adjacency_list[MARLINS].push_back(neighbor(CAMDEN, 930));
    adjacency_list[MARLINS].push_back(neighbor(NATIONALS, 930));

    adjacency_list[PNC].push_back(neighbor(ROGERS, 225));
    adjacency_list[PNC].push_back(neighbor(PROGRESSIVE, 115));
    adjacency_list[PNC].push_back(neighbor(GAP, 260));
    adjacency_list[PNC].push_back(neighbor(NATIONALS, 195));
    adjacency_list[PNC].push_back(neighbor(CAMDEN, 195));
    adjacency_list[PNC].push_back(neighbor(CITI, 315));
    adjacency_list[PNC].push_back(neighbor(YANKEE, 315));

    adjacency_list[FENWAY].push_back(neighbor(ROGERS, 430));
    adjacency_list[FENWAY].push_back(neighbor(YANKEE, 195));
    adjacency_list[FENWAY].push_back(neighbor(CITI, 195));
    adjacency_list[FENWAY].push_back(neighbor(MARLINS, 1255));

    adjacency_list[CBP].push_back(neighbor(YANKEE, 80));
    adjacency_list[CBP].push_back(neighbor(CITI, 80));
    adjacency_list[CBP].push_back(neighbor(CAMDEN, 90));
    adjacency_list[CBP].push_back(neighbor(NATIONALS, 90));

    adjacency_list[YANKEE].push_back(neighbor(CBP, 80));
    adjacency_list[YANKEE].push_back(neighbor(PNC, 315));
    adjacency_list[YANKEE].push_back(neighbor(FENWAY, 195));
    adjacency_list[YANKEE].push_back(neighbor(CITI, 10));

    adjacency_list[CITI].push_back(neighbor(CBP, 80));
    adjacency_list[CITI].push_back(neighbor(PNC, 315));
    adjacency_list[CITI].push_back(neighbor(FENWAY, 195));
    adjacency_list[CITI].push_back(neighbor(YANKEE, 10));

    adjacency_list[CAMDEN].push_back(neighbor(CBP, 90));
    adjacency_list[CAMDEN].push_back(neighbor(PNC, 195));
    adjacency_list[CAMDEN].push_back(neighbor(TURNER, 560));
    adjacency_list[CAMDEN].push_back(neighbor(MARLINS, 930));
    adjacency_list[CAMDEN].push_back(neighbor(NATIONALS, 8));

    adjacency_list[NATIONALS].push_back(neighbor(CBP, 90));
    adjacency_list[NATIONALS].push_back(neighbor(PNC, 195));
    adjacency_list[NATIONALS].push_back(neighbor(TURNER, 560));
    adjacency_list[NATIONALS].push_back(neighbor(MARLINS, 930));
    adjacency_list[NATIONALS].push_back(neighbor(CAMDEN, 8));

    //Menu for selecting a stadium to start at
    do
    {
		cout << "\nPlease select a stadium to start at: \n\n";
		for(i = 0; i < 30; i++)
		{
			cout << i+1 << ". "  << ballparks[i] << endl;
		}
		cout << "\nEnter Stadium #:  ";

//		cin >> FirstPick;

		invalid = inputChecker(FirstPick, 30);
    }while(invalid);
    //Menu for selecting a stadium to end at
    do

    {
  		cout << "Please select a stadium to end at:\n\n";
  		for(j = 0; j < 30; j++)
  		{
  			cout << j+1 << ". "  << ballparks[j] << endl;

  		}
		cout << "\nEnter Stadium #: ";
//  		cin >> SecondPick;

  		invalid = inputChecker(SecondPick, 30);
    }while(invalid);
    //Fixes userChoice
    --FirstPick;
    --SecondPick;
    //Preforms Dijkstras algorithm to find distance
	vector<weight_t> min_distance;
	vector<vertex_t> previous;
    Dijkstra(FirstPick, adjacency_list, min_distance, previous);
    cout << "\nThe distance from " << ballparks[FirstPick] << " to "
    	 << ballparks[SecondPick] << " is " << min_distance[SecondPick]
    	 << " miles.\n";
    //Outputs path taken
	list<vertex_t> path = Shortest(SecondPick, previous);
    cout << "Path: ";
	for (list<int>::iterator it = path.begin();
				 it != path.end();
				 it++)
			{
				cout << ballparks[*it] << ", ";
			}
			cout << endl << endl;
}
bool inputChecker(int &userChoice, int maxChoice)
{
	// VARIABLES
	bool invalid;		// CALC - Main boolean for the function.
	invalid = false;

	int shift;
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
	return invalid;
}

void tripPlanner(std::vector<stadium> &Stadiums)
{
	// VARIABLES
	vector<string> connections;
	vector<int> connectDistances;
	vector<stadium> S;
	vector<string> visits;
	int choice;			// INP  - Choice made by the user(s)
	int totalDistanceT;	// CALC - TOTAL DISTANCE TRAVELED
	int ballParkSize;	// CALC - Size of the ballparks array
	bool invalid = true;//Valid menu choice
	string passedStadium;

	// INITIALIZE
	totalDistanceT = 0;
	ballParkSize = 30;
	S = Stadiums;

	// OUTPUT - Prompts the user of what this option does
	cout << "\nWelcome to the Trip Planner! This tool allows you to plan your dream";
	cout << " baseball vacation. Choose any stadium to start: \n";

	// DO WHILE LOOP - Increments until the user enters a valid input
	do{
		// FOR LOOP - Increments until the index reaches the end of the array of ballparks
		for(int index = 0; index < ballParkSize; index++)
		{
			// OUTPUT BALLPARKS
			cout << index+1 << ". "  << Stadiums.at(index).getStadium() << endl;
		} // END OF FOR
		cout <<"0. BACK\n";
		cout <<"Enter Stadium #: ";

		// FUNCTION - Checks for invalid Input
		invalid = inputChecker(choice, ballParkSize);
	}while(invalid); // END OF DO WHILE LOOP

	// IF STATEMENT - Checking if User has exited the trip Planner
	if(choice!=0)
	{
		passedStadium = Stadiums.at(choice-1).getStadium();

		visits.push_back(passedStadium);

		// FUNCTION - Goes to the secondary menu of the tripPlanner
		tripPlannerSecondMenu(S, visits, totalDistanceT);
	}// END OF IF STATEMENT

}

void tripPlannerSecondMenu(std::vector<stadium> &Stadiums, std::vector<string> &visits, int distance)
{
	vector<string> connections;
	vector<int> connectDistances;
	vector<stadium> S;
	bool valid;
	int newChoice;
	int secondChoice;
	string currentStadium;
	string newStadium;

	S = Stadiums;
	secondChoice = -1;
	newChoice = -1;
	valid = true;

	currentStadium = visits.back();

	// REINITALIZE - Vectors being initialized to the user's choice
	if(currentStadium == "Angels Stadium of Anaheim")
	{
		connections = Stadiums.at(0).getConnect();
		connectDistances = Stadiums.at(0).getConnectD();
	}
	else if(currentStadium == "Comerica Park")
	{
		connections = Stadiums.at(1).getConnect();
		connectDistances = Stadiums.at(1).getConnectD();
	}
	else if(currentStadium == "Fenway Park")
		{
			connections = Stadiums.at(2).getConnect();
			connectDistances = Stadiums.at(2).getConnectD();
		}
	else if(currentStadium == "Rangers Ballpark")
		{
			connections = Stadiums.at(3).getConnect();
			connectDistances = Stadiums.at(3).getConnectD();
		}
	else if(currentStadium == "Kauffman Stadium")
		{
			connections = Stadiums.at(4).getConnect();
			connectDistances = Stadiums.at(4).getConnectD();
		}
	else if(currentStadium == "Minute Maid Park")
		{
			connections = Stadiums.at(5).getConnect();
			connectDistances = Stadiums.at(5).getConnectD();
		}
	else if(currentStadium == "Oco Coliseum")
		{
			connections = Stadiums.at(6).getConnect();
			connectDistances = Stadiums.at(6).getConnectD();
		}
	else if(currentStadium == "Oriole Park at Camden Yards")
		{
			connections = Stadiums.at(7).getConnect();
			connectDistances = Stadiums.at(7).getConnectD();
		}
	else if(currentStadium == "Progressive Field")
		{
			connections = Stadiums.at(8).getConnect();
			connectDistances = Stadiums.at(8).getConnectD();
		}
	else if(currentStadium == "Rogers Center")
		{
			connections = Stadiums.at(9).getConnect();
			connectDistances = Stadiums.at(9).getConnectD();
		}
	else if(currentStadium == "SafeCo Field")
		{
			connections = Stadiums.at(10).getConnect();
			connectDistances = Stadiums.at(10).getConnectD();
		}
	else if(currentStadium == "Target Field")
		{
			connections = Stadiums.at(11).getConnect();
			connectDistances = Stadiums.at(11).getConnectD();
		}
	else if(currentStadium == "US Cellular Field")
		{
			connections = Stadiums.at(12).getConnect();
			connectDistances = Stadiums.at(12).getConnectD();
		}
	else if(currentStadium == "Yankee Stadium")
		{
			connections = Stadiums.at(13).getConnect();
			connectDistances = Stadiums.at(13).getConnectD();
		}
	else if(currentStadium == "AT&T Park")
		{
			connections = Stadiums.at(14).getConnect();
			connectDistances = Stadiums.at(14).getConnectD();
		}
	else if(currentStadium == "Busch Stadium")
		{
			connections = Stadiums.at(15).getConnect();
			connectDistances = Stadiums.at(15).getConnectD();
		}
	else if(currentStadium == "Chase Field")
		{
			connections = Stadiums.at(16).getConnect();
			connectDistances = Stadiums.at(16).getConnectD();
		}
	else if(currentStadium == "Citi Field")
		{
			connections = Stadiums.at(17).getConnect();
			connectDistances = Stadiums.at(17).getConnectD();
		}
	else if(currentStadium == "Citizens Bank Park")
		{
			connections = Stadiums.at(18).getConnect();
			connectDistances = Stadiums.at(18).getConnectD();
		}
	else if(currentStadium == "Coors Field")
		{
			connections = Stadiums.at(19).getConnect();
			connectDistances = Stadiums.at(19).getConnectD();
		}
	else if(currentStadium == "Dodger Stadium")
		{
			connections = Stadiums.at(21).getConnect();
			connectDistances = Stadiums.at(21).getConnectD();
		}
	else if(currentStadium == "Great America Ball Park")
		{
			connections = Stadiums.at(22).getConnect();
			connectDistances = Stadiums.at(22).getConnectD();
		}
	else if(currentStadium == "Marlins Park")
		{
			connections = Stadiums.at(23).getConnect();
			connectDistances = Stadiums.at(23).getConnectD();
		}

	else if(currentStadium == "Miller Park")
		{
			connections = Stadiums.at(24).getConnect();
			connectDistances = Stadiums.at(24).getConnectD();
		}
	else if(currentStadium == "Nationals Park")
		{
			connections = Stadiums.at(25).getConnect();
			connectDistances = Stadiums.at(25).getConnectD();
		}
	else if(currentStadium == "Petco Park")
		{
			connections = Stadiums.at(26).getConnect();
			connectDistances = Stadiums.at(26).getConnectD();
		}
	else if(currentStadium == "PNC Park")
		{
			connections = Stadiums.at(27).getConnect();
			connectDistances = Stadiums.at(27).getConnectD();
		}
	else if(currentStadium == "Turner Field")
		{
			connections = Stadiums.at(28).getConnect();
			connectDistances = Stadiums.at(28).getConnectD();
		}
	else if(currentStadium == "Wrigley Field")
		{
			connections = Stadiums.at(29).getConnect();
			connectDistances = Stadiums.at(29).getConnectD();
		}

	cout << "\nStadiums connected to " << currentStadium <<": \n";



	// DO WHILE LOOP - Takes user input for stadiums that they would like to visit
	do
	{
			// FOR LOOP - Outputs the stadiums connected to the user's choice
			for(unsigned int i = 0; i < connections.size(); i++)
			{
				cout << i+1 << ". " << connections.at(i) << endl;
			} // END OF FOR LOOP

			cout << "0. (Check Total Distance Traveled/End the Trip)\n";
			valid = inputChecker(newChoice, connections.size());

			// CHECKING if User wants to exit
			if(newChoice == 0)
			{
				cout << "\nYour total distance traveled is: " << distance << " miles";
				cout << "\nYou've already visited: ";
				for(unsigned int i = 0; i < visits.size(); i++)
				{
					cout << "(" << visits.at(i) << "), ";
				}
				cout << "\nWould you like to exit?: ";
				cout << "\n1. Visit more Stadiums";
				cout << "\n0. Return to the main Menu";

				inputChecker(secondChoice, 1);
				if(secondChoice == 0)
				{
					return;
				}
				else
				{
					// FUNCTION - RECURSION
					tripPlannerSecondMenu(S, visits, distance);
				}
			} // END OF IF STATEMENT

	}while(valid); // END OF DO WHILE LOOP

	newStadium = connections.at(newChoice-1);
	// PROCESSING - Adding the new location to the visited vector
	visits.push_back(newStadium);

	distance+= connectDistances.at(newChoice-1);
	// FUNCTION - RECURSION
	tripPlannerSecondMenu(S, visits, distance);
}
void initializeStore(std::vector<item> &items)
{
	item cap;
	item bat;
	item pennant;
	item baseball;

	items.push_back(cap);
	items.at(0).setItem("Baseball Cap");
	items.at(0).setPrice(25.99);

	items.push_back(bat);
	items.at(1).setItem("Baseball Bat");
	items.at(1).setPrice(35.35);

	items.push_back(pennant);
	items.at(2).setItem("Team Pennant");
	items.at(2).setPrice(12.99);

	items.push_back(cap);
	items.at(3).setItem("Autographed Baseball");
	items.at(3).setPrice(19.99);
}
void storeMenu(std::vector<item> &items)
{
	bool invalid = true;
	int menuChoice;
	do
	{
	cout << "1. Buy stuff!\n";
	cout << "2. View Inventory\n";
	cout << "3. Return\n";
	cout << "Enter choice: ";
	invalid = inputChecker(menuChoice, 3);
	}while(invalid);
	switch(menuChoice)
	{
	case 1:
		accessStore(items);
		break;
	case 2:
		accessInventory(items);
		break;
	case 3:
		break;
	default:
		break;
	}
}
void accessStore(std::vector<item> &items)
{
	int i;							//Int for looping
	int size = items.size();
	int userChoice;
	bool again = true;
	bool invalid = true;
	int oldNum;						//Number of previously owned
									//items of a certain type
	cout << "\nWelcome to the store! Please make a purchase!\n\n";
	do
	{
		//outputs menu
		for(i = 0; i < size; i++)
		{
			cout << i+1 << ". " << items.at(i).getItem()
					<< " -- $" << items.at(i).getPrice();
			cout << endl;
		}
		cout << "Please select an item to buy: ";
		invalid = inputChecker(userChoice, i);
	}while(invalid);
	cin.ignore(1000, '\n');
	//decreases user choice
	userChoice--;
	cout << "\nYou have purchased a " << items.at(userChoice).getItem()
		 << " for $" << items.at(userChoice).getPrice();

	//Increases the number of items in possession by user
	oldNum = items.at(userChoice).getNumber();
	items.at(userChoice).setNumber(++oldNum);

	//Checks to see if the user wants to buy more items
	do
	{
	cout << "\nWould you like to continue shopping? (0 = yes 1 = no)";
	again = inputChecker(userChoice, 1);
	}while(again);

	//Runs the function again
	if(userChoice == 0)
	{
		accessStore(items);
	}


}
void accessInventory(std::vector<item> &items)
{
	float total = 0;
	int i;
	int size = items.size();

	cout << "You currently have the following items in your inventory:\n";
	for(i = 0; i < size-1; i++)
	{
		if(items.at(i).getNumber() != 0)
		{
			cout << "You have " << items.at(i).getNumber()
				 << ' ' << items.at(i).getItem() <<'s';
			total = total + (items.at(i).getNumber() * items.at(i).getPrice());
			cout << endl;
		}
	}
	if(total == 0)
	{
		cout << "You have no items!\n";
	}
	else
	{
		cout << "You have spent a total of $" << total << endl;
	}
	cin.ignore(1000, '\n');
	cout << "\n*Press ENTER to return*\n";
	cin.get();

}
void adminStorePanel(std::vector<item> &items)
{
	bool invalid = true;
	int menuChoice;
	do
	{
	cout << "1. Add Item\n";
	cout << "2. Delete Item\n";
	cout << "3. Modify Existing item\n";
	cout << "4. Return\n";
	cout << "Enter choice: ";
	invalid = inputChecker(menuChoice, 4);
	}while(invalid);
	switch(menuChoice)
	{
	case 1:
		adminAddItem(items);
		break;
	case 2:
		adminDeleteItem(items);
		break;
	case 3:
		adminModifyItem(items);
		break;
	case 4:
		break;
	default:
		break;
	}
}
void adminAddItem(std::vector<item> &items)
{
	item newItem;				//Creates a new item
	string itemName;			//Name of the new item
	float itemPrice;			//Price for the item

	cin.ignore(1000,'\n');
	//Asks user for the name of the new item
	cout << "Please enter a name for this Item: ";
	getline(cin, itemName);
	//Asks user for
	cout << "\nPlease enter a price for this Item: ";
	cin >> itemPrice;

	//Actually adds the item to the vector
	items.push_back(newItem);
	items.back().setItem(itemName);
	items.back().setPrice(itemPrice);

	//Informs the user of the details of the item they added
	cout << "You have added " << items.back().getItem()
		 << " at $" << items.back().getPrice();

	cout << "\n\n*Press ENTER to return*\n";
	cin.get();
}
void adminDeleteItem(std::vector<item> &items)
{
	int i;								//CALC - Int for looping
	int size = items.size();			//CALC - Size of vector
	bool invalid = true;				//CALC - Error Checking
	int userChoice;						//IN   - User input

	//Loops the menu
	do
	{
		//Outputs the menu
		for(i = 0; i < size; i++)
		{
			cout << i+1 << ". " << items.at(i).getItem()
					<< " -- $" << items.at(i).getPrice();
			cout << endl;
		}
		//prompts user to remove an item
		cout << "Please select an item to remove: ";
		invalid = inputChecker(userChoice, size);
	}while(invalid);
	cin.ignore(1000, '\n');
	//erases item
	cout << "Erasing " << items.at(userChoice-1).getItem();
	items.erase(items.begin()+userChoice-1);

	cout << "\n\n*Press ENTER to return*\n";
	cin.get();
}
void adminModifyItem(std::vector<item> &items)
{
	int i;								//CALC - Int for looping
	int size = items.size();			//CALC - Size of vector
	bool invalid = true;				//CALC - Error Checking
	int userChoice;						//IN   - User input
	string itemName;
	int itemPrice;

	cin.ignore(1000, '\n');
	//Loops the menu
	do
	{
		//Outputs the menu
		for(i = 0; i < size; i++)
		{
			cout << i+1 << ". " << items.at(i).getItem()
					<< " -- $" << items.at(i).getPrice();
			cout << endl;
		}
		//prompts user to remove an item
		cout << "Please select an item to Modify: ";
		invalid = inputChecker(userChoice, size);
	}while(invalid);
	//decreases i
	++i;
	//Asks user for the name of the new item
	cout << "\nPlease enter a new name for this Item: ";
	getline(cin, itemName);
	//Asks user for price of new item
	cout << "\nPlease enter a new price for this Item: ";
	cin >> itemPrice;
	//sets name and price
	items.at(i).setItem(itemName);
	items.at(i).setPrice(itemPrice);

	//Informs the user of the details of the item they modified
	cout << "You have changed the item to  " << items.at(i).getItem()
		 << " at $" << items.at(i).getPrice();

	cout << "\n\n*Press ENTER to return*\n";
	cin.get();
}
void LeagueVisit(std::vector<stadium> &Stadiums)
{
	int leagueChoice;					//Choice of league
	bool invalid = true;				//CALC - Error checking
	//Loops the menu
	do
	{
		cout << "\n0. Back\n1. American\n2.National\n";
		cout << "Please Select a League: \n";
		invalid = inputChecker(leagueChoice, 2);
	}while(invalid);
	if(leagueChoice != 0)
	{
		startingStadium(Stadiums, leagueChoice);
	}

}
void startingStadium(std::vector<stadium> &Stadiums, int League)
{
	string leagueName;						//CALC - NAME OF LEAGUE
	int i = 0;								//CALC - Int for looping
	int j = 0;								//CALC - int for looping
	int end = 0;							//CALC - int for looping
	string caliStadiums[15];				//CALC - Array holding stadium
											//names
	int stadStart;							//IN   - Stadium to start at
	bool invalid;							//CALC - Error checking
	//Switches league to assign a league
	switch(League)
	{
	case 1:
		leagueName = "American";
		break;
	case 2:
		leagueName = "National";
		break;
	default:
		break;
	}
	//Assigns menu options based on user choice of American or National
	for(i = 0; i < Stadiums.size(); i++)
	{
		if(leagueName == "American")
		{
			if(Stadiums.at(i).getState() == "CA" &&
			   Stadiums.at(i).getLeague() == AMERICAN)
			{
				++end;
				caliStadiums[j] = Stadiums.at(i).getStadium();
				++j;
			}
		}
		else
		{
			if(Stadiums.at(i).getState() == "CA" &&
			   Stadiums.at(i).getLeague() == NATIONAL)
			{
				++end;
				caliStadiums[j] = Stadiums.at(i).getStadium();
				++j;
			}
		}

	}

	//outputs menu
	cout << "\nPlease Select a Stadium to begin at:\n";
	do
	{
		for(i = 0; i < end; i++)
		{
			cout << i << ". " << caliStadiums[i] << endl;
		}
		invalid = inputChecker(stadStart, end-1);
	}while(invalid);

}
void adminStadiumMenu(std::vector<stadium> &Stadiums)
{
	bool invalid = true;
		int menuChoice;
		do
		{
		cout << "1. Modify Stadium Info\n";
		cout << "2. Add Stadiums\n";
		cout << "3. Return\n";
		cout << "Enter choice: ";
		invalid = inputChecker(menuChoice, 3);
		}while(invalid);
		switch(menuChoice)
		{
		case 1:
			ModifyStadium(Stadiums);
			break;
		case 2:
			AddNewStadium(Stadiums);
			break;
		case 3:
			break;
		default:
			break;
		}
}
void ModifyStadium(std::vector<stadium> &Stadiums)
{
	int i;								//int for looping
	bool invalid = true;				//error checking
	int userChoice;
	do
	{
	for(i = 0; i < Stadiums.size(); i++)
	{
		cout << i+1 << ". " << Stadiums.at(i).getStadium() << endl;
	}
	cout << "\nPlease select a stadium to modify: ";
	invalid = inputChecker(userChoice, Stadiums.size());
	}while(invalid);
	--userChoice;
	Modify(userChoice, Stadiums);
}
void Modify(int i, std::vector<stadium> &Stadiums)
{
	string newStadium;						//IN - Stadium
	string newLeague;						//IN - League
	string newTeam;							//IN - Team Name
	int leagueType;							//IN - League Type
	bool invalid = true;					//Error checking

	//Clears input buffer to avoid errors
	cin.ignore(1000, '\n');
	cout << "\nPlease enter a new Name for this stadium: ";
	getline(cin, newStadium);
	do{
	cout << "\nPlease enter a new League for"
			" this stadium (0 = American 1 = National: ";
	invalid = inputChecker(leagueType, 1);
	}while(invalid);
	//clears input buffer
	cin.ignore(1000, '\n');
	cout << "\nPlease enter a new Team Name for this stadium: ";
	getline(cin, newTeam);

	//Sets league type
	if(leagueType == 0)
	{
		newLeague = AMERICAN;
	}
	else
	{
		newLeague = NATIONAL;
	}

	cout << "\n\nOLD INFORMATION:";
	cout << "\nSTADIUM NAME: " << Stadiums.at(i).getStadium();
	cout << "\nLEAGUE: " << Stadiums.at(i).getLeague();
	cout << "\nTEAM NAME: " << Stadiums.at(i).getTeam();

	//Modifys stadium info
	Stadiums.at(i).setStadium(newStadium);
	Stadiums.at(i).setLeague(newLeague);
	Stadiums.at(i).setTeam(newTeam);

	cout << "\n\nNEW INFORMATION:";
	cout << "\nSTADIUM NAME: " << Stadiums.at(i).getStadium();
	cout << "\nLEAGUE: " << Stadiums.at(i).getLeague();
	cout << "\nTEAM NAME: " << Stadiums.at(i).getTeam();

	cout << "\n*Press ENTER to Continue*\n";
	cin.get();
}
void AddNewStadium(std::vector<stadium> &Stadiums)
{
	string newStadium;					//IN - Name
	string newLeague;					//IN - League
	string newTeam;						//IN - Team Name
	int leagueType;						//IN - Type of League
	bool invalid = true;

	//Creates a new stadium to be added
	stadium T;

	//Clears input buffer to avoid errors
	cin.ignore(1000, '\n');
	cout << "\nPlease enter a new Name for this stadium: ";
	getline(cin, newStadium);
	do{
	cout << "\nPlease enter a new League for"
			" this stadium (0 = American 1 = National: ";
	invalid = inputChecker(leagueType, 1);
	}while(invalid);
	//clears input buffer
	cin.ignore(1000, '\n');
	cout << "\nPlease enter a new Team Name for this stadium: ";
	getline(cin, newTeam);

	//Sets league type
	if(leagueType == 0)
	{
		newLeague = AMERICAN;
	}
	else
	{
		newLeague = NATIONAL;
	}

	//Adds the stadium to the vector
	Stadiums.push_back(T);
	Stadiums.back().setStadium(newStadium);
	Stadiums.back().setLeague(newLeague);
	Stadiums.back().setTeam(newTeam);
	Stadiums.back().setCity("Somewheresville");
	Stadiums.back().setState("CA");
	Stadiums.back().setDay(11);
	Stadiums.back().setMonth(5);
	Stadiums.back().setYear(2014);

	cout << "\n\nSTADIUM INFORMATION:";
	cout << "\nSTADIUM NAME: " << Stadiums.back().getStadium();
	cout << "\nLEAGUE: " << Stadiums.back().getLeague();
	cout << "\nTEAM NAME: " << Stadiums.back().getTeam();

	cout << "\n*Press ENTER to Continue*\n";
	cin.get();
}
void readInto(std::vector<stadium> &Stadiums)
{
	ofstream file;						//OUTPUT file
	int i;								//Integer for looping
	int j;
	vector<string> connections;			//Vector containing connections
	vector<int> connectionsD;			//Vector containing distances
	int size = Stadiums.size();			//Size of vector

	//Opens file to write to
	file.open("IFile.txt");
	//writes information to file
	for(i = 0; i < size; i++)
	{
		file << Stadiums.at(i).getLeague() << endl;
		file << Stadiums.at(i).getStadium() << endl;
		file << Stadiums.at(i).getTeam() << endl;
		file << Stadiums.at(i).getCity() << endl;
		file << Stadiums.at(i).getState() << endl;
		file << Stadiums.at(i).getDay() << endl;
		file << Stadiums.at(i).getMonth() << endl;
		file << Stadiums.at(i).getYear() << endl;
		file << Stadiums.at(i).getSurface() << endl;
		connections = Stadiums.at(i).getConnect();
		for(j = 0; j < connections.size(); j++)
		{
			file << connections.at(j) << ',';
		}
		file << endl;
		connectionsD = Stadiums.at(i).getConnectD();
		for(j = 0; j < connections.size(); j++)
		{
			file << connectionsD.at(j) << ',';
		}
		if(i != size)
		{
			file << endl << endl;
		}
	}
}
void adminMenu(std::vector<stadium> &Stadiums, std::vector<item> &items)
{
	bool invalid = true;
	int menuChoice;
	do{
	cout << "\n1. Add/Delete/Change Stadium Info."
			"\n2. Add/Delete/Change Store Info."
			"\n3. Back\n";
	cout << "Please Select an option: ";
	invalid = inputChecker(menuChoice, 3);
	}while(invalid);
	switch(menuChoice)
	{
	case 1:
		adminStadiumMenu(Stadiums);
		break;
	case 2:
		adminStorePanel(items);
		break;
	case 3:
		break;
	default:
		break;
	}
}
