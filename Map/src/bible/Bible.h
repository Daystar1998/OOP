#pragma once

// Author: Matthew Day

#include "../Map.hpp"
#include "Verse.h"
#include "VerseKey.h"

class Bible : util::Map<VerseKey, Verse> {

public:

	Bible();

	virtual ~Bible();
};

