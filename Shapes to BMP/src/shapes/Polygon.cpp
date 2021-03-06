// Author: Matthew Day

#include "Polygon.h"

#include <algorithm>

#include "../util/STBParser.h"

Polygon::Polygon() {}

Polygon::~Polygon() {}

void Polygon::initialize(const string &data) {

	vector<String> lines;

	String(data).split("\n", lines);

	isFilled = false;

	for (int i = 0; i < lines.size(); i++) {

		if (isParsingCommonData(lines[i])) {

			// Do nothing
		} else {

			lines[i].trim();

			int currentPosition = 0;

			String label = StringUtils::getNextVariable(lines[i], currentPosition, currentPosition);

			if (label == "vertex") {

				int x = StringUtils::getNextNumber(lines[i], currentPosition + 1, currentPosition);
				int y = StringUtils::getNextNumber(lines[i], currentPosition + 1, currentPosition);

				vertices.push_back(Coordinate(x, y));
			}
		}
	}
}

void Polygon::draw(Picture &picture) const {

	if (vertices.size() >= 1) {

		if (hasShadow) {

			drawShadow(picture);
		}

		for (int i = 0; i < vertices.size() - 1; i++) {

			picture.AddLine(startCoordinate.x + vertices[i].x, startCoordinate.y + vertices[i].y, startCoordinate.x + vertices[i + 1].x, startCoordinate.y + vertices[i + 1].y, color);
		}

		picture.AddLine(startCoordinate.x + vertices[0].x, startCoordinate.y + vertices[0].y, startCoordinate.x + vertices[vertices.size() - 1].x, startCoordinate.y + vertices[vertices.size() - 1].y, color);

		if (isFilled) {

			int minY = vertices[0].y;
			int maxY = vertices[0].y;

			for (int i = 1; i < vertices.size(); i++) {

				if (vertices[i].y < minY) {

					minY = vertices[i].y;
				} else if (vertices[i].y > maxY) {

					maxY = vertices[i].y;
				}
			}


			for (int y = minY + 1; y < maxY; y++) {

				vector<int> edges;

				findSortedEdgesOnHorizontalLine(y, edges);

				for (int i = 0; i < edges.size(); i += 2) {

					if (i + 1 != edges.size()) {

						picture.AddLine(startCoordinate.x + edges[i], startCoordinate.y + y, startCoordinate.x + edges[i + 1], startCoordinate.y + y, color);
					}
				}
			}
		}
	}
}

void Polygon::drawShadow(Picture &picture) const {

	RGBTriple shadowColor = getShadowColor();

	for (int i = 0; i < vertices.size() - 1; i++) {

		picture.AddLine(startCoordinate.x + vertices[i].x + shadowOffsetX, startCoordinate.y + vertices[i].y + shadowOffsetY, startCoordinate.x + vertices[i + 1].x + shadowOffsetX, startCoordinate.y + vertices[i + 1].y + shadowOffsetY, shadowColor);
	}

	picture.AddLine(startCoordinate.x + vertices[0].x + shadowOffsetX, startCoordinate.y + vertices[0].y + shadowOffsetY, startCoordinate.x + vertices[vertices.size() - 1].x + shadowOffsetX, startCoordinate.y + vertices[vertices.size() - 1].y + shadowOffsetY, shadowColor);
}

void Polygon::findSortedEdgesOnHorizontalLine(int y, vector<int> &edges) const {

	for (int i = 0; i < vertices.size(); i++) {

		int nextIndex = i + 1;

		if (nextIndex >= vertices.size()) {

			nextIndex = 0;
		}

		// Ensure the edge crosses the current y position
		if ((vertices[i].y < y && vertices[nextIndex].y < y) || (vertices[i].y > y && vertices[nextIndex].y > y)) {

			continue;
		}

		if (vertices[i].x != vertices[nextIndex].x) {

			double m1 = (double)(vertices[i].y - vertices[nextIndex].y) / (double)(vertices[i].x - vertices[nextIndex].x);

			double b1 = vertices[i].y - (vertices[i].x * m1);
			double b2 = y;

			// y1 = m1x + b1
			// y2 = b2
			// m1x + b1 = b2;
			// m1x = b2 - b1;
			// x = (b2 - b1) / m1
			int x = (int)floor((b2 - b1) / m1);

			if ((vertices[i].x < x && vertices[nextIndex].x < x) || (vertices[i].x > x && vertices[nextIndex].x > x) || (vertices[i].x == vertices[nextIndex].x)) {

				continue;
			}

			if (x == vertices[i].x && y == vertices[i].y) {

				int previousIndex = i - 1;

				if (previousIndex < 0) {

					previousIndex = (int)vertices.size() - 1;
				}

				bool bothAbove = vertices[previousIndex].y > vertices[i].y && vertices[nextIndex].y > vertices[i].y;
				bool bothBelow = vertices[previousIndex].y < vertices[i].y && vertices[nextIndex].y < vertices[i].y;

				if (bothAbove || bothBelow) {

					// Do nothing
				} else {

					edges.push_back(x);
				}
			} else if (x == vertices[nextIndex].x && y == vertices[nextIndex].y) {

				// Do nothing
			} else {

				edges.push_back(x);
			}
		} else {

			edges.push_back(vertices[i].x);
		}
	}

	sort(edges.begin(), edges.end());
}

bool Polygon::lineIntersects(Coordinate line1Start, Coordinate line1End, Coordinate line2Start, Coordinate line2End, Coordinate &oIntersection) const {

	bool result = false;

	// Both lines are horizontal
	if (line1Start.y == line1End.y && line2Start.y == line2End.y) {

		// Do nothing
	} else {

		double m1, m2;
		double b1, b2;
		double x, y;

		// Line one is vertical but line two is not
		if (line1Start.x == line1End.x && line2Start.x != line2End.x) {

			m2 = (double)(line2End.y - line2Start.y) / (double)(line2End.x - line2Start.x);
			b2 = line2Start.y - (line2Start.x * m2);

			x = line1Start.x;
			y = x * m2 + b2;
		// Line two is vertical but line one is not
		} else if (line1Start.x != line1End.x && line2Start.x == line2End.x) {

			m1 = (double)(line1End.y - line1Start.y) / (double)(line1End.x - line1Start.x);
			b1 = line1Start.y - (line1Start.x * m1);

			x = line2Start.x;
			y = x * m1 + b1;
		// Neither line is vertical
		} else if (line1Start.x != line1End.x && line2Start.x != line2End.x) {

			m1 = (double)(line1End.y - line1Start.y) / (double)(line1End.x - line1Start.x);
			m2 = (double)(line2End.y - line2Start.y) / (double)(line2End.x - line2Start.x);

			b1 = line1Start.y - (line1Start.x * m1);
			b2 = line2Start.y - (line2Start.x * m2);

			// y = m1x + b1
			// y = m2x + b2
			// m1x + b1 = m2x + b2;
			// m1x - m2x = b2 - b1;
			// (m1 - m2) * x = b2 - b1;
			// x = (b2 - b1) / (m1 - m2)
			x = (b2 - b1) / (m1 - m2);
			y = x * m1 + b1;
		}

		// Check that the x and why values are in range regardless of the order the points of the line are in
		bool inRangeOnX = ((x >= line1Start.x && x <= line1End.x) || (x >= line1End.x && x <= line1Start.x)) && ((x >= line2Start.x && x <= line2End.x) || (x >= line2End.x && x <= line2Start.x));
		bool inRangeOnY = ((y >= line1Start.y && y <= line1End.y) || (y >= line1End.y && x <= line1Start.y)) && ((y >= line2Start.y && y <= line2End.y) || (y >= line2End.y && y <= line2Start.y));

		// Ensure the coordinate is inside the range of both lines
		if (inRangeOnX && inRangeOnY) {

			result = true;

			oIntersection.x = (int)floor(x);
			oIntersection.y = (int)floor(y);
		}
	}

	return result;
}