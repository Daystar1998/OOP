// Author: Matthew Day

#include "Bible.h"

#include <cctype>
#include <fstream>

#include "../util/StringUtils.h"

Bible *Bible::instance = nullptr;

Bible::Bible() {

	std::fstream fin("res/bible.txt");

	string line;

	string currentBookName;

	while (!fin.eof()) {

		std::getline(fin, line);

		if (StringUtils::startsWith(line, "Book")) {

			// Start at index after "Book"
			int currentPosition = 4;

			// Skip the book number
			StringUtils::getNextNumber(line, currentPosition, currentPosition);

			currentBookName = StringUtils::getNextVariable(line, currentPosition + 1, currentPosition);

			if (std::isdigit(currentBookName[0])) {

				currentBookName += " ";

				currentBookName.append(StringUtils::getNextVariable(line, currentPosition + 1, currentPosition));
			}
		}
	}
}

Bible::~Bible() {}

Bible& Bible::getInstance() {

	if (instance == nullptr) {

		instance = new Bible();
	}

	return *instance;
}