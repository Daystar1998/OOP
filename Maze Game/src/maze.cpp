/******************************************************************
File Name: maze.cpp

Des: This file implements maze.h.

Author: Matthew Day

Due Date: 1/23/19
*******************************************************************/

#include "maze.h"

Maze::Maze(int width, int height) {

	initializeMaze(width, height);
}

Maze::~Maze() {

	while (!entities.empty()) {

		delete entities.back();
		entities.pop_back();
	}
}

void Maze::initializeMaze(int width, int height) {

	// Reset all data for the maze
	Maze::width = width;
	Maze::height = height;
	maze.resize(width * height);

	for (int i = 0; i < width * height; i++) {

		maze.push_back(Type::WALL);
	}

	digMaze();

	setDestination();
}

void Maze::digMaze() {

	stack<Entity::Position> positions;
	vector<Direction> availableDirections;

	srand(time(nullptr));

	Entity::Position current = getRandomPosition();
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
			Entity::Position newPosition(0, 0);

			digDirection(current, newPosition, availableDirections[random]);

			availableDirections.clear();
			positions.push(current);
			current = newPosition;
		}
	} while (!positions.empty());
}

void Maze::digDirection(Entity::Position &position, Entity::Position &newPosition, Direction direction) {

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

void Maze::getAvailableDirections(Entity::Position &position, vector<Direction> &availableDirections) {

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

void Maze::setDestination() {

	Entity::Position position(0, 0);

	// Case for when only one path tile exists, the start position is overwritten with the destination
	if (width == 3 && height == 3) {

		position.x = 1;
		position.y = 1;
	} else {

		do {

			position = getRandomPosition();
		} while (getType(position.x, position.y) != Type::PATH);
	}

	setType(position.x, position.y, Type::DESTINATION);
}

Entity::Position Maze::getRandomPosition() {

	return Entity::Position(1 + (rand() % ((width - 2) / 2) * 2), 1 + (rand() % ((height - 2) / 2) * 2));
}

void Maze::update() {

	for (unsigned int i = 0; i < entities.size(); i++) {

		entities[i]->update(*this);
	}
}

void Maze::draw(Display &display) {

	vector<Display::Pixel> pixels(width * height);

	for (int y = 0; y < height; y++) {

		for (int x = 0; x < width; x++) {

			// TODO: Hardcoded. Fix this
			if (getType(x, y) == Type::WALL) {

				pixels.push_back(display.getPixel("wall"));
			}else if (getType(x, y) == Type::PATH) {

				pixels.push_back(display.getPixel("path"));
			} else if (getType(x, y) == Type::START) {

				pixels.push_back(display.getPixel("start"));
			} else if (getType(x, y) == Type::DESTINATION) {

				pixels.push_back(display.getPixel("destination"));
			}
		}
	}

	display.draw(0, 0, width, height, pixels);

	for (unsigned int i = 0; i < entities.size(); i++) {

		entities[i]->draw(display);
	}
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