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
	std::getline(in, line);
	book = line;

	cout << "Enter the chapter: ";
	std::getline(in, line);
	chapter = stoi(line);

	cout << "Enter the verse number: ";
	std::getline(in, line);
	verseNumber = stoi(line);

	verseKey = VerseKey(book, chapter, verseNumber);

	return in;
}