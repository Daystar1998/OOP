#pragma once

// Author: Matthew Day

#include <string>

using std::string;

class VerseKey {

private:

	string book;

	int chapter;
	int verseNumber;
public:

	VerseKey();

	virtual ~VerseKey();

	bool operator==(const VerseKey &other) const;
};

