#pragma once

#include "Globals.h"

#include "WorldObject.h"

class Player : public WorldObject
{
public:
	Player(int age);
	~Player();

	int GetAge() const { return age; }

private:
	int age;
};
