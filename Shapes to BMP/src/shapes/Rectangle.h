// Author: Matthew Day

#pragma once

#include "Shape.h"

class Rectangle : public Shape {

protected:

	vector<Coordinate> vertices;
public:

	Rectangle();

	virtual ~Rectangle();

	virtual void initialize(const string &data) override;

	virtual void draw(Picture &picture) const override;

	virtual void drawShadow(Picture &picture) const override;
};

