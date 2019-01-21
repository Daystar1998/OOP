/******************************************************************
File Name: display.cpp

Des: This file implements display.h.

Author: Matthew Day

Due Date: 1/23/19
*******************************************************************/

#include "display.h"

Display::Display(int width, int height) {

	initializeDisplay(width, height);
}

void Display::initializeDisplay(int width, int height) {

	Display::width = width;
	Display::height = height;

	currentBuffer.resize(width * height);
	nextBuffer.resize(width * height);
}

void Display::clearScreen() {

	Pixel pixel((char)0, 0);
	fill(pixel);
}

void Display::fill(Pixel &pixel) {

	for (int i = 0; i < width * height; i++) {

		nextBuffer[i] = pixel;
	}
}

void Display::draw(int x, int y, Pixel data) {

	vector<Pixel> temp = { data };

	draw(x, y, 1, 1, temp);
}

void Display::draw(int startX, int startY, int width, int height, vector<Pixel> data) {

	// TODO: Implement clipping to avoid out of bounds errors and other odd effects

	for (int y = 0; y < height; y++) {

		for (int x = 0; x < width; x++) {

			Pixel current = data[y * width + x];
			nextBuffer[(Display::width - 1 - (y + startY)) * Display::width + (x + startX)] = current;
		}
	}
}

void Display::swapBuffers() {

	for (int y = 0; y < height; y++) {

		for (int x = 0; x < width; x++) {

			Pixel &currentPixel = currentBuffer[y * width + x];
			Pixel &nextPixel = nextBuffer[y * width + x];

			// Only update if the pixel has been changed
			if (currentPixel.symbol != nextPixel.symbol || currentPixel.color != nextPixel.color) {

				currentPixel.symbol = nextPixel.symbol;
				currentPixel.color = nextPixel.color;

				// TODO: Windows specific code. Consider splitting this into its own function to make changing platform specific code easier
				COORD newCoord = { x, y };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), newCoord);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), nextPixel.color);
				cout << nextPixel.symbol;
			}
		}
	}
}

void Display::resize(int width, int height) {

	// Only take the time to clear when shrinking the display
	if (Display::width > width || Display::height > height) {

		// Avoid leaving dead pixels
		clearScreen();
		swapBuffers();
	}

	initializeDisplay(width, height);
}

void Display::setPixel(string label, Pixel pixel) {

	pixelMap.emplace(label, pixel);
}

Display::Pixel Display::getPixel(string label) {

	return pixelMap[label];
}