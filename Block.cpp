/*---------------------------------
| File: Block.cpp
| Class: Block
| Description: A single block(cubie) in the megaminx
| Author: Kelsey Cole
-----------------------------------*/
#include "Block.h"

Block::Block()
{ 
	this->block_color = Color::red;
}

Block::Block(Color this_color)
{	
	this->block_color = this_color;
}

Block::Block(const Block &copy)
{
	this->block_color = copy.block_color;
}

void Block::print_ansi_color()
{
	int num = int(block_color);
	switch (num)
	{
		case 0:
		{	std::cout << red; 
			break;
		}
		case 1:
		{	std::cout << green;
			break;
		}
		case 2:
		{	std::cout << yellow;
			break;
		}
		case 3:
		{	std::cout << blue;
			break;
		}
		case 4:
		{	std::cout << magenta;
			break;
		}
		case 5:
		{	std::cout << cyan;
			break;
		}
		case 6:
		{	std::cout << light_red;
			break;
		}
		case 7:
		{	std::cout << light_green;
			break;
		}
		case 8:
		{	std::cout << light_yellow;
			break;
		}
		case 9:
		{	std::cout << light_blue;
			break;
		}
		case 10:
		{	std::cout << light_magenta;
			break;
		}
		case 11:
		{	std::cout << light_cyan;
			break;
		}
		default:
		{	std::cout << "Invalid color! " << num << std::endl;
			break;
		}

	}
}

Block::~Block(){ }

bool operator>(const Block &first, const Block &last)
{
	int x,y;
	x = int(first.block_color);
	y = int(last.block_color);
	if( x > y)
		return true;
	else return false;
}

bool operator<(const Block &first, const Block &last)
{
	int x,y;
	x = int(first.block_color);
	y = int(last.block_color);
	if( x < y)
		return true;
	else return false;
}

bool operator==(const Block &first, const Block &last)
{
	int x,y;
	x = int(first.block_color);
	y = int(last.block_color);
	if( x == y)
		return true;
	else return false;
}


bool operator!=(const Block &first, const Block &last)
{
	if(first == last)
		return false;
	else return true;
}
