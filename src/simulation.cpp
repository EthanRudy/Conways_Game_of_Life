// Initialization for the Simulation class
// @file simulation.h
// @Author Ethan Rudy


#include "simulation.h"
#include <iostream>

// Defualt constructor
Simulation::Simulation() : cells(Cells()) {
	this->window.create(sf::VideoMode(SIZE * SCALE, SIZE * SCALE), "Conway's Game of Life", sf::Style::Titlebar | sf::Style::Close);
}

// Deconstructor
Simulation::~Simulation() {}

// Runs the simulation
void Simulation::run() {

	while (this->window.isOpen()) {
		sf::Event e;
		while (this->window.pollEvent(e)) {
			switch (e.type) {
			case sf::Event::Closed:
				this->window.close();
				break;
			case::sf::Event::KeyReleased:
				if (e.key.code == sf::Keyboard::Key::Space) {
					this->cells.pause();
				}
				break;
			default:
				break;
			}
		}
	
		sf::Vector2i mPos = sf::Mouse::getPosition(this->window);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->cells.addCell(mPos.x / SCALE, mPos.y / SCALE);
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			this->cells.remCell(mPos.x / SCALE, mPos.y / SCALE);
		}
		if (!this->cells.isPaused()) {
			this->window.setFramerateLimit(dt);
			this->cells.step();
		}
		else {
			this->window.setFramerateLimit(60);
		}
		this->cells.render(this->window);

		this->window.display();
	}
}
