// Author: Matthew Day

#pragma once

#include <vector>

#include "Shape.h"
#include "../util/String.h"
#include "../util/StringUtils.h"

using std::vector;

class Polygon : public Shape {
	
protected:

	vector<Coordinate> vertices;
public:

	Polygon();

	virtual ~Polygon();
	
	virtual void initialize(const string &data) override;

	virtual void draw(Picture &picture) const override;

	virtual void drawShadow(Picture &picture) const override;
};