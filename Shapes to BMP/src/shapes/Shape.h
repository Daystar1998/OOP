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
private:

	static bool hasShadow;
public:


	RGBTriple color;
	Coordinate startCoordinate;

	Shape(string &data){}

	virtual ~Shape(){}

	virtual void draw() = 0;

	virtual void drawShadow() = 0;

	inline static bool getHasShadow() {

		return hasShadow;
	}

	inline static void setHasShadow(bool hasShadow) {

		Shape::hasShadow = hasShadow;
	}
};

