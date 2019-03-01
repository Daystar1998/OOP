// Author: Matthew Day

#pragma once

#include <cctype>
#include <fstream>
#include <vector>

#include "../Picture.h"
#include "../RGBTriple.h"
#include "../shapes/Point.h"
#include "../shapes/Polygon.h"
#include "../shapes/Shape.h"
#include "../shapes/Rectangle.h"
#include "../shapes/RightTriangle.h"
#include "StringUtils.h"
#include "String.h"

using std::getline;
using std::ifstream;
using std::isdigit;
using std::istream;
using std::vector;

class STBParser {

public:

	static Picture parseSTBFile(const String &fileName, vector<Shape*> &oShapes);

	static void parseShapes(String currentLine, istream &data, vector<Shape*> &oShapes);

	static RGBTriple parseColor(const String &data, int begin);

	static bool parseBoolean(const String &data, int begin);

	static String getCodeBlock(istream &data);
};

