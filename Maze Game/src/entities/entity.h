#pragma once

/******************************************************************
File Name: entity.h

Class Name: Entity

Des: This class is an abstract class for entities

Author: Matthew Day

Due Date: 1/23/19
*******************************************************************/

#include "../display.h"
#include "../gameObject.h"

class Maze;

class Entity : public GameObject {

protected:

	const int ID;

	Entity(GameObject::Position position, int width, int height, int id)
		: GameObject(position, width, height), ID(id) {}
public:

	virtual void draw(Display &display) override {

		display.draw(position.x, position.y, display.getPixel(ID));
	}
};

// Included at the end to avoid issues with interdependence
#include "../maze.h"