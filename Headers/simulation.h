// Declaration for the Simulation class
// @file simulation.h
// @Author Ethan Rudy


#ifndef SIMULATION_H
#define SIMULATION_H

#include "cells.h"

class Simulation {
private:
	sf::RenderWindow window;	// Window object
	Cells cells;	// Cell grid
public:
	/*
		Default constructor
	*/
	Simulation();
	/*
		Deconstructor
	*/
	~Simulation();

	/*
		Runs the simulation
	*/
	void run();
};

#endif
