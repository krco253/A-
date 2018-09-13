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
//	test.print();
	if (test == blank)
		std::cout << "All is right in the world" << std::endl;
	else 
		std::cout << "You need to do a lil work" << std::endl;


//	test.print();
//	blank.print();

	return 0;
}
