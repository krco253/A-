/*---------------------------------------------
| Project: Megaminx
| Author: Kelsey Cole
| Description:
| Compile with:
| Idea: store ANSI codes in colors array/map
| then use B's to represent individual cubies
| Idea: split up faces_array into 2 sides
|----------------------------------------------*/
#include "AStar.h"

int main()
{
	Megaminx test;
	Megaminx blank;
	int moves_to_solve = 0;
//	test.print(); //prints Megaminx
	test.scramble(); //randomizes Megaminx
//	test.scramble_1_2(1); //1_2??
//	std::cout << std::endl << "Scrambled Megaminx: ";	
	std::cout << std::endl << std::endl;
//	test.print();
//	std::cout << std::endl << std::endl;
//	blank = test.rotate_1_2();
//	blank.print();
//	blank = test.rotate_bot();
//	blank.print();
	AStar test_solution(test);
	test = test_solution.solve(moves_to_solve);
	std::cout << "SOLVED!" << std:: endl;
	std::cout << "H: " << test.h << "G: " << test.g << "F:  " << test.f << std::endl << std::endl;
	test.print();
	return 0;
}
