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
		}

		getline(file, lineText);
	}

	return Picture(width, height, backgroundColor);
}