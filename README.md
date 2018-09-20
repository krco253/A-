# AStar

AStar is a C++ project that utilizes the C++ standard library to model a Megaminx solver by the A* algorithm 

## Getting Started


### Prerequisites
- Can only be properly viewed on terminals that support ANSI characters 

## Installing

1. Download this repository:
```
git clone https://github.com/krco253/megaminx.git
```
(or downloading the folder from Canvas because this is an assignment)

2. Inside of the A- folder, compile with gcc
```
g++ -std=c++11 -o AStar AStar.cpp Block.cpp Row.cpp Face.cpp Megaminx.cpp main.cpp
```
3. Run the program:
```
./AStar
```
### Usage
1. This program must be given an input from the user of how many moves to take for randomization. This is obtained through C++ standard input/output. The user will not be prompted to enter this unless they remove the comment symbols // beside the prompt in the main.cpp

## Authors

* Kelsey Cole 

## Documented Bugs
* Because of the sheer size of object Megaminx, this code, fully uncommented, generates out of memory errors. It works consistently when you comment out any 10 faces from scramble() in Megaminx and the constructor and expand_Megaminx in A*. So, in short, this code works, but will only rotate so many faces at a time because of the sheer size of  the data structure. For all experiments/plots, I've used the top and bottom functions uncommented.


## Acknowledgments

* Used information from these sites to implement random number generator: https://en.cppreference.com/w/cpp/numeric/random/random_device and https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution 
* Also saw Harrison Incencio's GUI implementation on the discussion board, and drew inspiration for formatting my GUI output from it.
* Michael Murray gave me my idea for how I've changed my randomization since my last project; he inspired the algorithm I chose, in that I assign each face a number, generate a random number and then choose the cooresponding face to rotate.
* My heuristic was an idea presented in lecture
