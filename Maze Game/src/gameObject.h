#pragma once

/******************************************************************
File Name: gameObject.h

Class Name: GameObject

Des: This is an abstract class for game objects

Author: Matthew Day

Due Date: 1/23/19
*******************************************************************/

#include <string>
#include <vector>

#include "display.h"

using std::string;
using std::to_string;

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

	vector<int> data;
public:

	GameObject(Position position, int width, int height)
		: position(position), width(width), height(height), data(vector<int>(width * height)) {}

	virtual ~GameObject() {

		while (!children.empty()) {

			delete children.back();
			children.pop_back();
		}
	}

	virtual void update() {

		for (unsigned int i = 0; i < children.size(); i++) {

			children[i]->update();
		}
	}

	virtual void draw(Display &display) {

		for (unsigned int i = 0; i < children.size(); i++) {

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

	int getData(int x, int y) {

		if (x < 0 || y < 0 || x >= width || y >= height) {

			string exception = "Error: Position " + to_string(x) + ", " + to_string(y) + " is out of bounds";
			throw exception;
		}

		return data[y * width + x];
	}

	void setData(int x, int y, int newData) {

		if (x < 0 || y < 0 || x >= width || y >= height) {

			string exception = "Error: Position " + to_string(x) + ", " + to_string(y) + " is out of bounds";
			throw exception;
		}

		data[y * width + x] = newData;
	}

	inline GameObject* getParent() {

		return parent;
	}

	inline void setParent(GameObject *newParent) {

		parent = newParent;
	}
};