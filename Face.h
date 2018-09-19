/*---------------------------------
| File: Face.h
| Class: Face
| Description: A single face in the megaminx
| Author: Kelsey Cole
-----------------------------------*/

#include "Row.h"

class Face
{
	public:
		Face();
		Face(const Face &copy);
		Face(Row cent, Row a, Row b, Row c, Row d, Row e);
		void print_top();
		void print_center();
		void print_bot1();
		void print_bot2();
		void print_bot3();
		void sync(std::string which_row); //which_row was changed

		bool operator==(const Face &other) const;
		bool operator!=(const Face &other) const;		 
		~Face();
 
		Row center, top, top_right, bot_right, bot_left, top_left;
};
