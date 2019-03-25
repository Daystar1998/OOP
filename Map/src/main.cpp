// Author: Matthew Day

#include <iostream>
#include <string>

#include "bibleSearcher.h"
#include "bibleIterator.h"

using std::cin;
using std::endl;
using std::cout;

int searchOption = 1;
int iterateOption = 2;
int quitOption = 3;

void printMenu() {

	cout << searchOption << ": Search Bible for verse" << endl;
	cout << iterateOption << ": Iterate over Bible" << endl;
	cout << quitOption << ": Quit" << endl;
	cout <<  "\nEnter selection: ";
}

int main() {

	int selectedOption;

	std::string line;

	do {

		printMenu();

		std::getline(cin, line);

		selectedOption = std::stoi(line);

		if (selectedOption == searchOption) {

			searchBible();
		} else if (selectedOption == iterateOption) {

			iterateOverBible();
		}
	} while (selectedOption != quitOption);

	return 0;
}