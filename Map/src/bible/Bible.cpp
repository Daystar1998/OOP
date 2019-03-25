// Author: Matthew Day

#include "Bible.h"

#include <cctype>
#include <fstream>

#include "../util/StringUtils.h"

Bible *Bible::instance = nullptr;

Bible::Bible() {

	std::fstream fin("res/bible.txt");

	if (!fin.fail()) {

		string line;
		string currentBookName;

		while (!fin.eof() && !fin.fail()) {

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
			} else {

				int chapter;
				int verseNumber;
				string verseText;

				int currentPosition = 0;

				chapter = StringUtils::getNextNumber(line, currentPosition, currentPosition);

				verseNumber = StringUtils::getNextNumber(line, currentPosition + 1, currentPosition);

				verseText = line.substr(currentPosition + 1, line.length() - currentPosition - 1);

				VerseKey verseKey(currentBookName, chapter, verseNumber);

				StringUtils::trim(verseText);

				(*this)[verseKey] = Verse(verseKey, verseText);
			}
		}
	} else {

		throw std::runtime_error("File not found");
	}
}

Bible::~Bible() {}

Bible& Bible::getInstance() {

	if (instance == nullptr) {

		instance = new Bible();
	}

	return *instance;
}