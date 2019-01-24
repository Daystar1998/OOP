#include <map>

#include "display.h"
#include "entities/player.h"
#include "gameObject.h"
#include "maze.h"

#include "gui/actionListener.h"
#include "gui/button.h"
#include "gui/label.h"
#include "gui/menu.h"

GameObject *root = nullptr;

GameObject* getRootObject() {

	if (root == nullptr)
		root = new GameObject(GameObject::Position(0, 0), 1, 1);

	return root;
}

int main() {

	int width = 21;
	int height = 21;

	//Label *label = new Label(GameObject::Position(0, 0), "Testing");
	//root->addChild(label);

	Menu *mainMenu = new Menu();
	getRootObject()->addChild(mainMenu);

	Button *playButton = new Button(GameObject::Position(0, 0), "Play");
	mainMenu->addChild(playButton);

	Button *settingsButton = new Button(GameObject::Position(0, 1), "Settings");
	mainMenu->addChild(settingsButton);

	Button *quitButton = new Button(GameObject::Position(0, 2), "Quit");
	mainMenu->addChild(quitButton);

	Display display(width, height);

	// ActionListener for the play button
	class : public ActionListener {

	public:

		Maze *maze;
		Menu *menu;

		void performAction() {

			int width = 5;
			int height = 5;

			maze = new Maze(GameObject::Position(0, 0), width, height);
			getRootObject()->addChild(maze);

			maze->addChild(new Player(maze->getStart(), Maze::Type::PLAYER));
			menu->setVisible(false);
		}

		Maze* getMaze() {

			return maze;
		}

		void setMenu(Menu *menu) {

			this->menu = menu;
		}
	} playGameAction;

	// ActionListener for quiting the game
	class : public ActionListener {

	public:

		bool quit = false;

		void performAction() {

			quit = true;
		}

		bool hasQuit() {

			return quit;
		}
	} quitGameAction;

	playButton->setActionListener(&playGameAction);
	playGameAction.setMenu(mainMenu);

	quitButton->setActionListener(&quitGameAction);

	// Map pixels
	display.setPixel(Maze::Type::WALL, Display::Pixel((char)219, FOREGROUND_GREEN));
	display.setPixel(Maze::Type::PATH, Display::Pixel((char)0, 0));
	display.setPixel(Maze::Type::START, Display::Pixel('S', FOREGROUND_BLUE | FOREGROUND_INTENSITY));
	display.setPixel(Maze::Type::EXIT, Display::Pixel('E', FOREGROUND_RED | FOREGROUND_INTENSITY));
	display.setPixel(Maze::Type::PLAYER, Display::Pixel('P', FOREGROUND_RED | FOREGROUND_INTENSITY));

	while (!quitGameAction.hasQuit()) {

		display.clearScreen();
		getRootObject()->update();

		getRootObject()->draw(display);
		display.swapBuffers();
	}

	delete getRootObject();

	// Avoid having the press any button to exit message appear randomly in the middle of whatever was previously on screen
	display.clearScreen();
	display.swapBuffers();
}