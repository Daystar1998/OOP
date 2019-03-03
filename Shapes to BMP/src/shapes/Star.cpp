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

	vertices[1] = findIntersection(vertices[0], vertices[4], vertices[2], vertices[8]);
	vertices[3] = findIntersection(vertices[2], vertices[6], vertices[4], vertices[0]);
	vertices[5] = findIntersection(vertices[4], vertices[8], vertices[6], vertices[2]);
	vertices[7] = findIntersection(vertices[6], vertices[0], vertices[8], vertices[4]);
	vertices[9] = findIntersection(vertices[8], vertices[2], vertices[0], vertices[6]);
}

Shape::Coordinate Star::findIntersection(Coordinate line1Start, Coordinate line1End, Coordinate line2Start, Coordinate line2End) {

	Coordinate result;

	double m1, m2;

	// Check to avoid dividing by zero
	if (line1Start.x == 0 && line1End.x == 0) {

		m1 = 0;
	} else {

		m1 = (double)(line1End.y - line1Start.y) / (double)(line1End.x - line1Start.x);
	}

	// Check to avoid dividing by zero
	if (line2Start.x == 0 && line2End.x == 0) {

		m2 = 0;
	} else {

		m2 = (double)(line2End.y - line2Start.y) / (double)(line2End.x - line2Start.x);
	}

	double b1 = line1Start.y - (line1Start.x * m1);
	double b2 = line2Start.y - (line2Start.x * m2);

	// y1 = m1x + b1
	// y2 = m2x + b2
	// m1x + b1 = m2x + b2;
	// m1x - m2x = b2 - b1;
	// (m1 - m2) * x = b2 - b1;
	// x = (b2 - b1) / (m1 - m2)
	int x = floor((b2 - b1) / (m1 - m2));
	int y = floor(x * m1 + b1);

	result.x = x;
	result.y = y;

	return result;
}