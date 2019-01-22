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

Maze::~Maze() {

	while (!entities.empty()) {

		delete entities.back();
		entities.pop_back();
	}

	GameObject::~GameObject();
}

void Maze::initializeMaze() {

	for (int i = 0; i < width * height; i++) {

		maze.push_back(Type::WALL);
	}

	digMaze();

	setExit();
}

void Maze::digMaze() {

	stack<GameObject::Position> positions;
	vector<Direction> availableDirections;

	srand(time(nullptr));

	GameObject::Position current = getRandomPosition();
	setType(current.x, current.y, Type::START);

	entities.push_back(new Player(current, "player"));

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

			setType(position.x, position.y + 1, Type::PATH);
			setType(position.x, position.y + 2, Type::PATH);
			newPosition.x = position.x;
			newPosition.y = position.y + 2;
			break;
		case Direction::DOWN:

			setType(position.x, position.y - 1, Type::PATH);
			setType(position.x, position.y - 2, Type::PATH);
			newPosition.x = position.x;
			newPosition.y = position.y - 2;
			break;
		case Direction::LEFT:

			setType(position.x - 1, position.y, Type::PATH);
			setType(position.x - 2, position.y, Type::PATH);
			newPosition.x = position.x - 2;
			newPosition.y = position.y;
			break;
		case Direction::RIGHT:

			setType(position.x + 1, position.y, Type::PATH);
			setType(position.x + 2, position.y, Type::PATH);
			newPosition.x = position.x + 2;
			newPosition.y = position.y;
			break;
	}
}

void Maze::getAvailableDirections(GameObject::Position &position, vector<Direction> &availableDirections) {

	if (position.x - 2 >= 0 && getType(position.x - 2, position.y) == Type::WALL) {

		availableDirections.push_back(Direction::LEFT);
	}

	if (position.x + 2 < width && getType(position.x + 2, position.y) == Type::WALL) {

		availableDirections.push_back(Direction::RIGHT);
	}

	if (position.y + 2 < height && getType(position.x, position.y + 2) == Type::WALL) {

		availableDirections.push_back(Direction::UP);
	}

	if (position.y - 2 >= 0 && getType(position.x, position.y - 2) == Type::WALL) {

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
		} while (getType(position.x, position.y) != Type::PATH);
	}

	setType(position.x, position.y, Type::EXIT);
}

GameObject::Position Maze::getRandomPosition() {

	int x = 1 + (rand() % (int)(((width - 2) / 2.0 + 0.5)) * 2);
	int y = 1 + (rand() % (int)(((height - 2) / 2.0 + 0.5)) * 2);

	return GameObject::Position(x, y);
}

void Maze::update() {

	for (unsigned int i = 0; i < entities.size(); i++) {

		entities[i]->update(*this);
	}

	GameObject::update();
}

void Maze::draw(Display &display) {

	vector<Display::Pixel> pixels;

	for (int y = 0; y < height; y++) {

		for (int x = 0; x < width; x++) {

			Display::Pixel current;

			// TODO: Hardcoded. Fix this
			switch (getType(x, y)) {

				case Type::WALL:

					current = display.getPixel("wall");
					break;
				case Type::PATH:

					current = display.getPixel("path");
					break;
				case Type::START:

					current = display.getPixel("start");
					break;
				case Type::EXIT:

					current = display.getPixel("exit");
					break;
				default:
					throw "Error: Unsupported type";
			}

			pixels.push_back(current);
		}
	}

	display.draw(0, 0, width, height, pixels);

	for (unsigned int i = 0; i < entities.size(); i++) {

		entities[i]->draw(display);
	}

	GameObject::draw(display);
}

Maze::Type Maze::getType(int x, int y) {

	Type result;

	result = maze[y * width + x];

	return result;
}

void Maze::setType(int x, int y, Type newType) {

	string exception = "Position " + to_string(x) + ", " + to_string(y) + " is out of bounds";

	if (!inBounds(x, y)) {

		throw exception;
	}

	maze[y * width + x] = newType;
}

bool Maze::inBounds(int x, int y) {

	return !(y < 0 || y >= height || x < 0 || x >= width);
}