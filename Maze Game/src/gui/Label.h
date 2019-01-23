#pragma once

/******************************************************************
File Name: Label.h

Class Name: Label

Des: This is class for creating a label

Author: Matthew Day

Due Date: 1/23/19
*******************************************************************/

#include <string>
#include <vector>
#include <windows.h>

#include "../display.h"
#include "guiObject.h"

using std::string;
using std::vector;

class Label : public GuiObject {

private:

	string label;
public:

	Label(GameObject::Position position, string label, int color = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

	void draw(Display &display) override;

	inline string getString() {

		return label;
	}

	void setString(string label);
};