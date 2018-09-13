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
		void scramble_top_side1(int random);
		void scramble_bottom_side2(int random);
		void scramble_face0_side1(int random);
		void print();
		bool operator==(const Megaminx &other) const;
		void distance_to_solved(int depth);

		int g; //depth
		int h; //cost to goal
		int f; // depth + cost, or g + h		
		
		~Megaminx();

		friend void get_rand_ints(int &one, int &two, int &three, int sum);

		void scramble_top(int random);
	private:
		Face faces_array1[SIDE_1_SIZE];
		Face faces_array2[SIDE_2_SIZE];
		
};
