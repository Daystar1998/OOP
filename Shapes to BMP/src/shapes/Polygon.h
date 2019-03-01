#pragma once

#include <vector>

#include "Shape.h"
#include "../util/STBParser.h"
#include "../util/String.h"
#include "../util/StringUtils.h"

using std::vector;

class Polygon : public Shape {

public:

	vector<Coordinate> vertices;

	Polygon();

	virtual ~Polygon();
	
	virtual void initialize(const string &data) override;

	virtual void draw(Picture &picture) const override;

	virtual void drawShadow(Picture &picture) const override;
};

