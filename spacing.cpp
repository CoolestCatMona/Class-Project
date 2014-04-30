#include "headerfile.h"

/**********************************************************
*
* FUNCTION Spacing
*_________________________________________________________
* This function will adjust the spacing on invalid user inputs for the
* ErrorCheckMenu function
*_________________________________________________________
* PRE-CONDITIONS
* input: from the user.
*
* POST-CONDITIONS
* returns-> shift
***********************************************************/

int Spacing (int input)
{
	int shift;
	shift = 0;

	if (input <= -10000)
	{
		shift = 5;
	}
	else if (input <= -1000)
	{
		shift = 4;
	}
	else if (input <= -100)
	{
		shift = 3;
	}
	else if (input <= -10)
	{
		shift = 2;
	}
	else if (input <= -1)
	{
		shift = 1;
	}
	else if(input <= 9)
	{
		shift = 0;
	}
	else if(input <= 99)
	{
		shift = 1;
	}
	else if(input <= 999)
	{
		shift = 2;
	}
	else if(input <= 9999)
	{
		shift = 3;
	}
	else if(input <= 99999)
	{
		shift = 4;
	}
	else
	{
		shift = 5;
	}

	return shift;
}
