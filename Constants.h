/*---------------------------------
| File: Constants.h
| Project: Megaminx
| Description: constants for Megaminx
| Author: Kelsey Cole
-----------------------------------*/
#include <string>
//Colors
const std::string red = "\e[31m R \e[0m";
const std::string green = "\e[32m G \e[0m";
const std::string yellow = "\e[33m Y \e[0m";
const std::string blue = "\e[34m B \e[0m"; 
const std::string magenta = "\e[35m M \e[0m";
const std::string cyan = "\e[36m C \e[0m";
const std::string light_red = "\e[91m r \e[0m";
const std::string light_green = "\e[92m g \e[0m"; 
const std::string light_yellow = "\e[93m y \e[0m";
const std::string light_blue = "\e[94m b \e[0m";
const std::string light_magenta = "\e[95m m \e[0m";
const std::string light_cyan = "\e[96m c \e[0m";

//For a single row
const int ROW_SIZE = 3;

//For a single face
const int TOP_CAP = 3; //number of blocks allowed in a row
//For an entire megaminx
const int NUMBER_OF_FACES = 12;
const int SIDE_1_SIZE = 6;
const int SIDE_2_SIZE = 6;

