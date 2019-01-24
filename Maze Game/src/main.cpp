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

Maze *maze;

GameObject* getRootObject() {

	if (root == nullptr)
		root = new GameObject(GameObject::Position(0, 0), 1, 1);

	return root;
}

void setMaze(Maze *newMaze) {

	maze = newMaze;
}

int main() {

	bool running;

	int width = 21;
	int height = 21;

	Menu *mainMenu = new Menu();
	getRootObject()->addChild(mainMenu);

	Button *playButton = new Button(GameObject::Position(0, 0), "Play");
	mainMenu->addChild(playButton);

	Button *quitButton = new Button(GameObject::Position(0, 1), "Quit");
	mainMenu->addChild(quitButton);

	// ActionListener for the play button
	class : public ActionListener {

	public:

		int width;
		int height;

		Maze *maze;
		Menu *menus[2];

		void performAction() {

			maze = new Maze(GameObject::Position(0, 0), width, height);
			getRootObject()->addChild(maze);
			setMaze(maze);

			maze->addChild(new Player(maze->getStart(), Maze::Type::PLAYER));

			for (int i = 0; i < 2; i++) {

				menus[i]->setVisible(false);
			}
		}

		void setMenu(Menu *menu, int index) {

			this->menus[index] = menu;
		}

		void setWidth(int &width) {

			this->width = width;
		}

		void setHeight(int &height) {

			this->height = height;
		}
	} playGameAction;

	playGameAction.setWidth(width);
	playGameAction.setHeight(height);

	// ActionListener for the quit button
	class : public ActionListener {

	public:

		bool *running;

		void performAction() {

			*running = false;
		}

		void setRunning(bool *running) {

			this->running = running;
		}
	} quitGameAction;

	quitGameAction.setRunning(&running);

	playButton->setActionListener(&playGameAction);
	playGameAction.setMenu(mainMenu, 0);

	quitButton->setActionListener(&quitGameAction);

	// Menu displayed after the maze is completed

	Menu *completionMenu = new Menu();
	getRootObject()->addChild(completionMenu);

	Label *resultMessage = new Label(GameObject::Position(0, 0), "");
	completionMenu->addChild(resultMessage);

	Button *playAgainButton = new Button(GameObject::Position(0, 1), "Play Again?");
	completionMenu->addChild(playAgainButton);

	Button *mainMenuButton = new Button(GameObject::Position(0, 2), "Main Menu");
	completionMenu->addChild(mainMenuButton);

	// ActionListener for the main menu button
	class : public ActionListener {

	public:

		Menu *mainMenu;
		Menu *currentMenu;

		void performAction() {

			currentMenu->setVisible(false);
			mainMenu->setVisible(true);
		}

		void setMainMenu(Menu *mainMenu) {

			this->mainMenu = mainMenu;
		}

		void setCurrentMenu(Menu *currentMenu) {

			this->currentMenu = currentMenu;
		}
	} mainMenuAction;

	playAgainButton->setActionListener(&playGameAction);
	playGameAction.setMenu(completionMenu, 1);

	mainMenuButton->setActionListener(&mainMenuAction);
	mainMenuAction.setMainMenu(mainMenu);
	mainMenuAction.setCurrentMenu(completionMenu);

	completionMenu->setVisible(false);

	Display display(width, height);

	// Map pixels
	display.setPixel(Maze::Type::WALL, Display::Pixel((char)219, FOREGROUND_GREEN));
	display.setPixel(Maze::Type::PATH, Display::Pixel((char)0, 0));
	display.setPixel(Maze::Type::START, Display::Pixel('S', FOREGROUND_BLUE | FOREGROUND_INTENSITY));
	display.setPixel(Maze::Type::EXIT, Display::Pixel('E', FOREGROUND_RED | FOREGROUND_INTENSITY));
	display.setPixel(Maze::Type::PLAYER, Display::Pixel('P', FOREGROUND_RED | FOREGROUND_INTENSITY));

	while (running) {

		display.clearScreen();
		getRootObject()->update();

		if (maze != nullptr && maze->getStatus() != GameObject::Status::RUNNING) {

			if (maze->getStatus() == GameObject::Status::SUCCESS) {

				resultMessage->setString("You Win!");
			} else if (maze->getStatus() == GameObject::Status::FAILURE) {

				resultMessage->setString("You Lose");
			}

			completionMenu->setVisible(true);
			getRootObject()->removeChild(maze);
			maze = nullptr;
		}

		getRootObject()->draw(display);
		display.swapBuffers();
	}

	delete getRootObject();

	// Avoid having the press any button to exit message appear randomly in the middle of whatever was previously on screen
	display.clearScreen();
	display.swapBuffers();
}