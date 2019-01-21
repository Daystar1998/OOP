#include <map>

#include "display.h"
#include "maze.h"

using std::map;

void mapTypesToPixels(map<Maze::Type, Display::Pixel> &typeToPixelMap) {

	typeToPixelMap.emplace(Maze::Type::WALL, Display::Pixel((char)219, 1));
	typeToPixelMap.emplace(Maze::Type::PATH, Display::Pixel((char)0, 1));
	typeToPixelMap.emplace(Maze::Type::START, Display::Pixel('S', 1));
	typeToPixelMap.emplace(Maze::Type::DESTINATION, Display::Pixel('D', 1));
	typeToPixelMap.emplace(Maze::Type::PLAYER, Display::Pixel('P', 1));
}

int main() {

	Maze maze(25, 25);

	Display display(25, 25);

	display.setPixel("wall", Display::Pixel((char)219, 1));
	display.setPixel("path", Display::Pixel((char)0, 1));
	display.setPixel("start", Display::Pixel('S', 1));
	display.setPixel("destination", Display::Pixel('D', 1));
	display.setPixel("player", Display::Pixel('P', 1));

	bool stopped = false;

	while (!stopped) {

		maze.update();

		maze.draw(display);
		display.swapBuffers();
	}
}