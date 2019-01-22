#pragma once

/******************************************************************
File Name: maze.h

Class Name: Maze

Des: This class is used to create a maze

Author: Matthew Day

Due Date: 1/23/19
*******************************************************************/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>

#include "display.h"
#include "entities/entity.h"
#include "entities/player.h"
#include "gameObject.h"

using std::map;
using std::rand;
using std::stack;
using std::string;
using std::time;
using std::to_string;
using std::vector;

class Maze : public GameObject {

public:

	enum class Type {

		WALL,
		PATH,
		START,
		EXIT,
		PLAYER,
	};
private:

	enum class Direction {

		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	int width, height;

	vector<Type> maze;
	vector<Entity*> entities;
public:

	Maze(int width, int height);

	~Maze();

	void update();

	void draw(Display &display);

	Type getType(int x, int y);

	void setType(int x, int y, Maze::Type newType);

	bool inBounds(int x, int y);
private:

	void initializeMaze(int width, int height);

	void digMaze();

	void digDirection(Entity::Position &position, Entity::Position &newPosition, Direction direction);

	void getAvailableDirections(Entity::Position &position, vector<Direction> &availableDirections);

	void setExit();

	Entity::Position getRandomPosition();
};