// Author: Matthew Day

#pragma once

#include "Bible.h"

class BiblePigLatin : public Bible::IVisitor {

public:

	BiblePigLatin();

	virtual ~BiblePigLatin();

	virtual void visit(VerseKey &key, Verse &verse);

	virtual bool isVowel(char character) const;
};

