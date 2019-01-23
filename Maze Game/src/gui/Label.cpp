#include "Label.h"

Label::Label(GameObject::Position position, string label, int color)
	: GameObject(position, label.size(), 1), color(color) {

	setString(label);
}

void Label::draw(Display &display) {

	vector<Display::Pixel> pixels(label.size());

	for (unsigned int i = 0; i < label.size(); i++) {

		pixels[i] = Display::Pixel(label[i], color);
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