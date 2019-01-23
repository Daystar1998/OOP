#include <map>

#include "display.h"
#include "entities/player.h"
#include "gameObject.h"
#include "maze.h"
#include "gui/label.h"

int main() {

	int width = 5;
	int height = 5;

	GameObject *root = new GameObject(GameObject::Position(0, 0), width, height);

	Maze *maze = new Maze(GameObject::Position(0, 0), width, height);
	root->addChild(maze);

	maze->addChild(new Player(maze->getStart(), Maze::Type::PLAYER));

	Label *label = new Label(GameObject::Position(0, 3), "Testing");
	//root->addChild(label);

	Display display(width, height);

	// Map pixels
	display.setPixel(Maze::Type::WALL, Display::Pixel((char)219, FOREGROUND_GREEN));
	display.setPixel(Maze::Type::PATH, Display::Pixel((char)0, 0));
	display.setPixel(Maze::Type::START, Display::Pixel('S', FOREGROUND_BLUE | FOREGROUND_INTENSITY));
	display.setPixel(Maze::Type::EXIT, Display::Pixel('E', FOREGROUND_RED | FOREGROUND_INTENSITY));
	display.setPixel(Maze::Type::PLAYER, Display::Pixel('P', FOREGROUND_RED | FOREGROUND_INTENSITY));

	while (maze->getStatus() == GameObject::Status::RUNNING) {

		root->update();

		root->draw(display);
		display.swapBuffers();
	}

	delete root;
	//delete maze;
	delete label;

	// Avoid having the press any button to exit message appear randomly in the middle of what was previously on screen
	display.clearScreen();
	display.swapBuffers();
}