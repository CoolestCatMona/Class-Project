#include <string>
using namespace std;
#ifndef STADIUM_H_
#define STADIUM_H_


// Class - Stadium
typedef string Name;
class stadium
{
public:
	// CONSTRUCTOR
	stadium();

	// CONSTRUCTOR
	stadium(string inStadium,
			string inLeague,
			string inTeam,
			bool inSurface);

	// METHOD - setStadium: sets the current stadium name
	void setStadium(string inStadium);

	// METHOD - getStadium: gets the current stadium name
	Name getStadium() const;

	// METHOD - setLeague: sets the current league
	void setLeague(string inLeague);

	// METHOD - getLeague: gets the current league
	Name getLeague() const;

	// METHOD - setTeam: Sets the current team name
	void setTeam(string inTeam);

	// METHOD - getTeam: gets the current team name
	Name getTeam() const;

	// METHOD - setSurface: sets the current stadium surface
	//- True for Grass, False for Non Grass
	void setSurface(bool inSurface);

	// METHOD - getSurface: gets the current surface
	bool getSurface() const;

	// METHOD - setYear: Sets the year opened
	void setYear(int inYear);

	// METHOD - getYear: gets the year opened
	int getYear() const;

	// METHOD - setMonth: Sets the month opened
	void setMonth(int inMonth);

	// METHOD - getMonth: gets the month opened
	int getMonth() const;

	// METHOD - setDay: Sets the day opened
	void setDay(int inDay);

	// METHOD - getDay: gets the day opened
	int getDay() const;

	// METHOD - setCity: Sets the current city
	void setCity(string inCity);

	// METHOD - getCity: gets the current city
	Name getCity() const;

	// METHOD - setState: Sets the current tstate
	void setState(string inState);

	// METHOD - getState: gets the current state
	Name getState() const;



private:
	Name stadiumName;	// Name of the Stadium
	int year;			// Year opened
	int month;			// Month opened
	int day;			// Day opened
	string city;		// City of Stadium
	string state;		// State of Stadium
	Name league;		// League: National or American
	Name teamName;		// Name of team that plays there
	bool surface;		// True = Grass Surface; False = Non Grass Surface




}; // END OF CLASS - Stadium


#endif /* STADIUM_H_ */
