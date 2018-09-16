/*---------------------------------
| File: AStar.h
| Class: AStar
| Description: implementation of A*
| algorthim to solve the Megaminx
| Author: Kelsey Cole
-----------------------------------*/
#include "Megaminx.h"
#include <queue>

class AStar
{
	public: 
		AStar(Megaminx puzzle); //generates a priority queue based on the Megaminx puzzle given
		AStar(const AStar &copy);
		bool is_solved(); //returns true if the Megaminx is solved
		Megaminx solve(int &number_of_moves); 
		

	private:
		Megaminx unsolved_puzzle;
		std::priority_queue<Megaminx> megaminx_queue;	
};
