// Author: Matthew Day

#pragma once

#include <vector>

#include "Shape.h"
#include "../util/STBParser.h"
#include "../util/String.h"
#include "../util/StringUtils.h"

using std::vector;

class Point : public Shape {

public:

	Point();

	virtual ~Point();

	virtual void initialize(const string &data) override;

	virtual void draw(Picture &picture) const override;

	virtual void drawShadow(Picture &picture) const override;
};

