// Author: Matthew Day

#include "BiblePigLatin.h"

BiblePigLatin::BiblePigLatin() {}

BiblePigLatin::~BiblePigLatin() {}

void BiblePigLatin::visit(VerseKey &key, Verse &verse) {

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