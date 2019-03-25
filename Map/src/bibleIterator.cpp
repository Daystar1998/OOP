// Author: Matthew Day

#include "bibleIterator.h"

#include <iostream>

#include "bible/Bible.h"
#include "bible/VerseKey.h"
#include "bible/Verse.h"

using std::cin;
using std::endl;
using std::cout;

void iterateOverBible() {

	Bible &bible = Bible::getInstance();

	VerseKey verseKey("", 0, 0);

	Bible::Iterator i = bible.begin();

	int startOption = 1;
	int predecrementOption = 2;
	int postdecrementOption = 3;
	int preincrementOption = 4;
	int postincrementOption = 5;
	int displayCurrent = 6;
	int quitOption = 7;

	int selectedOption;

	do {

		cout << startOption << ": Start at new verse" << endl;
		cout << predecrementOption << ": Pre-decrement" << endl;
		cout << postdecrementOption << ": Post-decrement" << endl;
		cout << preincrementOption << ": Pre-increment" << endl;
		cout << postincrementOption << ": Post-increment" << endl;
		cout << displayCurrent << ": Display current verse" << endl;
		cout << quitOption << ": Quit" << endl;
		cout << "\nEnter selection: ";

		cin >> selectedOption;
	} while (selectedOption != quitOption);
}