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

		Position(int x = 0, int y = 0)
			: x(x), y(y) {}
	};

	enum class Status {

		RUNNING,
		FAILURE,
		FOCUSED,
		SUCCESS
	};
protected:

	Position position;
	int width, height;
private:

	Status currentStatus = Status::RUNNING;

	GameObject *parent = nullptr;
	vector<GameObject*> children;
	vector<GameObject*> removedChildren;

	vector<int> data;
public:

	GameObject(Position position, int width, int height);

	virtual ~GameObject();

	virtual void update();

	virtual void draw(Display &display);

	bool inBounds(int x, int y);

	void addChild(GameObject *child);

	void removeChild(GameObject *child);

	GameObject* getChild(int index) {

		return children[index];
	}

	int getNumberOfChildren() {

		return children.size();
	}

	inline Status getStatus() {

		return currentStatus;
	}

	inline void setStatus(Status status) {

		currentStatus = status;
	}

	void setPosition(Position position);

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

	int getData(int x, int y);

	void setData(int x, int y, int newData);

	inline GameObject* getParent() {

		return parent;
	}

	inline void setParent(GameObject *newParent) {

		parent = newParent;
	}
};