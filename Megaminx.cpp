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
	
	g = 0;
	h = 0;
	f = 0;		  	
}

Megaminx::Megaminx(const Megaminx &copy)
{
	for(int i = 0; i < NUMBER_OF_FACES/2; i++)
	{
		this->faces_array1[i] = copy.faces_array1[i];
		this->faces_array2[i] = copy.faces_array2[i];
	}
	
	this->g = copy.g;
	this->h = copy.h;
	this->f = copy.f;
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

void Megaminx::scramble_top(int random)
{
	//scramble tops from "side 1" view (faces 4 and 5 from side 2 hidden)
	// "rotate" clockwise "random" amount of times
	int turns = 0;
	while (turns < random) 
	{
		Row temp = faces_array2[4].top;
		faces_array2[4].top = faces_array2[5].top;
		faces_array2[4].sync("top");
	
		faces_array2[5].top = faces_array1[1].top;
		faces_array2[5].sync("top");
		
		faces_array1[1].top = faces_array1[2].top;
		faces_array1[1].sync("top");

		faces_array1[2].top = faces_array1[3].top;
		faces_array1[2].sync("top");

		faces_array1[3].top = temp;
		faces_array1[3].sync("top");

		turns++;	
	}
}

void Megaminx::scramble_bottom(int random)
{
	//scramble bottom (which are "tops" by defintion of Face)
	// from "side 1" view
	// "rotate" clockwise "random" amount of times
	int turns = 0;
	while (turns < random) 
	{
		Row temp = faces_array1[4].top;
		faces_array1[4].top = faces_array1[5].top;
		faces_array1[4].sync("top");
	
		faces_array1[5].top = faces_array2[1].top;
		faces_array1[5].sync("top");	

		faces_array2[1].top = faces_array2[2].top;
		faces_array2[1].sync("top");	

		faces_array2[2].top = faces_array2[3].top;
		faces_array2[2].sync("top");

		faces_array2[3].top = temp;
		faces_array2[3].sync("top");

		turns++;	

	}
}

void Megaminx::scramble_bot_left(int random)
{
	//scramble "bottom left"
	//from "side 1" view
	//rotate clockwise random amount of times
	int turns = 0;
	while (turns < random)
	{
		Row temp = faces_array1[5].top_right;
		faces_array1[5].top_right = faces_array1[2].bot_left;
		faces_array1[5].sync("top_right");

		faces_array1[2].bot_left = faces_array1[1].bot_right;
		faces_array1[2].sync("bot_left");
	
		faces_array1[1].bot_right = faces_array2[3].top_left;
		faces_array1[1].sync("bot_right");
	
		faces_array2[3].top_left = faces_array2[0].bot_right;
		faces_array2[3].sync("top_left");
		
		faces_array2[0].bot_right = temp;
		faces_array2[0].sync("bot_right");
		turns++;
	}
}

Megaminx Megaminx::rotate_bot_left()
{
	//scramble "bottom left"
	//from "side 1" view
	//rotate clockwise random amount of times

	Megaminx manip_megaminx; //create a megaminx to apply manipulations to
	manip_megaminx = *this;	//copy this megaminx into it	

	Row temp = (manip_megaminx.faces_array2[0]).bot_right;
	(manip_megaminx.faces_array2[0]).bot_right = (manip_megaminx.faces_array2[3]).top_left;
	(manip_megaminx.faces_array2[0]).sync("bot_right");

 	(manip_megaminx.faces_array2[3]).top_left = (manip_megaminx.faces_array1[1]).bot_right;
 	(manip_megaminx.faces_array2[3]).sync("top_left"); 

	(manip_megaminx.faces_array1[1]).bot_right = (manip_megaminx.faces_array1[2]).bot_left;
	(manip_megaminx.faces_array1[1]).sync("bot_right"); 

	(manip_megaminx.faces_array1[2]).bot_left = (manip_megaminx.faces_array1[5]).top_right;
	(manip_megaminx.faces_array1[2]).sync("bot_left"); 	

	(manip_megaminx.faces_array1[5]).top_right = temp;
	(manip_megaminx.faces_array1[5]).sync("top_right"); 	

	return manip_megaminx;
	
}

void Megaminx::scramble_bot_right(int random)
{
	//scramble "bottom right"
	//from "side 1" view
	// rotate clockwise random amount of times
	int turns = 0;
	while (turns < random)
	{
		Row temp = faces_array1[4].top_right;
		faces_array1[4].top_right = faces_array2[0].bot_left;
		faces_array1[4].sync("top_right");
		
		faces_array2[0].bot_left = faces_array2[1].bot_left;
		faces_array2[0].sync("bot_left");
		
		faces_array2[1].bot_left = faces_array1[3].bot_left;
		faces_array2[1].sync("bot_left");

		faces_array1[3].bot_left = faces_array1[2].bot_right;
		faces_array1[3].sync("bot_left");

		faces_array1[2].bot_right = temp;
		faces_array1[2].sync("bot_right");

		turns++;
	}

}

Megaminx Megaminx::rotate_bot_right()
{
	//scramble "bottom left"
	//from "side 1" view
	//rotate clockwise random amount of times

	Megaminx manip_megaminx; //create a megaminx to apply manipulations to
	manip_megaminx = *this;	//copy this megaminx into it	

	Row temp = (manip_megaminx.faces_array1[2]).bot_right;
	(manip_megaminx.faces_array1[2]).bot_right = (manip_megaminx.faces_array1[3]).bot_left;
	(manip_megaminx.faces_array1[2]).sync("bot_right");

 	(manip_megaminx.faces_array1[3]).bot_left = (manip_megaminx.faces_array2[1]).bot_left;
 	(manip_megaminx.faces_array1[3]).sync("bot_left"); 

	(manip_megaminx.faces_array2[1]).bot_left = (manip_megaminx.faces_array2[0]).bot_left;
	(manip_megaminx.faces_array2[1]).sync("bot_left"); 

	(manip_megaminx.faces_array2[0]).bot_left = (manip_megaminx.faces_array1[4]).top_right;
	(manip_megaminx.faces_array2[0]).sync("bot_left"); 	

	(manip_megaminx.faces_array1[4]).top_right = temp;
	(manip_megaminx.faces_array1[4]).sync("top_right"); 	

	return manip_megaminx;	
}

void Megaminx::scramble_2_2(int random)
{
	//scramble blocks around face 2 from side 2 view
	//rotate clockwise random amount of times
	int turns = 0;
	while (turns < random)
	{
		Row temp = faces_array2[1].top_left;
		faces_array2[1].top_left = faces_array2[0].top;
		faces_array2[1].sync("top_left");
		
		faces_array2[0].top = faces_array2[3].top_right;
		faces_array2[1].sync("top");

		faces_array2[3].top_right = faces_array2[5].bot_left;
		faces_array2[3].sync("top_right");

		faces_array2[5].bot_left = faces_array2[4].bot_right;
		faces_array2[5].sync("bot_left");

		faces_array2[4].bot_right = temp;
		faces_array2[4].sync("bot_right");

		turns++;
	}
}


Megaminx Megaminx::rotate_2_2()
{
	//scramble "bottom left"
	//from "side 1" view
	//rotate clockwise random amount of times

	Megaminx manip_megaminx; //create a megaminx to apply manipulations to
	manip_megaminx = *this;	//copy this megaminx into it	

	Row temp = (manip_megaminx.faces_array2[4]).bot_right;
	(manip_megaminx.faces_array2[4]).bot_right = (manip_megaminx.faces_array2[5]).bot_left;
	(manip_megaminx.faces_array2[4]).sync("bot_right");

 	(manip_megaminx.faces_array2[5]).bot_left = (manip_megaminx.faces_array2[3]).top_right;
 	(manip_megaminx.faces_array2[5]).sync("bot_left"); 

	(manip_megaminx.faces_array2[3]).top_right = (manip_megaminx.faces_array2[0]).top;
	(manip_megaminx.faces_array1[1]).sync("top_right"); 

	(manip_megaminx.faces_array2[0]).top = (manip_megaminx.faces_array2[1]).top_left;
	(manip_megaminx.faces_array2[0]).sync("top"); 	

	(manip_megaminx.faces_array2[1]).top_left = temp;
	(manip_megaminx.faces_array2[1]).sync("top_left"); 	

	return manip_megaminx;

}


void Megaminx::scramble_2_4(int random)
{
	int turns = 0;
	while(turns < random)
	{
		Row temp = faces_array2[1].bot_left;
		faces_array2[1].bot_left = faces_array2[2].bot_right;
		faces_array2[1].sync("bot_left");
		
		faces_array2[2].bot_right = faces_array2[5].top_left;
		faces_array2[2].sync("bot_right");
		
		faces_array2[5].top_left = faces_array1[0].bot_left;
		faces_array2[5].sync("top_left");
			
		faces_array1[0].bot_left = faces_array1[3].top_right;
		faces_array1[0].sync("bot_left");
		
		faces_array1[3].top_right = temp;
		faces_array1[3].sync("top_right");
		
		turns++;
	}
}

Megaminx Megaminx::rotate_2_4()
{
	//scramble "bottom left"
	//from "side 1" view
	//rotate clockwise random amount of times

	Megaminx manip_megaminx; //create a megaminx to apply manipulations to
	manip_megaminx = *this;	//copy this megaminx into it	

	Row temp = (manip_megaminx.faces_array1[3]).top_right;
	(manip_megaminx.faces_array1[3]).top_right = (manip_megaminx.faces_array1[0]).bot_left;
	(manip_megaminx.faces_array1[3]).sync("top_right");

 	(manip_megaminx.faces_array1[0]).bot_left = (manip_megaminx.faces_array2[5]).top_left;
 	(manip_megaminx.faces_array1[0]).sync("bot_left"); 

	(manip_megaminx.faces_array2[5]).top_left = (manip_megaminx.faces_array2[2]).bot_right;
	(manip_megaminx.faces_array2[5]).sync("top_left"); 

	(manip_megaminx.faces_array2[2]).bot_right = (manip_megaminx.faces_array2[1]).bot_left;
	(manip_megaminx.faces_array2[2]).sync("bot_right"); 	

	(manip_megaminx.faces_array2[1]).bot_left = temp;
	(manip_megaminx.faces_array2[1]).sync("bot_left"); 	

	return manip_megaminx;
}

void Megaminx::scramble_2_1(int random)
{
	int turns = 0;
	while(turns < random)
	{
		Row temp = faces_array2[4].bot_left;
		faces_array2[4].bot_left = faces_array1[3].bot_right;
		faces_array2[4].sync("bot_left");

		faces_array1[3].bot_right = faces_array1[5].top_right;
		faces_array1[3].sync("bot_right");

		faces_array1[5].top_right = faces_array2[0].top_left;
		faces_array1[5].sync("top_right");
		
		faces_array2[0].top_left = faces_array2[2].top_right;
		faces_array2[0].sync("top_left");
		
		faces_array2[2].top_right = temp;
		faces_array2[2].sync("top_right");

		turns++;
	}
}

Megaminx Megaminx::rotate_2_1()
{
	//scramble "bottom left"
	//from "side 1" view
	//rotate clockwise random amount of times

	Megaminx manip_megaminx; //create a megaminx to apply manipulations to
	manip_megaminx = *this;	//copy this megaminx into it	

	Row temp = (manip_megaminx.faces_array2[2]).top_right;
	(manip_megaminx.faces_array2[2]).top_right = (manip_megaminx.faces_array2[0]).top_left;
	(manip_megaminx.faces_array2[2]).sync("top_right");

 	(manip_megaminx.faces_array2[0]).top_left = (manip_megaminx.faces_array1[5]).top_right;
 	(manip_megaminx.faces_array2[0]).sync("top_left"); 

	(manip_megaminx.faces_array1[5]).top_right = (manip_megaminx.faces_array1[3]).bot_right;
	(manip_megaminx.faces_array1[5]).sync("top_right"); 

	(manip_megaminx.faces_array1[3]).bot_right = (manip_megaminx.faces_array2[4]).bot_left;
	(manip_megaminx.faces_array1[3]).sync("bot_right"); 	

	(manip_megaminx.faces_array2[4]).bot_left = temp;
	(manip_megaminx.faces_array2[4]).sync("bot_left"); 	

	return manip_megaminx;

}

void Megaminx::scramble_2_3(int random)
{
	int turns = 0;
	while(turns < random)
	{
		Row temp = faces_array2[0].top_right;
		faces_array2[0].top_right = faces_array1[4].top_right;
		faces_array2[0].sync("top_right");

		faces_array1[4].top_right = faces_array1[1].bot_left;
		faces_array1[4].sync("top_right");

		faces_array1[1].bot_left = faces_array2[5].bot_right;
		faces_array1[1].sync("bot_left");

		faces_array2[5].bot_right = faces_array2[2].top_left;
		faces_array2[5].sync("bot_right");
	
		faces_array2[2].top_left = temp;
		faces_array2[2].sync("top_left");
		
		turns++;
	}
}

Megaminx Megaminx::rotate_2_3()
{
	//scramble "bottom left"
	//from "side 1" view
	//rotate clockwise random amount of times

	Megaminx manip_megaminx; //create a megaminx to apply manipulations to
	manip_megaminx = *this;	//copy this megaminx into it	

	Row temp = (manip_megaminx.faces_array2[2]).top_left;
	(manip_megaminx.faces_array2[2]).top_left = (manip_megaminx.faces_array2[5]).bot_right;
	(manip_megaminx.faces_array2[2]).sync("top_left");

 	(manip_megaminx.faces_array2[5]).bot_right = (manip_megaminx.faces_array1[1]).bot_left;
 	(manip_megaminx.faces_array2[5]).sync("bot_right"); 

	(manip_megaminx.faces_array1[1]).bot_left = (manip_megaminx.faces_array1[4]).top_right;
	(manip_megaminx.faces_array1[1]).sync("bot_left"); 

	(manip_megaminx.faces_array1[4]).top_right = (manip_megaminx.faces_array2[0]).top_right;
	(manip_megaminx.faces_array1[4]).sync("top_right"); 	

	(manip_megaminx.faces_array2[0]).top_right = temp;
	(manip_megaminx.faces_array2[0]).sync("top_right"); 	

	return manip_megaminx;

}

void Megaminx::scramble_2_5(int random)
{
	int turns = 0;
	while(turns < random)
	{
		Row temp = faces_array2[2].bot_left;
		faces_array2[2].bot_left = faces_array2[3].bot_right;
		faces_array2[2].sync("bot_left");

		faces_array2[3].bot_right = faces_array1[1].top_left;
		faces_array2[3].sync("bot_right");

		faces_array1[1].top_left = faces_array1[0].bot_right;
		faces_array1[1].sync("top_left");

		faces_array1[0].bot_right = faces_array2[4].top_right;
		faces_array1[0].sync("bot_right");

		faces_array2[4].top_right = temp;
		faces_array2[4].sync("top_right");
	
		turns++;
	}
}

Megaminx Megaminx::rotate_2_5()
{
	//scramble "bottom left"
	//from "side 1" view
	//rotate clockwise random amount of times

	Megaminx manip_megaminx; //create a megaminx to apply manipulations to
	manip_megaminx = *this;	//copy this megaminx into it	

	Row temp = (manip_megaminx.faces_array2[4]).top_right;
	(manip_megaminx.faces_array2[4]).top_right = (manip_megaminx.faces_array1[0]).bot_right;
	(manip_megaminx.faces_array2[4]).sync("top_right");

 	(manip_megaminx.faces_array1[0]).bot_right = (manip_megaminx.faces_array1[1]).top_left;
 	(manip_megaminx.faces_array1[0]).sync("bot_right"); 

	(manip_megaminx.faces_array1[1]).top_left = (manip_megaminx.faces_array2[3]).bot_right;
	(manip_megaminx.faces_array1[1]).sync("top_left"); 

	(manip_megaminx.faces_array2[3]).bot_right = (manip_megaminx.faces_array2[2]).bot_left;
	(manip_megaminx.faces_array2[3]).sync("bot_right"); 	

	(manip_megaminx.faces_array2[2]).bot_left = temp;
	(manip_megaminx.faces_array2[2]).sync("bot_left"); 	

	return manip_megaminx;

}

void Megaminx::scramble_left_side(int random)
{
	//scramble "left" rotating side of megaminx
	//from "side 1" view
	//rotate clockwise "random" amount of times
	int turns = 0;
	while (turns < random) 
	{
		Row temp = faces_array1[2].top_left;

		faces_array1[2].top_left = faces_array1[0].top_left;
		faces_array1[2].sync("top_left");
		faces_array1[0].top_left = faces_array2[5].top_right;
		faces_array1[0].sync("top_left");
		faces_array2[5].top_right = faces_array2[3].bot_left;
		faces_array2[5].sync("top_right");
		faces_array2[3].bot_left = faces_array1[4].bot_right;
		faces_array2[3].sync("bot_left");
		faces_array1[4].bot_right = temp;
		faces_array1[4].sync("bot_right");
		turns++;	
	}

}

Megaminx Megaminx::rotate_left_side()
{
	//scramble "bottom left"
	//from "side 1" view
	//rotate clockwise random amount of times

	Megaminx manip_megaminx; //create a megaminx to apply manipulations to
	manip_megaminx = *this;	//copy this megaminx into it	

	Row temp = (manip_megaminx.faces_array1[4]).bot_right;
	(manip_megaminx.faces_array1[4]).bot_right = (manip_megaminx.faces_array2[3]).bot_left;
	(manip_megaminx.faces_array1[4]).sync("bot_right");

 	(manip_megaminx.faces_array2[3]).bot_left = (manip_megaminx.faces_array2[5]).top_right;
 	(manip_megaminx.faces_array2[3]).sync("bot_left"); 

	(manip_megaminx.faces_array2[5]).top_right = (manip_megaminx.faces_array1[0]).top_left;
	(manip_megaminx.faces_array2[5]).sync("top_right"); 

	(manip_megaminx.faces_array1[0]).top_left = (manip_megaminx.faces_array1[2]).top_left;
	(manip_megaminx.faces_array1[0]).sync("top_left"); 	

	(manip_megaminx.faces_array1[2]).top_left = temp;
	(manip_megaminx.faces_array1[2]).sync("top_left"); 	

	return manip_megaminx;

}

void Megaminx::scramble_right_side(int random)
{
	//scramble "right" rotating side of megaminx
	//from "side 1" view
	//rotate clockwise "random" amount of times
	int turns = 0;
	while (turns < random)
	{
		Row temp = faces_array1[2].top_right;
		faces_array1[2].top_right = faces_array1[5].bot_left;
		faces_array1[2].sync("top_right");
	
		faces_array1[5].bot_left = faces_array2[1].bot_right;
		faces_array1[5].sync("bot_left");

		faces_array2[1].bot_right = faces_array2[4].top_left;
		faces_array2[1].sync("bot_right");
	
		faces_array2[4].top_left = faces_array1[0].top_right;
		faces_array2[4].sync("top_left");

		faces_array1[0].top_right = temp;
		faces_array1[0].sync("top_right");

		turns++;
	}

}
Megaminx Megaminx::rotate_right_side()
{
	//scramble "bottom left"
	//from "side 1" view
	//rotate clockwise random amount of times

	Megaminx manip_megaminx; //create a megaminx to apply manipulations to
	manip_megaminx = *this;	//copy this megaminx into it	

	Row temp = (manip_megaminx.faces_array1[0]).top_right;
	(manip_megaminx.faces_array1[0]).top_right = (manip_megaminx.faces_array2[4]).top_left;
	(manip_megaminx.faces_array1[0]).sync("top_right");

 	(manip_megaminx.faces_array2[4]).top_left = (manip_megaminx.faces_array2[1]).bot_right;
 	(manip_megaminx.faces_array2[4]).sync("top_left"); 

	(manip_megaminx.faces_array2[1]).bot_right = (manip_megaminx.faces_array1[5]).bot_left;
	(manip_megaminx.faces_array2[1]).sync("bot_right"); 

	(manip_megaminx.faces_array1[5]).bot_left = (manip_megaminx.faces_array1[2]).top_right;
	(manip_megaminx.faces_array1[5]).sync("bot_left"); 	

	(manip_megaminx.faces_array1[2]).top_right = temp;
	(manip_megaminx.faces_array1[2]).sync("top_right"); 	

	return manip_megaminx;

}

void Megaminx::scramble_1_2(int random)
{
	//scramble "bottom left" rotating side of megaminx
	//from "side 1" view
	// rotate clockwise "random" amount of times
	int turns = 0;
	while(turns < random)
	{
		Row temp = faces_array1[0].top;
		faces_array1[0].top = faces_array1[1].top_right;
	
		faces_array1[1].top_right = faces_array1[4].bot_left;
		faces_array1[1].sync("top_right");
	
		faces_array1[4].bot_left = faces_array1[5].bot_right;
		faces_array1[4].sync("bot_left");

		faces_array1[5].bot_right = faces_array1[3].top_right;
		faces_array1[5].sync("bot_right");
		
		faces_array1[3].top_right = temp;
		faces_array1[3].sync("top_right");
		turns++;
	}
}
Megaminx Megaminx::rotate_1_2()
{
	//scramble "bottom left"
	//from "side 1" view
	//rotate clockwise random amount of times

	Megaminx manip_megaminx; //create a megaminx to apply manipulations to
	manip_megaminx = *this;	//copy this megaminx into it	

	Row temp = (manip_megaminx.faces_array1[3]).top_right;
	(manip_megaminx.faces_array1[3]).top_right = (manip_megaminx.faces_array1[5]).bot_right;
	(manip_megaminx.faces_array1[3]).sync("top_right");

 	(manip_megaminx.faces_array1[5]).bot_right = (manip_megaminx.faces_array1[4]).bot_left;
 	(manip_megaminx.faces_array1[5]).sync("bot_right"); 

	(manip_megaminx.faces_array1[4]).bot_left = (manip_megaminx.faces_array1[1]).top_right;
	(manip_megaminx.faces_array1[4]).sync("bot_left"); 

	(manip_megaminx.faces_array1[1]).top_right = (manip_megaminx.faces_array1[0]).top;
	(manip_megaminx.faces_array1[1]).sync("top_right"); 	

	(manip_megaminx.faces_array1[0]).top = temp;
	(manip_megaminx.faces_array1[0]).sync("top"); 	

	return manip_megaminx;

}

void Megaminx::scramble()
{
	int moves = 0;
//	std::cout << "Enter number of desired moves: ";
	std::cin >> moves;
	
	//std::cout << "The tops from view of side 1 face 3 view will be scrambled " << rand3 << " times." << std::endl;

	std::random_device rand_dev;
	std::uniform_int_distribution<int> range(0,1);
	for(int i = 0; i < moves; i++)
	{
		int which_move = range(rand_dev);

		switch(which_move)
		{
		case 0:
		{
			this->scramble_top(1);	 
			break;
		}
		case 1:
		{	this->scramble_bottom(1);
			break;
		}
		case 2:
		{	this->scramble_left_side(1);
			break;
		}
		case 3:
		{	this->scramble_right_side(1);
			break;
		}
		case 4:
		{	this->scramble_1_2(1);
			break;
		}
		case 5:
		{	this->scramble_bot_left(1);
			break;
		}
		case 6:
		{	this->scramble_bot_right(1);
			break;
		}
		case 7:
		{	this->scramble_2_2(1);
			break;
		}
		case 8:
		{	this->scramble_2_4(1);
			break;
		}
		case 9:
		{	this->scramble_2_1(1);
			break;
		}
		case 10:
		{	this->scramble_2_3(1);
			break;
		}
		case 11:
		{	this->scramble_2_5(1);
			break;
		}

		}
	}

	

}
int Megaminx::calculate_stickers()
{		
	int misplaced_stickers = 0;
	for(int i =0; i < SIDE_1_SIZE; i++)//for each face in side 1
	{
		Face current_face = (this->faces_array1[i]);
		Block center_sticker((current_face.center).row[1]); //the main center sticker of the face

		for(int j =0; j < ROW_SIZE; j++) //for top row of face
		{
			if((current_face.top).row[j] != center_sticker)
				misplaced_stickers++;
		}

		if ((current_face.center).row[0] != center_sticker)
			misplaced_stickers++;
		if((current_face.center).row[2] != center_sticker)
			misplaced_stickers++;
	
		for(int j =0; j < ROW_SIZE; j++) //for bottom left row of face
		{
			if((current_face.bot_left).row[j] != center_sticker)
				misplaced_stickers++;
		}
		 
		if ((current_face.bot_right).row[0] != center_sticker)
			misplaced_stickers++;
		if((current_face.bot_right).row[2] != center_sticker)
			misplaced_stickers++;		
	
	}

	for(int i =0; i < SIDE_2_SIZE; i++)//for each face in side 1
	{
		Face current_face = (this->faces_array2[i]);
		Block center_sticker((current_face.center).row[1]); //the main center sticker of the face

		for(int j =0; j < ROW_SIZE; j++) //for top row of face
		{
			if((current_face.top).row[j] != center_sticker)
				misplaced_stickers++;
		}

		if ((current_face.center).row[0] != center_sticker)
			misplaced_stickers++;
		if((current_face.center).row[2] != center_sticker)
			misplaced_stickers++;
	
		for(int j =0; j < ROW_SIZE; j++) //for bottom left row of face
		{
			if((current_face.bot_left).row[j] != center_sticker)
				misplaced_stickers++;
		}
		 
		if ((current_face.bot_right).row[0] != center_sticker)
			misplaced_stickers++;
		if((current_face.bot_right).row[2] != center_sticker)
			misplaced_stickers++;		
	}	
	return misplaced_stickers;
}
void Megaminx::distance_to_solved(int depth)
{
	int misplaced_sticks = this->calculate_stickers();
	this->g = depth;
		
	//assign h to be the ceiling of the number of misplaced stickers divided by 15
	this->h = (misplaced_sticks / 15) + (misplaced_sticks % 15 != 0);
	this->f = h + g;
}

/*----------------------------------------
|               rotate_top()    
|-----------------------------------------
| Description: return copy of this Megaminx 
| top rotated counterclockwise by one
------------------------------------------*/
Megaminx Megaminx::rotate_top()
{
	Megaminx manip_megaminx; //create a megaminx to apply manipulations to
	manip_megaminx = *this;	//copy this megaminx into it	

	Row temp = (manip_megaminx.faces_array2[5]).top;
	(manip_megaminx.faces_array2[5]).top = (manip_megaminx.faces_array2[4]).top;
	(manip_megaminx.faces_array2[4]).top = (manip_megaminx.faces_array1[3]).top;
	(manip_megaminx.faces_array1[3]).top = (manip_megaminx.faces_array1[2]).top;
	(manip_megaminx.faces_array1[2]).top = (manip_megaminx.faces_array1[1]).top;
	(manip_megaminx.faces_array1[1]).top = temp;
	
	return manip_megaminx;

}

/*----------------------------------------
|               rotate_bot()    
|-----------------------------------------
| Description: return copy of this Megaminx 
| bottom rotated counterclockwise by one
------------------------------------------*/
Megaminx Megaminx::rotate_bot()
{
	Megaminx manip_megaminx; //create a megaminx to apply manipulations to
	manip_megaminx = *this;	//copy this megaminx into it

	Row temp = (manip_megaminx.faces_array1[4]).top;
	(manip_megaminx.faces_array1[4]).top = (manip_megaminx.faces_array2[3]).top;
	(manip_megaminx.faces_array2[3]).top = (manip_megaminx.faces_array2[2]).top;
	(manip_megaminx.faces_array2[2]).top = (manip_megaminx.faces_array2[1]).top;
	(manip_megaminx.faces_array2[1]).top = (manip_megaminx.faces_array1[5]).top;
	(manip_megaminx.faces_array1[5]).top = temp;

	return manip_megaminx;
}


bool Megaminx::operator>(const Megaminx &other) const
{
	if(this->f < other.f) //std::priority_queue puts largest element on top by default, but we want the smallest.
		return true;
	else return false;
}

bool Megaminx::operator<(const Megaminx &other) const
{
	if(this->f > other.f)
		return true;
	else return false;
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
bool Megaminx::operator!=(const Megaminx &other) const
{
	if(*this == other)
		return false;
	else return true;
}

bool Megaminx::is_solved()
{
	Megaminx blank;
	if(*this == blank)
		return true;
	else
		return false;
}

Megaminx::~Megaminx(){ }	
