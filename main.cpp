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
//	if(test == blank)
//		std::cout << "true" << std::endl;
//	else
//		std::cout << "false" << std::endl;
	int moves_to_solve = 0;
//	test.print(); //prints Megaminx
	test.scramble(); //randomizes Megaminx
//	test.scramble_bottom(1);
//	std::cout << std::endl << "Scrambled Megaminx: ";	
//	std::cout << std::endl << std::endl;
//	test.print();
//	blank = test.rotate_top();
//	test.rotate_bot();	
	AStar test_solution(test);
	blank = test_solution.solve(moves_to_solve);
	std::cout << "SOLVED!" << std::endl;
	std::cout << "Nodes expanded: "<< test_solution.nodes_expanded << std::endl;
	std::cout << "H: " << blank.h << "G: " << blank.g << "F:  " << blank.f << std::endl << std::endl;
//	blank.print();
	return 0;
}
