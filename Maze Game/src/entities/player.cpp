#include "player.h"

Player::Player(GameObject::Position position, int id)
	: Entity(position, 1, 1, id) {}

void Player::update() {

	if (getKey(VK_LEFT) && getParent()->getData(position.x - 1, position.y) != Maze::Type::WALL) {

		position.x--;
	} else if (getKey(VK_RIGHT) && getParent()->getData(position.x + 1, position.y) != Maze::Type::WALL) {

		position.x++;
	} else if (getKey(VK_UP) && getParent()->getData(position.x, position.y - 1) != Maze::Type::WALL) {

		position.y--;
	} else if (getKey(VK_DOWN) && getParent()->getData(position.x, position.y + 1) != Maze::Type::WALL) {

		position.y++;
	}

	if (getParent()->getData(position.x, position.y) == Maze::Type::EXIT) {

		getParent()->setState(GameObject::State::SUCCESS);
	}
}

// TODO: Consider splitting to an Inputs class to make it easier to change platform specific code
int Player::getKey(int key) {

	int result = 0;

	short MAX_SHORT = 0x7FFF; //111111111111111

	if (GetAsyncKeyState(key) & MAX_SHORT) {

		result = key;
	}

	return result;
}