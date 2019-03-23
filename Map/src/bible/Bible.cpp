// Author: Matthew Day

#include "Bible.h"

Bible *Bible::instance = nullptr;

Bible::Bible() {}

Bible::~Bible() {}

Bible& Bible::getInstance() {

	if (instance == nullptr) {

		instance = new Bible();
	}

	return *instance;
}