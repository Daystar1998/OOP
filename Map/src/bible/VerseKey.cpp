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

	string book;
	int chapter;
	int verseNumber;

	cout << "Enter the book: ";
	in >> book;

	if (std::isdigit(book[0])) {

		book += " ";

		string bookSecondPart;

		in >> bookSecondPart;

		book += bookSecondPart;
	}

	cout << "Enter the chapter: ";
	in >> chapter;

	cout << "Enter the verse number: ";
	in >> verseNumber;

	verseKey = VerseKey(book, chapter, verseNumber);

	return in;
}