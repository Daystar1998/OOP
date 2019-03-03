#pragma once

#include "Polygon.h"

class Star : public Polygon {

public:

	Star();

	virtual ~Star();

	void initialize(const string &data) override;
private:

	Coordinate findIntersection(Coordinate line1Start, Coordinate line1End, Coordinate line2Start, Coordinate line2End);
};

