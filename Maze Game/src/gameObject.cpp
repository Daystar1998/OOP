#pragma once

/******************************************************************
File Name: gameObject.cpp

Des: This is an implementation for gameObject

Author: Matthew Day

Due Date: 1/23/19
*******************************************************************/

#include "gameObject.h"

GameObject::GameObject(GameObject::Position position, int width, int height)
	: position(position), width(width), height(height), data(vector<int>(width * height)) {}

GameObject::~GameObject() {

	while (!children.empty()) {

		delete children.back();
		children.pop_back();
	}
}

void GameObject::update() {

	for (unsigned int i = 0; i < children.size(); i++) {

		children[i]->update();
	}

	for (unsigned int i = 0; i < removedChildren.size(); i++) {

		for (unsigned int j = 0; j < children.size(); j++) {

			if (children[j] == removedChildren[i]) {

				children.erase(children.begin() + j);
			}
		}

		delete removedChildren[i];
	}

	removedChildren.clear();
}

void GameObject::draw(Display &display) {

	for (unsigned int i = 0; i < children.size(); i++) {

		children[i]->draw(display);
	}
}

bool GameObject::inBounds(int x, int y) {

	return y >= 0 || y < height || x >= 0 || x < width;
}

void GameObject::addChild(GameObject *child) {

	child->setParent(this);
	child->setPosition(child->getPosition());

	children.push_back(child);
}

void GameObject::removeChild(GameObject *child) {

	removedChildren.push_back(child);
}

void GameObject::setPosition(Position position) {

	// Sets the child's position relative to the parent's position
	Position parentPosition = parent->getPosition();

	this->position.x = parentPosition.x + position.x;
	GameObject::position.y = parentPosition.y + position.y;

	for (unsigned int i = 0; i < children.size(); i++) {

		children[i]->setPosition(children[i]->getPosition());
	}
}

int GameObject::getData(int x, int y) {

	if (!inBounds(x, y)) {

		string exception = "Error: Position " + to_string(x) + ", " + to_string(y) + " is out of bounds";
		throw exception;
	}

	return data[y * width + x];
}

void GameObject::setData(int x, int y, int newData) {

	if (!inBounds(x, y)) {

		string exception = "Error: Position " + to_string(x) + ", " + to_string(y) + " is out of bounds";
		throw exception;
	}

	data[y * width + x] = newData;
}