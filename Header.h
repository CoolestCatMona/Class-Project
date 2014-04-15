/*************************************************************************
* AUTHOR		: Sean Dougher
* STUDENT ID	: #271896
* ASSGN #		: Heaps
* CLASS		: CS1D
* SECTION		: MW 5:30p - 7:30a
* DUE DATE		: March 31
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

using namespace std;

/**************************************************************************
* CONSTANTS
* ------------------------------------------------------------------------
* NAME - Name of Assingnment/Lab
* TYPE - Type of Assignment
* NUM  - Assignment/Lab Number
*************************************************************************/
const string NAME = "Heaps";
const char TYPE = 'A';
const int NUM = 9;

/*************************************************************************
* PrintHeader
* 	This function outputs the class heading
*************************************************************************/
void PrintHeader(string asName,	// IN - assignment Name
	char asType, 	// IN - assignment Type
	//	  - (LAB or ASSIGNMENT)
	int asNum);	// IN - assignment number
void readInput();
void randomTeam(Node* head);

#endif /* HEADERFILE_H_ */
