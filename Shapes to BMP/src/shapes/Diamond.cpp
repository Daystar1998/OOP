#include "Diamond.h"

Diamond::Diamond() {}

Diamond::~Diamond() {}

void Diamond::initialize(const string &data) {

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

	vertices.push_back(Coordinate(0, height / 2));
	vertices.push_back(Coordinate(width / 2, 0));
	vertices.push_back(Coordinate(0, -height / 2));
	vertices.push_back(Coordinate(-width / 2, 0));
}