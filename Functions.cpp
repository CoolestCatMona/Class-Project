#include "headerfile.h"
#include "stadium.h"

const string MAJOR = "Major";
const string AMERICAN = "American";
//FUNCTION - reads input from designated input file and stores it
//in a vector of classes
void readInput(std::vector<stadium> &Stadiums)
{
	ifstream file;				//IN - Input File
	file.open("filename.txt");	//CALC - Opens input file
	string string;				//CALC - String
	bool surface;				//CALC - bool holding surface type
	int i = 0;					//CALC - integer for looping
	//loops until all input has been read from input file
	while (!file.eof())
	{
		//Sets LEAGUE
		getline(file, string);
		Stadiums.at(i).setLeague(string);
		//Sets STADIUM
		getline(file, string);
		Stadiums.at(i).setStadium(string);
		//Sets TEAM
		getline(file, string);
		Stadiums.at(i).setTeam(string);
		//Sets SURFACE
		file >> surface;
		Stadiums.at(i).setSurface(surface);
		//Moves to a new line
		file.ignore(1000, '\n');
		//Increases i
		i++;
	}
	//Closes file when finished
	file.close();
}
//FUNCTION - Accesses and returns a random stadium
string randomStadium(std::vector<stadium> Stadiums)
{
	srand(time(0));
	int random;								//CALC - Integer holding random number
	random = rand() % Stadiums.size() + 0;	//CALC - Generates a random number
											//between 0 and the size of vector

	//FIND function to find a stadium at an integer
	return find(random, Stadiums);			
	

}
//FUNCTION - Finds an specific stadium at a certain point
string find(int i, std::vector<stadium> Stadiums)
{
	return Stadiums.at(i).getStadium();
}
//FUNCTION - Sort the stadium vector by Stadium name
bool sortStadium(stadium &lhs, stadium &rhs)
{
	return lhs.getStadium() > rhs.getStadium();
}
//FUNCTION - Sort the stadium vector by Team Name
bool sortTeamName(stadium &lhs, stadium &rhs)
{
	return lhs.getTeam() > rhs.getTeam();
}
//FUNCTION - Outputs a list of all major league stadiums alphabetically
void OutputMLG(std::vector<stadium> Stadiums)
{
	int i;						//CALC - int for looping
	int size = Stadiums.size();	//CALC - int holding size of vector
	//SORT function to sort the vector by stadium 
	sort(Stadiums.begin(), Stadiums.end(), sortStadium);
	//Outputs all MAJOR LEAGUE Stadiums
	for(i = 0; i < size; i++)
	{
		if (Stadiums.at(i).getLeague() == MAJOR)
		{
			cout << endl << Stadiums.at(i).getStadium();
		}
	}
}