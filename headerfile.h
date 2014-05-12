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
#include <set>
#include <utility>
#include <iterator>
#include "stadium.h"
#include "store.h"

typedef int vertex_t;
typedef double weight_t;
using namespace std;

// ENUMERATED TYPES
/*************************************************************************
* ENUM Menu
* ------------------------------------------------------------------------
* This ENUM is designed to create a menu for user selection.
**************************************************************************/
enum menu
{
	EXIT,
	STADIUMNAME,
	TEAMNAME,
	GRASSTOP,
	LEAGUETYPE,
	DATEOFCREATION,
	RANDOMSTADIUM
};

/*************************************************************************
* ENUM field
* ------------------------------------------------------------------------
* This ENUM is designed to create a menu for user selection.
**************************************************************************/
enum field
{
	EXITFIELD,
	GRASS,
	ASTROTURF
};

/*************************************************************************
* ENUM league
* ------------------------------------------------------------------------
* This ENUM is designed to create a menu for user selection.
**************************************************************************/
enum league
{
	EXITlEAGUE,
	NATIONALLEAGUE,
	AMERICANLEAGUE
};

/*************************************************************************
* ENUM mainMenu
* ------------------------------------------------------------------------
* This ENUM is designed to create a main menu for user selection
**************************************************************************/
enum mainMenu
{
	EXITMAIN,
	STADIUMFINDER,
	TRIPPLANNER,
	SOUVENIRSHOP,
	DISTANCEMEASURE,
	LEAGUEVISIT,
	ADMINLOGIN
};

/*************************************************************************
* ENUM stad
* ------------------------------------------------------------------------
* This ENUM is designed to create a menu of all possible stadiums the user can access
**************************************************************************/
enum stad
{
	EXITSTAD,
	ATT,
	OCO,
	SAFECO,
	DODGERS,
	ANGELS,
	CHASE,
	PETCO,
	COORS,
	TARGET,
	RANGERS,
	MM,
	ROYALS,
	MILLER,
	WRIGLEY,
	CELLULAR,
	BUSCH,
	ROGERS,
	COMERCIA,
	PROGRESSIVE,
	GAP,
	TURNER,
	TROPICANA,
	MARLINS,
	PNC,
	FENWAY,
	CBP,
	YANKEE,
	CITI,
	CAMDEN,
	NATIONALS
};

/*************************************************************************
* ENUM tripMenu
* ------------------------------------------------------------------------
* This ENUM is designed to create a menu of all possible stadiums the user can access
**************************************************************************/

enum tripPlanner
{

};


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
const weight_t max_weight = std::numeric_limits<double>::infinity();

struct neighbor {
    vertex_t target;
    weight_t weight;
    neighbor(vertex_t arg_target, weight_t arg_weight)
        : target(arg_target), weight(arg_weight) { }
};

typedef std::vector<std::vector<neighbor> > adjacency_list_t;

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
 * byGrass
 * 	This function tells the std::sort to sort out stadiums that have grass
 *************************************************************************/
bool byGrass(const stadium& lhs,const stadium& rhs);

/**************************************************************************
 * byDate
 * 	This function tells the std::sort to sort out stadiums that have grass
 *************************************************************************/
bool byDate(const stadium& lhs,const stadium& rhs);

/**************************************************************************
 * OutputMLG
 * 	This function outputs a list of Major League Stadiums sorted
 * 	alphabetically
 *************************************************************************/
void OutputMLG(std::vector<stadium> Stadiums, //IN - Stadium Class
			   int sortType); 				  //IN - Type of sort being performed

/**************************************************************************
 * Spacing
 * 	This function maintains proper spacing for the userChoice function
 *************************************************************************/
int Spacing (int input);

/**************************************************************************
 * UserChoice
 * 	This function handles the menu for selecting sorting options
 *************************************************************************/
void UserChoice(int &userChoice, int menuType, int maxMenu);

/**************************************************************************
 * Dijkstra
 * 	This function traverses the graph of stadiums
 *************************************************************************/
void Dijkstra(vertex_t source,
                          const adjacency_list_t &adjacency_list,
                          std::vector<weight_t> &min_distance,
                          std::vector<vertex_t> &previous);

/**************************************************************************
 * Shortest
 * 	This function determines the shortest distance between two stadiums
 *************************************************************************/
std::list<vertex_t> Shortest(
    vertex_t vertex, const std::vector<vertex_t> &previous);

/**************************************************************************
 * inputChecker
 * 	This function checks for invalid input
 *************************************************************************/
bool inputChecker(int &userChoice, int maxChoice);

/**************************************************************************
 * StoryTen
 * 	This function handles the menu for determining the shortest distance
 * 	between any two stadiums
 *************************************************************************/
void StoryTen();

/**************************************************************************
 * TripPlanner
 * 	This function handles the menu and distance traveled for the trip planner
 * 	option
 *************************************************************************/
void tripPlanner(std::vector<stadium> &Stadiums);

/**************************************************************************
 * TripPlannerSecondMenu
 * 	This function handles the menu and distance traveled for the trip planner
 * 	option
 *************************************************************************/
void tripPlannerSecondMenu(std::vector<stadium> &Stadiums, std::vector<string> &visits, int distance);
void initializeStore(std::vector<item> &items);
void accessStore(std::vector<item> &items);
void accessInventory(std::vector<item> &items);
void adminStorePanel(std::vector<item> &items);
void adminAddItem(std::vector<item> &items);
void adminDeleteItem(std::vector<item> &items);
void adminModifyItem(std::vector<item> &items);
void storeMenu(std::vector<item> &items);
void startingStadium(std::vector<stadium> &Stadiums, int League);
void LeagueVisit(std::vector<stadium> &Stadiums);
void adminStadiumMenu(std::vector<stadium> &Stadiums);
void ModifyStadium(std::vector<stadium> &Stadiums);
void Modify(int i, std::vector<stadium> &Stadiums);
void AddNewStadium(std::vector<stadium> &Stadiums);
void readInto(std::vector<stadium> &Stadiums);
void adminMenu(std::vector<stadium> &Stadiums, std::vector<item> &items);
#endif /* HEADERFILE_H_ */
