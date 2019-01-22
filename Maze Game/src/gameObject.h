#pragma once

/******************************************************************
File Name: gameObject.h

Class Name: GameObject

Des: This is an abstract class for game objects

Author: Matthew Day

Due Date: 1/23/19
*******************************************************************/

#include <vector>

#include "display.h"

class GameObject {

public:

	struct Position {

		int x, y;

		Position(int x, int y)
			: x(x), y(y) {}
	};

	enum class State {

		RUNNING,
		FAILURE,
		SUCCESS
	};
protected:

	Position position;
	int width, height;
private:

	State currentState = State::RUNNING;

	GameObject *parent = nullptr;
	vector<GameObject*> children;
public:

	GameObject(Position position, int width, int height)
		: position(position), width(width), height(height) {}

	virtual ~GameObject() {

		while (!children.empty()) {

			delete children.back();
			children.pop_back();
		}
	}

	virtual void update() {

		for (int i = 0; i < children.size(); i++) {

			children[i]->update();
		}
	}

	virtual void draw(Display &display) {

		for (int i = 0; i < children.size(); i++) {

			children[i]->draw(display);
		}
	}

	inline State getState() {

		return currentState;
	}

	inline void setState(State state) {

		currentState = state;
	}

	void addChild(GameObject *child) {

		child->setParent(this);
		child->setPosition(child->getPosition());

		children.push_back(child);
	}

	inline void setPosition(Position position) {

		GameObject::position.x = parent->position.x + position.x;
		GameObject::position.y = parent->position.y + position.y;
	}

	inline Position getPosition() {

		return position;
	}

	inline int getWidth() {

		return width;
	}

	inline int getHeight() {

		return height;
	}
private:

	inline void setParent(GameObject *newParent) {

		parent = newParent;
	}
};