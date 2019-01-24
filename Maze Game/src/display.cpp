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

	// Set the console cursor to not visible
	CONSOLE_CURSOR_INFO *cursor = new CONSOLE_CURSOR_INFO { 10, false };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	delete cursor;
}

void Display::clearScreen() {

	Pixel pixel((char)0, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
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
			int index = (y + startY) * Display::width + (x + startX);
			nextBuffer[index] = current;
		}
	}
}

void Display::swapBuffers() {

	// Draw starting from the bottom right corner up to the the upper left corner. This is done to avoid a bug where the upper part of the display is not drawn at first
	for (int y = height - 1; y >= 0; y--) {

		for (int x = width - 1; x >= 0; x--) {

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

void Display::setPixel(int id, Pixel pixel) {

	pixelMap.emplace(id, pixel);
}

Display::Pixel Display::getPixel(int id) {

	return pixelMap[id];
}