/*---------------------------------------------
| Project: AStar
| Author: Kelsey Cole
| Description: Solve a randomized Megaminx by AStar
| Compile with: gcc -std=c++11 -o AStar AStar.cpp
| Megaminx.cpp Face.cpp Row.cpp Block.cpp
|----------------------------------------------*/
#include "AStar.h"

int main()
{
	//allocate a Megaminx to test
	Megaminx test;
	int moves_to_solve = 0; //this moves_to_solve variable is unused - needs taken out
//	test.print(); //prints the initial Megaminx
	test.scramble(); //randomizes Megaminx
//	std::cout << std::endl << "Scrambled Megaminx: ";	
//	std::cout << std::endl << std::endl;
//	test.print(); //prints the randomized Megaminx
	AStar test_solution(test);
	blank = test_solution.solve(moves_to_solve);
	std::cout << "SOLVED!" << std::endl;
	std::cout << "Nodes expanded: "<< test_solution.nodes_expanded << std::endl;
	std::cout << "H: " << blank.h << "G: " << blank.g << "F:  " << blank.f << std::endl << std::endl;
//	blank.print(); //prints out the solved Megaminx for confirmation
	return 0;
}
