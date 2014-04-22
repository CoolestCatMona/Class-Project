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
	int integer;				//CALC - Integer holding date
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
		file >> integer;
		Stadiums.at(i).setMonth(integer);
		//Moves to a new line
		file.ignore(1000, '\n');
		//Sets YEAR
		file >> integer;
		Stadiums.at(i).setYear(integer);
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
	cout << "Finding a Random Stadium...\n\n";
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
		cout << "n Astro-Turf Surface.\n";
	}

	//adds a new line beofre the next line in the output
	cout << endl;
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
//FUNCTION - Sort the stadium vector by Team Name
bool byTeamName(stadium &lhs, stadium &rhs)
{
	string a;
	string b;
	a = lhs.getTeam();
	b = rhs.getTeam();

	return a < b;
}
//FUNCTION - Outputs a list of all major league stadiums alphabetically
void OutputMLG(std::vector<stadium> Stadiums)
{
	int i;						//CALC - int for looping
	int j = 1;					//CALC - index starting at 1
	int size = Stadiums.size();	//CALC - int holding size of vector

	//Tells user that the program is outputting stadiums
	cout << "Outputting a list of ALL Major League Stadiums...\n\n";

	//SORT function to sort the vector by stadium
	sort(Stadiums.begin(), Stadiums.end(), byStadium);

	//Outputs all MAJOR LEAGUE Stadiums ALPHABETICALLY
	for(i = 0; i < size; i++)
	{
		//Outputs all stadiums of a certain League in a formatted manner
		if (Stadiums.at(i).getLeague() == MAJOR)
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
	//Output if no stadiums were found
	if (j <= 1)
	{
		cout << "There were no stadiums of the " << MAJOR
				<< " League found.\n";
	}
	//Outputs a new line and resets setfill before next section of output
	cout << endl << setfill(' ');
}
