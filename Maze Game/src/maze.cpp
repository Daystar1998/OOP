/******************************************************************
File Name: maze.cpp

Des: This file implements maze.h.

Author: Matthew Day

Due Date: 1/23/19
*******************************************************************/

#include "maze.h"

Maze::Maze(GameObject::Position position, int width, int height)
	: GameObject(position, width, height) {

	initializeMaze();
}

void Maze::initializeMaze() {

	for (int y = 0; y < height; y++) {

		for (int x = 0; x < width; x++) {

			setData(x, y, Type::WALL);
		}
	}

	digMaze();

	setExit();
}

void Maze::digMaze() {

	stack<GameObject::Position> positions;
	vector<Direction> availableDirections;

	srand(time(nullptr));

	GameObject::Position current = getRandomPosition();
	setData(current.x, current.y, Type::START);

	addChild(new Player(current, Type::PLAYER));

	positions.push(current);

	do {

		getAvailableDirections(current, availableDirections);

		if (availableDirections.empty()) {

			current = positions.top();
			positions.pop();
		} else {

			int random = rand() % availableDirections.size();
			GameObject::Position newPosition(0, 0);

			digDirection(current, newPosition, availableDirections[random]);

			availableDirections.clear();
			positions.push(current);
			current = newPosition;
		}
	} while (!positions.empty());
}

void Maze::digDirection(GameObject::Position &position, GameObject::Position &newPosition, Direction direction) {

	switch (direction) {

		case Direction::UP:

			setData(position.x, position.y + 1, Type::PATH);
			setData(position.x, position.y + 2, Type::PATH);
			newPosition.x = position.x;
			newPosition.y = position.y + 2;
			break;
		case Direction::DOWN:

			setData(position.x, position.y - 1, Type::PATH);
			setData(position.x, position.y - 2, Type::PATH);
			newPosition.x = position.x;
			newPosition.y = position.y - 2;
			break;
		case Direction::LEFT:

			setData(position.x - 1, position.y, Type::PATH);
			setData(position.x - 2, position.y, Type::PATH);
			newPosition.x = position.x - 2;
			newPosition.y = position.y;
			break;
		case Direction::RIGHT:

			setData(position.x + 1, position.y, Type::PATH);
			setData(position.x + 2, position.y, Type::PATH);
			newPosition.x = position.x + 2;
			newPosition.y = position.y;
			break;
	}
}

void Maze::getAvailableDirections(GameObject::Position &position, vector<Direction> &availableDirections) {

	if (position.x - 2 >= 0 && getData(position.x - 2, position.y) == Type::WALL) {

		availableDirections.push_back(Direction::LEFT);
	}

	if (position.x + 2 < width && getData(position.x + 2, position.y) == Type::WALL) {

		availableDirections.push_back(Direction::RIGHT);
	}

	if (position.y + 2 < height && getData(position.x, position.y + 2) == Type::WALL) {

		availableDirections.push_back(Direction::UP);
	}

	if (position.y - 2 >= 0 && getData(position.x, position.y - 2) == Type::WALL) {

		availableDirections.push_back(Direction::DOWN);
	}
}

void Maze::setExit() {

	GameObject::Position position(0, 0);

	// Case for when only one path tile exists, the start position is overwritten with the exit
	if (width == 3 && height == 3) {

		position.x = 1;
		position.y = 1;
	} else {

		do {

			position = getRandomPosition();
		} while (getData(position.x, position.y) != Type::PATH);
	}

	setData(position.x, position.y, Type::EXIT);
}

GameObject::Position Maze::getRandomPosition() {

	int x = 1 + (rand() % (int)(((width - 2) / 2.0 + 0.5)) * 2);
	int y = 1 + (rand() % (int)(((height - 2) / 2.0 + 0.5)) * 2);

	return GameObject::Position(x, y);
}

void Maze::draw(Display &display) {

	vector<Display::Pixel> pixels;

	for (int y = 0; y < height; y++) {

		for (int x = 0; x < width; x++) {

			Display::Pixel current = display.getPixel(getData(x, y));

			pixels.push_back(current);
		}
	}

	display.draw(0, 0, width, height, pixels);

	GameObject::draw(display);
}