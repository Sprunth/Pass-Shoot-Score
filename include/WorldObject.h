#pragma once

#include "Globals.h"

#include <boost/uuid/uuid_generators.hpp>

class WorldObject
{
public:
	WorldObject();
	virtual ~WorldObject();

	std::string GetName() const { return name; }
	void SetName(std::string n) { name = n; }

	boost::uuids::uuid GetID() const { return ID; }

private:
	static boost::uuids::random_generator uuid_gen;

	std::string name;
	boost::uuids::uuid ID;
};

