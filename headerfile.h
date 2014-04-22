/*************************************************************************
* AUTHOR		: Sean Dougher + Steven Alvarez
* STUDENT ID	: #271896 + #Steven
* ASSGN #		: Class Project
* CLASS			: CS1D
* SECTION		: MW 5:30p - 7:30a
* DUE DATE		: May 11
************************************************************************/
#ifndef HEADERFILE_H_
#define HEADERFILE_H_


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
#include "stadium.h"


using namespace std;


/**************************************************************************
* CONSTANTS
* ------------------------------------------------------------------------
* NAME - Name of Assingnment/Lab
* TYPE - Type of Assignment
* NUM  - Assignment/Lab Number
*************************************************************************/
const string NAME = "I hate steven";
const char TYPE = 'A';
const int NUM = 777;
const string MAJOR = "Major";
const string AMERICAN = "American";
const string NATIONAL = "National";

/*************************************************************************
* PrintHeader
* 	This function outputs the class heading
*************************************************************************/
void PrintHeader(string asName,					// IN - assignment Name
				char asType, 					// IN - assignment Type
												//	  - (LAB or ASSIGNMENT)
				int asNum);						// IN - assignment number
/**************************************************************************
 * readInput
 * 	This function reads input from an input file and adds it to a vector
 * 	containing stadiums
 *************************************************************************/
void readInput(std::vector<stadium> &Stadiums);		//IN - Stadium Class
/**************************************************************************
 * randomStadium
 * 	This function is passed in a vector containing stadiums and outputs
 * 	a random stadium and information about that stadium such as
 * 	Location, home team, league of home team, date opened and surface
 * 	type.
 *************************************************************************/
void randomStadium(std::vector<stadium> Stadiums);//IN - Stadium Class
/**************************************************************************
 * find
 * 	This function recieves an integer and a vector of stadiums and returns
 * 	the stadium located at i
 *************************************************************************/
stadium find(int i,									//IN - int for location
			std::vector<stadium> Stadiums);			//IN - Stadium Class
/**************************************************************************
 * byStadium
 * 	This function tells the std::sort to sort the vector by Stadium Name
 *************************************************************************/
bool byStadium(const stadium &lhs,const stadium &rhs);//IN - start and end
													  //of Stadium Class
/**************************************************************************
 * byTeamName
 * 	This function tells the std::sort to sort the vector by Team Name
 *************************************************************************/
bool byTeamName(const stadium &lhs,const stadium &rhs);//IN - start and end
													   //of stadium Class
/**************************************************************************
 * OutputMLG
 * 	This function outputs a list of Major League Stadiums sorted
 * 	alphabetically
 *************************************************************************/
void OutputMLG(std::vector<stadium> Stadiums);		//IN - Stadium Class


#endif /* HEADERFILE_H_ */
