// Author: Matthew Day

#include "BibleWordCounter.h"

BibleWordCounter::BibleWordCounter(const string &word)
	: word(word), count(0) {}

BibleWordCounter::~BibleWordCounter() {}

void BibleWordCounter::visit(VerseKey &key, Verse &verse) {

}