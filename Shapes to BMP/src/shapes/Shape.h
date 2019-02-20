#pragma once

#include <string>

#include "../RGBTriple.h"

using std::string;

class Shape {

public:

	struct Coordinate {
	
		int x, y;

		Coordinate(int x = 0, int y = 0) 
			: x(x), y(y){}
	};
public:

	RGBTriple color;
	Coordinate startCoordinate;

	Shape(string &data){}

	virtual ~Shape(){}

	virtual void draw() = 0;

	virtual void drawShadow() = 0;
};

