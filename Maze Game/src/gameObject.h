#pragma once

/******************************************************************
File Name: gameObject.h

Class Name: GameObject

Des: This is an abstract class for game objects

Author: Matthew Day

Due Date: 1/23/19
*******************************************************************/

#include "display.h"

class GameObject {

public:

	enum class State {

		RUNNING,
		FAILURE,
		SUCCESS
	};
private:

	State currentState = State::RUNNING;
public:

	virtual void update() = 0;

	virtual void draw(Display &display) = 0;

	inline State getState() {

		return currentState;
	}

	inline void setState(State state) {

		currentState = state;
	}
};