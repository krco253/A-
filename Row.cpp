/*---------------------------------
| File: Row.cpp
| Class: Row
| Description: A single row on a single
| face in the Megaminx
| Author: Kelsey Cole
-----------------------------------*/
#include "Row.h"

Row::Row(){}

Row::Row(const Row &copy)
{
	for(int i = 0; i < TOP_CAP; i++)
	{
		this->row[i] = copy.row[i];
	}

}

Row::Row(Block a, Block b, Block c)
{
	row[0] = a;
	row[1] = b;
	row[2] = c;
}

void Row::print()
{
	for(int i = 0; i < TOP_CAP; i++)
	{
		row[i].print_ansi_color();
	}
}

Row::Row(Block row_array[])
{	
	for(int block = 0; block < TOP_CAP; block++)
	{
		this->row[block] = row_array[block];
	}

}

bool Row::operator==(const Row &other) const
{
	for(int i = 0; i < TOP_CAP; i++)
	{
		if(this->row[i] != other.row[i])
			return false;
	}
	
	return true;
}

bool Row::operator!=(const Row &other) const
{
	if (*this == other)
		return false;
	else return true;
}

Row::~Row(){}

