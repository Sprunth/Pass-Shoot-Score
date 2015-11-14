#pragma once

#include "Globals.h"

#include "WorldObject.h"

class Player :
	public WorldObject
{
public:
	Player();
	~Player();

	std::string GetName() { return Name; }

private:

	std::string Name;
};

