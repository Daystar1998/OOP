#pragma once

/******************************************************************
File Name: entity.h

Class Name: Entity

Des: This class is an abstract class for entities

Author: Matthew Day

Due Date: 1/23/19
*******************************************************************/

#include <string>

#include "../display.h"

class Maze;

class Entity {

public:

	struct Position {

		int x, y;

		Position(int x, int y)
			: x(x), y(y) {}
	};
protected:

	Position position;
	string pixelLabel;

	Entity(Position position, string pixelLabel)
		: position(position), pixelLabel(pixelLabel) {}
public:

	virtual void update(Maze &maze) = 0;

	virtual void draw(Display &display) {

		display.draw(position.x, position.y, display.getPixel(pixelLabel));
	}
};

// Included at the end to avoid issues with interdependence
#include "../maze.h"