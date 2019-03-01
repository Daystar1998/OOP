#pragma once

#include "Shape.h"

class RightTriangle : public Shape {

protected:

	vector<Coordinate> vertices;
public:

	RightTriangle();

	virtual ~RightTriangle();

	virtual void initialize(const string &data) override;

	virtual void draw(Picture &picture) const override;

	virtual void drawShadow(Picture &picture) const override;
};

