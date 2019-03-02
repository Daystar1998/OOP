// Author: Matthew Day

#include "Polygon.h"
#include "../util/STBParser.h"

Polygon::Polygon() {}

Polygon::~Polygon() {}

void Polygon::initialize(const string &data) {

	vector<String> lines;

	String(data).split("\n", lines);

	for (int i = 0; i < lines.size(); i++) {

		if (isParsingCommonData(lines[i])) {

			// Do nothing
		} else {

			lines[i].trim();

			int currentPosition = 0;

			String label = StringUtils::getNextVariable(lines[i], currentPosition, currentPosition);

			if (label == "vertex") {

				int x = StringUtils::getNextNumber(lines[i], currentPosition + 1, currentPosition);
				int y = StringUtils::getNextNumber(lines[i], currentPosition + 1, currentPosition);

				vertices.push_back(Coordinate(x, y));
			}
		}
	}
}

void Polygon::draw(Picture &picture) const {

	if (vertices.size() >= 1) {

		if (hasShadow) {

			drawShadow(picture);
		}

		for (int i = 0; i < vertices.size() - 1; i++) {

			picture.AddLine(startCoordinate.x + vertices[i].x, startCoordinate.y + vertices[i].y, startCoordinate.x + vertices[i + 1].x, startCoordinate.y + vertices[i + 1].y, color);
		}

		picture.AddLine(startCoordinate.x + vertices[0].x, startCoordinate.y + vertices[0].y, startCoordinate.x + vertices[vertices.size() - 1].x, startCoordinate.y + vertices[vertices.size() - 1].y, color);
	}
}

void Polygon::drawShadow(Picture &picture) const {

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

	for (int i = 0; i < vertices.size() - 1; i++) {

		picture.AddLine(startCoordinate.x + vertices[i].x + shadowOffsetX, startCoordinate.y + vertices[i].y + shadowOffsetY, startCoordinate.x + vertices[i + 1].x + shadowOffsetX, startCoordinate.y + vertices[i + 1].y + shadowOffsetY, shadowColor);
	}

	picture.AddLine(startCoordinate.x + vertices[0].x + shadowOffsetX, startCoordinate.y + vertices[0].y + shadowOffsetY, startCoordinate.x + vertices[vertices.size() - 1].x + shadowOffsetX, startCoordinate.y + vertices[vertices.size() - 1].y + shadowOffsetY, shadowColor);
}
