// Author: Matthew Day

#pragma once

#include "Bible.h"

class BibleWordCounter : public Bible::IVisitor {

public:

	BibleWordCounter();

	virtual ~BibleWordCounter();

	virtual void visit(VerseKey &key, Verse &verse);
};

