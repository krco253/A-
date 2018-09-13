/*---------------------------------
| File: Block.h
| Class: Block
| Description: A single block in the megaminx
| Author: Kelsey Cole
-----------------------------------*/

#include <iostream>
#include "Constants.h" 
#include <iomanip>

enum class Color {red, green, yellow, blue, magenta, cyan, light_red, light_green, light_yellow, light_blue, light_magenta, light_cyan}; 

class Block
{
	public: 
		Block();
		Block(const Block &copy);
		Block(Color this_color);
		void print_ansi_color();
		~Block();
		friend bool operator<(const Block &first, const Block &last);
		friend bool operator==(const Block &first, const Block &last);
		friend bool operator>(const Block &first, const Block &last);
		friend bool operator!=(const Block &first, const Block &last);

		Color block_color;
		
	
};
