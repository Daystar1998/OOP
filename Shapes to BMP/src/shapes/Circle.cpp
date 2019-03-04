#include "Circle.h"

#define _USE_MATH_DEFINES
#include <math.h>

Circle::Circle() {}

Circle::~Circle() {}

void Circle::initialize(const string &data) {

	vector<String> lines;

	String(data).split("\n", lines);

	radius = 0;
	isFilled = false;

	for (int i = 0; i < lines.size(); i++) {

		if (isParsingCommonData(lines[i])) {

			// Do nothing
		} else {

			lines[i].trim();

			int currentPosition = 0;

			String label = StringUtils::getNextVariable(lines[i], currentPosition, currentPosition);

			if (label == "radius") {

				radius = StringUtils::getNextNumber(lines[i], currentPosition + 1, currentPosition);
			}
		}
	}
}

void Circle::draw(Picture &picture) const {

	if (hasShadow) {

		drawShadow(picture);
	}

	drawCircle(startCoordinate, radius, color, picture);

	if (isFilled) {

		for (int x = -radius; x < radius; x++) {

			for (int y = -radius; y < radius; y++) {

				int distance = (int)sqrt((x * x) + (y * y));

				if (distance < radius) {

					picture.SetPixelColor(startCoordinate.x + x, startCoordinate.y + y, color);
				}
			}
		}
	}
}

void Circle::drawShadow(Picture &picture) const {

	RGBTriple shadowColor = getShadowColor();

	Coordinate shadowPosition(startCoordinate.x + shadowOffsetX, startCoordinate.y + shadowOffsetY);

	drawCircle(shadowPosition, radius, shadowColor, picture);
}

void Circle::drawCircle(Coordinate position, int radius, RGBTriple color, Picture &picture) const {

	// Algorithm source: https://www.mathopenref.com/coordcirclealgorithm.html

	int lastX = (int)(radius * cos(0));
	int lastY = (int)(radius * sin(0));

	// Increasing the number of segments results in a higher res circle, but the tradeoff is lower performance
	int segments = 30;

	for (double t = 2 * M_PI / segments; t < 2 * M_PI; t += 2 * M_PI / segments) {

		int nextX = (int)(radius * cos(t));
		int nextY = (int)(radius * sin(t));

		picture.AddLine(position.x + lastX, position.y + lastY, position.x + nextX, position.y + nextY, color);

		lastX = nextX;
		lastY = nextY;
	}

	picture.AddLine(position.x + lastX, position.y + lastY, (int)(position.x + radius * cos(0)), (int)(position.y + radius * sin(0)), color);
}