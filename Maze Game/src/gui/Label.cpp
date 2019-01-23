/******************************************************************
File Name: label.cpp

Des: This file implements label.h.

Author: Matthew Day

Due Date: 1/23/19
*******************************************************************/

#include "label.h"

Label::Label(GameObject::Position position, string label, int color, bool focusable)
	: GuiObject(position, label.size(), 1, color, focusable) {

	setString(label);
}

void Label::draw(Display &display) {

	vector<Display::Pixel> pixels(label.size());

	for (unsigned int i = 0; i < label.size(); i++) {

		pixels[i] = Display::Pixel(label[i], getColor());
	}

	display.draw(getPosition().x, getPosition().y, label.size(), 1, pixels);

	GameObject::draw(display);
}

void Label::setString(string label) {

	Label::label = label;

	GameObject::setWidth(label.size());

	for (unsigned int i = 0; i < label.size(); i++) {

		GameObject::setData(i, 0, label[i]);
	}
}