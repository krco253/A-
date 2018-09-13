/*---------------------------------
| File: Row.h
| Class: Row
| Description: A single row on a single
| face in the Megaminx
| Author: Kelsey Cole
-----------------------------------*/
#include "Block.h"

class Row
{
	public:
		Row();
		Row(const Row &copy);
		Row(Block row_array[]);
		Row(Block a, Block b, Block c);
		void print();
		bool operator==(const Row &other) const;
		bool operator!=(const Row &other) const;
	
		~Row();
	
		Block row[TOP_CAP];

};
