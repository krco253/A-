/*---------------------------------------------
| Project: Megaminx
| Author: Kelsey Cole
| Description:
| Compile with:
| Idea: store ASCII codes in colors array/map
| then use B's to represent individual cubies
| Idea: split up faces_array into 2 sides
|----------------------------------------------*/
#include "Megaminx.h"

int main()
{
	Megaminx test;
	Megaminx blank;
//	test.print(); //prints Megaminx
//	test.scramble(); //randomizes Megaminx	
//	std::cout << std::endl << std::endl;
//	blank.print();
	test.print();
	test.scramble();
	test.print();
	test.distance_to_solved(0);
	std::cout << "Distance to solved: " << test.f << std::endl;

	return 0;
}
