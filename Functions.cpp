#include "Header.h"

void readInput()
{
	ifstream file
	file.open("filename.txt");
	file.close();
}
stadium randomTeam(std::list<stadium> Stadiums)
{
	srand(time(0));
	int random;
	random = rand() % Stadiums.size() + 1;

	return find(random, stadiums);
	

}
stadium find(int i, std::list<stadium> Stadiums)
{
	if (i == 0)
	{
		return stadiums;
	}
	else
	{
		--i;
		stadiums = stadiums++;
		find(i, stadiums);
	}
	return stadiums;
}