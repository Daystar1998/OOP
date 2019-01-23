#pragma once

/******************************************************************
File Name: input.h

Class Name: Input

Des: This is a static class for handling inputs

Author: Matthew Day

Due Date: 1/23/19
*******************************************************************/

#include <windows.h>

class Input {

public:

	enum Key {

		LEFT = VK_LEFT,
		RIGHT = VK_RIGHT,
		UP = VK_UP,
		DOWN = VK_DOWN
	};

	static int getKey(int key) {

		int result = 0;

		short MAX_SHORT = 0x7FFF; //111111111111111

		if (GetAsyncKeyState(key) & MAX_SHORT) {

			result = key;
		}

		return result;
	}
};