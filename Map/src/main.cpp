// Author: Matthew Day

#include <iostream>
#include <string>

#include "bible/BiblePigLatin.h"
#include "bible/BibleWordCounter.h"

#include "menu/bibleSearcherMenu.h"
#include "menu/bibleIteratorMenu.h"

using std::cin;
using std::endl;
using std::cout;

const int searchOption = 1;
const int iterateOption = 2;
const int countWordsOption = 3;
const int pigLatinOption = 4;
const int quitOption = 5;

void printMenu() {

	cout << searchOption << ") Search Bible for verse" << endl;
	cout << iterateOption << ") Iterate over Bible" << endl;
	cout << countWordsOption << ") Count number of instances of the specified word" << endl;
	cout << pigLatinOption << ") Convert to pig latin" << endl;
	cout << quitOption << ") Quit" << endl;
	cout << "\nEnter selection: ";
}

int main() {

	int selectedOption;

	std::string line;

	BibleWordCounter counter("");
	BiblePigLatin pigLatin;

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

				counter = BibleWordCounter(line);

				Bible::getInstance().visit(counter);

				cout << "\"" << line << "\" was found " << counter.getCount();

				if (counter.getCount() == 1) {

					cout << " time" << endl;
				} else {

					cout << " times" << endl;
				}

				break;
			case pigLatinOption:

				Bible::getInstance().visit(pigLatin);

				break;
		};
	} while (selectedOption != quitOption);

	return 0;
}