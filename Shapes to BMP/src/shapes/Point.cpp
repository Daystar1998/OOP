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

	RGBTriple shadowColor;

	int shadowOffset = 100;

	if (color.Red < shadowOffset) {

		shadowColor.Red = 0;
	} else {

		shadowColor.Red = color.Red - shadowOffset;
	}

	if (color.Green < shadowOffset) {

		shadowColor.Green = 0;
	} else {

		shadowColor.Green = color.Green - shadowOffset;
	}

	if (color.Blue < shadowOffset) {

		shadowColor.Blue = 0;
	} else {

		shadowColor.Blue = color.Blue - shadowOffset;
	}

	picture.SetPixelColor(startCoordinate.x + shadowOffsetX, startCoordinate.y + shadowOffsetY, shadowColor);
}