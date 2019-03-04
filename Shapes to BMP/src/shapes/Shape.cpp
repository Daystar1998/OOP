// Author: Matthew Day

#include "Shape.h"

bool Shape::hasShadow = false;
int Shape::shadowOffsetX = 0;
int Shape::shadowOffsetY = 0;

bool Shape::isParsingCommonData(const String &data) {

	bool isCommonData = false;

	String temp = data;

	temp.trim();

	if (temp.startsWith("//")) {

		isCommonData = true;
	} else {

		int currentPosition = 0;

		String label = StringUtils::getNextVariable(data, currentPosition, currentPosition);

		if (label == "start_position") {

			startCoordinate.x = StringUtils::getNextNumber(data, currentPosition + 1, currentPosition);
			startCoordinate.y = StringUtils::getNextNumber(data, currentPosition + 1, currentPosition);

			isCommonData = true;
		} else if (label == "color") {

			color = STBParser::parseColor(data, currentPosition);

			isCommonData = true;
		} else if (label == "isFilled") {

			isFilled = STBParser::parseBoolean(data, currentPosition + 1);

			isCommonData = true;
		}
	}

	return isCommonData;
}

RGBTriple Shape::getShadowColor() const {

	RGBTriple result;

	int shadowOffset = 100;

	if (color.Red < shadowOffset) {

		result.Red = 0;
	} else {

		result.Red = color.Red - shadowOffset;
	}

	if (color.Green < shadowOffset) {

		result.Green = 0;
	} else {

		result.Green = color.Green - shadowOffset;
	}

	if (color.Blue < shadowOffset) {

		result.Blue = 0;
	} else {

		result.Blue = color.Blue - shadowOffset;
	}

	return result;
}