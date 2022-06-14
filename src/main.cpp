// Main file for a Conway's Game of Life simulation
// @file main.cpp
// @author Ethan Rudy

#include "simulation.h"

/*
* DISCLAIMER: Written with SFML-2.5.1 and is required to run. Can be found here: https://www.sfml-dev.org/download/sfml/2.5.1/
*
* Controls:
* - Left click to place a live cell
* - Right click to remove a live cell
* - Spacebar to pause/unpase the simulation (simulation starts paused for cell placement)
* 
* Game rules here: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
*/
int main() {
	Simulation s; // Simulation object
	s.run();	// Runs the simulation
	return 0;
}
