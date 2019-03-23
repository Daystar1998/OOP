#pragma once

// Author: Matthew Day

#include "../Map.hpp"
#include "Verse.h"
#include "VerseKey.h"

class Bible : public util::Map<VerseKey, Verse> {

public:

	Bible();

	virtual ~Bible();
};

