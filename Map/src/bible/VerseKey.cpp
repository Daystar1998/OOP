// Author: Matthew Day

#include "VerseKey.h"

#include <cctype>

VerseKey::VerseKey(string book, int chapter, int verseNumber)
	: book(book), chapter(chapter), verseNumber(verseNumber) {
}

VerseKey::~VerseKey() {}

bool VerseKey::operator==(const VerseKey &other) const {

	bool result = this->book == other.book && this->chapter == other.chapter && this->verseNumber == other.verseNumber;

	return result;
}

istream& operator>>(istream &in, VerseKey &verseKey) {

	string line;

	string book;
	int chapter;
	int verseNumber;

	cout << "Enter the book: ";

	do {

		std::getline(in, line);
		book = line;
	} while (line.size() == 0);

	cout << "Enter the chapter: ";

	do {

		std::getline(in, line);

		try {

			chapter = stoi(line);
		} catch (std::invalid_argument) {

			cout << "The value entered is not valid" << endl;
			line.clear();
		}
	} while (line.size() == 0);

	cout << "Enter the verse number: ";

	do {

		std::getline(in, line);

		try {

			verseNumber = stoi(line);
		} catch (std::invalid_argument) {

			cout << "The value entered is not valid" << endl;
			line.clear();
		}
	} while (line.size() == 0);

	verseKey = VerseKey(book, chapter, verseNumber);

	return in;
}