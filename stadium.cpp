#include "stadium.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ios>
#include <limits>
#include <list>
#include <queue>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <random>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#include <iterator>
#include <sstream>

// CONSTRUCTOR - Default
stadium::stadium()
{
	surface = false;
	day = 1;
	month = 1;
	year = 1920;
}

// CONSTRUCTOR - User input
stadium::stadium(string inStadium,	//IN - Stadium Name
				 string inLeague,	//IN - League
				 string inTeam,		//IN - Team Name
				 bool inSurface,	//IN - Surface Type
				 int inDay,
				 int inMonth,
				 int inYear)
{
	surface = inSurface;
	stadiumName = inStadium;
	teamName = inTeam;
	league = inLeague;
	day = inDay;
	year = inYear;
	month = inMonth;
}

// METHOD - setStadium: sets the current stadium name
void stadium::setStadium(string inStadium)	//IN - Stadium Name
{
	stadiumName = inStadium;
}

// METHOD - getStadium: gets the current stadium name
string stadium::getStadium() const
{
	return stadiumName;
}

// METHOD - setLeague: sets the current league
void stadium::setLeague(string inLeague)	//IN - League
{
	league = inLeague;
}

// METHOD - getLeague: gets the current league
string stadium::getLeague() const
{
	return league;
}

// METHOD - setTeam: Sets the current team name
void stadium::setTeam(string inTeam)	//IN - Team Name
{
	teamName = inTeam;
}

// METHOD - getTeam: gets the current team name
string stadium::getTeam() const
{
	return teamName;
}

// METHOD - setSurface: sets the current stadium surface
//- True for Grass, False for Non Grass
void stadium::setSurface(bool inSurface)
{
	surface = inSurface;
}

// METHOD - getSurface: gets the current surface
bool stadium::getSurface() const
{
	return surface;
}

// METHOD - setYear: sets the Year opened
void stadium::setYear(int inYear)	//IN - Year
{
	year = inYear;
}

// METHOD - getYear: gets & returns the year opened
int stadium::getYear() const
{
	return year;
}

// METHOD - setMonth: sets the Month opened
void stadium::setMonth(int inMonth)	//IN - Month
{
	month = inMonth;
}

// METHOD - getMonth: gets & returns the day opened
int stadium::getMonth() const
{
	return month;
}

// METHOD - setDay: sets the Day opened
void stadium::setDay(int inDay)	//IN - Day
{
	day = inDay;
}

// METHOD - getDay: gets & returns the day opened
int stadium::getDay() const
{
	return day;
}

// METHOD - setCity: sets the City of Stadium
void stadium::setCity(string inCity)	//IN - City
{
	city = inCity;
}

// METHOD - getCity: gets & returns the city of stadium
string stadium::getCity() const
{
	return city;
}
// METHOD - setDay: sets the State of Stadium
void stadium::setState(string inState)	//IN - State
{
	state = inState;
}

// METHOD - getDay: gets & returns the State of stadium
string stadium::getState() const
{
	return state;
}

// METHOD - setConnect: Sets the current connections of the stadium
void stadium::setConnect(string &inConnections)
{
	// Segments after split
	string token;

	// CALC - Reading in the string to be split
	std::istringstream ss(inConnections);

	// WHILE LOOP - Splitting the string
	while(std::getline(ss, token, ','))
	{
		connections.push_back(token);
	} // END OF SPLIT STRING WHILE LOOP

}

// METHOD - getConnect: Gets the current connections of the stadium
vector<string> stadium::getConnect()
{
	return connections;
}

// METHOD - setConnect: Sets the current connection distances of the stadium
void stadium::setConnectD(string &inConnectionD)
{
	// Segments after split
	string token;
	int result;

	// CALC - Reading in the string to be split
	std::istringstream ss(inConnectionD);

	// WHILE LOOP - Splitting the string
	while(std::getline(ss, token, ','))
	{
		stringstream convert(token);
		convert >> result;
		// Typecasting the string to an integer
		connectionD.push_back(result);
	} // END OF SPLIT STRING WHILE LOOP
}

// METHOD - getConnect: Gets the current connection distances of the stadium
vector<int> stadium::getConnectD()
{
	return connectionD;
}
