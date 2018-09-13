/*---------------------------------
| File: Face.cpp
| Class: Face
| Description: A single face in the megaminx
| Author: Kelsey Cole
-----------------------------------*/
#include "Face.h"

Face::Face() {}
Face::Face(Row cent, Row a, Row b, Row c, Row d, Row e)
{
	this->center = cent;
	this->top = a;
	this->top_right = b;
	this->bot_right = c;
	this->bot_left = d;
	this->top_left = e;
}
Face::Face(const Face &copy)
{
	center = copy.center;
	top = copy.top;
	top_right = copy.top_right;
	bot_right = copy.bot_right;
	bot_left = copy.bot_left;
	top_left = copy.top_left;
}
void Face::print_top()
{
	(top).print();
}
void Face::print_center()
{
	(center).print();
}

void Face::print_bot1()
{
	(bot_left.row[0]).print_ansi_color();
	std::cout << " ";
	(bot_right.row[2]).print_ansi_color(); 

}
void Face::print_bot2()
{
	(bot_left.row[1]).print_ansi_color();
	std::cout << " ";
	(bot_right.row[1]).print_ansi_color();
}
void Face::print_bot3()
{
	(bot_left.row[2]).print_ansi_color();
}

bool Face::operator==(const Face &other) const
{
	if(this->center != other.center)
		return false;
	else if(this->top != other.top)
		return false;
	else if(this->top_right != other.top_right)
		return false;	
	else if(this->bot_right != other.bot_right)
		return false;
	else if(this->bot_left != other.bot_left)
		return false;
	else if(this->top_left != other.top_left)
		return false;
	else 
		return true;
}

bool Face::operator!=(const Face &other) const
{
	if (*this == other)
		return false;
	else return true;
}

Face::~Face() { }
