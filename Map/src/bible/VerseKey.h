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
};

istream& operator>>(istream &in, VerseKey &verseKey);