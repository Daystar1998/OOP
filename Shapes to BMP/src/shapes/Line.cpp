#include "Line.h"

Line::Line() {}

Line::~Line() {}

void Line::initialize(const string &data) {

	vector<String> lines;

	String(data).split("\n", lines);

	for (int i = 0; i < lines.size(); i++) {

		if (isParsingCommonData(lines[i])) {

			// Do nothing
		} else {

			lines[i].trim();

			int currentPosition = 0;

			String label = StringUtils::getNextVariable(lines[i], currentPosition, currentPosition);

			if (label == "start") {

				int x = StringUtils::getNextNumber(lines[i], currentPosition + 1, currentPosition);
				int y = StringUtils::getNextNumber(lines[i], currentPosition + 1, currentPosition);

				startCoordinate = Coordinate(x, y);
			} else if (label == "end") {

				int x = StringUtils::getNextNumber(lines[i], currentPosition + 1, currentPosition);
				int y = StringUtils::getNextNumber(lines[i], currentPosition + 1, currentPosition);

				endCoordinate = Coordinate(x, y);
			}
		}
	}
}

void Line::draw(Picture &picture) const {

	if (hasShadow) {

		drawShadow(picture);
	}

	picture.AddLine(startCoordinate.x, startCoordinate.y, endCoordinate.x, endCoordinate.y, color);
}

void Line::drawShadow(Picture &picture) const {

	RGBTriple shadowColor = getShadowColor();

	picture.AddLine(startCoordinate.x + shadowOffsetX, startCoordinate.y + shadowOffsetY, endCoordinate.x + shadowOffsetX, endCoordinate.y + shadowOffsetY, shadowColor);
}