#pragma once

/******************************************************************
File Name: display.h

Class Name: Display

Des: This class is used to display to the command prompt

Author: Matthew Day

Due Date: 1/23/19
*******************************************************************/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <windows.h>

using std::cout;
using std::map;
using std::string;
using std::vector;

class Display {

public:

	struct Pixel {

		char symbol;
		short color;

		Pixel()
			: symbol((char)0), color(0){}

		Pixel(char symbol, int color)
			: symbol(symbol), color(color){}
	};
private:

	int width, height;

	map<string, Pixel> pixelMap;

	vector<Pixel> currentBuffer;
	vector<Pixel> nextBuffer;
public:

	Display(int width, int height);

	void clearScreen();
	void fill(Pixel &pixel);

	void draw(int x, int y, Pixel data);
	void draw(int startX, int startY, int width, int height, vector<Pixel> data);

	void resize(int width, int height);

	void swapBuffers();
private:

	void initializeDisplay(int width, int height);
public:

	void setPixel(string label, Pixel pixel);

	Pixel getPixel(string label);
};