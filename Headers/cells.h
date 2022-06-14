// Declaration for the Cells class
// @file cells.h
// @Author Ethan Rudy

#ifndef CELLS_H
#define CELLS_H

#include <SFML/Graphics.hpp>

#include "constants.h"

class Cells
{
	int size;	// Holds the size of one side of the cell grid
	bool cells[SIZE * SIZE];	// Holds the cell state of the cell grid
	bool nextCells[SIZE * SIZE];	// The updated grid of cell states
	bool paused = true;	// Pause state flag

	/*
		Initialize

		@param "arr[]" of type BOOL
		@param "size" of type INT
	*/
	void init(bool arr[], int size);

	/*
		Sum of Surrounding

		@param "x" of type INT
		@param "y" of type INT

		@return the sum of alive cells at the passed (x, y) coordinates
	*/
	int sumSur(int x, int y);

	/*
		Stays alive

		@param "alive" of type BOOL
		@param "sur" of type INT

		@returns if the cell tested stays alived based on current state and 
			surrounding cells
	*/
	bool stays(bool alive, int sur);

public:
	/*
		Default Constructor
	*/
	Cells();
	/*
		Deconstructor
	*/
	~Cells();

	/*
		Add Cell

		@param "x" of type INT
		@param "y" of type INT
	*/
	void addCell(int x, int y);
	/*
		Remove Cell

		@param "x" of type INT
		@param "y" of type INT
	*/
	void remCell(int x, int y);

	/*
		Steps forward in the cell grid's life
	*/
	void step();

	/*
		Render

		@param window of type SF::RENDERWINDOW
	*/
	void render(sf::RenderWindow& window);

	/*
		Pause/Unpause the simulation
	*/
	void pause();

	/*
		Checks if the cell grid is paused

		@return BOOL value
	*/
	bool isPaused();
};


#endif
