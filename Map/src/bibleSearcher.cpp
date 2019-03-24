// Author: Matthew Day

#include "bibleSearcher.h"

#include <iostream>

#include "bible/Bible.h"
#include "bible/VerseKey.h"
#include "bible/Verse.h"

using std::cin;
using std::endl;
using std::cout;

void searchBible() {

	Bible &bible = Bible::getInstance();

	VerseKey verseKey("", 0, 0);
	Verse verse(verseKey, "");

	cin >> verseKey;

	while (verseKey.getBook() != "Quit") {

		try {

			verse = bible[verseKey];
			cout << verse.getText() << endl;
		} catch (std::range_error) {

			cout << "Verse not found" << endl;
		}

		cin >> verseKey;
	}
}