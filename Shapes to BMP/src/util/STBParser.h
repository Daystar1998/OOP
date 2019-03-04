// Author: Matthew Day

#pragma once

#include <cctype>
#include <fstream>
#include <map>
#include <vector>

#include "../Picture.h"
#include "../RGBTriple.h"
#include "../shapes/Shape.h"
#include "String.h"

using std::getline;
using std::ifstream;
using std::isdigit;
using std::istream;
using std::map;
using std::vector;

class STBParser {

private:

	static map<String, RGBTriple> colors;
public:

	static Picture parseSTBFile(const String &fileName, vector<Shape*> &oShapes);

	static void parseShapes(String currentLine, istream &data, vector<Shape*> &oShapes);

	static RGBTriple parseColor(const String &data, int begin);

	static bool parseBoolean(const String &data, int begin);

	static String getCodeBlock(istream &data);

	static RGBTriple getColor(const String &name);

	static void setColor(const String &name, RGBTriple &color);
};

