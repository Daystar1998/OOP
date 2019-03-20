// Author: Matthew Day

#include "VerseKey.h"

VerseKey::VerseKey(string book, int chapter, int verseNumber)
	: book(book), chapter(chapter), verseNumber(verseNumber) {
}

VerseKey::~VerseKey() {}

bool VerseKey::operator==(const VerseKey &other) const {

	bool result = this->book == other.book && this->chapter == other.chapter && this->verseNumber == other.verseNumber;

	return result;
}