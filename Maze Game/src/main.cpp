#include <map>

#include "display.h"
#include "entities/player.h"
#include "gameObject.h"
#include "maze.h"

#include "gui/actionListener.h"
#include "gui/button.h"
#include "gui/label.h"

GameObject *root = nullptr;

GameObject* getRootObject() {

	if (root == nullptr)
		root = new GameObject(GameObject::Position(0, 0), 1, 1);

	return root;
}

int main() {

	int width = 5;
	int height = 5;

	Label *label = new Label(GameObject::Position(0, 0), "Testing");
	//root->addChild(label);

	Button *button = new Button(GameObject::Position(0, 0), "Testing");
	getRootObject()->addChild(button);

	Display display(width, height);

	class : public ActionListener {

	public:

		Maze *maze;

		void performAction() {

			int width = 5;
			int height = 5;

			maze = new Maze(GameObject::Position(0, 0), width, height);
			getRootObject()->addChild(maze);

			maze->addChild(new Player(maze->getStart(), Maze::Type::PLAYER));
		}

		Maze* getMaze() {

			return maze;
		}
	} buttonAction;

	button->setActionListener(&buttonAction);

	// Map pixels
	display.setPixel(Maze::Type::WALL, Display::Pixel((char)219, FOREGROUND_GREEN));
	display.setPixel(Maze::Type::PATH, Display::Pixel((char)0, 0));
	display.setPixel(Maze::Type::START, Display::Pixel('S', FOREGROUND_BLUE | FOREGROUND_INTENSITY));
	display.setPixel(Maze::Type::EXIT, Display::Pixel('E', FOREGROUND_RED | FOREGROUND_INTENSITY));
	display.setPixel(Maze::Type::PLAYER, Display::Pixel('P', FOREGROUND_RED | FOREGROUND_INTENSITY));

	button->setStatus(GameObject::Status::FOCUSED);

	while (true) {

		getRootObject()->update();

		getRootObject()->draw(display);
		display.swapBuffers();
	}

	delete getRootObject();
	//delete maze;
	delete label;
	delete button;

	// Avoid having the press any button to exit message appear randomly in the middle of what was previously on screen
	display.clearScreen();
	display.swapBuffers();
}