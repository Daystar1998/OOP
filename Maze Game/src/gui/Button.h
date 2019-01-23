#pragma once

/******************************************************************
File Name: button.h

Class Name: Button

Des: This is a class for creating a button

Author: Matthew Day

Due Date: 1/23/19
*******************************************************************/

#include <string>
#include <vector>
#include <windows.h>

#include "actionListener.h"
#include "../display.h"
#include "../input.h"
#include "label.h"

using std::string;
using std::vector;

class Button : public Label {

private:

	int selectedColor;
	ActionListener *actionListener;
public:

	Button(GameObject::Position position, string label, int color = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY, int selectedColor = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE);

	~Button();

	void update() override;

	void draw(Display &display) override;

	inline int getSelectedColor() {

		return selectedColor;
	}

	inline void setSelectedColor(int selectedColor) {

		Button::selectedColor = selectedColor;
	}

	inline void setActionListener(ActionListener *actionListener) {

		Button::actionListener = actionListener;
	}
};