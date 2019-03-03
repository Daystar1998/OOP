#pragma once

#include "Shape.h"

class Circle : public Shape {

public:

	int radius;
public:

	Circle();

	virtual ~Circle();

	virtual void initialize(const string &data) override;

	virtual void draw(Picture &picture) const override;

	virtual void drawShadow(Picture &picture) const override;
private:

	virtual void drawCircle(Coordinate position, int radius, RGBTriple color, Picture &picture) const;
};

