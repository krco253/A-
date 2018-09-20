/*---------------------------------
| File: Megaminx.h
| Class: Megaminx
| Description: The entire megaminx
| Author: Kelsey Cole
-----------------------------------*/
#include "Face.h"
#include <iomanip> // setw
#include <random> //random_device, uniform_int_distribution
#include <utility> //swap

class Megaminx
{
	public:
		Megaminx();
		Megaminx(const Megaminx &copy);
		void scramble();
		void scramble_top(int random);
		void scramble_bottom(int random);
		void scramble_left_side(int random);
		int calculate_stickers();
		Megaminx rotate_left_side();
		void scramble_right_side(int random);
		Megaminx rotate_right_side();
		void scramble_1_2(int random);
		void scramble_bot_left(int random);
		Megaminx rotate_bot_left();
		void scramble_bot_right(int random);
		Megaminx rotate_bot_right();
		void scramble_2_2(int random);
		Megaminx rotate_2_2();
		void scramble_2_4(int random);
		Megaminx rotate_2_4();
		void scramble_2_1(int random);
		Megaminx rotate_2_1();		
		void scramble_2_3(int random);
		Megaminx rotate_2_3();
		void scramble_2_5(int random);
		Megaminx rotate_2_5();		
		Megaminx rotate_top();
		Megaminx rotate_bot(); 	
		Megaminx rotate_1_2();
		void print();
		bool operator==(const Megaminx &other) const;
		bool operator!=(const Megaminx &other) const;
		void distance_to_solved(int depth);
		bool is_solved();
		bool operator<(const Megaminx &other) const;
		bool operator>(const Megaminx &other) const;
	
	
		int g; //depth
		int h; //cost to goal
		int f; // depth + cost, or g + h		
		
		~Megaminx();


	private:
		Face faces_array1[SIDE_1_SIZE];
		Face faces_array2[SIDE_2_SIZE];
		
};
