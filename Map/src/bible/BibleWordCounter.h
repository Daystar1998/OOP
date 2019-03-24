// Author: Matthew Day

#pragma once

#include <string>

#include "Bible.h"

using std::string;

class BibleWordCounter : public Bible::IVisitor {

private:

	string word;
	unsigned int count;
public:

	BibleWordCounter(const string &word);

	virtual ~BibleWordCounter();

	virtual void visit(VerseKey &key, Verse &verse);

	inline unsigned int getCount() const {

		return count;
	}
};

