/*---------------------------------
| File: AStar.cpp
| Class: AStar
| Description: implementation of A*
| algorthim to solve the Megaminx
| Author: Kelsey Cole
-----------------------------------*/
#include "AStar.h"

/* TODO
1. finish constructor (Include priority queue)
2. finish solve()

*/

AStar::AStar(Megaminx puzzle) 
{
	this->unsolved_puzzle = puzzle;
	//make child for moving top counterclockwise
	Megaminx top_rotation; 
	top_rotation = unsolved_puzzle.rotate_top();
	megaminx_queue.push(top_rotation);
	//make child for moving bottom counterclockwise
	Megaminx bot_rotation;
	bot_rotation = unsolved_puzzle.rotate_bot();
	megaminx_queue.push(bot_rotation);
			
}

AStar::AStar(const AStar &copy)
{
	this->unsolved_puzzle = copy.unsolved_puzzle;
}

bool AStar::is_solved()
{
	Megaminx blank;
	if ((this->unsolved_puzzle) == blank)
		return true;
	else 	
		return false;
}

Megaminx AStar::solve(int &number_of_moves)
{
	number_of_moves = 0;

	if (this->is_solved())
		return (this->unsolved_puzzle);
	
}
