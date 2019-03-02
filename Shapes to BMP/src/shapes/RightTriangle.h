#pragma once

#include "Polygon.h"

class RightTriangle : public Polygon {

public:

	RightTriangle();

	virtual ~RightTriangle();

	virtual void initialize(const string &data) override;
};

