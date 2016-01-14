#pragma once

#include "Globals.h"

class Player
{
public:
	Player();
	~Player();

	std::string GetName() const { return name; }
	void SetName(std::string n) { name = n; }

private:
	std::string name;
};

