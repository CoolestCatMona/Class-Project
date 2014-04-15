#include "BaseballTeams.h"

BaseballTeam::BaseballTeam()
{
	teamName = "";
	leagueName = "";
}
void BaseballTeam::setName(string name)
{
	teamName = name;
}
void BaseballTeam::setLeague(string league)
{
	leagueName = league;

}
string BaseballTeam::getName() const
{
	return teamName;
}
string BaseballTeam::getLeague() const
{
	return leagueName;
}