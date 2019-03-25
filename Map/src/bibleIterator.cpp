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

	const int startOption = 1;
	const int predecrementOption = 2;
	const int postdecrementOption = 3;
	const int preincrementOption = 4;
	const int postincrementOption = 5;
	const int displayCurrent = 6;
	const int quitOption = 7;

	int selectedOption;

	std::string line;

	do {

		cout << startOption << ": Start at new verse" << endl;
		cout << predecrementOption << ": Pre-decrement" << endl;
		cout << postdecrementOption << ": Post-decrement" << endl;
		cout << preincrementOption << ": Pre-increment" << endl;
		cout << postincrementOption << ": Post-increment" << endl;
		cout << displayCurrent << ": Display current verse" << endl;
		cout << quitOption << ": Quit" << endl;
		cout << "\nEnter selection: ";

		std::getline(cin, line);
		selectedOption = std::stoi(line);

		switch (selectedOption) {

		case startOption:

			cin >> verseKey;

			try {

				i = bible.getIterator(verseKey);
			} catch (std::range_error) {

				cout << "Verse not found" << endl;
			}

			cout << (*i).getText() << endl;

			break;
		case predecrementOption:

			cout << (*(--i)).getText() << endl;

			break;
		case postdecrementOption:

			cout << (*(i--)).getText() << endl;

			break;
		case preincrementOption:

			cout << (*(++i)).getText() << endl;

			break;
		case postincrementOption:

			cout << (*(i++)).getText() << endl;

			break;
		case displayCurrent:

			cout << (*i).getText() << endl;

			break;
	};
	} while (selectedOption != quitOption);
}