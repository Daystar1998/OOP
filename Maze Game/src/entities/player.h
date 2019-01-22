#pragma once

/******************************************************************
File Name: player.h

Class Name: Player

Des: This is a class for a player

Author: Matthew Day

Due Date: 1/23/19
*******************************************************************/

#include <windows.h>

#include "entity.h"

class Player : public Entity {

public:

	Player(GameObject::Position position, int id);

	void update() override;
private:

	int getKey(int key);
};

