# Megaminx

Megaminx is a C++ project that utilizes the C++ standard library to model a Megaminx 

## Getting Started


### Prerequisites
- Can only be properly viewed on terminals, and they must support ANSI characters 

## Installing

1. Download this repository:
```
git clone https://github.com/krco253/megaminx.git
```
(or downloading the folder from Canvas works, too, if you don't have my login information)

2. Inside of the megaminx folder, compile with gcc
```
g++ -o Megaminx Block.cpp Row.cpp Face.cpp Megaminx.cpp main.cpp
```
3. Run the program:
```
./Megaminx
```
### Usage
1. This program must be given an input from the user of how many moves to take for randomization. This is obtained through C++ standard input/output. The user will be prompted to enter the information when appropriate.

## Authors

* Kelsey Cole 


## Acknowledgments

* Used information from these sites to implement random number generator: https://en.cppreference.com/w/cpp/numeric/random/random_device and https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution 
* Also saw Harrison Incencio's GUI implementation on the discussion board, and drew inspiration for formatting my GUI output from it.
