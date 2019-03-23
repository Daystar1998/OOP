#pragma once

// Author: Matthew Day

#include "../Map.hpp"
#include "Verse.h"
#include "VerseKey.h"

class Bible : public util::Map<VerseKey, Verse> {

private:

	static Bible *instance;

	Bible(const Bible &other) = delete;
	const Bible& operator=(const Bible &other) = delete;

	Bible();
public:

	virtual ~Bible();

	static Bible& getInstance();
};

