#include "Shape.h"

bool Shape::hasShadow = false;
int Shape::shadowOffsetX = 0;
int Shape::shadowOffsetY = 0;

Shape::Shape(const string &data) {

	initialize(data);
}