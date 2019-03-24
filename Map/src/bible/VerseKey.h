#pragma once

// Author: Matthew Day

#include <iostream>
#include <string>

using std::cout;
using std::istream;
using std::string;

class VerseKey {

private:

	string book;

	int chapter;
	int verseNumber;
public:

	VerseKey(string book, int chapter, int verseNumber);

	virtual ~VerseKey();

	bool operator==(const VerseKey &other) const;

	inline string getBook() {

		return book;
	}

	inline int getChapter() {

		return chapter;
	}

	inline int getVerseNumber() {

		return verseNumber;
	}
};

istream& operator>>(istream &in, VerseKey &verseKey);