#include "Header.h"

typedef string Name;
class BaseballTeam
{
public:
	BaseballTeam();
	~BaseballTeam();
	void setName(string name);		//CALC - Sets the Team Name
	void setLeague(string league);	//CALC - Sets the League
	Name getName() const;			//OUT  - Returns the Team Name
	Name getLeague() const;			//OUT  - Returns the League name
private:
	Name  teamName;					//CALC - Name of Baseball Team
	Name leagueName;				//CALC - League of Baseball Team
};