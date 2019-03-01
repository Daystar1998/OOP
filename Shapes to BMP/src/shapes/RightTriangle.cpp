#include "RightTriangle.h"

RightTriangle::RightTriangle() {}

RightTriangle::~RightTriangle() {}

void RightTriangle::initialize(const string &data) {

	vector<String> lines;

	String(data).split("\n", lines);

	int width = 0;
	int height = 0;

	for (int i = 0; i < lines.size(); i++) {

		if (isParsingCommonData(lines[i])) {

			// Do nothing
		} else {

			lines[i].trim();

			int currentPosition = 0;

			String label = StringUtils::getNextVariable(lines[i], currentPosition, currentPosition);

			if (label == "width") {

				width = StringUtils::getNextNumber(lines[i], currentPosition + 1, currentPosition);
			} else if (label == "height") {

				height = StringUtils::getNextNumber(lines[i], currentPosition + 1, currentPosition);
			}
		}
	}

	vertices.push_back(Coordinate(0, 0));
	vertices.push_back(Coordinate(0, height));
	vertices.push_back(Coordinate(width, 0));
}

void RightTriangle::draw(Picture &picture) const {

	for (int i = 0; i < vertices.size() - 1; i++) {

		picture.AddLine(startCoordinate.x + vertices[i].x, startCoordinate.y + vertices[i].y, startCoordinate.x + vertices[i + 1].x, startCoordinate.y + vertices[i + 1].y, color);
	}

	picture.AddLine(startCoordinate.x + vertices[0].x, startCoordinate.y + vertices[0].y, startCoordinate.x + vertices[vertices.size() - 1].x, startCoordinate.y + vertices[vertices.size() - 1].y, color);
}

void RightTriangle::drawShadow(Picture &picture) const {

	RGBTriple shadowColor(color.Blue - 50, color.Green - 50, color.Red - 50);

	for (int i = 0; i < vertices.size() - 1; i++) {

		picture.AddLine(startCoordinate.x + vertices[i].x + shadowOffsetX, startCoordinate.y + vertices[i].y + shadowOffsetY, startCoordinate.x + vertices[i + 1].x + shadowOffsetX, startCoordinate.y + vertices[i + 1].y + shadowOffsetY, shadowColor);
	}

	picture.AddLine(startCoordinate.x + vertices[0].x + shadowOffsetX, startCoordinate.y + vertices[0].y + shadowOffsetY, startCoordinate.x + vertices[vertices.size() - 1].x + shadowOffsetX, startCoordinate.y + vertices[vertices.size() - 1].y + shadowOffsetY, shadowColor);
}