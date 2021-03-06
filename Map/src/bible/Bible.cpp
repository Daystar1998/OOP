// Author: Matthew Day

#include "Bible.h"

#include <cctype>
#include <fstream>

#include "../util/StringUtils.h"

Bible *Bible::instance = nullptr;

Bible::Bible() {

	std::ifstream fin("res/bible.txt");

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

				currentBookName = line.substr(currentPosition + 1, line.size() - currentPosition - 1);
				StringUtils::trim(currentBookName);
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

	fin.close();
}

Bible::~Bible() {}

Bible& Bible::getInstance() {

	if (instance == nullptr) {

		instance = new Bible();
	}

	return *instance;
}