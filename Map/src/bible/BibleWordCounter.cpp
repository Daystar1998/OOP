// Author: Matthew Day

#include "BibleWordCounter.h"

#include "../util/StringUtils.h"

BibleWordCounter::BibleWordCounter(const string &word)
	: word(word), count(0) {}

BibleWordCounter::~BibleWordCounter() {}

void BibleWordCounter::visit(VerseKey &key, Verse &verse) {

	string verseText = verse.getText();

	int currentPosition = 0;

	string currentWord = StringUtils::getNextVariable(verseText, currentPosition, currentPosition);

	while (currentPosition < verseText.size()) {

		if (currentWord == word) {

			count++;
		}

		currentWord = StringUtils::getNextVariable(verseText, currentPosition + 1, currentPosition);
	}
}