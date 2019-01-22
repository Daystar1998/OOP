#include <map>

#include "display.h"
#include "maze.h"

using std::map;

int main() {

	Maze maze(25, 25);

	Display display(25, 25);

	display.setPixel("wall", Display::Pixel((char)219, 1));
	display.setPixel("path", Display::Pixel((char)0, 1));
	display.setPixel("start", Display::Pixel('S', 1));
	display.setPixel("destination", Display::Pixel('D', 1));
	display.setPixel("player", Display::Pixel('P', 1));

	while (maze.getState() == GameObject::State::RUNNING) {

		maze.update();

		maze.draw(display);
		display.swapBuffers();
	}
}