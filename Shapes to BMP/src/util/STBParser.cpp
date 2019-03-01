// Author: Matthew Day

#include "STBParser.h"

Picture STBParser::parseSTBFile(const String &fileName, vector<Shape*> &oShapes) {

	ifstream file(fileName);

	String lineText;

	int width = 0;
	int height = 0;

	RGBTriple backgroundColor;

	getline(file, lineText);

	while (!file.eof()) {

		lineText.trim();

		int currentPosition = 0;

		String label = StringUtils::getNextVariable(lineText, currentPosition, currentPosition);

		if (label == "width") {

			width = StringUtils::getNextNumber(lineText, currentPosition + 1, currentPosition);
		} else if (label == "height") {

			height = StringUtils::getNextNumber(lineText, currentPosition + 1, currentPosition);
		} else if (label == "background_color") {

			backgroundColor = parseColor(lineText, currentPosition);
		} else if (label == "has_shadows") {

			Shape::setHasShadow(parseBoolean(lineText, currentPosition + 1));
		} else if (label == "shadow_offset") {

			Shape::setShadowOffsetX(StringUtils::getNextNumber(lineText, currentPosition + 1, currentPosition));
			Shape::setShadowOffsetY(StringUtils::getNextNumber(lineText, currentPosition + 1, currentPosition));
		} else {

			parseShapes(lineText, file, oShapes);
		}

		getline(file, lineText);
	}

	return Picture(width, height, backgroundColor);
}

void STBParser::parseShapes(String currentLine, istream &data, vector<Shape*> &oShapes) {

	currentLine.trim();

	int currentPosition = 0;

	String label = StringUtils::getNextVariable(currentLine, currentPosition, currentPosition);

	Shape *shape = nullptr;

	if (label == "point") {

		shape = new Point();
	} else if (label == "polygon") {

		shape = new Polygon();
	} else if (label == "rectangle") {

		shape = new Rectangle();
	}

	if (shape != nullptr) {

		shape->initialize(getCodeBlock(data));
		oShapes.push_back(shape);
	}
}

RGBTriple STBParser::parseColor(const String &data, int begin) {

	RGBTriple result;

	int red;
	int green;
	int blue;

	int currentPosition = begin;

	red = StringUtils::getNextNumber(data, currentPosition + 1, currentPosition);
	green = StringUtils::getNextNumber(data, currentPosition + 1, currentPosition);
	blue = StringUtils::getNextNumber(data, currentPosition + 1, currentPosition);

	String colorOrder(StringUtils::getNextVariable(data, currentPosition, currentPosition));

	colorOrder.toUpper();

	int temp;

	// Sort colors based on the specified order
	if (colorOrder == "" || colorOrder == "RGB") {

		// Do nothing
	} else if (colorOrder == "RBG") {

		temp = blue;
		blue = green;
		green = temp;
	} else if (colorOrder == "BRG") {

		temp = red;
		red = green;
		green = blue;
		blue = temp;
	} else if (colorOrder == "BGR") {

		temp = red;
		red = blue;
		blue = temp;
	} else if (colorOrder == "GRB") {

		temp = red;
		red = green;
		green = temp;
	} else if (colorOrder == "GBR") {

		temp = red;
		red = blue;
		blue = green;
		green = temp;
	}

	result.Red = red;
	result.Green = green;
	result.Blue = blue;

	return result;
}

bool STBParser::parseBoolean(const String &data, int begin) {

	bool result = false;

	String value = StringUtils::getNextVariable(data, begin, begin);

	value.toLower();

	if (value == "true") {

		result = true;
	} else {

		// Do nothing
	}

	return result;
}

String STBParser::getCodeBlock(istream &data) {

	String result = "";

	String line;

	getline(data, line);

	int blockLevel = 1;

	while (!data.eof()) {

		line.trim();

		if (line.endsWith("{")) {

			blockLevel++;
		} else if (line.endsWith("}")) {

			blockLevel--;
		}

		result += '\n' + line;

		if (blockLevel == 0) {

			break;
		}

		getline(data, line);
	}

	return result;
}