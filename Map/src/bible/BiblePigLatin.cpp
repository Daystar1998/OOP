// Author: Matthew Day

#include "BiblePigLatin.h"

#include "../util/StringUtils.h"

BiblePigLatin::BiblePigLatin() {}

BiblePigLatin::~BiblePigLatin() {}

void BiblePigLatin::visit(VerseKey &key, Verse &verse) {

	string verseText = verse.getText();

	string convertedVerse = "";

	for (int i = 0; i < verseText.size(); i++) {

		if (std::isalpha(verseText[i])) {

			string currentWord = StringUtils::getVariable(verseText, i, i);

			string convertedWord = "";

			bool capitalized = false;

			if (std::isupper(currentWord[0])) {

				currentWord[0] = tolower(currentWord[0]);
				capitalized = true;
			}

			if (isVowel(currentWord[0])) {

				convertedWord.append(currentWord);
				convertedWord.append("yay");
			} else {

				string consonants = "";

				for (int j = 0; j < currentWord.size(); j++) {

					if (j == currentWord.size() - 1 || isVowel(currentWord[j])) {

						convertedWord += currentWord.substr(j, currentWord.size() - j);
						convertedWord += consonants;
						convertedWord += "ay";

						break;
					} else {

						consonants += currentWord[j];
					}
				}
			}

			if (capitalized) {

				convertedWord[0] = toupper(convertedWord[0]);
			}

			convertedVerse += convertedWord;
		} else {

			convertedVerse += verseText[i];
		}
	}

	verse = Verse(key, convertedVerse);
}

bool BiblePigLatin::isVowel(char character) const {

	bool result = false;

	switch (character) {

		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':

			result = true;
	}

	return result;
}