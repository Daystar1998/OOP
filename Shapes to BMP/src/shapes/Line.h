#pragma once

#include "Shape.h"

class Line : public Shape {

private:

	Coordinate endCoordinate;
public:

	Line();

	virtual ~Line();

	virtual void initialize(const string &data) override;

	virtual void draw(Picture &picture) const override;

	virtual void drawShadow(Picture &picture) const override;
};

