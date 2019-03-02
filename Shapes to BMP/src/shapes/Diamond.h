#pragma once

#include "Polygon.h"

class Diamond : public Polygon {

public:

	Diamond();

	virtual ~Diamond();

	void initialize(const string &data) override;
};
