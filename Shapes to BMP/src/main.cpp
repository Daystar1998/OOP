// Author: Matthew Day

#include <vector>

#include "Picture.h"
#include "shapes/Point.h"
#include "shapes/Shape.h"
#include "util/STBParser.h"
#include "RGBTriple.h"

int main(int argc, char *argv[]) {

	if (argc > 1 && argc <= 3) {

		if (String(argv[1]).endsWith(".stb")) {

			vector<Shape*> shapes;

			Picture picture = STBParser::parseSTBFile(argv[1], shapes);

			Shape::setShadowOffsetX(-1);
			Shape::setShadowOffsetY(-1);

			for (int i = 0; i < shapes.size(); i++) {

				shapes[i]->drawShadow(picture);
				shapes[i]->draw(picture);
			}

			for (int i = 0; i < shapes.size(); i++) {

				delete shapes[i];
			}

			const char *outputFile;

			string temp = argv[1];
			temp.replace(temp.length() - 3, 3, "bmp");
			outputFile = temp.c_str();

			picture.WriteToFile(outputFile);
		} else {

			throw "Error: Incorrect filetype. Supported type is STB";
		}
	} else {

		throw "Error: Too many arguments";
	}
}