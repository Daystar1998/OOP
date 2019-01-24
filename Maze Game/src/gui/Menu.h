#pragma once

/******************************************************************
File Name: Menu.h

Class Name: Menu

Des: This is class for creating a menu

Author: Matthew Day

Due Date: 1/23/19
*******************************************************************/

#include "../gameObject.h"
#include "../input.h"
#include "guiObject.h"

class Menu : public GameObject {

private:

	int index;
	bool visible;
public:

	Menu(int startIndex = 0)
		: GameObject(Position(0, 0), 1, 1), index(startIndex), visible(true){}

	void update() override {

		if (visible) {

			if (Input::getKey(Input::Key::DOWN)) {

				getChild(index)->setStatus(Status::RUNNING);

				do {

					index++;

					if (index >= getNumberOfChildren()) {

						index = 0;
					}
				} while (!((GuiObject*)getChild(index))->isFocusable());
			} else if (Input::getKey(Input::Key::UP)) {

				getChild(index)->setStatus(Status::RUNNING);

				do {

					index--;

					if (index < 0) {

						index = getNumberOfChildren() - 1;
					}
				} while (!((GuiObject*)getChild(index))->isFocusable());
			}

			getChild(index)->setStatus(Status::FOCUSED);

			GameObject::update();
		}
	}

	void draw(Display &display) override {

		if (visible) {

			GameObject::draw(display);
		}
	}

	bool isVisible() {

		return visible;
	}

	void setVisible(bool visible) {

		this->visible = visible;
	}
};