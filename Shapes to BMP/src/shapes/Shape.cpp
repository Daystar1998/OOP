// Author: Matthew Day

#include "Shape.h"

bool Shape::hasShadow = false;
int Shape::shadowOffsetX = 0;
int Shape::shadowOffsetY = 0;

bool Shape::isParsingCommonData(const String &data) {

	bool isCommonData = false;

	int currentPosition = 0;

	String label = StringUtils::getNextVariable(data, currentPosition, currentPosition);

	if (label == "start_position") {

		startCoordinate.x = StringUtils::getNextNumber(data, currentPosition + 1, currentPosition);
		startCoordinate.y = StringUtils::getNextNumber(data, currentPosition + 1, currentPosition);

		isCommonData = true;
	} else if (label == "color") {

		color = STBParser::parseColor(data, currentPosition);

		isCommonData = true;
	}

	return isCommonData;
}