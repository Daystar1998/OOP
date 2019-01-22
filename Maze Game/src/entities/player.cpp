#include "player.h"

Player::Player(Position position, string pixelLabel)
	: Entity(position, pixelLabel) {}

void Player::update(Maze &maze) {

	int key = getKey();

	if (key == VK_LEFT && maze.getType(position.x - 1, position.y) != Maze::Type::WALL) {

		position.x--;
	} else if (key == VK_RIGHT && maze.getType(position.x + 1, position.y) != Maze::Type::WALL) {

		position.x++;
	} else if (key == VK_UP && maze.getType(position.x, position.y + 1) != Maze::Type::WALL) {

		position.y++;
	} else if (key == VK_DOWN && maze.getType(position.x, position.y - 1) != Maze::Type::WALL) {

		position.y--;
	}
}

// TODO: Consider splitting to an Inputs class to make it easier to change platform specific code
int Player::getKey() {

	int result = 0;

	short MAX_SHORT = 0x7FFF; //111111111111111

	if (GetAsyncKeyState(VK_LEFT) & MAX_SHORT) {

		result = VK_LEFT;
	} else if (GetAsyncKeyState(VK_UP) & MAX_SHORT) {

		result = VK_UP;
	} else if (GetAsyncKeyState(VK_RIGHT) & MAX_SHORT) {

		result = VK_RIGHT;
	} else if (GetAsyncKeyState(VK_DOWN) & MAX_SHORT) {

		result = VK_DOWN;
	}

	return result;
}