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

	virtual void update() = 0;

	virtual void draw(Display &display) = 0;
};