/*
 * stadium.h
 *
 *  Created on: Apr 14, 2014
 *      Author: salvarez14
 */

#include <string>
#include <iostream>
#include <vector>
using namespace std;

#ifndef STADIUM_H_
#define STADIUM_H_

// Class - Stadium
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
		string getStadium();

		// METHOD - setLeague: sets the current league
		void setLeague(string inLeague);

		// METHOD - getLeague: gets the current league
		string getLeague();

		// METHOD - setTeam: Sets the current team name
		void setTeam(string inTeam);

		// METHOD - getTeam: gets the current team name
		string getTeam();

		// METHOD - setSurface: sets the current stadium surface - True for Grass, False for Non Grass
		void setSurface(bool inSurface);

		// METHOD - getSurface: gets the current surface
		bool getSurface();


	private:
		string stadiumName;	// Name of the Stadium
		string league;		// League: National or American
		string teamName;	// Name of team that plays there
		bool surface;		// True = Grass Surface; False = Non Grass Surface


}; // END OF CLASS - Stadium


#endif /* STADIUM_H_ */
