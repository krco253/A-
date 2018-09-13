/*---------------------------------
| File: Megaminx.cpp
| Class: Megaminx
| Description: The entire megaminx
| Author: Kelsey Cole
-----------------------------------*/
#include "Megaminx.h"

Megaminx::Megaminx()
{
	Block temp_q1[TOP_CAP];
	Block temp_q2[TOP_CAP];
	for(int i = 0; i < NUMBER_OF_FACES/2; i++)
	{
		for (int j = 0; j <TOP_CAP; j++)
		{
			Color color1 = Color(i);
			Color color2 = Color(NUMBER_OF_FACES -(i+1));	
			Block temp1(color1);
			Block temp2(color2);
			temp_q1[j] = temp1;
			temp_q2[j] = temp2;
			
		}
	
		Row center1(temp_q1);
		Row top1(temp_q1);
		Row topr1(temp_q1);
		Row botr1(temp_q1);
		Row botl1(temp_q1);
		Row topl1(temp_q1);
	
		Row center2(temp_q2);
		Row top2(temp_q2);
		Row topr2(temp_q2);
		Row botr2(temp_q2);
		Row botl2(temp_q2);
		Row topl2(temp_q2);
 	
		Face temp_face1(center1, top1, topr1, botr1, botl1, topl1);
		Face temp_face2(center2, top2, topr2, botr2, botl2, topl2);
		faces_array1[i] = temp_face1;
		faces_array2[i] = temp_face2;	
	}		
			  	
}

Megaminx::Megaminx(const Megaminx &copy)
{
	for(int i = 0; i < NUMBER_OF_FACES/2; i++)
	{
		this->faces_array1[i] = copy.faces_array1[i];
		this->faces_array2[i] = copy.faces_array2[i];
	}

}

void Megaminx::print()
{
	//side 1 face 0 top 
	std::cout << std::setw(20);
	faces_array1[0].print_top();
	std::cout << std::setw(35);
	
	//side 2 faces 4-5 
	faces_array2[4].print_top();
	std::cout << "  "; 
	faces_array2[5].print_top();
	std::cout << std::endl;
	
	//side 1 face 0 center
	std::cout << std::setw(20);
	faces_array1[0].print_center();
	std::cout << std::setw(35);
	
	//side 2 faces 4-5 center
	faces_array2[4].print_center();
	std::cout << " ";
	faces_array2[5].print_center();
	std::cout << std::endl;
	
	//side 1 face 0 bottom
	std::cout << std::setw(22);
	faces_array1[0].print_bot1();
	std::cout << std::setw(37);
	
	//side 2 faces 4-5 bottom
	faces_array2[4].print_bot1();
	std::cout << "   ";
	faces_array2[5].print_bot1();
	std::cout << std::endl;
	
	//side 1 face 0 bottom 2
	std::cout << std::setw(22);
	faces_array1[0].print_bot2();
	std::cout << std::setw(37);
	
	//side 2 faces 4-5 bottom 2
	faces_array2[4].print_bot2();
	std::cout << "   ";
	faces_array2[5].print_bot2();
	std::cout << std::endl;

	//side 1 face 0 bottom 3
	std::cout << std::setw(24);
	faces_array1[0].print_bot3();
	std::cout << std::setw(41);
	
	//side 2 faces 4-5 bottom 3
	faces_array2[4].print_bot3();
	std::cout << std::setw(19);
	faces_array2[5].print_bot3();
	std::cout << std::endl <<std::endl;
	
	//side 1 faces 1-3 top
	faces_array1[1].print_top();
	std::cout << " ";
	faces_array1[2].print_top();
	std::cout << " ";
	faces_array1[3].print_top();
	std::cout << std::setw(20);
	
	//side 2 faces 1-3 top
	faces_array2[1].print_top();
	std::cout << " ";
	faces_array2[2].print_top();
	std::cout << " ";
	faces_array2[3].print_top();
	std::cout << " ";
	
	std::cout << std::endl;
	
	//side 1 faces 1-3 center
	faces_array1[1].print_center();
	std::cout << " ";
	faces_array1[2].print_center();
	std::cout << " ";
	faces_array1[3].print_center();
	std::cout << std::setw(20);
	
	//side 2 faces 1-3 center
	faces_array2[1].print_center();
	std::cout << " ";
	faces_array2[2].print_center();
	std::cout << " ";
	faces_array2[3].print_center();
	std::cout << " ";
	
	std::cout << std::endl;
	
	//side 1 faces 1-3 bottom 1
	std::cout << std::setw(13);
	faces_array1[1].print_bot1();
	std::cout << std::setw(15);
	faces_array1[2].print_bot1();
	std::cout << std::setw(15);
	faces_array1[3].print_bot1();
	std::cout << std::setw(22);
	
	//side 2 faces 1-3 bottom
	faces_array2[1].print_bot1();
	std::cout << std::setw(15);
	faces_array2[2].print_bot1();
	std::cout << std::setw(15);
	faces_array2[3].print_bot1();

	std::cout << std::endl;

	//side 1 faces 1-3 bottom 2
	std::cout << std::setw(13);
	faces_array1[1].print_bot2();
	std::cout << std::setw(15);
	faces_array1[2].print_bot2();
	std::cout << std::setw(15);
	faces_array1[3].print_bot2();
	std::cout << std::setw(22);
		
	//side 2 faces 1-3 bottom 2
	faces_array2[1].print_bot2();
	std::cout << std::setw(15);
	faces_array2[2].print_bot2();
	std::cout << std::setw(15);
	faces_array2[3].print_bot2();
	
	std::cout << std::endl;

	//side 1 faces 1-3 bottom 3
	std::cout << std::setw(15);
	faces_array1[1].print_bot3();
	std::cout << std::setw(19);
	faces_array1[2].print_bot3();
	std::cout << std::setw(19);
	faces_array1[3].print_bot3();
	std::cout << std::setw(26);
	
	//side 2 faces 1-3 bottom 3
	faces_array2[1].print_bot3();
	std::cout << std::setw(19);
	faces_array2[2].print_bot3();
	std::cout << std::setw(19);
	faces_array2[3].print_bot3();
	
	std::cout << std::endl << std::endl;

	//side 1 faces 4-5 
	std::cout << std::setw(17);
	faces_array1[4].print_top();
	std::cout << "  "; 
	faces_array1[5].print_top();
		
	//side 2 face 0 top 
	std::cout << std::setw(35);
	faces_array2[0].print_top();
	std::cout << std::setw(35);
	std::cout << std::endl;
		
	//side 1 faces 4-5 center
	std::cout << std::setw(17);
	faces_array1[4].print_center();
	std::cout << "  ";
	faces_array1[5].print_center();
	
	//side 2 face 0 center
	std::cout << std::setw(35);
	faces_array2[0].print_center();
	std::cout << std::endl;

	//side 1 faces 4-5 bottom
	std::cout << std::setw(19);
	faces_array1[4].print_bot1();
	std::cout << "    ";
	faces_array1[5].print_bot1();

	//side 2 face 0 bottom
	std::cout << std::setw(36);
	faces_array2[0].print_bot1();
	std::cout << std::endl;
		
	//side 1 faces 4-5 bottom 2
	std::cout << std::setw(19);
	faces_array1[4].print_bot2();
	std::cout << "    ";
	faces_array1[5].print_bot2();


	//side 2 face 0 bottom 2
	std::cout << std::setw(36);
	faces_array2[0].print_bot2();
	std::cout << std::endl;

	//side 1 faces 4-5 bottom 3
	std::cout << std::setw(22);
	faces_array1[4].print_bot3();
	std::cout << std::setw(19);
	faces_array1[5].print_bot3();

		
	//side 2 face 0 bottom 3
	std::cout << std::setw(40);
	faces_array2[0].print_bot3();
	std::cout << std::endl;
}	

void get_rand_ints(int &one, int &two, int &three, int sum)
{
	std::random_device rand_dev;
	std::uniform_int_distribution<int> range(0,sum/2);
	
	one = range(rand_dev);
	two = range(rand_dev);
	three = sum - (one + two); 
}

void Megaminx::scramble_top_side1(int random)
{
	//scramble tops from "side 1" view (faces 4 and 5 from side 2 hidden)
	// "rotate" clockwise "random" amount of times
	int turns = 0;
	while (turns < random) 
	{
		Row temp = faces_array2[4].top;
		faces_array2[4].top = faces_array2[5].top;
		faces_array2[5].top = faces_array1[1].top;
		faces_array1[1].top = faces_array1[2].top;
		faces_array1[2].top = faces_array1[3].top;
		faces_array1[3].top = temp;
		turns++;	
	}
}

void Megaminx::scramble_bottom_side2(int random)
{
	//scramble bottoms from "side 2" view
	// "rotate" clockwise "random" amount of times
	int turns = 0;
	while (turns < random) 
	{
		Row temp = faces_array1[4].top;
		faces_array1[4].top = faces_array2[3].top;
		faces_array2[3].top = faces_array2[2].top;
		faces_array2[2].top = faces_array2[1].top;
		faces_array2[1].top = faces_array1[5].top;
		faces_array1[5].top = temp;
		turns++;	
	}
}

void Megaminx::scramble_face0_side1(int random)
{
	//scramble tops from "side1" "face 3" view (this particular view not shown in GUI)
	// "rotate" clockwise "random" amount of times
	// this is so face 0 will be scrambled
	int turns = 0;
	while (turns < random) 
	{
		Row temp = faces_array1[5].top;
		faces_array1[5].top = faces_array2[1].top;
		faces_array2[1].top = faces_array2[4].top;
		faces_array2[4].top = faces_array1[0].top;
		faces_array1[0].top = faces_array1[2].top;
		faces_array1[2].top = temp;
		turns++;	
	}
}

void Megaminx::scramble()
{
	int moves = 0;
	std::cout << "Enter number of desired moves: ";
	std::cin >> moves;
	
	int rand1, rand2, rand3;
	get_rand_ints(rand1, rand2, rand3, moves);
	std::cout << "The tops of side 1 will be scrambled " << rand1 << " times." << std::endl;
	std::cout << "The tops of side 2 bottom view will be scrambled " << rand2 << " times." << std::endl;
	std::cout << "The tops from view of side 1 face 3 view will be scrambled " << rand3 << " times." << std::endl;
	
	//picks a "random" number between 1-10
	// then turns the top from side 2 view clockwise
	// that number of times
	scramble_top_side1(rand1);
	// scramble side 2 bottom
	scramble_bottom_side2(rand2);
	//scramble from view outside of GUI
	scramble_face0_side1(rand3);
}
bool Megaminx::operator==(const Megaminx &other) const
{
		for(int i =0 ; i <SIDE_1_SIZE; i++)
		{
			if((this->faces_array1[i] == other.faces_array1[i])) {}
			else return false;
		}	

		for(int i =0 ; i <SIDE_2_SIZE; i++)
		{
			if((this->faces_array2[i] == other.faces_array2[i])) {}			
			else return false;
		}

		return true;
}


Megaminx::~Megaminx(){ }	
