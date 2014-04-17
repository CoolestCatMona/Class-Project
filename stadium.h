#include "headerfile.h"
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
	stadium(string inStadium, string inLeague, string inTeam, bool inSurface);

	// DESTRUCTOR
	~stadium();

	// METHOD - setStadium: sets the current stadium name
	void setStadium(string inStadium);

	// METHOD - getStadium: gets the current stadium name
	Name getStadium();

	// METHOD - setLeague: sets the current league
	void setLeague(string inLeague);

	// METHOD - getLeague: gets the current league
	Name getLeague();

	// METHOD - setTeam: Sets the current team name
	void setTeam(string inTeam);

	// METHOD - getTeam: gets the current team name
	Name getTeam();

	// METHOD - setSurface: sets the current stadium surface - True for Grass, False for Non Grass
	void setSurface(bool inSurface);

	// METHOD - getSurface: gets the current surface
	bool getSurface();


private:
	Name stadiumName;	// Name of the Stadium
	Name league;		// League: National or American
	Name teamName;		// Name of team that plays there
	bool surface;		// True = Grass Surface; False = Non Grass Surface


}; // END OF CLASS - Stadium

#endif /* STADIUM_H_ */