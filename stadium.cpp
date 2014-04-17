/*
 * stadium.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: salvarez14
 */

#include <string>
#include <iostream>
#include <vector>
#include "stadium.h"
using namespace std;

// CONSTRUCTOR - Default
stadium::stadium()
{
	surface = false;
}

// CONSTRUCTOR - User input
stadium::stadium(string inStadium, string inLeague, string inTeam, bool inSurface)
{
	surface = inSurface;
	stadiumName = inStadium;
	teamName = inTeam;
	league = inLeague;
}

// METHOD - setStadium: sets the current stadium name
void stadium::setStadium(string inStadium)
{
	stadiumName = inStadium;
}

// METHOD - getStadium: gets the current stadium name
string stadium::getStadium()
{
	return stadiumName;
}

// METHOD - setLeague: sets the current league
void stadium::setLeague(string inLeague)
{
	league = inLeague;
}

// METHOD - getLeague: gets the current league
string stadium::getLeague()
{
	return league;
}

// METHOD - setTeam: Sets the current team name
void stadium::setTeam(string inTeam)
{
	teamName = inTeam;
}

// METHOD - getTeam: gets the current team name
string stadium::getTeam()
{
	return teamName;
}

// METHOD - setSurface: sets the current stadium surface - True for Grass, False for Non Grass
void stadium::setSurface(bool inSurface)
{
	surface = inSurface;
}

// METHOD - getSurface: gets the current surface
bool stadium::getSurface()
{
	return surface;
}

