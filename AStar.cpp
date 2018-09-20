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
	this->nodes_expanded = 1;
	if(puzzle.is_solved())
	{megaminx_queue.push(puzzle); }
	else
	{
	//make child for moving top counterclockwise
	Megaminx top_rotation; 
	top_rotation = unsolved_puzzle.rotate_top();
	top_rotation.distance_to_solved(1);
	megaminx_queue.push(top_rotation);
	//make child for moving bottom counterclockwise
	Megaminx bot_rotation;
	bot_rotation = unsolved_puzzle.rotate_bot();
	bot_rotation.distance_to_solved(1);
	megaminx_queue.push(bot_rotation);
	//make child for "left" side scramble
	Megaminx left_rotation;
	left_rotation = unsolved_puzzle.rotate_left_side();
	left_rotation.distance_to_solved(1);
	megaminx_queue.push(left_rotation);
	//make child for "right" side scramble
	Megaminx right_rotation;
	right_rotation = unsolved_puzzle.rotate_right_side();
	right_rotation.distance_to_solved(1);
	megaminx_queue.push(right_rotation);
	// make child for 1_2 scramble
	Megaminx o_2_rotation;
	o_2_rotation = unsolved_puzzle.rotate_1_2();
	o_2_rotation.distance_to_solved(1);
	megaminx_queue.push(o_2_rotation);
	//make child for bot left scramble
	Megaminx bot_left_rotation;
	bot_left_rotation = unsolved_puzzle.rotate_bot_left();
	bot_left_rotation.distance_to_solved(1);
	megaminx_queue.push(bot_left_rotation);

	//make child for bot right scramble
	Megaminx bot_right_rotation;
	bot_right_rotation = unsolved_puzzle.rotate_bot_right();
	bot_right_rotation.distance_to_solved(1);
	megaminx_queue.push(bot_right_rotation);

	
	//make child for 2_2 scramble
	Megaminx t_2_rotation;
	t_2_rotation = unsolved_puzzle.rotate_2_2();
	t_2_rotation.distance_to_solved(1);
	megaminx_queue.push(t_2_rotation);
	
	
	//make child for 2_4 right scramble
	Megaminx t_4_rotation;
	t_4_rotation = unsolved_puzzle.rotate_2_4();
	t_4_rotation.distance_to_solved(1);
	megaminx_queue.push(t_4_rotation);		
	
	//make child for 2_1 right scramble
	Megaminx t_1_rotation;
	t_1_rotation = unsolved_puzzle.rotate_2_1();
	t_1_rotation.distance_to_solved(1);
	megaminx_queue.push(t_1_rotation);		

	//make child for 2_3 right scramble
	Megaminx t_3_rotation;
	t_3_rotation = unsolved_puzzle.rotate_2_3();
	t_3_rotation.distance_to_solved(1);
	megaminx_queue.push(t_3_rotation);		

	//make child for 2_5 right scramble
	Megaminx t_5_rotation;
	t_5_rotation = unsolved_puzzle.rotate_2_5();
	t_5_rotation.distance_to_solved(1);
	megaminx_queue.push(t_5_rotation);		

	}
}

void AStar::expand_megaminx_node(Megaminx puzzle, int deep)
{
	nodes_expanded++;
	//make child for moving top counterclockwise
	Megaminx top_rotation; 
	top_rotation = puzzle.rotate_top();
	top_rotation.distance_to_solved(deep);
	megaminx_queue.push(top_rotation);
	//make child for moving bottom counterclockwise
	Megaminx bot_rotation;
	bot_rotation = puzzle.rotate_bot();
	bot_rotation.distance_to_solved(deep);
	megaminx_queue.push(bot_rotation);
	//make child for "left" side scramble
	Megaminx left_rotation;
	left_rotation = unsolved_puzzle.rotate_left_side();
	left_rotation.distance_to_solved(deep);
	megaminx_queue.push(left_rotation);
	//make child for "right" side scramble
	Megaminx right_rotation;
	right_rotation = unsolved_puzzle.rotate_right_side();
	right_rotation.distance_to_solved(deep);
	megaminx_queue.push(right_rotation);
	// make child for 1_2 scramble
	Megaminx o_2_rotation;
	o_2_rotation = unsolved_puzzle.rotate_1_2();
	o_2_rotation.distance_to_solved(deep);
	megaminx_queue.push(o_2_rotation);
	//make child for bot left scramble
	Megaminx bot_left_rotation;
	bot_left_rotation = unsolved_puzzle.rotate_bot_left();
	bot_left_rotation.distance_to_solved(deep);
	megaminx_queue.push(bot_left_rotation);

	//make child for bot right scramble
	Megaminx bot_right_rotation;
	bot_right_rotation = unsolved_puzzle.rotate_bot_right();
	bot_right_rotation.distance_to_solved(deep);
	megaminx_queue.push(bot_right_rotation);

	
	//make child for 2_2 scramble
	Megaminx t_2_rotation;
	t_2_rotation = unsolved_puzzle.rotate_2_2();
	t_2_rotation.distance_to_solved(deep);
	megaminx_queue.push(t_2_rotation);
	
	
	//make child for 2_4 right scramble
	Megaminx t_4_rotation;
	t_4_rotation = unsolved_puzzle.rotate_2_4();
	t_4_rotation.distance_to_solved(deep);
	megaminx_queue.push(t_4_rotation);		
	
	//make child for 2_1 right scramble
	Megaminx t_1_rotation;
	t_1_rotation = unsolved_puzzle.rotate_2_1();
	t_1_rotation.distance_to_solved(deep);
	megaminx_queue.push(t_1_rotation);		

	//make child for 2_3 right scramble
	Megaminx t_3_rotation;
	t_3_rotation = unsolved_puzzle.rotate_2_3();
	t_3_rotation.distance_to_solved(deep);
	megaminx_queue.push(t_3_rotation);		

	//make child for 2_5 right scramble
	Megaminx t_5_rotation;
	t_5_rotation = unsolved_puzzle.rotate_2_5();
	t_5_rotation.distance_to_solved(deep);
	megaminx_queue.push(t_5_rotation);		

}

AStar::AStar(const AStar &copy)
{
	this->unsolved_puzzle = copy.unsolved_puzzle;
}

bool AStar::is_solved()
{
	Megaminx blank;
	if ((this->megaminx_queue.top()) == blank)
		return true;
	else 	
		return false;
}

Megaminx AStar::solve(int &depth)
{
	Megaminx blank;
	Megaminx top_mega = this->megaminx_queue.top();
	if (top_mega.calculate_stickers() == 0)
		return (top_mega);
	while(top_mega.calculate_stickers() != 0)
	{
//		top_mega.print();
		megaminx_queue.pop();
		depth = top_mega.g;
		depth++;
		this->expand_megaminx_node(top_mega, depth);
		top_mega = this->megaminx_queue.top();
	}
	return top_mega;
	
}
