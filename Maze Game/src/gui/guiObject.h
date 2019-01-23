#pragma once

/******************************************************************
File Name: GuiObject.h

Class Name: GuiObject

Des: This is an abstract class for creating a gui object

Author: Matthew Day

Due Date: 1/23/19
*******************************************************************/

#include "../display.h"
#include "../gameObject.h"

class GuiObject : public GameObject {

private:

	int color;
	bool focusable;
public:
	
	GuiObject(GameObject::Position position, int width, int height, int color, bool focusable)
	: GameObject(position, width, height), color(color), focusable(focusable) {}

	inline int getColor() {

		return color;
	}

	inline void setColor(int color) {

		GuiObject::color = color;
	}

	bool isFocusable() {

		return focusable;
	}
};