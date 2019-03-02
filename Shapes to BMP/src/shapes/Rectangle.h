// Author: Matthew Day

#pragma once

#include "Polygon.h"

class Rectangle : public Polygon {

public:

	Rectangle();

	virtual ~Rectangle();

	virtual void initialize(const string &data) override;
};

