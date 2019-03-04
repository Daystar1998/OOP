#pragma once

#include "Polygon.h"

class Star : public Polygon {

public:

	Star();

	virtual ~Star();

	void initialize(const string &data) override;
};

