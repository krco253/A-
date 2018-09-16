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
	test.print(); //prints Megaminx
//	test.scramble(); //randomizes Megaminx	
	std::cout << std::endl << std::endl;
	blank = test.rotate_bot();
	std::cout << test.h << " " << test.g << " " << test.f << std::endl;
	blank.print();
	std::cout << blank.h << " " << blank.g << " " << blank.f << std::endl;
//	test.rotate_bot();
//	test.print();

//	AStar test_solution(test);
//	test = test_solution.solve();
//	test.print();
	return 0;
}
