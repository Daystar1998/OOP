// Author: Matthew Day

#pragma once

#include <string>

#include "../Picture.h"
#include "../RGBTriple.h"
#include "../util/String.h"
#include "../util/StringUtils.h"

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

	bool isFilled;
	RGBTriple color;
	Coordinate startCoordinate;
public:

	Shape() {}

	virtual ~Shape() {}

	virtual void initialize(const string &data) = 0;

	virtual void draw(Picture &picture) const = 0;

protected:

	virtual void drawShadow(Picture &picture) const = 0;

	virtual bool isParsingCommonData(const String &data);

	virtual RGBTriple getShadowColor() const;
public:

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

// Avoid issues with interdependence
#include "../util/STBParser.h"