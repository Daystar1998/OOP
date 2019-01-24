/******************************************************************
File Name: button.cpp

Des: This file implements button.h.

Author: Matthew Day

Due Date: 1/23/19
*******************************************************************/

#include "button.h"

Button::Button(GameObject::Position position, string label, int color, int selectedColor)
	: Label(position, label, color, true), selectedColor(selectedColor), actionListener(nullptr) {

	setString(label);
}

void Button::update() {

	if (getStatus() == Status::FOCUSED && actionListener != nullptr && Input::getKey(Input::Key::ENTER)) {

		actionListener->performAction();
	}
}

void Button::draw(Display &display) {

	vector<Display::Pixel> pixels(getString().size());

	int color = getColor();

	if (getStatus() == Status::FOCUSED) {

		color = selectedColor;
	}

	for (unsigned int i = 0; i < getString().size(); i++) {

		pixels[i] = Display::Pixel(getString()[i], color);
	}

	display.draw(getPosition().x, getPosition().y, getString().size(), 1, pixels);

	GameObject::draw(display);
}