// Author: Matthew Day

#include <iostream>

#include "bibleSearcher.h"

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

	do {

		printMenu();

		cin >> selectedOption;

		if (selectedOption == searchOption) {

			searchBible();
		} else if (selectedOption == iterateOption) {


		}
	} while (selectedOption != quitOption);

	return 0;
}