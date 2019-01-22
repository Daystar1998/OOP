#include <map>

#include "display.h"
#include "maze.h"

using std::map;

int main() {

	GameObject *maze = new Maze(25, 25);

	Display display(25, 25);

	display.setPixel("wall", Display::Pixel((char)219, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED));
	display.setPixel("path", Display::Pixel((char)0, 0));
	display.setPixel("start", Display::Pixel('S', FOREGROUND_BLUE | FOREGROUND_INTENSITY));
	display.setPixel("exit", Display::Pixel('E', FOREGROUND_GREEN | FOREGROUND_INTENSITY));
	display.setPixel("player", Display::Pixel('P', FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY));

	while (maze->getState() == GameObject::State::RUNNING) {

		maze->update();

		maze->draw(display);
		display.swapBuffers();
	}

	delete maze;

	// Avoid having the press any button to exit message appear randomly in the middle of what was previously on screen
	display.clearScreen();
	display.swapBuffers();
}