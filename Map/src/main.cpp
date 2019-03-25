// Author: Matthew Day

#include <iostream>
#include <string>

#include "menu/bibleSearcherMenu.h"
#include "menu/bibleIteratorMenu.h"

using std::cin;
using std::endl;
using std::cout;

const int searchOption = 1;
const int iterateOption = 2;
const int quitOption = 3;

void printMenu() {

	cout << searchOption << ": Search Bible for verse" << endl;
	cout << iterateOption << ": Iterate over Bible" << endl;
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
		};
	} while (selectedOption != quitOption);

	return 0;
}