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

	enum Type {

		WALL = 0,
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
public:

	Maze(GameObject::Position position, int width, int height);

	void draw(Display &display) override;

	bool inBounds(int x, int y);
private:

	void initializeMaze();

	void digMaze();

	void digDirection(GameObject::Position &position, GameObject::Position &newPosition, Direction direction);

	void getAvailableDirections(GameObject::Position &position, vector<Direction> &availableDirections);

	void setExit();

	GameObject::Position getRandomPosition();
};