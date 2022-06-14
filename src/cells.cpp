// Initialization for the Cells class
// @file cells.cpp
// @Author Ethan Rudy

#include "cells.h"
#include <iostream>
#include <iterator>

// Declaring IX in this instance
int IX(int x, int y, int N);

// Default Constructor
Cells::Cells(){
	this->size = SIZE;
	this->init(cells, SIZE * SIZE);
	this->init(nextCells, SIZE * SIZE);
}

// Deconstructor
Cells::~Cells() {}

// Initialize
void Cells::init(bool arr[], int size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = false;
	}
}

// Sum of Surrounding
int Cells::sumSur(int x, int y) {
	int sum = 0;
	sum += this->cells[IX(x + 1, y + 1, this->size)];
	sum += this->cells[IX(x + 1, y, this->size)];
	sum += this->cells[IX(x + 1, y - 1, this->size)];
	sum += this->cells[IX(x, y + 1, this->size)];
	sum += this->cells[IX(x, y - 1, this->size)];
	sum += this->cells[IX(x - 1, y + 1, this->size)];
	sum += this->cells[IX(x - 1, y, this->size)];
	sum += this->cells[IX(x - 1, y - 1, this->size)];
	return sum;
}

// Stays alive
bool Cells::stays(bool alive, int sur) {
	if (alive) {
		if (sur < 2 || sur > 3) {
			return false;
		}
		return true;
	}
	if (sur == 3) {
		return true;
	}
	return false;
}

// Add Cell
void Cells::addCell(int x, int y) {
	this->cells[IX(x, y, this->size)] = true;
}

// Remove Cell
void Cells::remCell(int x, int y) {
	this->cells[IX(x, y, this->size)] = false;
}

// Steps forward in the cell grid's life
void Cells::step() {
	// Only doing the inside part :|
	for (int y = 1; y < this->size; ++y) {
		for (int x = 1; x < this->size; ++x) {
			int sur = sumSur(x, y);
			this->nextCells[IX(x, y, this->size)] = stays(this->cells[IX(x, y, this->size)], sur);
		}
	}

	std::copy(std::begin(nextCells), std::end(nextCells), std::begin(cells));
}

// Render
void Cells::render(sf::RenderWindow& window) {
	window.clear();
	for (int y = 0; y < this->size; ++y) {
		for (int x = 0; x < this->size; ++x) {
			sf::RectangleShape rect;
			rect.setFillColor(sf::Color(0, 0, 0, 255));
			rect.setSize(sf::Vector2f(SCALE, SCALE));
			rect.setPosition(x * SCALE, y * SCALE);
			window.draw(rect);
			rect.setSize(sf::Vector2f(SCALE - 1, SCALE - 1));
			rect.setPosition(x * SCALE + 1, y * SCALE + 1);
			if (cells[IX(x, y, this->size)]) {
				rect.setFillColor(sf::Color(0, 255, 0, 255));
			}
			else {
				rect.setFillColor(sf::Color(255, 255, 255, 255));
			}
			window.draw(rect);
		}
	}
}

// Pause/Unpause the simulation
void Cells::pause() {
	this->paused = !this->paused;
}

// Checks if the cell grid is paused
bool Cells::isPaused() {
	return this->paused;
}
