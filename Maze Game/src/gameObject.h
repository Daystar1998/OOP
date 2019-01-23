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

	bool inBounds(int x, int y) {

		return y >= 0 || y < height || x >= 0 || x < width;
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

		// Sets the child's position relative to the parent's position
		Position parentPosition = parent->getPosition();

		GameObject::position.x = parentPosition.x + position.x;
		GameObject::position.y = parentPosition.y + position.y;

		for (unsigned int i = 0; i < children.size(); i++) {

			children[i]->setPosition(children[i]->getPosition());
		}
	}

	inline Position getPosition() {

		return position;
	}

	inline int getWidth() {

		return width;
	}

	inline void setWidth(int width) {

		GameObject::width = width;

		data.resize(width * height);
	}

	inline int getHeight() {

		return height;
	}

	inline void setHeight(int height) {

		GameObject::height = height;

		data.resize(width * height);
	}

	int getData(int x, int y) {

		if (!inBounds(x, y)) {

			string exception = "Error: Position " + to_string(x) + ", " + to_string(y) + " is out of bounds";
			throw exception;
		}

		return data[y * width + x];
	}

	void setData(int x, int y, int newData) {

		if (!inBounds(x, y)) {

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