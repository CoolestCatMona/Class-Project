#include "headerfile.h"
#include "stadium.h"

//right-click the project and go to "Properties"
//C/C++ Build -> Settings -> Tool Settings -> GCC C++ Compiler -> Miscellaneous -> Other Flags. Put -std=c++0x at the end
int main()
{
	srand(time(0));
	//Creates a vector containing the stadium class
	vector<stadium> S;
	//Reads input into the vector
	readInput(S);
	OutputMLG(S);
	cout << S.size();
	return 0;
}
