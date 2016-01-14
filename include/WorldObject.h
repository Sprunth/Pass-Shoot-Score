#pragma once

#include "Globals.h"

class WorldObject
{
public:
	WorldObject();
	~WorldObject();

	std::string GetName() const { return name; }
	void SetName(std::string n) { name = n; }

private:
	std::string name;
};

