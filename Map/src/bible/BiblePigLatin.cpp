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

			if (isVowel(currentWord[0])) {

				convertedVerse.append(currentWord);
				convertedVerse.append("yay");
			} else {

				string consonants = "";

				for (int j = 0; j < currentWord.size(); j++) {

					if (j == currentWord.size() - 1 || isVowel(currentWord[j])) {

						convertedVerse += currentWord.substr(j, currentWord.size() - j);
						convertedVerse += consonants;
						convertedVerse += "ay";

						break;
					} else {

						consonants += currentWord[j];
					}
				}
			}
		} else {

			convertedVerse += verseText[i];
		}
	}

	Bible::getInstance()[key] = Verse(key, convertedVerse);
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