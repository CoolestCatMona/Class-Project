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
#include <ifstream>
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

/*************************************************************************
* PrintHeader
* 	This function outputs the class heading
*************************************************************************/
void PrintHeader(string asName,						// IN - assignment Name
				char asType, 						// IN - assignment Type
													//	  - (LAB or ASSIGNMENT)
				int asNum);							// IN - assignment number
void readInput(std::vector<stadium> &Stadiums);		//IN - Stadium Class
string randomStadium(std::vector<stadium> Stadiums);//IN - Stadium Class
string find(int i,									//IN - int for location
			std::vector<stadium> Stadiums);			//IN - Stadium Class
bool sortStadium(stadium &lhs, stadium &rhs);		//IN - start and end
													//of Stadium Class
bool sortTeamName(stadium &lhs, stadium &rhs);		//IN - start and end
													//of stadium Class
void OutputMLG(std::vector<stadium> Stadiums);		//IN - Stadium Class

#endif /* HEADERFILE_H_ */
