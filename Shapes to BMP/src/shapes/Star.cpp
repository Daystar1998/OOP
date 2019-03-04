#include "Star.h"

Star::Star() {}

Star::~Star() {}

void Star::initialize(const string &data) {

	Polygon::initialize(data);

	if (vertices.size() < 5) {

		throw "Error: Not enough vertices for a star. Needs to have 5";
	} else if (vertices.size() > 5) {

		throw "Error: Too many vertices for a star. Needs to have 5";
	}

	vertices.insert(vertices.begin() + 5, Coordinate());
	vertices.insert(vertices.begin() + 4, Coordinate());
	vertices.insert(vertices.begin() + 3, Coordinate());
	vertices.insert(vertices.begin() + 2, Coordinate());
	vertices.insert(vertices.begin() + 1, Coordinate());

	lineIntersects(vertices[0], vertices[4], vertices[2], vertices[8], vertices[1]);
	lineIntersects(vertices[2], vertices[6], vertices[4], vertices[0], vertices[3]);
	lineIntersects(vertices[4], vertices[8], vertices[6], vertices[2], vertices[5]);
	lineIntersects(vertices[6], vertices[0], vertices[8], vertices[4], vertices[7]);
	lineIntersects(vertices[8], vertices[2], vertices[0], vertices[6], vertices[9]);
}