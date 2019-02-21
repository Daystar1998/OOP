// Author: Matthew Day

#pragma once

#include <string>

#include "../Picture.h"
#include "../RGBTriple.h"

using std::string;

class Shape {

public:

	struct Coordinate {

		int x, y;

		Coordinate(int x = 0, int y = 0)
			: x(x), y(y) {
		}
	};
protected:

	static bool hasShadow;
	static int shadowOffsetX, shadowOffsetY;

	RGBTriple color;
	Coordinate startCoordinate;
public:

	Shape(const string &data) {}

	virtual ~Shape() {}

	virtual void draw(Picture &picture) const = 0;

	virtual void drawShadow(Picture &picture) const = 0;

	inline static bool getHasShadow() {

		return hasShadow;
	}

	inline static void setHasShadow(bool hasShadow) {

		Shape::hasShadow = hasShadow;
	}

	inline static int getShadowOffsetX() {

		return shadowOffsetX;
	}

	inline static void setShadowOffsetX(int shadowOffsetX) {

		Shape::shadowOffsetX = shadowOffsetX;
	}

	inline static int getShadowOffsetY() {

		return shadowOffsetY;
	}

	inline static void setShadowOffsetY(int shadowOffsetY) {

		Shape::shadowOffsetY = shadowOffsetY;
	}
};