#include <map>

#include "display.h"
#include "gameObject.h"
#include "maze.h"

using std::map;

int main() {

	int width = 25;
	int height = 25;

	GameObject *maze = new Maze(GameObject::Position(0, 0), width, height);

	Display display(width, height);

	display.setPixel("wall", Display::Pixel((char)219, FOREGROUND_GREEN));
	display.setPixel("path", Display::Pixel((char)0, 0));
	display.setPixel("start", Display::Pixel('S', FOREGROUND_BLUE | FOREGROUND_INTENSITY));
	display.setPixel("exit", Display::Pixel('E', FOREGROUND_RED | FOREGROUND_INTENSITY));
	display.setPixel("player", Display::Pixel('P', FOREGROUND_RED | FOREGROUND_INTENSITY));

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