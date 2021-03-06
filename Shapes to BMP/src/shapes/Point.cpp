#include "Point.h"

Point::Point() {}

Point::~Point() {}

void Point::initialize(const string &data) {

	vector<String> lines;

	String(data).split("\n", lines);

	for (int i = 0; i < lines.size(); i++) {

		isParsingCommonData(lines[i]);
	}
}

void Point::draw(Picture &picture) const {

	if (hasShadow) {

		drawShadow(picture);
	}

	picture.SetPixelColor(startCoordinate.x, startCoordinate.y, color);
}

void Point::drawShadow(Picture &picture) const {

	RGBTriple shadowColor = getShadowColor();

	picture.SetPixelColor(startCoordinate.x + shadowOffsetX, startCoordinate.y + shadowOffsetY, shadowColor);
}