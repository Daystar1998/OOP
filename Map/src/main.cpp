// Author: Matthew Day

#include <iostream>
#include <string>

#include "bible/BibleWordCounter.h"

#include "menu/bibleSearcherMenu.h"
#include "menu/bibleIteratorMenu.h"

using std::cin;
using std::endl;
using std::cout;

const int searchOption = 1;
const int iterateOption = 2;
const int countWordsOption = 3;
const int quitOption = 4;

void printMenu() {

	cout << searchOption << ": Search Bible for verse" << endl;
	cout << iterateOption << ": Iterate over Bible" << endl;
	cout << countWordsOption << ": Count number of instances of the specified word" << endl;
	cout << quitOption << ": Quit" << endl;
	cout << "\nEnter selection: ";
}

int main() {

	int selectedOption;

	std::string line;

	do {

		printMenu();

		std::getline(cin, line);

		selectedOption = std::stoi(line);

		switch (selectedOption) {

		case searchOption:

			searchBible();
			break;
		case iterateOption:

			iterateOverBible();
			break;
		case countWordsOption:

			cout << "Enter word: ";
			std::getline(cin, line);

			BibleWordCounter counter(line);

			Bible::getInstance().visit(counter);

			cout << "\"" << line << "\" was found " << counter.getCount();

			if (counter.getCount() == 1) {

				cout << " time" << endl;
			} else {

				cout << " times" << endl;
			}

			break;
		};
	} while (selectedOption != quitOption);

	return 0;
}