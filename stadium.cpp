#include "stadium.h"

// CONSTRUCTOR - Default
stadium::stadium()
{
	surface = false;
}

// CONSTRUCTOR - User input
stadium::stadium(string inStadium,	//IN - Stadium Name
				 string inLeague,	//IN - League
				 string inTeam,		//IN - Team Name
				 bool inSurface)	//IN - Surface Type
{
	surface = inSurface;
	stadiumName = inStadium;
	teamName = inTeam;
	league = inLeague;
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
