#pragma once

// Author: Matthew Day

#include <string>

#include "VerseKey.h"

using std::string;

class Verse {

private:

	VerseKey verseKey;
	string verseText;
public:

	Verse(VerseKey verseKey, string verseText);

	virtual ~Verse();

	inline string getText() {

		return verseText;
	}
};