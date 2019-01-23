#include "player.h"

Player::Player(GameObject::Position position, int id)
	: Entity(position, 1, 1, id) {}

void Player::update() {

	if (Input::getKey(Input::Key::LEFT) && getParent()->getData(position.x - 1, position.y) != Maze::Type::WALL) {

		position.x--;
	} else if (Input::getKey(Input::Key::RIGHT) && getParent()->getData(position.x + 1, position.y) != Maze::Type::WALL) {

		position.x++;
	} else if (Input::getKey(Input::Key::UP) && getParent()->getData(position.x, position.y - 1) != Maze::Type::WALL) {

		position.y--;
	} else if (Input::getKey(Input::Key::DOWN) && getParent()->getData(position.x, position.y + 1) != Maze::Type::WALL) {

		position.y++;
	}

	if (getParent()->getData(position.x, position.y) == Maze::Type::EXIT) {

		getParent()->setStatus(GameObject::Status::SUCCESS);
	}
}